FROM php:7.0-apache

COPY file /var/www/html

RUN mv /var/www/html/flag / \
    && chmod -R 777 /var/www/html/* \
    && chmod -R 777 /flag 

EXPOSE 80

CMD ["/bin/sh", "-c", "/var/www/html/start.sh"]
