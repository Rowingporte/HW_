/*
FeatureVector : l’objet est prévu pour stocker un vecteur de caractéristique et proposer des
méthodes pour l’exploiter, par exemple des méthodes permettant de calculer sa norme, de
calculer des produits scalaires, etc.
*/

#include "FeatureVector.h"

// Calcule et retourne la norme euclidienne du vecteur
double FeatureVector::norme() {
    double somme = 0.0;
    for (double value : _vector) {
        somme += value * value;
    }
    _norme = std::sqrt(somme);
    return _norme;
}


// Calcule le produit scalaire entre deux vecteurs
double FeatureVector::operator*(const FeatureVector& other) const {
    double scalaire = 0.0;

    for (size_t i = 0; i < _vector.size(); ++i) {
        scalaire += _vector[i] * other._vector[i];
    }

    return scalaire;
}

 // Surcharge de l'opérateur
//double& FeatureVector::operator[](void) {
    // Aucune idée de à quoi ça sert
//}


// Retourne la taille du vecteur
size_t FeatureVector::size() const {
    return _vector.size();
}