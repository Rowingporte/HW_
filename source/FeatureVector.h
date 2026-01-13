#ifndef FEATUREVECTOR_H
#define FEATUREVECTOR_H

#include <vector>
#include <cmath>  // Nécessaire pour std::sqrt
#include <iostream>

class FeatureVector {
    public:
        // Constructeur
        FeatureVector(int dimension = 0, double val = 0.0);
        
        // Constructeur alternatif
        FeatureVector(std::vector<double> data);

        // Méthodes publiques
        double norme();
        double operator*(const FeatureVector& other) const;
        
        // Surcharge de l'opérateur [] (lecture/écriture)
        double& operator[](int index);
        
        // Surcharge de l'opérateur [] (lecture seule pour les objets const)
        double operator[](int index) const;
        
        size_t size() const;

    private:
        // Attributs privés
        double _norme;
        std::vector<double> _vector;
};

#endif