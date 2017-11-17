#include "csvReader.h"

namespace phonexia{

csvReader::csvReader()
{
    //ctor
}

csvReader::~csvReader()
{
    //dtor
}

csvReader::csvReader(const csvReader& other)
{
    //copy ctor
}

csvReader& csvReader::operator=(const csvReader& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

ifstream& csvReader::readCsvFile(const char* infile)
{
    ifstream inFile(infile);

    return inFile;
}

void closeCsvFile(ifstream inFile)
{
    inFile.close();
}

}
