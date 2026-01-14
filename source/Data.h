#ifndef DATA_H
#define DATA_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Sample.h"

using namespace std;

class Data {
public:
    void load(const string& file_name);
    void add(int tag, const vector<double> &features);
    void toString() const;
    
    // Accès sécurisé aux échantillons (indispensable pour Knn)
    const Sample& getSample(int index) const { return _data[index]; }
    
    int nbSamples() const { return _nbSamples; }
    double operator[](int index) const;

private:
    vector<Sample> _data;
    int _nbSamples;
    int _nbFeatures;
};

#endif