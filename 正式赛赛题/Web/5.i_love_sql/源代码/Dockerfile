FROM  ctftraining/base_image_nginx_mysql_php_56

COPY file /var/www/html

RUN mv /var/www/html/flag / \
	&& chmod -R 777 /var/www/html/*

EXPOSE 80

CMD ["/bin/sh", "-c", "/var/www/html/start.sh"]
