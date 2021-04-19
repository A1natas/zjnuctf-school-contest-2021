create database IF NOT EXISTS ctf;
use ctf;
CREATE TABLE IF NOT EXISTS users
		(
		id int(3) NOT NULL AUTO_INCREMENT,
		username varchar(20) NOT NULL,
		password varchar(60) NOT NULL,
		PRIMARY KEY (id)
		);
CREATE TABLE emails
		(
		id int(3)NOT NULL AUTO_INCREMENT,
		email_id varchar(30) NOT NULL,
		PRIMARY KEY (id)
		);
CREATE TABLE uagents
		(
		id int(3)NOT NULL AUTO_INCREMENT,
		uagent varchar(256) NOT NULL,
		ip_address varchar(35) NOT NULL,
		username varchar(20) NOT NULL,
		PRIMARY KEY (id)
		);
CREATE TABLE referers
		(
		id int(3)NOT NULL AUTO_INCREMENT,
		referer varchar(256) NOT NULL,
		ip_address varchar(35) NOT NULL,
		PRIMARY KEY (id)
		);

INSERT INTO ctf.users (id, username, password) VALUES ('1', 'Dumb', 'Dumb'), ('2', 'Angelina', 'I-kill-you'), ('3', 'Dummy', 'p@ssword'), ('4', 'secure', 'crappy'), ('5', 'superman', 'genious'), ('6', 'batman', 'mob!le'), ('7', 'admin', 'flag in /flag');

INSERT INTO `ctf`.`emails` (id, email_id) VALUES ('1', 'Dumb@dhakkan.com'), ('2', 'Angel@iloveu.com'), ('3', 'Dummy@dhakkan.local'), ('4', 'secure@dhakkan.local'), ('5', 'stupid@dhakkan.local'), ('6', 'superman@dhakkan.local'), ('7', 'batman@dhakkan.local'), ('8', 'flag in /flag');
