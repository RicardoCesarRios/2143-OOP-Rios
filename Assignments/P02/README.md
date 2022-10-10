## P02 - Vector list
### Ricardo Cesar Rios
### Description:

This program implements a class that will be a basic container type of integers that can shrink or grow dymaically while items are eiter added or removed
create a more robust MyVector class that includes some added functionality with the overloading of some C++ operators.
The operations performed by using a particular operator will be defined by us with a brief discussion on what we should do. The user do not have to abide by 
convention, we can define each operator to do anything we want.


One of the main purposes of this program is to further expand the understanding of the essence of object oriented programming
### Files

|   #   | File      | Description                      |
| :---: | --------  | -------------------------------- |
|   1   | main.cpp  | Main driver of my list program . |
|   2   | Banner.txt| Coverpage             |
|   3   | Output.txt| The output file of resulting data|

### Instructions

- This program does not require any non standard libraries

### Example Command
v1[4] = 9;
// v1 now = [1,2,3,4,9]

fout << v1 << endl;
fout << v1 << endl;

MyVector v3 = v1 + v2;
fout << v3 << endl;

v3 = v1 - v2;
fout << v3 << endl;
