#include <fstream>
#include <iostream>
#include <string>

#define INF 1000000000  // infinity

using namespace std;

// Node for our linked list
struct Node {
    int Data;

    Node* Next;

    Node(int x) {
        Data = x;
        Next = NULL;
    }
};

class MyVector {
private:
    Node*           head;  // base pointer of list
    Node*           tail;
    int             size;
    static ofstream fout;
    string          fileName;
    bool            sorted;

    /**
     * @brief Private version of inOrder push. 
     * 
     * @param x 
     */
    void _inorderPush(int x) {
        Node* tempPtr = new Node(x);  // allocate new node
        Node* Prev = head;            // get Previous and Next pointers
        Node* curr = head;

        while (curr->Data > x) {  // loop to find proper location
            Prev = curr;
            curr = curr->Next;
        }

        tempPtr->Next = Prev->Next;  // add new node in its proper position
        Prev->Next = tempPtr;

        size++;  // add to size :)
    }

public:
    /**
     * @brief Default constructor 
     * 
     */
    MyVector() {
        init();
    }

    /**
     * @brief Overloaded Constructor 
     * 
     * @param int   *A - pointer to array 
     * @param int   aSize - size of array
     */
    MyVector(int A[], int aSize) {
        init();

        for (int i = 0; i < aSize; i++) {
            pushRear(A[i]);
        }
    }

    /**
     * @brief Overloaded Constructor 
     * 
     * @param string FileName - file to open and read
     * 
     * Assumes infile will contain numbers only delimited by spaces or 
     * new lines.
     */
    MyVector(string FileName) {
        init();

        ifstream fin;
        int      x = 0;

        fin.open(FileName);
        while (!fin.eof()) {
            fin >> x;
            pushRear(x);
        }
    }

    /**
     * @brief Copy Constructor 
     * 
     * @param MyVector &other 
     */
    MyVector(const MyVector& other) {
        init();

        Node* temp = other.head;

        while (temp) {
            pushRear(temp->Data);
            temp = temp->Next;
        }
    }

    /**
     * @brief - Initialize the Data members so we don't
     *      have duplicate lines in each constructor.
     * 
     */
    void init() {
        head = tail = NULL;
        fileName = "";
        size = 0;
        sorted = 0;
    }


    /**
     * @brief Public version of inOrder push.
     * 
     * @param x 
     */
    void inorderPush(int x) {
        if (!sorted) {
            sortList();
        }

        if (!head) {
            pushFront(x);  // call push front for empty list (or pushRear would work)
        } else if (x < head->Data) {
            pushFront(x);  // call push front if x is less than head
        } else if (x > tail->Data) {
            pushRear(x);  // call push rear if x > tail
        } else {
            _inorderPush(x);  // call private version of push in order
        }
    }

    /**
     * @brief Sort the current values in the linked list.
     * 
     * @returns None
     */
    void sortList() {
        Node* newFront = head;
        while (newFront->Next) {
            Node* smallest = newFront;
            Node* current = newFront;
            int   minimum = INF;
            while (current) {
                if (current->Data < minimum) {
                    smallest = current;
                    minimum = current->Data;
                }
                current = current->Next;
            }
            smallest->Data = newFront->Data;
            newFront->Data = minimum;
            newFront = newFront->Next;
        }
        sorted = true;
    }

    /**
     * @brief Add value to front of list.
     * 
     * @param x 
     */
    void pushFront(int x) {
        Node* tempPtr = new Node(x);

        // empty list make head and tail
        // point to new value
        if (!head) {
            head = tail = tempPtr;
            // otherwise adjust head pointer
        } else {
            tempPtr->Next = head;
            head = tempPtr;
        }
        size++;
    }

    /**
     * @brief This method loads values from 'other' list in 'this' list.
     *          It loads an array first so we can process the values in
     *          reverse so they end up on 'this' list in the proper order.
     *          If we didn't use the array, we would reverse the values
     *          from the 'other' list.
     * 
     * @depends - Uses `pushFront(int)`
     * @param MyVector& other 
     * @return None
     */
    void pushFront(const MyVector& other) {
        Node* otherPtr = other.head;           // get copy of other lists head
        int*  tempData = new int[other.size];  // allocate memory to hold values

        // load other list into array
        int i = 0;
        while (otherPtr) {
            tempData[i] = otherPtr->Data;
            otherPtr = otherPtr->Next;
            ++i;
        }

        // process list in reverse in order to keep them
        // in their original order.
        for (int i = other.size - 1; i >= 0; i--) {
            pushFront(tempData[i]);
        }
    }

