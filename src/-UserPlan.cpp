#include "-UserPlan.h"

-UserPlan::-UserPlan()
{
    //ctor
}

-UserPlan::~-UserPlan()
{
    //dtor
}

-UserPlan::-UserPlan(const -UserPlan& other)
{
    //copy ctor
}

-UserPlan& -UserPlan::operator=(const -UserPlan& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
