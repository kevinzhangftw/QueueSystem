//
//  dlinkedlist.cpp
//  QueueSystem
//
//  Created by Kai Zhang on 2016-01-25.
//  Copyright © 2016 Kai Zhang. All rights reserved.
//

//#include "dlinkedlist.h"
// helper function for deep copy
// Used by copy constructor and operator=
template <class T>
void DLinkedList<T>::CopyList(const DLinkedList& ll){
    size = 0;
    if (ll.size == 0) {
        front = NULL;
        back = NULL;
        return;
    }
    for (int i = 0; i < ll.size; i++) {
        InsertBack(ll.ElementAt(i));

    }
}

// helper function for deep delete
// Used by destructor and copy/assignment
template <class T>
void DLinkedList<T>::DeleteList(){
//    Node<T> temp = *front;
//    while (temp != NULL) {
//        temp = front->next;
//        delete front;
//        front = temp;
//    }
}

// default constructor


template <class T>
DLinkedList<T>::DLinkedList(){
    size = 0;
    front =  NULL;
    back = NULL;
}

// copy constructor, performs deep copy of list elements
template <class T>
DLinkedList<T>::DLinkedList(const DLinkedList& ll){
    CopyList(ll);
}

// destructor
template <class T>
DLinkedList<T>::~DLinkedList(){
    DeleteList();
}

// MUTATORS

// Inserts an item at the front of the list
// POST:  List contains item at position 0
// PARAM: item = item to be inserted
template <class T>
void DLinkedList<T>::InsertFront(T item){
    Node<T> *newnode = new Node<T> (item);
    if (front != NULL) { //HAX
        front->prev = newnode;
    }
    newnode->next = front;
    front = newnode;
    size++;
    if (size == 1) { //HAX
        back = front;
    }
}
template <class T>
void DLinkedList<T>::InsertBack(T item){
    Node<T> *newnode = new Node<T> (item);
    if (back != NULL) { //HAX
        back->next = newnode;
    }
    newnode->prev = back;
    back = newnode;
    size++;
    if (size == 1) { //HAX
        front = back;
    }
}

// Inserts an item in position p (0-indexed)
// Throws exception for invalid index
// PRE:   0 <= p <= size
// POST:  List contains item at position p
// PARAM: item = item to be inserted, p = position where item will be inserted
template <class T>
void DLinkedList<T>::InsertAt(T item, int p){
    //traverse the list till position p
    Node<T> *tempNode = front;
    for (int i = 0; i < p; i++) {
        tempNode = tempNode->next;
    }
    //splice before tempnode
    if (tempNode == front) {
        InsertFront(item);
        return;
    }
    else if (tempNode == NULL) {
        InsertBack(item);
        return;
    }
    Node<T> *newNode = new Node<T>(item);
    //UNHAX PLZ
    newNode->prev = tempNode->prev;
    newNode->prev->next = newNode;
    newNode->next = tempNode;
    tempNode->prev = newNode;
    size++;
    return;
    
}

// Removes and returns an item from position p (0-indexed)
// Throws exception if list is empty or index invalid
// PRE:   0 <= p < size
// POST:  Item is removed from list
// PARAM: p = position from where item will be removed
template <class T>
T DLinkedList<T>::RemoveAt(int p){
    T posp;
    Node<T> *tempNode = front;
    if (p >= size) {
        throw std::out_of_range("OUT OF BOUNDS");
    }
    for (int i = 0; i < p; i++) {
        tempNode = tempNode->next;
    }
    //invariant: tempNode has a value and is within range.
    
    posp = tempNode->data;
    if (tempNode->next == NULL && tempNode->prev == NULL) {
        front = NULL;
        back = NULL;
    }
    if (tempNode == front) {
        front = tempNode->next;
        tempNode->next->prev = NULL;
    } else if (tempNode == back) {
        back = tempNode->prev;
        tempNode->prev->next = NULL;
    } else {
        tempNode->prev->next = tempNode->next;
        tempNode->next->prev = tempNode->prev;
    }
    delete tempNode;
    size--;
    return posp;
}

// The first occurrence of any duplicate (relative to the front of the list)
//   is the one which remains.
// We have not yet learned about efficiency so you may implement this in any way
//   as long as the resulting list satisfies the requirement above.
// PRE:
// POST:  List contains no duplicates, front and back point to the appropriate nodes
// PARAM:
template <class T>
void DLinkedList<T>::RemoveDuplicates(){
    //TODO:
    //preserve existing order
    //keep the first one
    T uniqueOccurance;
    //iterate...
    for (int i = 0; i < size; i++) {
        if (uniqueOccurance == ElementAt(i)) {
            //the last element is the same as this one.
            //keep last one, remove this one.
            RemoveAt(i);
            //if removed, unique occurance does not get reassigned. check for the next one, without incrementing i...
            i--; //HAX
            continue;
        }
        uniqueOccurance = ElementAt(i);
        
    }
    
    
}

// ACCESSORS

// Returns size of list
template <class T>
int DLinkedList<T>::Size() const{
    return size;
}

// Returns whether the list is empty
template <class T>
bool DLinkedList<T>::IsEmpty() const{
    if (size==0) {
        return true;
    }else{
        return false;
    }
    
}

// Returns existence of item
template <class T>
bool DLinkedList<T>::Contains(T item) const{
    for (int i = 0; i < size; i++) {
        if (ElementAt(i) == item) {
            return true;
        }
    }
    return false;
}

// Returns item at index (0-indexed)
// Throws exception for invalid index
template <class T>
T DLinkedList<T>::ElementAt(int p) const{
    //TODO: verify later with larger number of elements in the list...
    Node<T> movingFront = *front;
    for (int i=0; i<p; ++i) {
        if (movingFront.next) {
            movingFront = *movingFront.next;
        }
        
    }
    return movingFront.data;
}


template <class T>
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList& ll){
    bool same = true;
    Node<T> *tempLeft = front;
    Node<T> *tempRight = ll.front;
    if (size != ll.size) {
        same = false;
    } else {
        for (int i = 0; i < size; i++) {
            if (tempLeft != tempRight) {
                same = false;
                break;
            }
            tempLeft = tempLeft->next;
            tempRight = tempRight->next;
            //TODO: verify with boundary conditions...
        }
    }
    if (!same) {
        CopyList(ll);
    }
    return *this;
}