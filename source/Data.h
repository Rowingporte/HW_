#ifndef DATA_H
#define DATA_H

#include "Sample.h"
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
    vector<Sample> _data;
public:
    Data() : _nbSamples(0), _nbFeatures(0) {}           // Constructeur par défaut
    void load(const string& file_name);                 // Charger les données depuis un fichier
    void add(int tag, const vector<double> &features);  // Ajouter un échantillon
    void toString() const;                              // Afficher les données
    double operator[](int index) const;                 // Accès aux échantillons par index
    int nbSamples() const { return _nbSamples; }        // Obtenir le nombre d'échantillons
};

#endif // DATA_H
