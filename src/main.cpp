// Main
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

#include "csvReader.h"
#include "myBill.h"
#include "myPlan.h"
#include "myUsage.h"

using namespace std;
using namespace phonexia;

void helpMenu()
{
    cout<<"usage : Phonexia -p <call_plan_file> -d <call_data_file>"<<endl;
}

// Main
int main(int argc , char *argv[])
{

        int opt,p,d;
        p=d=0;
        string dataFile;
        string planFile;
        while ((opt = getopt(argc,argv,"p:d:")) != EOF)
        switch(opt)
        {
            case 'p': p = 1; planFile.assign(optarg) ; break;
            case 'd': d = 1; dataFile.assign(optarg); break;
            case '?': fprintf(stderr, "usuage is \n -a : for enabling a \n -b : for enabling b \n -c: <value> ");
            default: cout<<endl; abort();
        }

        if(!(p && d))
        {
            helpMenu();
            exit(0);
        }

        myUsage usage;
        usage.readMyUsageData(dataFile);
        usage.getMyCallCharges();

        ifstream myPlanFile(planFile.c_str());
        string entry;
        myPlan planEntry;

        if(myPlanFile.good())
        {
           getline(myPlanFile,entry);
           cout<<"\n \n"<<entry.c_str()<<endl;
           planEntry.setBaseBill(std::stof(entry.c_str()));
        }


      cout<<"Done!!"<<endl;

}

