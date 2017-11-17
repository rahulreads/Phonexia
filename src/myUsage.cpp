#include "myUsage.h"
#include <algorithm>
#include <iostream>
#include <fstream>

namespace phonexia{
myUsage::myUsage()
{
    //ctor
}

myUsage::~myUsage()
{
    //dtor
}

myUsage::myUsage(const myUsage& other)
{
    //copy ctor
}

myUsage& myUsage::operator=(const myUsage& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

// Set Method;
void myUsage::setMyCallCharges(usageCircle myCircle)
{

    map<usageCircle,myUsageCharges>::iterator it = myCharges.find(myCircle);

    if ( it != myCharges.end() )
    {
        it->second.messageVolume += 1;
        //cout<<"Inserting sms through "<<myCircle<<endl;
    }
    else
    {
        //cout<<"New entry of sms through"<<myCircle<<endl;
        myUsageCharges newEntry;
        newEntry.callVolume = 0;
        newEntry.messageVolume = 1;
        myCharges.insert(make_pair(myCircle,newEntry));
    }
}

void myUsage::setMyCallCharges(usageCircle myCircle,float mins)
{
    map<usageCircle,myUsageCharges>::iterator it = myCharges.find(myCircle);
    float f;

    if ( it != myCharges.end() )
    {
        it->second.callVolume += mins;
        //cout<<"inserting Mins through"<<myCircle<<"usage till now is "<<it->second.callVolume<<endl;
        f=it->second.callVolume-(long)it->second.callVolume;
        if(f>0.60)
        {
            //cout<<"Adjusting seconds from"<<it->second.callVolume<<"to";
            it->second.callVolume -= f;
            it->second.callVolume += 1;
            f -=0.60;
            it->second.callVolume += f;
            //cout<<it->second.callVolume<<endl;
        }
    }
    else
    {
        //cout<<"New entry of mins through"<<myCircle<<endl;
        myUsageCharges newEntry;
        newEntry.callVolume = mins;
        newEntry.messageVolume = 0;
        myCharges.insert(make_pair(myCircle,newEntry));
    }
}

void myUsage::readMyUsageData(string dataFile)
{
    int mins,sec,dur;
    float total;
    string temp,number,duration,type;

    usageCircle circle = IN;
    ifstream myDataFile(dataFile.c_str());

    if(myDataFile.good())
    {
        getline(myDataFile,temp);
        temp.clear();

        while(myDataFile.good())
        {
            getline(myDataFile,temp,';');
            getline(myDataFile,number,';');
            getline(myDataFile,duration,';');
            getline(myDataFile,type,'\n');

            //check if this is a call entry;
            if(!duration.empty())
            {
                dur=std::stoi(duration);

                if(dur > 60 && dur != 0 )
                {
                    mins=dur/60;
                    sec=(dur-(mins*60));
                    total = (float)mins+sec*0.01;
                }
                else
                {
                    total = 1;
                }

                if(type.compare("VM")==0)
                {
                    circle = OUT;
                }
                else
                {
                    circle = IN;
                }

                //set the call usage
                setMyCallCharges(circle,total);
            }
            else
            {
                // then this is an sms entry
                if(type.compare("SM")==0)
                {
                    circle = OUT;
                }
                else
                {
                    circle = IN;
                }
                setMyCallCharges(circle);
            }

            //set the sms usage


            //cout<<number.c_str()<<"  "<<duration.c_str()<<"  "<<type.c_str()<< "##"<<endl;
        }
    }

}

// Get Method;
void myUsage::getMyCallCharges()
{
    for(usageItr it= myCharges.begin(); it!= myCharges.end(); it++)
    {
        cout<<"Circle "<<((it->first==IN)?"in ":"out ");
        cout<<"usage Summary \n"<<it->second.callVolume<<"mins && "<<it->second.messageVolume<<"SMS"<<endl;
    }
}

}