    /**
     * @brief -  Add 'other' list's values to end of 'this' list.
     * @note - Uses `pushRear(int)`
     * @param MyVector& other 
     * @return None
     */
    void pushRear(const MyVector& other) {
        Node* otherPtr = other.head;  // get copy of other lists head

        while (otherPtr) {  // traverse and add
            pushRear(otherPtr->Data);
            otherPtr = otherPtr->Next;
        }
    }

    /**
     * @brief Push value onto list at soecified position, if it exists.
     * 
     * @param int i - location index 
     * @param inr x - value to add 
     * @return bool - true add successful / false add failed 
     */
    bool pushAt(int i, int x) {
        if(i >= size){
            return false;
        }
        
        Node* tempPtr = new Node(x);  // allocate new node
        Node* Prev = head;            // get Previous and Next pointers
        Node* curr = head;

        while (i>0) {  // loop to find proper location
            Prev = curr;
            curr = curr->Next;
            i--;
        }

        tempPtr->Next = Prev->Next;  // add new node in its proper position
        Prev->Next = tempPtr;

        size++;  // add to size :)
        return true;
    }

    /**
     * @brief - Add value to rear of list
     * 
     * @param int x - value to be added 
     * @return None
     */
    void pushRear(int x) {
        Node* tempPtr = new Node(x);

        if (!head) {
            head = tail = tempPtr;

        } else {
            tail->Next = tempPtr;
            tail = tempPtr;
        }
        size++;  // add to size of list
    }
//------------------------------------------------------------------------------
      /**
     * @brief - Overloading the << operator to print the list to console
     * 
     * @param  MyVector& V 
     * @return os
     */

