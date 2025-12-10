#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using std::ifstream;
using std::string;

class Data{
    public:
    // add();
    // aspire_les_donnees();
    // Data();
    int load(const string file_name){
        ifstream infile(file_name);
        string line;

        while (std::getline(infile, line)) {
            std::istringstream iss(line);
            int label;
            iss >> label; 

            std::vector<double> data;
            while (iss) {
                int index;
                double value;
                if (!(iss >> index >> value)) break;
                data.push_back(value);
            }
        }
        return 0;
    };
    // nbSamples();
    // operator();
    // scale();
    // toString();

    private:
    // _data();
    // _nb_features();
    // _nb_samples();
};