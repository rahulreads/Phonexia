#ifndef MYPLAN_H
#define MYPLAN_H

#include "myPlanData.h"

using namespace std;
namespace phonexia{
class myPlan
{
    public:
        myPlan();
        virtual ~myPlan();
        myPlan(const myPlan& other);
        myPlan& operator=(const myPlan& other);

        // Set Methods
        void setBaseBill(float bill);
        void setFreeMinutes(float bill);
        void setFreeMessages(int freeMessages);
        void setMyCharges(myCircle circle,float callPerMin, float callPerSec,float message);
        void setMyNumbers(string number);

        // Get Methods
        float getBaseBill();
        float getFreeMinutes();
        int getFreeMessages();
        charges getMyChagrges();
        bool isMyNumbers(string number);

    protected:

    private:

        float baseBill;
        float freeMinutes;
        uint16_t freeMessages;
        charges myCharges;
        numbers myNumbers;

};

}

#endif // MYPLAN_H

