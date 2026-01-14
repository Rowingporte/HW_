#include "KnnCosine.h"
#include "Sample.h"
#include <cmath>
#include <vector>

// On appelle explicitement le constructeur de la classe de base
KnnCosine::KnnCosine(int k) : Knn(k) {
}

double KnnCosine::similarity(const Sample& a, const Sample& b) {
    const std::vector<double>& featA = a.getFeatures();
    const std::vector<double>& featB = b.getFeatures();

    double dotProduct = 0.0;
    double normA = 0.0;
    double normB = 0.0;

    // Calcul du produit scalaire et des normes
    for (size_t i = 0; i < featA.size(); ++i) {
        dotProduct += featA[i] * featB[i];
        normA += featA[i] * featA[i];
        normB += featB[i] * featB[i];
    }

    // Sécurité contre la division par zéro
    if (normA <= 0.0 || normB <= 0.0) {
        return 1.0; // Distance maximale si un vecteur est nul
    }

    double cosSim = dotProduct / (std::sqrt(normA) * std::sqrt(normB));

    /**
     * Transformation en "distance" :
     * Cosinus = 1  => Retourne 0 (Identique)
     * Cosinus = 0  => Retourne 1 (Orthogonal)
     * Cosinus = -1 => Retourne 2 (Opposé)
     * * Cela permet à Knn::getKnn d'utiliser un tri croissant (std::sort).
     */
    return 1.0 - cosSim;
}