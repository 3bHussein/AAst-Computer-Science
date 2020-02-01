# OOP USing Java programming

![unnamed](https://user-images.githubusercontent.com/39864308/73590958-73461000-44f1-11ea-9b81-3f9a3f619082.png)




<br/><br/>

![javacodecompile](https://user-images.githubusercontent.com/39864308/73591074-b359c280-44f2-11ea-9dad-838772545117.png)

<br/><br/>
To Create java File just <ChooseFilename>.java and save it ;<br/>
-java file in javacode ; <br/>
  <input style="color:red" type="text">
TO compile to <file>.class consider bytecode work with any OS JVM<br/>
Using javac in Command Prompet 
-To Run <File>.class use Java in Cmd<br/>

[![npm](https://img.shields.io/npm/v/github-buttons)](https://www.npmjs.com/github-buttons)

--Funation in Java it's Called method

--TO Declare Variable 
(Access Modified)(DataType)(Identifier)=Value<br>
  
  Public int c =5;<br>
 --To Declare Constants Variable 
  
(Access Modified)(static)(final)(DataType)(Identifier)=Value<br>
#
TypeErrors | #Logic Error | #RunTime Error | #syntax Error 
--- | --- | --- | --- 
Seconds |  A logic error produces unintended or undesired output or other behaviour | A program crash is the most noticeable type of runtime error, since the program unexpectedly quits while running. Crashes can be caused by memory leaks or other programming errors. | A syntax error is an error in the source code of a program. Since computer programs must follow strict syntax to compile correctly, any aspects of the code that do not conform to the syntax of the programming language will produce a syntax error. | 286 | 289 | 285 | 287 | 287 | 272 | 276 | 269

# 1. Constructor & Method
constructor | method 
--- | --- |
  Constructor is used to create and initialize an Object  | 	Method is used to execute certain statements. |#
A constructor cannot have any return type.	|	A method can have a return type   |#
A constructor must have same name as that of the class.	 |	 A method name cannot be same as class name.  |#
Only access modifier in constructor in public	|	A method can be having any access modifier  |#



	


# 2.Static & Non-static
Static  |	Non-static
--- | --- |
A variable must be declaring with static keyword  |	A variable should not be content a static keyword while declare
Memory allocated a variable once in all program	 |Memory allocated a variable any time created new object |

# 3.Local variable & Member variable
Local variable|	Member variable
--- | --- |
A local variable is the variable you declare in a function.|	A member variable is the variable you declare in a class definition |
Access modifiers cannot be used for local variables.|	Access modifiers can be given for instance variables.|
Local variables are visible only within the declared method, constructor, or block.|	The instance variables are visible for all methods, constructors and block in the class. Normally |







# Class :
			#Must Any Class strart with Capital Word
			#Must be name of File.java the same name of class
the  Class is blueprint or Templete
Any Class Can Content :
 1-Feild
 2-function
 3-constractor
 
 # Access Modifiers
<h2>1-Default:</h2><br>
 The access level of a default modifier is only within the package. It cannot be accessed from outside the package. If you do not specify any access level, it will be the default.
 <br>
 <h2> 2-Public:</h2><br>
 The access level of a public modifier is everywhere. It can be accessed from within the class, outside the class, within the package and outside the package.
 <br>
  <h2> 3-Private:</h2><br>
 The access level of a private modifier is only within the class. It cannot be accessed from outside the class.
  <br>
<h2> 4-Protected:</h2><br>
  The access level of a protected modifier is within the package and outside the package through child class. If you do not make the child class, it cannot be accessed from outside the package
 <br>
 
![Access-Modifiers-in-Java](https://user-images.githubusercontent.com/39864308/73590851-02522880-44f0-11ea-802b-6837d4ead839.png)


# simple java Code
	import java.lang;
	package com.test ;
	class Test {
	
    public static void main(String[] args){
        System.out.println("Hello World!");
    }
	}
	
	
	
