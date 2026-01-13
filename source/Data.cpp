#include "Data.h"
#include "Sample.h"
#include <vector>
#include <iostream>

void Data::load(const string& file_name) {
    std::ifstream file(file_name);
    if (file) {
        file >> _nbSamples;     // Recuperation premiere ligne du fichier : nombre de 'samples'
        file >> _nbFeatures;    // Recuperation deuxieme ligne du fichier : nombre de 'features' par 'samples'

        cout << "Samples : " << _nbSamples << " and Features : " << _nbFeatures << endl;

        string line;
        vector<double> tabFeatures; // Tableaux de features
        double feature;
        uint8_t tag;                // Notation attribue au sujet etudie

        file.ignore(1, ' ');
        
        for(int i = 0 ; i < _nbSamples ; i++) {
            std::getline(file, line);       // lecture d'une ligne complete (debut troisieme ligne)
            //cout << "\nLigne " << i << " : " << line << endl;

            std::istringstream iss(line);   // flux de la ligne en cours
            iss >> tag;                     // recuperation du tag
            cout << "Note donner : " << tag << endl;

            tabFeatures.clear();            // Vide le tableau (nouveau sample)

            while(iss >> feature) {
                tabFeatures.push_back(feature);
            }
            Sample(tag, tabFeatures);
        }
        file.close();
        return;
    }
    else {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        return;
    }
}