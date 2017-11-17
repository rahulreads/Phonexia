#ifndef MYUSAGE_H
#define MYUSAGE_H

#include <algorithm>
#include "myUsageData.h"

using namespace std;

namespace phonexia{

class myUsage
{
    public:
        myUsage();
        virtual ~myUsage();
        myUsage(const myUsage& other);
        myUsage& operator=(const myUsage& other);

        // Set Method;
        void setMyCallCharges(usageCircle myCircle);
        void setMyCallCharges(usageCircle myCircle,float mins);
        void readMyUsageData(string dataFile);

        // Get Method;
        void getMyCallCharges();

    protected:

    private:
      usageCharges myCharges;

};

}
#endif // MYUSAGE_H
