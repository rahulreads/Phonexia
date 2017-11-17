#ifndef MYPLANDATA_H_INCLUDED
#define MYPLANDATA_H_INCLUDED

#include<map>
#include<vector>
using namespace std;

namespace phonexia{

typedef struct call
{
    float perMin;
    float perSec;
}callCharge;

typedef struct planCharges{
    callCharge myCallCharge;
    float myMessageCharge;
} myPlanCharges;

typedef enum e{
    IN_CIRCLE=1,
    OUT_CIRCLE=2,
} myCircle;

typedef map<myCircle,myPlanCharges> charges;
typedef vector<string> numbers;

}
#endif // MYPLANDATA_H_INCLUDED
