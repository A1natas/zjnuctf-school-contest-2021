FROM  ctftraining/base_image_nginx_mysql_php_56

COPY file /var/www/html

RUN chmod -R 555 /var/www/html

EXPOSE 80

CMD ["/bin/sh", "-c", "docker-entrypoint"]