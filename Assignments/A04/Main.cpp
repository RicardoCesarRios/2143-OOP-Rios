/*****************************************************************************
*                    
*  Author:           Ricardo Cesar Rios 
*  Email:            RicardoCesarRios14@outlook.com
*  Label:            A04
*  Title:            Code Comments and Organization
*  Course:          CMPS 2143
*  Semester:         Fall 2022
* 
*  Description:
*      This program implements a class that allows a linked list to be used just like 
*       
* 
*  Usage:
*       The program is mainly to used as an example file for Basic Code Documentation 
* 
*  Files:           
         main.cpp    : driver program 

*****************************************************************************/




#include <iostream>

using namespace std;
/**
 * CircularArrayQue
 * 
 * Description:
 *      This Class allows for a linked list to be used as an array for the purposes of queueing
 *      items and removing them with the use of the functions pop and push. 
 * 
 * Public Methods:
 *      
 *      void        Push(int item)
 *      int         Pop()
 * 
 * Private Methods:
 * 
 *      void        init(int size = 0)
 *      bool        Full()
 * 
 * Usage: 
 *  
 * CircularArrayQue Name(Int);                      //Creare an instance of CircularArrayQue                  
 *                                                  //Name = The label of this Instance of CircularArrayQue
 *                                                  // Int = the size of this instance of CircularArrayQue
 *      
 */


    
class CircularArrayQue {                   
private:
    int *Container;
    int Front;
    int Rear;
    int QueSize; // items in the queue
    int CurrentSize;
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }
    /**
     * Private : init
     * 
     * Description:
     *      The function determines how many items are in the class
     * 
     * Params:
     *  
     *      Int         : Size intialized as 0         
     * 
     * Returns:
     *    Void            Returns Nothing 
     */


    bool Full() {
        return CurrentSize == QueSize;
    }  
        /**
     * Private: Full
     * 
     * Description:
     *      The function returns a boolean Variable to determine wether the 
     *      linked list is full or not. 
     * 
     * Params:
     *      Bool        :   T or F 
     * 
     * Returns:
     *      - CurrentSize == QueSize : A bool
     */
                                         
public:
    CircularArrayQue() {
        Container = new int[10];  /
        init(10);
    }
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

    
    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }
/**
     * Public : Push
     * 
     * Description:
     *      This function adds an item to the front of the linked list 
     * 
     * Params:
     *      Int     :   Item The Instance that is being added to the list
     * Returns:
     *     Void     Returns Nothing 
     */
    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    /**
     * Public : Pop
     * 
     * Description:
     *      This function removesa an item that is to the front of the linked list 
     * 
     * Params:
     *      Int     :   The instance that is being removed from the linked list
     * 
     * Returns:
     *      temp        Which creates an empty node in the list to replace the removed Instance 
     */
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
    ?#include <iostream>

using namespace std;


class CircularArrayQue {
private:
    int *Container;
    int Front;
    int Rear;
    int QueSize;                            // items in the queue
    int CurrentSize;
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

    bool Full() {
        return CurrentSize == QueSize;
    }

public:
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }

    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}
