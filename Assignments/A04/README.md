## A05

- Name: Ricardo Rios
- Date: 26 Oct 2022
- Class: 2143 OOP

# OOP TERMINOLOGY
## Abstraction
Abstraction in C++ Data abstraction is one of the most essential and important features of object-oriented programming in C++. Abstraction means displaying only essential information and hiding the details.

![image](https://user-images.githubusercontent.com/98514621/197786170-6e37107c-96ba-41e7-999c-d4695139c0c2.png)

## Attributes / Properties

Attributes/Properties are data members inside a class or an object that represent the different features of the class. They can also be referred to as characteristics of the class that can be accessed from other objects or differentiate a class from other classes.

![image](https://user-images.githubusercontent.com/98514621/197786968-313440f0-958f-4d3c-886e-0de6dceadb23.png)
## Class
A class in C++ is a user-defined type or data structure declared with keyword class that has data and functions as its members whose access is governed by the three access specifiers private, protected or public. By default access to members of a C++ class is private.

![image](https://user-images.githubusercontent.com/98514621/197787695-ed08800b-1b6f-4774-899f-426570b7e66c.png)

## Class Variable
Class Variables and methods are basically variables and functions that belongs to the class. These are often referred to as "class members".

![image](https://user-images.githubusercontent.com/98514621/197788010-5c02ae8f-6205-4500-96cb-994bb5f246a7.png)

## Composition
In C++ Composition, an object is a part of another object. The object that is a part of another object is known as sub object. When a C++ Composition is destroyed, then all of its sub objects are destroyed as well. Such as when car is destroyed, then its motor, frame, and other part are also destroyed with it. It has do and die relationship.

![image](https://user-images.githubusercontent.com/98514621/197788543-006d16c8-dc9f-4eb3-88d6-8b911c3878b2.png)

## Constructor
Constructor in C++ is a special method that is invoked automatically at the time of object creation. It is used to initialize the data members of new objects generally. The constructor in C++ has the same name as the class or structure. Constructor is invoked at the time of object creation. It constructs the values i.e. provides data for the object which is why it is known as constructors.
![image](https://user-images.githubusercontent.com/98514621/197789191-87b2e8ca-1223-4d9b-8725-adab4068a148.png)

## Encapsulation
Encapsulation is an Object Oriented Programming concept that binds together the data and functions that manipulate the data, and that keeps both safe from outside interference and misuse. Data encapsulation led to the important OOP concept of data hiding. 

![image](https://user-images.githubusercontent.com/98514621/197789305-629086fc-9df4-449c-9d71-f156632e58d3.png)

## Friends
### Friend Class
Friend Class A friend class can access private and protected members of other class in which it is declared as friend. It is sometimes useful to allow a particular class to access private members of other class. For example, a LinkedList class may be allowed to access private members of Node. 

A friend class can access both private and protected members of the class in which it has been declared as friend.

![image](https://user-images.githubusercontent.com/98514621/197790348-3a0cf48c-51c5-4bff-98ba-af144dc764e9.png)


### Friend Function

Friend Function Like friend class, a friend function can be given a special grant to access private and protected members. A friend function can be: 
a) A member of another class 
b) A global function 
 ![image](https://user-images.githubusercontent.com/98514621/197790237-292e0305-4958-408c-aac6-aff8440c8181.png)
 
 ## Inheritance
 
 Inheritance is a feature or a process in which, new classes are created from the existing classes. The new class created is called “derived class” or “child class” and the existing class is known as the “base class” or “parent class”. The derived class now is said to be inherited from the base class.
 
 ![image](https://user-images.githubusercontent.com/98514621/197969056-aeb1d8a3-5979-4dc8-a818-8d26cab29968.png)

## Instance Variable

Instance variable in C++
Instance Variables: Instance variables are non-static variables and are declared in a class outside any method, constructor, or block. As instance variables are declared in a class, these variables are created when an object of the class is created and destroyed when the object is destroyed.

![image](https://user-images.githubusercontent.com/98514621/197969598-0134fbb7-629a-4554-9eff-5aabbf7e7a3e.png)

## Member Variable

A member variable is a variable (an object) that is part of a class.

![image](https://user-images.githubusercontent.com/98514621/197970282-2062b79f-75b8-4436-914a-6c28c46a9f3e.png)

## Method

Methods are functions that belongs to the class.

There are two ways to define functions that belongs to a class:

Inside class definition
Outside class definition

![image](https://user-images.githubusercontent.com/98514621/197970550-8d46c2e9-b966-49f2-9356-19591c5925ad.png)

## Multiple Inheritance


Multiple Inheritance is a feature of C++ where a class can inherit from more than one classes.  The constructors of inherited classes are called in the same order in which they are inherited. For example, in the following program, B’s constructor is called before A’s constructor.

A class can be derived from more than one base class.

Eg: 

(i) A CHILD class is derived from FATHER and MOTHER class
(ii) A PETROL class is derived from LIQUID and FUEL class.

![image](https://user-images.githubusercontent.com/98514621/197970785-19c1a521-5e8a-421e-a170-b6efa8edabae.png)

## Object

An Object is an instance of a Class. When a class is defined, no memory is allocated but when it is instantiated (i.e. an object is created) memory is allocated.

![image](https://user-images.githubusercontent.com/98514621/197971234-b877f762-596b-40cb-b816-91b71eee422e.png)

## Overloading 

C++ allows you to specify more than one definition for a function name or an operator in the same scope, which is called function overloading and operator overloading respectively.

An overloaded declaration is a declaration that is declared with the same name as a previously declared declaration in the same scope, except that both declarations have different arguments and obviously different definition (implementation).\

![image](https://user-images.githubusercontent.com/98514621/197971852-2d52821f-ae4e-4161-b7fa-5b7ef743582a.png)

## Polymorphism

The word polymorphism means having many forms. Typically, polymorphism occurs when there is a hierarchy of classes and they are related by inheritance.

C++ polymorphism means that a call to a member function will cause a different function to be executed depending on the type of object that invokes the function.

![image](https://user-images.githubusercontent.com/98514621/197972215-7e2041d1-0bab-4991-9832-a1310ab1d36c.png)

## Public / Private / Protected

The public/private/protected keywords are access specifiers. Access specifiers define how the members (attributes and methods) of a class can be accessed. 

### Public
- members are accessible from outside the class
### Private

private - members cannot be accessed (or viewed) from outside the class

### Protected

protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes. You will learn more about Inheritance later.

PUBLIC/PRIVATE

![image](https://user-images.githubusercontent.com/98514621/197973130-361c8dd6-6333-4a98-8798-e88508bf2bdd.png)


PROTECTED

![image](https://user-images.githubusercontent.com/98514621/197973310-dd1cec0a-1593-4804-80a9-2a2461804e13.png)

## Static

### In a function 
Static variables in a Function: When a variable is declared as static, space for it gets allocated for the lifetime of the program. Even if the function is called multiple times, space for the static variable is allocated only once and the value of variable in the previous call gets carried through the next function call. This is useful for implementing coroutines in C/C++ or any other application where previous state of function needs to be stored.

![image](https://user-images.githubusercontent.com/98514621/197973783-8ae2c3ee-dfde-4a3c-b77e-1e76c37f751a.png)


### In a class

Static variables in a class: As the variables declared as static are initialized only once as they are allocated space in separate static storage so, the static variables in a class are shared by the objects. There can not be multiple copies of same static variables for different objects. Also because of this reason static variables can not be initialized using constructors.

![image](https://user-images.githubusercontent.com/98514621/197973936-20a2590b-1754-4f17-a143-41f5ed607391.png)

## Virtual 

A virtual function is a member function which is declared within a base class and is re-defined (overridden) by a derived class. When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class’s version of the function. 

![image](https://user-images.githubusercontent.com/98514621/197974232-7076e227-33f3-4b35-ba6a-e78602ceb67b.png)












 
 
 



