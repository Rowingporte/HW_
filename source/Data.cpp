#include "Data.h"

void Data::load(const string& file_name) {
    std::ifstream file(file_name);

    if (file) {

        string line;
        vector<double> tabFeatures;
        double feature;
        int tag;                                            // Note associée au sample

        file >> _nbSamples;                                 // Premiere ligne du fichier : nombre de 'samples'
        file >> _nbFeatures;                                // Deuxieme ligne du fichier : nombre de 'features' par 'samples'
        file.ignore(1, ' ');                                // Ignorer le saut de ligne après le nombre de features
        //cout << "Samples : " << _nbSamples << " and Features : " << _nbFeatures << endl;
        
        for(int i = 0 ; i < _nbSamples ; i++) {
            tabFeatures.clear();                            // Réinitialisation du tableau de features
            std::getline(file, line);                       // Lecture d'une ligne complète
            std::istringstream iss(line);                   // Flux pour extraire les données de la ligne
            iss >> tag;
            //cout << "\nLigne " << i << " : " << line << endl;            
            //cout << "Note donner : " << tag << endl;

            while(iss >> feature) {
                tabFeatures.push_back(feature);             // Extraction des features et ajout au tableau
                //cout << "Feature : " << feature << endl;
            }
            _data.push_back(Sample(tag, tabFeatures));      // Création et ajout du Sample au vecteur de données
        }
        file.close();
        return;
    }
    else {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        return;
    }
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