
/*****************************************************************************
*                    
*  Author:           Ricardo Cesar Rios
*  Email:            Ricardocesarrios14@outlook.com
*  Label:            Program 1
*  Title:            Creation of a linked list based Vector container
*  Course:           CMPS-2143-101
*  Semester:         Fall 2022
* 
*  Description:
*        The program fetures the implimentation of a linked list based container
         labedled as "vector" which has the ability to store and recieve values from\
         an array,Vector,or file and remove said values or add new ones while     
         dynamically shrinking or growing in size. 
* 
*  Usage:
*        The progam is meant to take in int values from an array,Vector,or file
         and store them with modifiers such as inserted in the front or back of list
         or removed. 
* 
*  Files:            Main.cpp
                     input.dat
                     output.dat
*****************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;



struct Node
{
  int Data;
  Node* Next;
  Node* Prev;
 Node(int D)
  {                    //Creates a new Node in which data shall
    Data = D;          // be stored. Nodes point to new node & 
    Next = NULL;       // Previous Node 
    Prev = NULL;
    
  
  }
};




/*
  Vector 
  DESCRIPTION:
    This Class uses a linked list in order to be able to add and remove data 
    to the front, back, at any specified position, or in numerical order. The class 
    also includes a find function. The array shall also allow for the intialization 
    of a new list from a vector, file, of ints read in from the console. 

  PUBLIC METHODS: 
    CONSTRUCTORS:
      Vector() 
      Vector(int* X, int Size)
      Vector(string filename)
      Vector(const Vector &v)
    FUNCTIONS
      BOOL    isorder
      VOID    ORDER
      VOID    pushFront(int X)
      VOID    pushFront(const Vector &V)
      VOID    pushRear(int X)
      VOID    pushRear(const Vector &V)
      VOID    pushAt(int loc, int X)
      VOID    pushinorder(int X)
      VOID    print()
      VOID    Order()
      INT     popFront()
      INT     popRear()
      INT     popAt(int loc)
      INT     Find(int d)
      FRIEND  friend ostream &operator(ostream &, const Vector &);
  PRIVATE METHODS 

  USAGE:
  Vector(a,5)    //creates an instance of Vector from an array
                  with a size of 5
                  


    
      
      






  */
class Vector
{
  private:
    Node* Head;
    Node* Tail;
  public:

int size;















  // Default constructor
  Vector()
  {
    Head = NULL;
    Tail = NULL;
    size =0;
  }

  Vector(int*a, int size)

  {
    Head = NULL;
    Tail = NULL;
    size =0;
    for (int i=0; i<size; i++)
      {
        pushRear(a[i]);
      }
  }
   Vector(string filename)
  {	
    Head = NULL;
    Tail = NULL;
    size = 0;
    int Data;
    ifstream in;
    in.open(filename);	
     while (!in.eof()) 
    {	
      in>> Data;		
      pushRear(Data);		
    }
    in.close();
  }   
  Vector(const Vector &V)
  {
    Head = NULL;
    Tail = NULL; 
    size = 0;
    Node *Traverse = V.Head;
    while(Traverse!= NULL)
      {
        pushRear(Traverse->Data);
        Traverse = Traverse->Next;
      }
    
  }

