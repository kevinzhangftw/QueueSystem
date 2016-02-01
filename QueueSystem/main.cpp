
// File:        a1simpledriver.cpp
// Author:      (your name here) / Geoffrey Tien
// Date:        January 19, 2016
// Description: Basic test driver for CMPT 225 assignment #2
//              This file tests some functions of the CCQueue and DLinkedList classes of assignment #2.
//              Note that only functions which are called will be compiled, therefore you must
//                ensure that every function in your classes is called at least once.
//              Not all special cases have been tested; you will be responsible for adding
//                your own test code and function calls to this file in order to thoroughly
//                test all general and boundary cases for your functions.
//              In general, please ensure that you test:
//               1. invalid parameter(s)
//               2. valid parameter(s), boundary case
//               3. valid parameter(s), general case

#include <iostream>
#include "dlinkedlist.h"
#include "ccqueue.h"

using namespace std;

// forward function declarations
void LLTest();
void CCQTest();

// program entry point
int main()
{
    cout << "Entering DLinkedList test function... " << endl;
    CCQTest();
    return 0;
}

void printAll(Node<int> *frontNode) {
    if (frontNode == NULL) {
        cout << "Empty List!" << endl;
        return;
    }
    Node<int> *tempNode = frontNode;
    cout << tempNode->data << " - ";
    while (tempNode->next != NULL) {
        tempNode = tempNode->next;
        cout << tempNode->data << " - ";
    }
    cout << endl;
    
}

void LLTest()
{
    
    DLinkedList<int> lla; //we think this works, for now.
    
    lla.InsertFront(111);
    lla.InsertFront(222);
    lla.InsertBack(333);
    lla.InsertBack(444);
    lla.InsertBack(555);
    lla.InsertBack(666);
    lla.InsertBack(777);
    
    DLinkedList<int> llb(lla);
    
    
    llb.InsertAt(7, 1);
    
    int firstitempopped = llb.RemoveAt(1);
    cout << "first item popped is "<< firstitempopped<< endl;
    int seconditemPopped = llb.RemoveAt(2);
    cout << "second item popped is "<< seconditemPopped<< endl;
    
    try{
        int temp = llb.RemoveAt(12345);
    } catch (exception e) {
        cout << "Exception in RemoveAt(): " << e.what() << endl;
    }
    
    if (llb.IsEmpty()) {
        cout << "llb is empty." << endl;
    } else {
        cout << "llb is not empty." << endl;
    }
    // assignment operator, IsEmpty, Size, RemoveDuplicates, Contains
    DLinkedList<int> llc;
    
    if (llc.IsEmpty()){
        cout << "llc is empty." << endl;
    } else{
        cout << "llc is not empty." << endl;
    }
    llc = lla;
    llc.InsertBack(1313);
    llc.InsertBack(1313);
    llc.InsertBack(1313);
    llc.InsertBack(1313);
    llc.InsertBack(1313);
    llc.InsertBack(5454);
    llc.InsertBack(5454);
    llc.InsertBack(5454);
    llc.InsertBack(13);
    llc.InsertBack(10);

    cout << "llc contains " << llc.Size() << " items." << endl;
    llc.RemoveDuplicates();

}

void CCQTest()
{
    CCQueue ccq;
    ccq.Add("Alrikr", "Video card smoked");
    ccq.Add("Bjornstjerne", "Received wrong colour cable");
    ccq.Add("Cyprianus", "Motherboard DOA");
    ccq.Add("Dietrich", "Order not received");
    ccq.Add("Elisaeus", "Only 931GB on 1TB hard drive");
    cout << "Size of ticket queue: " << ccq.Size() << endl;
    ccq.Service();
    cout << "Size of ticket queue: " << ccq.Size() << endl;
    ccq.MoveUp(3);
    ccq.MoveUp(2);
    cout << ccq.PrintStatus() << endl;
    ccq.MoveDown(2);
    cout << ccq.PrintStatus() << endl;
}