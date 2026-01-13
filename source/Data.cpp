#include "Data.h"

void Data::load(const string& file_name) {
    std::ifstream file(file_name);

    if (file) {

        string line;                                        // Ligne en cours de lecture
        vector<double> tabFeatures;                         // Tableaux de features
        double feature;                                     // Valeur d'une feature
        int tag;                                            // Note associée au sample

        file >> _nbSamples;                                 // Recuperation premiere ligne du fichier : nombre de 'samples'
        file >> _nbFeatures;                                // Recuperation deuxieme ligne du fichier : nombre de 'features' par 'samples'
        file.ignore(1, ' ');                                // Ignorer le saut de ligne après le nombre de features
        //cout << "Samples : " << _nbSamples << " and Features : " << _nbFeatures << endl;
        
        for(int i = 0 ; i < _nbSamples ; i++) {
            tabFeatures.clear();                            // Réinitialisation du tableau de features
            std::getline(file, line);                       // Lecture d'une ligne complète
            std::istringstream iss(line);                   // Flux pour extraire les données de la ligne
            iss >> tag;                                     // Extraction de la note (tag)
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

void Data::toString() const {
    for (const auto& sample : _data) {
        sample.print();
    }
}

Data Data::scale(double factor) const {
    Data scaledData;
    scaledData._nbSamples = _nbSamples;
    scaledData._nbFeatures = _nbFeatures;

    for (const auto& sample : _data) {
        vector<double> scaledFeatures;
        for (const auto& feature : sample.getFeatures()) {
            scaledFeatures.push_back(feature * factor);
        }
        scaledData._data.push_back(Sample(sample.getLabel(), scaledFeatures));
    }
    return scaledData;
}

double Data::operator[](size_t index) const {
    if (index >= _nbSamples) {
        throw std::out_of_range("Index out of range");
    }
    // Assuming we want to return the label of the sample at the given index
    return _data[index].getLabel();
}