    /**
     * Public: isOrder
     * 
     * Description:
     *      Determines wether the values in the Vector are in order;
     * 
     * Params:
     *      None
     * Returns:
     *     bool- returns a boolean variable (true or false)
     */ 
  bool  isorder()// I'm gonna be real with you Prof I looked up the logic on this. 
  {
    int count =0;
    Node* traverse = Head;
    while (traverse->Next!=NULL)
      {
        if(traverse->Data>=traverse->Next->Next->Data)
        {
           count++;
        }
        traverse = traverse->Next; 
      }
    if(count==0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

    /**
     * Public : Order
     * 
     * Description:
     *      If the previous function returned false then the vector is 
     *      not in order, this function will put the list in order
     * Params:
     *      None
     * 
     * Returns:
     *      Nothing as the function is void 
     */
  void  Order()
  {
    Node* traverse = Head;
    if (traverse->Data > traverse->Next->Data)
    {
      int Temp = traverse->Data;				
  		traverse->Data = traverse->Next->Data;
  		traverse->Next->Data = Temp;
  		Temp = 0;
    }
    traverse = traverse->Next;
  }

    /**
     * Public: pushFront(int X)
     * 
     * Description:
     *     inserts a single int to the front of vector
     * 
     * Params:
     *      - int
     *      The type of data that is being added
     * 
     * Returns:
     *      Void returns nothing 
     */
  void pushFront(int X)
  {
    Node*Temp=new Node(X);
    if(Head==NULL)
    {
      Head= Temp;
      Tail= Temp;
    }
    else
    {
      Temp->Next=Head;
      Head=Temp;
    }
    size++;
  }
  
/**
     * Public: Print
     * 
     * Description:
     *     prints out the values of the vector to the console
     * 
     * Params:
     *      
     *      None
     * 
     * Returns:
     *      Void returns nothing 
     */
  void print() 
  {	
  	Node* traverse = Head;
  	while (traverse)
    {				
  		cout << traverse->Data << " ";
  		traverse = traverse->Next;
  	}
  }
/**
     * Public: pushFront(const Vector &V)
     * 
     * Description:
     *     inserts the values of another vector to the front of vector
     * 
     * Params:
     *      - const Vector
     *      The type of data that is being added
     * 
     * Returns:
     *      Void returns nothing 
     */

  void pushFront(const Vector &V)
    {
      Node*Temp = V.Head; 
      while(Temp!=NULL)
        {
          pushFront(Temp->Data);
          Temp =Temp->Next;
          
        }
      size++;
    }
/**
     * Public: pushRear(int X)
     * 
     * Description:
     *     inserts a single int to the rear of vector
     * 
     * Params:
     *      - int
     *      The type of data that is being added
     * 
     * Returns:
     *      Void returns nothing 
     */
  void pushRear(int X)
  {
    Node*Temp=new Node(X);
      if(Head==NULL)
      {
        Head= Temp;
        Tail= Temp;
      }
      else
      {
        Temp->Prev = Tail;
        Tail->Next=Temp;
        Tail=Temp;
      }
      size++;
    
  }
/**
     * Public: pushRear(const Vector &V)
     * 
     * Description:
     *     inserts the values of another vector to the rear of vector
     * 
     * Params:
     *      - const Vector
     *      The type of data that is being added
     * 
     * Returns:
     *      Void returns nothing 
     */
  void pushRear(Vector V)
  {
    Node *Temp = V.Head;
        while(Temp!=NULL)
        {
          pushRear(Temp->Data);
          Temp = Temp->Next;
        }
    size++;
  }

    /**
     * Public: PushAt
     * 
     * Description:
     *      Inserts a value into a specific location 
     * 
     * Params:
     *      - list params
     *      - one per line
     *      - with return type
     *      - and one line description
     * 
     * Returns:
     *      - what does this function return (including the type)?
     */
  void pushAt(int loc, int X)
  {
    Node* Temp = new Node(X);
    if(loc<0||loc>size)
    {
      cout<<"Invalid location";
    }
    if(loc ==1)
    {
      pushFront(X);
    }
    if(loc==size)
    {
      pushRear(X);
    }
    else
    {
      Node*Traverse=Head;
      for(int i = 0; i<loc-1;i++)
        {
          Traverse= Traverse->Next;
          
        }
      Temp->Next = Traverse;				//adds node to the middle of the list 
  			Temp->Prev = Traverse->Prev;
  			Traverse->Prev->Next = Temp;
  			Traverse->Prev = Temp;
    }
    
    size++;
  }

    /**
     * Public: pushinorder(int X)
     * 
     * Description:
     *      Adds a value to the list in it's place according 
     *      to it's numerical order
     * Params:
     *     Int 
     *     The value being added in 
     * Returns:
     *      void returns nothing 
     */
  void    pushinorder(int X)
  {
    if(!isorder())
    {
      Order();
    }
    if(Head==NULL)
    {
       pushFront(X);
    }
    else
    {
      Node* Traverse= Head;
      if(X<Head->Data)\
      {
        pushFront(X);
      }
      else if (X>Tail->Data)
      {
        pushRear(X);
      }
      else
      {
        int count = 0;
        while(Traverse->Data<=X&&Traverse!=NULL)
          {
            count++;
  					Traverse = Traverse->Next;
          }
        pushAt(count, X);
      };
    }
    size++;
  }
/**
     * Public:popFront
     * 
     * Description:
     *     removes a value from the front of the list 
     *      
     * Params:
     *     Int 
     *     The value being removed 
     * Returns:
     *      void returns nothing 
     */
  int popFront()
  {
    if(Head==NULL)
    {
      cout<< "invalid list is empty";
      return -1;
      
    }
    Node*Temp=Head;
    int Data= Temp->Data;
    Head=Head->Next;
    delete Temp; 
    size--;
    return Data;
  }
/**
     * Public:popRear
     * 
     * Description:
     *     removes a value from the rear of the list list 
     *      
     * Params:
     *     Int 
     *     The value being removed 
     * Returns:
     *      void returns nothing 
     */
  int popRear()
  {
    int Num =Tail->Data;
    Node* Temp = Tail;
    if(Head==NULL)
    {
      cout<< "invalid list is empty";
      return -1;
      
    }
    else
    {
    Tail=Tail->Prev;
    delete Temp;
    Tail->Next=NULL;
    return Num;
    }
  }
/**
     * Public:popAt
     * 
     * Description:
     *     removes a value from a specified location in the
     *      list
     * Params:
     *     Int 
     *     The value being removed 
     * Returns:
     *      void returns nothing 
     */
int popAt(int loc)
{
    int num;
    if(loc<0||loc>size|| Head==NULL)
    {
      cout<<"Invalid location";
      return -1;
    }
    if(loc ==1)
    {
      return popFront();
    }
    if(loc==size)
    {
      return popRear();
    }
  else
    {
      Node*Traverse=Head;
      for(int i = 0; i<loc-1;i++)
        {
          Traverse= Traverse->Next;
          
        }
      num = Traverse->Data;
      Traverse->Prev->Next = Traverse->Next;
      Traverse->Next->Prev = Traverse->Prev;
      delete Traverse;
      return num;
      
    }
}
/**
     * Public:find
     * 
     * Description:
     *     Scowers the list to find a defined value.
     *      list
     * Params:
     *     Int 
     *     The value being searched for
     * Returns:
     *      returns a negative 1 or the value specified and location
     */
int Find(int X)
{
  Node*Traverse=Head;
  for(int i = 0;i<size;i++)
    {
      if(Traverse->Data==X)
      {
        return i;
      }
      Traverse = Traverse->Next;
    }
  
  return -1;
}

friend ofstream& operator<<(ofstream& outfile, const Vector& V);

  


};

int main() {
int x = 0;
ofstream outfile;
 outfile.open("test.out"); 
 outfile << "Ricardo Cesar Rios" << endl;
  outfile << "CMPS 2143 OOP" << endl;
	outfile << "Program 1" << endl;
	outfile << endl; 
Vector v1;
v1.pushFront(18);
v1.pushFront(20);
v1.pushFront(25);
v1.pushRear(18);
v1.pushRear(20);
v1.pushRear(25);
v1.print();
// [25, 20, 18, 18, 20, 25]

int A[] = {11,25,33,47,51};
Vector v2(A,5);
v2.print();
// [11, 25, 33, 47, 51]

v2.pushFront(9);
//v2.inOrderPush(27);
v2.pushRear(63);
v2.print();
// [9, 11, 25, 33, 47, 51, 63]

v1.pushRear(v2);
v1.print();
// [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]

x = v1.popFront();
x = v1.popFront();
x = v1.popFront();
v1.print();
// [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
outfile<<x<<endl;
// 18

x = v1.popRear();
x = v1.popRear();
x = v1.popRear();
v1.print();
// [18, 20, 25, 9, 11, 25, 27, 33]
outfile<<x<<endl;
// 47

x = v2.popAt(3);
v2.print();
// [9, 11, 25, 33, 47, 51, 63]
outfile<<x<<endl;
// 27

x = v2.Find(51);
outfile<<x<<endl;
// 5

x = v2.Find(99);
outfile<<x<<endl;
// -1

Vector v3(v1);
v3.print();
// [18, 20, 25, 9, 11, 25, 27, 33]

v3.pushFront(v2);
v3.print();
//[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

Vector v4("input.dat");
v4.pushRear(v3);
v4.print();
}