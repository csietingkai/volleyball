DECLARE @DATABASE_NAME nvchar(20);
SET @DATABASE_NAME = "htk103u_volleyball"

CREATE DATABASE IF NOT EXISTS @DATABASE_NAME;
USING DATABASE @DATABASE_NAME;

CREATE TABLE IF NOT EXISTS auth
(
	ID varchar(255) NOT NULL,
	ACCOUNT varchar(255) NOT NULL, 
	PWD varchar(255) NOT NULL,
	ROLE varchar(255) NOT NULL,
	PRIMARY KEY(ID),
	UNIQUE(ACCOUNT)
);

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
	JUDGE_ID varchar(255),
	GAME_TIME DATETIME,
	PRIMARY KEY(ID),
	CONSTRAINT TEAM_IDS UNIQUE(TEAM_1_ID, TEAM_2_ID)
);

INSERT INTO auth
VALUES ('c888cf04-16d4-4f69-bed7-6669409dd6bf', 'htk103u', 'htkkoeoh', 64);
