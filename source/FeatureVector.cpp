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

// Accès en lecture/écriture
double& FeatureVector::operator[](int index) {
    return _vector[index]; 
}

// Accès en lecture seule (pour les objets const)
double FeatureVector::operator[](int index) const {
    return _vector[index];
}

// Retourne la taille du vecteur
size_t FeatureVector::size() const {
    return _vector.size();
}