if [ ${AUTOINDEX} == 0 ]
then
	rm /etc/nginx/sites-available/default
	mv /default_off /etc/nginx/sites-available/default
else
	:
fi
/usr/local/bin/supervisord -c /supervisor/supervisord.conf
supervisorctl -c /supervisor/supervisord.conf restart nginx
