CREATE TABLE empty_queries (
 ID int(11) NOT NULL AUTO_INCREMENT PRIMARY KEY,
 query text NOT NULL,
 timestamp timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP
);
