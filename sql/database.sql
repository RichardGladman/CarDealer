-- CarDealer.customers definition

CREATE TABLE `customers` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) DEFAULT NULL,
  `address` varchar(255) DEFAULT NULL,
  `email` varchar(100) DEFAULT NULL,
  `phone` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;


-- CarDealer.part_exchanges definition

CREATE TABLE `part_exchanges` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `Make` varchar(100) DEFAULT NULL,
  `Model` varchar(100) DEFAULT NULL,
  `registration` varchar(100) DEFAULT NULL,
  `miles` float DEFAULT NULL,
  `price` float DEFAULT NULL,
  `sales_id` int(11) DEFAULT NULL,
  `auctioned` tinyint(1) DEFAULT NULL,
  `stocked` tinyint(1) DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;


-- CarDealer.sales definition

CREATE TABLE `sales` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `vehicle_id` int(11) DEFAULT NULL,
  `customer_id` int(11) DEFAULT NULL,
  `seller_id` int(11) DEFAULT NULL,
  `registration` varchar(100) DEFAULT NULL,
  `added_date` datetime DEFAULT curtime(),
  `negotiated_price` float DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;


-- CarDealer.sellers definition

CREATE TABLE `sellers` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `first_name` varchar(100) DEFAULT NULL,
  `last_name` varchar(100) DEFAULT NULL,
  `email` varchar(100) DEFAULT NULL,
  `phone` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;


-- CarDealer.vehicles definition

CREATE TABLE `vehicles` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `manufacturer` varchar(100) DEFAULT NULL,
  `year_of_manufacture` varchar(4) DEFAULT NULL,
  `miles` decimal(10,2) DEFAULT NULL,
  `vehicle_condition` varchar(4) DEFAULT NULL,
  `drive` varchar(3) DEFAULT NULL,
  `quantity` int(11) DEFAULT NULL,
  `price` decimal(10,2) DEFAULT NULL,
  `picture` longblob DEFAULT NULL,
  `name` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
