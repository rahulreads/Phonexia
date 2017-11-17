#include "myBill.h"

myBill::myBill()
{
    //ctor
}

myBill::~myBill()
{
    //dtor
}

myBill::myBill(const myBill& other)
{
    //copy ctor
}

myBill& myBill::operator=(const myBill& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
