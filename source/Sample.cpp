#include "Sample.h"

// Constructeur
Sample::Sample(int label, const std::vector<double>& features) 
    : label(label), features(features) {}

// Méthode pour obtenir l'étiquette
int Sample::getLabel() const {
    return label;
}

// Méthode pour obtenir les caractéristiques
const std::vector<double>& Sample::getFeatures() const {
    return features;
}

// Méthode pour afficher les informations de l'échantillon
void Sample::print() const {
    std::cout << "Label: " << label << " | Features: ";
    for (const auto& feature : features) {
        std::cout << feature << " ";
    }
    std::cout << std::endl;
}
