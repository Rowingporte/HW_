#include "Sample.h"

// Constructeur
Sample::Sample(int tag, const std::vector<double>& features) 
    : _tag(tag), features(features) {}

// Méthode pour obtenir l'étiquette
int Sample::tag() const {
    return _tag;
}

// Méthode pour obtenir les caractéristiques
const std::vector<double>& Sample::getFeatures() const {
    return features;
}

// Méthode pour afficher les informations de l'échantillon
void Sample::print() const {
    std::cout << "tag: " << _tag << " | Features: ";
    for (const auto& feature : features) {
        std::cout << feature << " ";
    }
    std::cout << std::endl;
}

double Sample::operator[](size_t index) const {
    return features[index];
}

Sample Sample::scale(double factor) const {
    std::vector<double> scaledFeatures(features.size());
    for (size_t i = 0; i < features.size(); ++i) {
        scaledFeatures[i] = features[i] * factor;
    }
    return Sample(_tag, scaledFeatures);
}

std::string Sample::toString() const {
    std::string result = "Label: " + std::to_string(_tag) + " | Features: ";
    for (const auto& feature : features) {
        result += std::to_string(feature) + " ";
    }
    return result;
}


