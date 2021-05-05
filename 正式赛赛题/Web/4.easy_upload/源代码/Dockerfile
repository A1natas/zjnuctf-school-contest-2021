FROM php:7.0-apache

LABEL Author="bmth"

COPY file /var/www/html

RUN mkdir /var/www/html/upload/ && \
	chmod -R 755 /var/www/html/ && \
    chmod -R 777 /var/www/html/upload/ && \
    chown -R root:root /var/www/html && \
    mv /var/www/html/flag /flag && \
    mv ./apache2.conf /etc/apache2/apache2.conf

CMD ["/bin/sh", "-c", "/var/www/html/start.sh"]

EXPOSE 80


