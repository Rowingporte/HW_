#ifndef FEATUREVECTOR_H
#define FEATUREVECTOR_H

#include <vector>
#include <cmath>

class FeatureVector {
private:
    std::vector<double> _vector;
    double _norme;

public:
    // Constructeur par défaut
    FeatureVector();
    
    // Constructeur à partir d'un vecteur de doubles
    FeatureVector(const std::vector<double>& features);

    // Retourne la norme euclidienne du vecteur.
    double norme();

    // Surcharge de l'opérateur de produit scalaire
    double operator*(const FeatureVector& other) const;

    // Surcharge de l'opérateur
    //double& operator[]();

    // Retourne la taille du vecteur
    size_t size() const;
};

#endif // FEATUREVECTOR_H