#include "KnnCosine.h"

double KnnCosine::similarity(const Sample &a, const Sample &b) {
    const std::vector<double>& featuresA = a.features();
    const std::vector<double>& featuresB = b.features();

    double dotProduct = 0.0;
    double normA = 0.0;
    double normB = 0.0;

    for (size_t i = 0; i < featuresA.size(); ++i) {
        dotProduct += featuresA[i] * featuresB[i];
        normA += featuresA[i] * featuresA[i];
        normB += featuresB[i] * featuresB[i];
    }

    if (normA == 0 || normB == 0) {
        return 0.0; // Éviter la division par zéro
    }

    return dotProduct / (std::sqrt(normA) * std::sqrt(normB));
}

int KnnCosine::predictSingle(const Sample &sample) {
    // Implémentation spécifique pour la prédiction avec similarité cosinus
    // Récupérer les k plus proches voisins en utilisant la similarité cosinus
    std::vector<std::pair<double, int>> neighbors; // paire de (similarité, étiquette)

    for (int i = 0; i < _data.nbSamples(); ++i) {
        const Sample& trainSample = _data[i];
        double sim = similarity(sample, trainSample);
        neighbors.push_back(std::make_pair(sim, _data.tag()));
    }

    // Trier les voisins par similarité décroissante
    std::sort(neighbors.begin(), neighbors.end(), [](const auto& a, const auto& b) {
        return a.first > b.first;
    });

    // Compter les votes des k plus proches voisins
    std::vector<int> votes(10, 0); // Supposons 10 classes (0 à 9)
    for (int i = 0; i < _k; ++i) {
        votes[neighbors[i].second]++;
    }

    // Trouver l'étiquette avec le maximum de votes
    int predictedLabel = std::distance(votes.begin(), std::max_element(votes.begin(), votes.end()));
    return predictedLabel;
}