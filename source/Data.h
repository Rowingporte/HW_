#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

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