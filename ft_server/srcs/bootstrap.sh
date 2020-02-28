#!/bin/bash

echo -e "\n\e[92mUpdating the system\e[0m\n"
apt-get -qq update && apt-get -qq upgrade \
&& apt-get install -qq \
wget \
procps \
gnupg \
lsb-release \
supervisor \
nginx \
mariadb-server \
python3-pip \
openssl \
lsof \
curl \
vim

echo "==========================================="

echo -e "\n\e[92mCopying nginx conf file\e[0m\n"
service nginx stop
cp /etc/nginx/nginx.conf /etc/nginx/nginx.conf.bak
mv nginx.conf /etc/nginx/nginx.conf
echo -e "\n\e[92mCopying sites conf files\e[0m\n"
mv /default.conf /etc/nginx/sites-available/default
rm /etc/nginx/sites-enabled/default
ln -s /etc/nginx/sites-available/default /etc/nginx/sites-enabled/

echo "==========================================="

echo -e "\n\e[92mInstalling Supervisor\e[0m\n"
mkdir supervisor
pip3 -qqq install supervisor
echo -e "\n\e[92mCopying conf file in /supervisor\n"
mv /supervisord.conf /supervisor/supervisord.conf

echo "==========================================="

echo -e "\n\e[92mGenerating MySQL password\e[0m\n"
PASS_MYSQL_ROOT=`openssl rand -base64 12`
echo -e "\n\e[92mConfiguring MySQL for wordpress\e[0m\n"
service mysql start
WPDB=wordpress
mysql -u root <<_EOF_
CREATE OR REPLACE USER wordpress_user@localhost IDENTIFIED BY '${PASS_MYSQL_ROOT}';
CREATE DATABASE ${WPDB} DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;
GRANT ALL ON ${WPDB}.* TO 'wordpress_user'@'localhost' IDENTIFIED BY '${PASS_MYSQL_ROOT}';
FLUSH PRIVILEGES;
_EOF_

echo "==========================================="

echo -e "\n\e[92mUpdating my.cnf file with wordpress_user\e[0m\n"
echo "[client]" >> /etc/mysql/my.cnf
echo "user=wordpress_user" >> /etc/mysql/my.cnf
echo "password=\"${PASS_MYSQL_ROOT}\"" >> /etc/mysql/my.cnf

echo "==========================================="

echo -e "\n\e[92mInstalling PHP\e[0m\n"
DEBIAN_FRONTEND=noninteractive apt-get -qq install php7.3 php7.3-fpm php7.3-mysql php-common php7.3-cli php7.3-common php7.3-json php7.3-opcache php7.3-readline php-{mbstring,zip,gd,xml,pear,gettext,cgi,curl,gd,intl,mbstring,soap,xml,xmlrpc,zip}
mkdir /run/php
mv /php_test /var/www/html/info.php

echo "==========================================="

echo -e "\n\e[92mInstalling phpmyadmin\e[0m\n"
wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-english.tar.gz
mkdir /var/www/html/phpmyadmin
tar xzf phpMyAdmin-4.9.0.1-english.tar.gz --strip-components=1 -C /var/www/html/phpmyadmin
mv /config.inc.php /var/www/html/phpmyadmin/
chown -R www-data:www-data /var/www/html/
chmod 660 /var/www/html/phpmyadmin/config.inc.php
PASS_PHPADM_ROOT=`openssl rand -base64 24`
echo "${PASS_PHPADM_ROOT}" > php_pwd
sed -i "0,/''/ s@''@'${PASS_PHPADM_ROOT}'@" /var/www/html/phpmyadmin/config.inc.php
mkdir -p /var/lib/phpmyadmin/tmp
chown -R www-data:www-data /var/lib/phpmyadmin
mysql -u root < /var/www/html/phpmyadmin/sql/create_tables.sql
mysql -u root -e "GRANT SELECT, INSERT, UPDATE, DELETE ON *.* TO 'pma'@'localhost' IDENTIFIED BY '${PASS_PHPADM_ROOT}';"
mysql -u root -e "FLUSH PRIVILEGES;"

echo "==========================================="

echo -e "\n\e[92mInstalling wordpress\e[0m\n"
cd /tmp
curl -LO https://wordpress.org/latest.tar.gz
tar xzf latest.tar.gz
cd /
mv /wp-config.php /tmp/wordpress/wp-config.php
cp -a /tmp/wordpress/* /var/www/html/
chown -R www-data:www-data /var/www/html/
find /var/www/html/ -type d -exec chmod 750 {} \;
find /var/www/html/ -type f -exec chmod 640 {} \;
sed -i "0,/'password_here'/ s@'password_here'@'${PASS_MYSQL_ROOT}'@" /var/www/html/wp-config.php
mkdir -p /var/www/html/wp-content/uploads/2020/02
mv /sacrifice-1-1200x675.jpeg /var/www/html/wp-content/uploads/2020/02
chown -R www-data:www-data /var/www/html/wp-content/uploads/
mysql -u wordpress_user wordpress < /dbdump.sql

echo "==========================================="

echo -e "\n\e[92mCreating a SSL certificate\e[0m\n"
country=GB
state=Greater_London
locality=Hammersmith
organization=Ace-of-spades.uk
organizationalunit=IT
email=Lemmy@killedbydeath.com
commonname=DogfaceBoy

openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt \
    -subj "/C=$country/ST=$state/L=$locality/O=$organization/OU=$organizationalunit/CN=$commonname/emailAddress=$email"

echo "---------------------------"
echo "-----Below is your CSR-----"
echo "---------------------------"

cat /etc/ssl/certs/nginx-selfsigned.crt

echo
echo "---------------------------"
echo "-----Below is your Key-----"
echo "---------------------------"

cat /etc/ssl/private/nginx-selfsigned.key

echo -e "\n\e[92mCreating Diffie-Hellman key pair\e[0m\n"
openssl dhparam -dsaparam -out /etc/nginx/dhparam.pem 4096

echo -e "\n\e[92mConfiguring Nginx for SSL\e[0m\n"
echo -e "ssl_certificate /etc/ssl/certs/nginx-selfsigned.crt;\nssl_certificate_key /etc/ssl/private/nginx-selfsigned.key;" > /etc/nginx/snippets/self-signed.conf
mv /ssl-params.conf /etc/nginx/snippets/ssl-params.conf

echo -e "\n\e[92mCleaning the house\e[0m\n"
rm -r /dbdump.sql phpMyAdmin-*
rm -rf /tmp/wordpress
mv *_pwd /root
mv *.sh /root
