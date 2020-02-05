# Web programming Track(HTML,CSS,JS,Mysql,Ajax,JQuery,Php)
![WebDevelopment](https://user-images.githubusercontent.com/39864308/73829280-62581000-480b-11ea-9d53-7901895aa5e7.jpg)

 	-20 For exam
	-40 For Project
#
# Php
	On of Lectures:
	Syntax For Mysql:
	--------------
	mysql-connect |(servername,uname,password,port,socket);
	--------------
	
	Example for Old Exam:
	-Make Form by PHP
	-Trace Code
	-CRUD by PHP Code
	-Handle Code
	in Php1,2 Power point in Slide 22,23,24
#
# CSS
	There Was Tree Way To Write CSS:
	1-inline:
	<p style="color:red;">Hello</p>
	================
	2-Documant Level|
	================
	<html>
	<body>
	<style>
	p{
	color:red
	}
	</style>
	<p>Hello</p>
	</body>
	</html>
	================
	3-External Level|
	================
	<html>
	<link rel="stylesheet" type="text/css" href="mystyle.css">
	<body>
	<p>Hello</p>
	</body>
	</html>
	
#
# Type of CSS Selectors
	1-Element Selector:
	p{color:red;}
	
	2-Id Selector:
	#para1 {color:red;}
	
	3-Class Selector:
	.center {text-align:center;}
	
	4-Universal Selector:
	* {text-align: center;color: blue;}
	
	5-Pseudo Selector:
	a:link {  color: #FF0000;}


  
#

# JavaScript

	ThinkTank:
	2-PostMan Application
	1-SetTime out function in JavaScript:infinite loop
	
# DOM :Documant Object Model
	Dom Work with :
		1-Ankor
		2-Form
		3-Style
		4-Mouse-Keyboard Click
		
	By using Code :
		getelementbyid("");




	
#

					=========================================================
		                        Web Programming Project [Library Integrated System (LIS)]
		                        =========================================================
 # Note:
 	- 31/1/2020 We Take Ajax Last Lecture 14,15,16,17
 	-تصنيف ديوي العشري
 	-Dewey decimal classification
 	-Z39.50 protocal
	-Add CategoriesTable For BookTable
	-Add Complent Table For Client
	
 
 #  :arrow_right: Presentation Content
 #
 <br>
  <kbd>></kbd> introducation
  						&nbsp; &nbsp; &nbsp;  <kbd>></kbd> MindMap <br>

  <kbd>></kbd> Feature
  					&nbsp;	&nbsp;&nbsp; &nbsp; &nbsp;  <kbd>></kbd> SnapShot
<br>


#


#					        <kbd>></kbd>Introducation

	-The Library  System is a web Application Create,Developed TO Store ,Trace
	The Book,Auther,Categories,Borrow Transaction,Sell Transation
	
	



#					 <kbd>></kbd> MindMap 
![Capture](https://user-images.githubusercontent.com/39864308/73829002-e8c02200-480a-11ea-9a7e-ea50c2a9b802.PNG)



#			        <kbd>></kbd>Feature
 	
	-A modern Library System Desgin
	-Full Catalog For Book
	-Simple,Clear Search, UI UX for All User
	-Easy Way To Enter New Book
	-Easy Way To Login and Sign in
	-Easy To Maintain Database
	
	
#				  <kbd>></kbd>SnapShot


![New Doc 2020-02-04 13 45 08_1](https://user-images.githubusercontent.com/39864308/73742282-be139200-4754-11ea-879f-0526c1d16a1c.jpg)

#

#				  <kbd>></kbd>DataBase Code using MSSQL Server

	create Database LibrarySystemDB;
	--Dewey Decimal Classification (DDC)
	--Tables:  BOOk,Author,Category,Employee,Borrow,Customer,Selling,
	go
	use LibrarySystemDB;
	go
	--Create Table Author in Database
	Create Table AuthorTb
	(authorid int primary key identity(1,1),
	Name nvarchar(max),Desription nvarchar(max))
	go
	--Create Table CategoryTb
	Create Table CategoryTb
	(cateid int primary key identity(1,1),
	CateName nvarchar(max),Desription nvarchar(max))
	go
	
	--Create Table BOOK in Database
	Create Table BookTb
	(bookid int primary key identity(1,1),Title nvarchar(max),
	CopyNo int,DDCNo varchar(max),Description nvarchar(max),
	Authorid int,Cateid int ,constraint FK_BookAuthor Foreign key
	(Authorid)REFERENCES AuthorTb(authorid),constraint FK_BookCate
	Foreign key(Cateid)REFERENCES CategoryTb(Cateid));
	go
	
	--Create Table 





