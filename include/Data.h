#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdint>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cerr;

class Data{
    int _nbSamples;
    int _nbFeatures;
public:
    void load(const string& file_name);
};

#endif // DATA_H
