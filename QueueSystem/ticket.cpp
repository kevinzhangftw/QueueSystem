// File:        ticket.cpp
// Author:      Geoffrey Tien
// Date:        January 18, 2016
// Description: Implementation of a customer complaint ticket class for CMPT 225 assignment 2

#include "ticket.h"

// default constructor
Ticket::Ticket()
{
    ticketid = 0;
    customername = "Cornelius";
    complaint = "Star Wars Darth Vader waffle maker does not produce accurate waffle likeness of Darth Vader";
}

// parameterized constructor
Ticket::Ticket(unsigned int tid, std::string cname, std::string cplnt)
{
    ticketid = tid;
    if (cname == "")
        customername = "Cornelius";
    else
        customername = cname;
    if (cplnt == "")
        complaint = "Star Wars Darth Vader waffle maker does not produce accurate waffle likeness of Darth Vader";
    else
        complaint = cplnt;
}

// MUTATORS

// ACCESSORS
unsigned int Ticket::GetID() const
{
    return ticketid;
}

std::string Ticket::GetCustomer() const
{
    return customername;
}

std::string Ticket::GetComplaint() const
{
    return complaint;
}

// overloaded operators
// equality returns true if either ticketid matches,
//   or customername and complaint match
bool Ticket::operator==(const Ticket& tick) const
{
    if (ticketid == tick.ticketid || (customername == tick.customername && complaint == tick.complaint) )
        return true;
    else
        return false;
}

bool Ticket::operator!=(const Ticket& tick) const
{
    return !(*this == tick);
}