    friend ostream& operator<<(ostream& os, const MyVector& V) {
        Node* temp = V.head;  // temp pointer copies head

        while (temp) {  // this loops until temp is NULL
                        // same as `while(temp != NULL)`

            os << temp->Data;  // print Data from Node
            if (temp->Next) {
                os << "->";
            }
            temp = temp->Next;  // move to Next Node
        }
        os << endl;
        return os;
    }
//------------------------------------------------------------------------------
       /**
     * @brief - Overloading the << operator to print the list to a file
     * 
     * @param  MyVector& V 
     * @return outfile
     */
     friend ofstream& operator<<(ofstream& outfile, const MyVector& V) {
        Node* temp = V.head;  // temp pointer copies head

        while (temp) {  // this loops until temp is NULL
                        // same as `while(temp != NULL)`

            outfile << temp->Data;  // print Data from Node
            if (temp->Next) {
                outfile << "->";
            }
            temp = temp->Next;  // move to Next Node
        }
        outfile << endl;
        return outfile;
    }
//------------------------------------------------------------------------------
     /**
     * @brief - Overloading the << operator to print the list to console
     * 
     * @param  MyVector &v
     * @return os
     */
    friend ostream & operator<<(ostream &os, MyVector &v)
        {
        Node* Prev = v.head;            
        Node* Next = v.head;
          while (Next->Next != NULL) 
          {  
            Prev = Next;
            Next = Next->Next;
            os << Prev->Data << " "; 
          }
          os << Next->Data;
          return os;
        }
//------------------------------------------------------------------------------
     /**
     * @brief - Overloading the << operator to print the list to console
     * 
     * @param  MyVector &v
     * @return os
     */
    friend ofstream & operator<<(ofstream &outfile, MyVector &v)
        {
        Node* Prev = v.head;            
        Node* Next = v.head;
          while (Next->Next != NULL) 
          {  
            Prev = Next;
            Next = Next->Next;
            outfile << Prev->Data << " "; 
          }
          outfile << Next->Data;
          return outfile;
        }
//------------------------------------------------------------------------------
      //friend ostream & operator<<(ostream &os, MyVector &v)
//------------------------------------------------------------------------------
       /**
     * @brief - Overloading the << [] so that MyVector may be treated as an array
     * 
     * @param  int index
     * @return Traverse->Data;  value at index 
     *///might not work                                             REVISIT
    int& operator[](int index) 
      {
    		MyVector V;
    		Node* Traverse = head;
    		
    		if (index > size) {
    			cout << "invalid location"; //determining wether search query is valid 
    			int X = 0; 
    			return X;
    		}
    		else {
    			
    			for (int i = 0; i != index; i++) {
    				Traverse = Traverse->Next; //loop to traverse the vector to index
    			}
    			return Traverse->Data; //returning value at index 
    		}
    	}
//------------------------------------------------------------------------------
/**
     * @brief - Overloading the + operator to add two vector objects together 
     * 
     * @param  MyVector &v
     * @return v
     */
  MyVector operator+(MyVector &V) 
{
  MyVector Vector; 
  Node*Traverse = head; 
  Node*Prev = head;
  
  Node* TraverseV = V.head;
   Node* PrevV = V.head;

  while (Traverse != NULL)
        {    
            
          if(Traverse != NULL && TraverseV != NULL)
            {
              Vector.pushRear(Traverse->Data + TraverseV->Data);
              
              Prev = Traverse;
              Traverse = Traverse->Next;

              PrevV = TraverseV;
              TraverseV = TraverseV->Next;
            }
          else if(Traverse != NULL)
            {
              Vector.pushRear(Traverse->Data);

              Prev = Traverse;
              Traverse = Traverse->Next;
            }
          else if(TraverseV != NULL)
            {
              Vector.pushRear(TraverseV->Data);

              PrevV = TraverseV;
              TraverseV = TraverseV->Next;
            }          
        }
    
if(Traverse != NULL)
        {
            Vector.pushRear(Traverse->Data);
        }
        else if(TraverseV != NULL)
        {
            Vector.pushRear(TraverseV->Data);
        }
  return V;
}
//------------------------------------------------------------------------------
/**
     * @brief - Overloading the - operator to subtract two vector objects 
     * 
     * @param  MyVector &v
     * @return v
     */
  MyVector operator-(MyVector &V) 
{
  MyVector Vector; 
  Node*Traverse = head; 
  Node*Prev = head;
  
  Node* TraverseV = V.head;
   Node* PrevV = V.head;

  while (Traverse != NULL)
        {    
            
          if(Traverse != NULL && TraverseV != NULL)
            {
              Vector.pushRear(Traverse->Data - TraverseV->Data);
              
              Prev = Traverse;
              Traverse = Traverse->Next;

              PrevV = TraverseV;
              TraverseV = TraverseV->Next;
            }
          else if(Traverse != NULL)
            {
              Vector.pushRear(Traverse->Data);

              Prev = Traverse;
              Traverse = Traverse->Next;
            }
          else if(TraverseV != NULL)
            {
              Vector.pushRear(TraverseV->Data);

              PrevV = TraverseV;
              TraverseV = TraverseV->Next;
            }          
        }
    
if(Traverse != NULL)
        {
            Vector.pushRear(Traverse->Data);
        }
        else if(TraverseV != NULL)
        {
            Vector.pushRear(TraverseV->Data);
        }
  return V;
}
//------------------------------------------------------------------------------
/**
     * @brief - Overloading the * operator to multiply two vector objects 
     * 
     * @param  MyVector &v
     * @return v
     */
MyVector operator*(MyVector &V) 
{
  MyVector Vector; 
  Node*Traverse = head; 
  Node*Prev = head;
  
  Node* TraverseV = V.head;
   Node* PrevV = V.head;

  while (Traverse != NULL)
        {    
            
          if(Traverse != NULL && TraverseV != NULL)
            {
              Vector.pushRear(Traverse->Data * TraverseV->Data);
              
              Prev = Traverse;
              Traverse = Traverse->Next;

              PrevV = TraverseV;
              TraverseV = TraverseV->Next;
            }
          else if(Traverse != NULL)
            {
              Vector.pushRear(Traverse->Data);

              Prev = Traverse;
              Traverse = Traverse->Next;
            }
          else if(TraverseV != NULL)
            {
              Vector.pushRear(TraverseV->Data);

              PrevV = TraverseV;
              TraverseV = TraverseV->Next;
            }          
        }
    
if(Traverse != NULL)
        {
            Vector.pushRear(Traverse->Data);
        }
        else if(TraverseV != NULL)
        {
            Vector.pushRear(TraverseV->Data);
        }
  return V;
}
//------------------------------------------------------------------------------
/**
     * @brief - Overloading the / operator to divide two vector objects 
     * 
     * @param  MyVector &v
     * @return v
     */
MyVector operator/(MyVector &V) 
{
  MyVector Vector; 
  Node*Traverse = head; 
  Node*Prev = head;
  
  Node* TraverseV = V.head;
   Node* PrevV = V.head;

  while (Traverse != NULL)
        {    
            
          if(Traverse != NULL && TraverseV != NULL)
            {
              Vector.pushRear(Traverse->Data / TraverseV->Data);
              
              Prev = Traverse;
              Traverse = Traverse->Next;

              PrevV = TraverseV;
              TraverseV = TraverseV->Next;
            }
          else if(Traverse != NULL)
            {
              Vector.pushRear(Traverse->Data);

              Prev = Traverse;
              Traverse = Traverse->Next;
            }
          else if(TraverseV != NULL)
            {
              Vector.pushRear(TraverseV->Data);

              PrevV = TraverseV;
              TraverseV = TraverseV->Next;
            }          
        }
    
if(Traverse != NULL)
        {
            Vector.pushRear(Traverse->Data);
        }
        else if(TraverseV != NULL)
        {
            Vector.pushRear(TraverseV->Data);
        }
  return V;
}
//------------------------------------------------------------------------------
/**
     * @brief - Overloading the = operator to assign the values of a vector 
     * to another
     * @param  MyVector &v
     * @return *this
     */
MyVector& operator=(const MyVector& V) 
  {
      MyVector V1;
			Node* Traverse = V.head;
			while (Traverse !=NULL) 
        {
  				V1.pushRear(Traverse->Data);
  				Traverse = Traverse->Next;
        }
			this->head = V1.head;
			this->tail = V1.tail;
      return *this;
		
	}

//------------------------------------------------------------------------------
/**
     * @brief - Overloading the = operator to determine whether the values 
     * of two vectors are equvilent
     * @param  MyVector &v
     * @return bool
     */
bool operator==(const MyVector V)
    {
        Node* Traverse = head;
        Node* prev = head;

        Node* Traverse_V = V.head;
        Node* prev_V = V.head;

        while((Traverse_V->Data == Traverse->Data) && Traverse->Next != NULL)
        {
            if(Traverse_V->Data == Traverse->Data)
            {
                prev = Traverse;
                Traverse = Traverse->Next;

                prev_V = Traverse_V;
                Traverse_V = Traverse_V->Next;
            }
        }
        if(Traverse_V->Data != Traverse->Data)
        {
            return false;
        }
        else
        {
            return true;
        }
    }









//------------------------------------------------------------------------------
    /**
     * @brief Destroy the My Vector object
     * 
     */
    ~MyVector() {
        Node* curr = head;
        Node* Prev = head;

        while(curr){
            Prev = curr;
            curr = curr->Next;
            cout << "deleting: " << Prev->Data << endl;
            delete Prev;
        }
    }



};

