FROM 1275178869/base_image_apache_php_mysql:sjx 

COPY file /var/www/html

RUN echo [mysqld] >> /etc/alternatives/my.cnf \
    && echo secure_file_priv="" >> /etc/alternatives/my.cnf \
    && service mysql start \
    && mysql -uroot -proot -e "CREATE USER 'ubuntu'@'%' IDENTIFIED BY 'ubuntu';GRANT ALL PRIVILEGES ON *.* TO 'ubuntu'@'%' WITH GRANT OPTION;FLUSH PRIVILEGES;" \
    && mysql -uroot -proot  < '/var/www/html/db.sql' \
    && rm /var/www/html/index.html \
    && chmod 777 /var/www/html/start111.sh
EXPOSE 80

CMD ["/bin/sh", "-c", "/var/www/html/start111.sh"]





