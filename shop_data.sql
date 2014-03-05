# ************************************************************
# Sequel Pro SQL dump
# Version 4096
#
# http://www.sequelpro.com/
# http://code.google.com/p/sequel-pro/
#
# Host: localhost (MySQL 5.1.63)
# Database: d7demo
# Generation Time: 2014-03-05 18:43:22 +0000
# ************************************************************


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;


# Dump of table customer
# ------------------------------------------------------------

LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;

INSERT INTO `customer` (`cid`, `firstname`, `lastname`, `email`)
VALUES
	(1,'Clare','Lindley','c@c.com'),
	(2,'Anna','Lindley','c@c.com'),
	(3,'Kate','Lindley','c@c.com');

/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;


# Dump of table order_details
# ------------------------------------------------------------

LOCK TABLES `order_details` WRITE;
/*!40000 ALTER TABLE `order_details` DISABLE KEYS */;

INSERT INTO `order_details` (`did`, `oid`, `pid`, `qty`, `price`)
VALUES
	(1,1,1,1,'99'),
	(2,1,8,1,'50'),
	(3,1,12,1,'100'),
	(5,2,1,1,'99'),
	(6,3,13,1,'25');

/*!40000 ALTER TABLE `order_details` ENABLE KEYS */;
UNLOCK TABLES;


# Dump of table orders
# ------------------------------------------------------------

LOCK TABLES `orders` WRITE;
/*!40000 ALTER TABLE `orders` DISABLE KEYS */;

INSERT INTO `orders` (`oid`, `cid`, `order_date`, `shipped_date`, `status`)
VALUES
	(1,1,1393097020,234234234,1),
	(2,2,1388620800,234234234,1),
	(3,3,1388600800,234234234,1);

/*!40000 ALTER TABLE `orders` ENABLE KEYS */;
UNLOCK TABLES;


# Dump of table product
# ------------------------------------------------------------

LOCK TABLES `product` WRITE;
/*!40000 ALTER TABLE `product` DISABLE KEYS */;

INSERT INTO `product` (`pid`, `title`, `description`, `image`)
VALUES
	(1,'iphone5','nice','phone.jpg'),
	(2,'car','desc','phone.jpg'),
	(4,'Fridge','nice','phone.jpg'),
	(5,'speakers','nice','phone.jpg'),
	(6,'Blackberry','desc','phone.jpg'),
	(8,'iPhone Case','desc','phone.jpg'),
	(9,'Ebook','desc','phone.jpg'),
	(10,'Microwave','desc','phone.jpg'),
	(11,'Road Bike','desc','phone.jpg'),
	(12,'Garmin Swim watch','desc','watch.jpg'),
	(13,'Game of Thrones Box Set','Good','dvd.jpg');

/*!40000 ALTER TABLE `product` ENABLE KEYS */;
UNLOCK TABLES;



/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
