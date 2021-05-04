#!/bin/sh

echo $FLAG > /etc/flag

export FLAG=not_flag
FLAG=not_flag

service apache2 start
service mysql start

tail -F /var/log/apache2/error.log
rm /var/www/html/start.sh