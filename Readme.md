# Volleyball Scheduling

A scheduling application for National Chung Cheng University Volleyball League.

Using techniques:

+ MySQL
+ Gtkmm
+ C++ Boost
+ Gliffy (to design application structure and view) 

## Project Status
[![Build Status](https://travis-ci.org/csietingkai/volleyball.svg?branch=master)](https://travis-ci.org/csietingkai/volleyball)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/c41ed6ad92d043ce93192e4b00d9ba59)](https://www.codacy.com/app/csietingkai/volleyball?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=csietingkai/volleyball&amp;utm_campaign=Badge_Grade)

## Developers: 

+ [Ting-Kai Hu](https://github.com/csietingkai)
+ [RB Lin](https://github.com/RBRBRB)

## Things To Do Before Execute

```
sudo apt-get install libboost-all-dev
sudo apt-get install libmysqlcppconn-dev
sudo apt-get install libgtkmm-3.0-dev
```

## TODO List

+ [x] set team conditions
+ [ ] implement of class 'Game' & 'Schedule'
+ [ ] frontend view
+ [ ] algorithm for scheduling games
+ [ ] add code coverage test
+ [ ] create data in database for testing
+ [ ] test unit in test.cpp
+ [x] [add ci test](https://travis-ci.org/csietingkai/volleyball)
+ [ ] [add code coverage test](https://coveralls.io)
+ [ ] [add code review tool](https://app.codacy.com/project/csietingkai/volleyball)

## Fail TODO List

+ duplicate class name condition in log file

## Usage

+ clone the whole project
```
$ git clone git@github.com:csietingkai/volleyball.git
```

+ generate executable file
```
$ make
```

+ execute the exe file
```
$ ./volleyball.exe
```
