#include "Data.h"
#include <limits>

void Data::load(const string& file_name) {
    std::ifstream file(file_name);
    if (!file) {
        cerr << "Error: Impossible to open " << file_name << endl;
        return;
    }

    // Clear previous data if any
    _data.clear();
    _nbSamples = 0;

    int tag;
    double feature;
    
    file >> _nbSamples;                                 
    file >> _nbFeatures;                                
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    for(int i = 0 ; i < _nbSamples ; i++) {
        string line;
        if(!std::getline(file, line) || line.empty()) break;

        std::istringstream iss(line);
        iss >> tag;

        vector<double> tabFeatures;
        while(iss >> feature) {
            tabFeatures.push_back(feature);
        }
        _data.push_back(Sample(tag, tabFeatures));
    }
    file.close();
}

void Data::add(int tag, const vector<double> &features) {
   _data.push_back(Sample(tag, features));
   _nbSamples++;
}

void Data::toString() const {
    for (const auto  &sample : _data) {
        sample.print();
    }
}

double Data::operator[](int index) const {
    if (index >= _nbSamples) {
        throw std::out_of_range("Index non valide");
    }
    return _data[index].tag();   // Retourne le tag de l'échantillon à l'index donné
}