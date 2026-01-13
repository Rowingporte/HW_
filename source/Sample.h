#ifndef SAMPLE_H
#define SAMPLE_H

#include <vector>
#include <iostream>

class Sample {
public:
    // Constructeur
    Sample(int label, const std::vector<double>& features);

    // Méthodes pour obtenir des informations sur l'échantillon
    int getLabel() const;
    const std::vector<double>& getFeatures() const;

    // Afficher les informations de l'échantillon
    void print() const;

private:
    int label; // Étiquette de classe (0 à 9)
    std::vector<double> features; // Vecteur de caractéristiques
};

#endif // SAMPLE_H