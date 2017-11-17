#ifndef MYUSAGEDATA_H_INCLUDED
#define MYUSAGEDATA_H_INCLUDED

#include<map>

using namespace std;

namespace phonexia{

typedef struct usageVolume{
    float callVolume;
    int messageVolume;
} myUsageCharges;

typedef enum e2{
    IN=1,
    OUT=2,
} usageCircle;

typedef map<usageCircle,myUsageCharges> usageCharges;
typedef map<usageCircle,myUsageCharges>::iterator usageItr;


}

#endif // MYUSAGEDATA_H_INCLUDED
