#include "Knn.h"
#include "Data.h"                // Pour utiliser _trainData->nbSamples()
#include "Sample.h"              // Pour utiliser sample.tag()
#include "ClassificationReport.h"
#include <algorithm>             // Pour std::sort (le tri)
#include <map>                   // Pour le vote (compter les occurrences)
#include <iostream>

// Constructeur
Knn::Knn(int k) : _k(k), _trainData(nullptr) {
    if (_k < 1) {
        std::cout << "Attention : k doit etre > 0. K remis a 1." << std::endl;
        _k = 1;
    }
}

// Lazy Train : On stocke juste l'adresse des données (classifieur paresseux)
void Knn::lazy_train(Data* data) {
    _trainData = data;
}

// Processus de test
ClassificationReport* Knn::predict(Data* testData) {
    ClassificationReport* report = new ClassificationReport();

    // On boucle sur tous les exemples du fichier de test
    // (Supposons que Data a une méthode nbSamples et un opérateur [])
    for (size_t i = 0; i < testData->nbSamples(); ++i) {
        const Sample& currentTestSample = (*testData)[i];

        // 1. On prédit l'étiquette
        int predictedTag = predictSingle(currentTestSample);

        // 2. On ajoute le résultat au rapport (Prédiction vs Réalité)
        report->add(predictedTag, currentTestSample.tag());
    }

    return report;
}

int Knn::predictSingle(const Sample& sample) {
    // Récupérer les k voisins les plus proches -> liste de paires {Score, Étiquette}
    std::vector<std::pair<double, int>> neighbors = getKnn(sample);

    // Faire voter les voisins
    std::map<int, int> votes;
    for (const auto& neighbor : neighbors) {
        int label = neighbor.second; // On récupère l'étiquette du voisin
        votes[label]++;              // On ajoute 1 vote
    }

    // Trouver celui qui a le plus de votes
    int bestLabel = -1;
    int maxVotes = -1;

    for (auto const& [label, count] : votes) {
        if (count > maxVotes) {
            maxVotes = count;
            bestLabel = label;
        }
    }

    return bestLabel;
}