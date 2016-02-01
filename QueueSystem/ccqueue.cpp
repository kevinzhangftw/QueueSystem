//
//  ccqueue.cpp
//  QueueSystem
//
//  Created by Kai Zhang on 2016-01-25.
//  Copyright © 2016 Kai Zhang. All rights reserved.
//
#include "ccqueue.h"


//template <class Ticket>
CCQueue::CCQueue(){
  //TODO: make linked list.
    tickets = DLinkedList<Ticket>();
    
}

// MUTATORS

// enqueues a new ticket at the back of the ticket queue

// ticketid is assigned automatically as 1+maxticketid if enqueueing is possible
// does not enqueue
// POST:  new ticket with supplied parameters is added to back of tickets,
//        maxticketid is incremented
// PARAM: customer and complaint fields to pass to Ticket constructor
//template <class Ticket>
bool CCQueue::Add(string customer, string complaint){
    if (customer == "" ||
        complaint == "" ) {
        return false;
    }
    //TODO: instantiate ticket, then add to end of list.
    Ticket stupidTicket = Ticket(maxticketid++, customer, complaint);
    tickets.InsertBack(stupidTicket);
    
    return true;
}

// removes and returns an item from the front of the ticket queue
// throws a logic_error if the ticket queue is empty
// POST:  first item of the ticket queue is removed
//template <class Ticket>
Ticket CCQueue::Service(){
    return tickets.RemoveAt(0);
}

bool CCQueue::MoveUp(int index){
    if (index <= 0 ||
        index >= Size()) {
        return false;
    }
    Ticket tempTicket = tickets.RemoveAt(index);
    tickets.InsertAt(tempTicket, index-1);
    return true;
}

// moves an item towards the back of the queue by 1 position and returns true
// returns false if supplied index is the last item or outside the list boundaries
// POST:  DLinkedList items at position and position+1 swap spots in the list
// PARAM: initial index of item to move down
//template <class Ticket>
bool CCQueue::MoveDown(int index){
    if (index >= Size()-1 ||
        index < 0) {
        return false;
    }
    Ticket dumbTicket = tickets.RemoveAt(index);
    tickets.InsertAt(dumbTicket, index+1);
    return true;
}

// ACCESSORS

// returns the number of tickets
//template <class Ticket>
int CCQueue::Size() const{
    return tickets.Size();
}
