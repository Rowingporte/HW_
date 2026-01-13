#ifndef SAMPLE_H
#define SAMPLE_H

#include <vector>
#include <iostream>



class Sample {
public:
    // Constructeur
    Sample(int tag, const std::vector<double>& features);

    // Méthodes pour obtenir des informations sur l'échantillon
    int gettag() const;
    const std::vector<double>& getFeatures() const;

    // Afficher les informations de l'échantillon
    void print() const;

    // Accès aux caractéristiques
    double operator[](size_t index) const;
    Sample scale(double factor) const;
    std::string toString() const;

private:
    int _tag; // Étiquette de classe (0 à 9)
    std::vector<double> features; // Vecteur de caractéristiques
};

#endif // SAMPLE_H