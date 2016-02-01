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
  //imp here
}

// helper function for deep delete
// Used by destructor and copy/assignment
template <class T>
void DLinkedList<T>::DeleteList(){
  //imp here
}

// default constructor


template <class T>
DLinkedList<T>::DLinkedList(){
    //
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
    //imp here
}

// Inserts an item at the back of the list
// POST:  List contains item at back
// PARAM: item = item to be inserted
template <class T>
void DLinkedList<T>::InsertBack(T item){
    //imp here
}

// Inserts an item in position p (0-indexed)
// Throws exception for invalid index
// PRE:   0 <= p <= size
// POST:  List contains item at position p
// PARAM: item = item to be inserted, p = position where item will be inserted
template <class T>
void DLinkedList<T>::InsertAt(T item, int p){
    //imp here
}

// Removes and returns an item from position p (0-indexed)
// Throws exception if list is empty or index invalid
// PRE:   0 <= p < size
// POST:  Item is removed from list
// PARAM: p = position from where item will be removed
template <class T>
T DLinkedList<T>::RemoveAt(int p){
    T posp;
    //imp here
    return posp;
}

// Removes duplicates from the list, preserving existing order of remaining items.
// The first occurrence of any duplicate (relative to the front of the list)
//   is the one which remains.
// We have not yet learned about efficiency so you may implement this in any way
//   as long as the resulting list satisfies the requirement above.
// PRE:
// POST:  List contains no duplicates, front and back point to the appropriate nodes
// PARAM:
template <class T>
void DLinkedList<T>::RemoveDuplicates(){
    //imp here
}

// ACCESSORS

// Returns size of list
template <class T>
int DLinkedList<T>::Size() const{
    //imp here
    return 0;
}

// Returns whether the list is empty
template <class T>
bool DLinkedList<T>::IsEmpty() const{
    //imp here
    return false;
}

// Returns existence of item
template <class T>
bool DLinkedList<T>::Contains(T item) const{
    //imp here
    return false;
}

// Returns item at index (0-indexed)
// Throws exception for invalid index
template <class T>
T DLinkedList<T>::ElementAt(int p) const{
    T pos0;
    //imp here
    return pos0;
}

// OVERLOADED OPERATORS

// overloaded assignment operator
// must work in the following cases:
// list2 = list1 -> general case
// list2 = list2 -> should do nothing
template <class T>
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList& ll){
    return *this;
}