//ofstream MyVector::fout;

int main() {
int a1[] = { 1, 2, 3, 4, 5 };
int a2[] = { 10, 20, 30 };

MyVector v1(a1,5);
MyVector v2(a2,3);

ofstream fout;
fout.open("output.txt");
fout << "Ricardo Cesar Rios\n"<<"2143 OPP\n"<<"Program 2\n";
fout << v1[2] << endl;
// writes out 3

v1[4] = 9;
// v1 now = [1,2,3,4,9]

fout << v1 << endl;
// writes out [1,2,3,4,9] to console.

fout << v1 << endl;
// writes out [1,2,3,4,9] to your output file.

MyVector v3 = v1 + v2;
fout << v3 << endl;
// writes out [11,22,33,4,9] to console.

v3 = v1 - v2;
fout << v3 << endl;
// writes out [-9,-18,-27,4,9] to console.

v3 = v2 - v1;
fout << v3 << endl;
// writes out [9,18,27,4,9] to console.

v3 = v2 * v1;
fout << v3 << endl;
// writes out [10,40,90,4,9] to console.

v3 = v1 * v2;
fout << v3 << endl;
// writes out [10,40,90,4,9] to console.

v3 = v1 / v2;
fout << v3 << endl;
// writes out [0,0,0,4,9] to console.

v3 = v2 / v1;
fout << v3 << endl;
// writes out [10,10,10,4,9] to console.

fout << (v2 == v1) << endl;
// writes 0 to console (false) .

MyVector v4 = v1;
fout << (v4 == v1) << endl;
// writes 1 to console (true) .
  }
