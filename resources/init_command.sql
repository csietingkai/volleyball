DECLARE @DATABASE_NAME nvchar(20);
SET @DATABASE_NAME = "htk103u_volleyball"

CREATE DATABASE IF NOT EXISTS @DATABASE_NAME;
USING DATABASE @DATABASE_NAME;

CREATE TABLE IF NOT EXISTS persons
(
	ID varchar(255) NOT NULL,
	NAME varchar(255) NOT NULL, 
	AGE int NOT NULL,
	GENDER BIT(1) NOT NULL,
	PHONE_NUMBER varchar(255) NOT NULL,
	IS_ACTIVE BIT(1) NOT NULL,
	PRIMARY KEY(ID)
);

CREATE TABLE IF NOT EXISTS teams
(
	ID varchar(255) NOT NULL,
	NAME varchar(255) NOT NULL, 
	MEMBER_ID varchar(255) NOT NULL,
	PREFER_WEEK varchar(255) NOT NULL,
	PREFER_TIME varchar(255) NOT NULL,
	PRIMARY KEY(ID, MEMBER_ID)
);

CREATE TABLE IF NOT EXISTS games
(
	ID varchar(255) NOT NULL,
	TEAM_1_ID varchar(255) NOT NULL, 
	TEAM_2_ID varchar(255) NOT NULL,
	DATETIME DATETIME,
	PRIMARY KEY(ID)
);

INSERT INTO `persons` (`ID`, `NAME`, `AGE`, `GENDER`, `PHONE_NUMBER`, `IS_ACTIVE`) VALUES
('353de133f85ff64454a58ff782c31f483854c8f5', 'test1', 21, b'1', '0987654321', b'1'),
('4e9dac67d5863be963d80f64925a689a68c8cbf7', 'test4', 24, b'1', '0987654321', b'1'),
('5b638035021f1dffae1dc5be45f490534edd628e', 'test3', 23, b'1', '0987654321', b'1'),
('6bced46dd43429b141c07d427c868a4002e104f5', 'test2', 22, b'1', '0987654321', b'1'),
('a2259774926c8c9b3a60d5d2cd7db9854e94b4d3', 'test5', 25, b'1', '0987654321', b'1');

INSERT INTO `teams` (`ID`, `NAME`, `MEMBER_ID`, `PREFER_WEEK`, `PREFER_TIME`) VALUES
('e8177aaa852a9537e65234121593fbf649fc4a92', 'test_team', '353de133f85ff64454a58ff782c31f483854c8f5', 'true;false;false;false;false;false;false', '19:00:00'),
('e8177aaa852a9537e65234121593fbf649fc4a92', 'test_team', '4e9dac67d5863be963d80f64925a689a68c8cbf7', 'true;false;false;false;false;false;false', '19:00:00'),
('e8177aaa852a9537e65234121593fbf649fc4a92', 'test_team', '5b638035021f1dffae1dc5be45f490534edd628e', 'true;false;false;false;false;false;false', '19:00:00'),
('e8177aaa852a9537e65234121593fbf649fc4a92', 'test_team', '6bced46dd43429b141c07d427c868a4002e104f5', 'true;false;false;false;false;false;false', '19:00:00'),
('e8177aaa852a9537e65234121593fbf649fc4a92', 'test_team', 'a2259774926c8c9b3a60d5d2cd7db9854e94b4d3', 'true;false;false;false;false;false;false', '19:00:00');
