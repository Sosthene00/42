#!/bin/bash

echo -e "\n\e[92mCreating a SSL certificate\e[0m\n"
#Change to your company details
country=GB
state=Greater London
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
