#ifndef CSVREADER_H
#define CSVREADER_H

#include <iostream>
#include <fstream>

using namespace std;

namespace phonexia{

class csvReader
{
    public:
        csvReader();
        virtual ~csvReader();
        csvReader(const csvReader& other);
        csvReader& operator=(const csvReader& other);
        ifstream& readCsvFile(const char* infile);
        void closeCsvFile();

    protected:

    private:
        //ifstream inFile;
};

}
#endif // CSVREADER_H
