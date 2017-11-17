#include "myPlan.h"
#include <algorithm>


using namespace std;

namespace phonexia {
myPlan::myPlan()
{
    //ctor
}

myPlan::~myPlan()
{
    //dtor
}

myPlan::myPlan(const myPlan& other)
{
    //copy ctor
}

myPlan& myPlan::operator=(const myPlan& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

// Set Methods
void myPlan::setBaseBill(float bill)
{
    baseBill = bill;
}

void myPlan::setFreeMinutes(float mins)
{
    freeMinutes = mins;
}
void myPlan::setFreeMessages(int freeMsg)
{
    freeMessages = freeMsg;
}

void myPlan::setMyCharges(myCircle circle,float callPerMin, float callPerSec,float message)
{
    myPlanCharges myPlanChrg;

    myPlanChrg.myCallCharge.perMin = callPerMin;
    myPlanChrg.myCallCharge.perSec = callPerSec;
    myPlanChrg.myMessageCharge = message;

    myCharges.insert(make_pair(circle,myPlanChrg));

}

void myPlan::setMyNumbers(string number)
{
    myNumbers.push_back(number);
}

// Get Methods
float myPlan::getBaseBill()
{
    return baseBill;
}

float myPlan::getFreeMinutes()
{
    return freeMinutes;
}

int myPlan::getFreeMessages()
{
    return freeMessages;
}

charges myPlan::getMyChagrges()
{
    return myCharges;
}

bool myPlan::isMyNumbers(string number)
{
    vector<string>::iterator it = find(myNumbers.begin(),myNumbers.end(),number);
    if(it != myNumbers.end())
        return true;

    return false;
}

}
