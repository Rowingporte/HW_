#include "Data.h"

void Data::load(const string& file_name) {
    std::ifstream file(file_name);
    if (file) {
        file >> _nbSamples;
        file >> _nbFeatures;
        cout << "Samples : " << _nbSamples << " Features : " << _nbFeatures << endl;
        for(int i = 0 ; i < _nbSamples ; i++) {
            
        }
        file.close();
        return;
    }
    else {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        return;
    }
}
