#include "knn.h"
#include "Data.h"
#include "Sample.h"
#include "ClassificationReport.h"
#include <algorithm>
#include <map>
#include <cmath>

Knn::Knn(int k) : _k(k), _trainData(nullptr) {}

void Knn::lazy_train(Data* data) {
    _trainData = data;
}

std::vector<std::pair<double, int>> Knn::getKnn(const Sample& sample) {
    std::vector<std::pair<double, int>> distances;

    for (int i = 0; i < _trainData->nbSamples(); ++i) {
        const Sample& trainSample = _trainData->getSample(i);
        double dist = similarity(sample, trainSample);
        distances.push_back({dist, trainSample.tag()});
    }

    // Tri par distance (ordre croissant)
    std::sort(distances.begin(), distances.end());

    if (distances.size() > (size_t)_k) {
        distances.resize(_k);
    }
    return distances;
}

int Knn::predictSingle(const Sample& sample) {
    std::vector<std::pair<double, int>> neighbors = getKnn(sample);
    std::map<int, int> votes;

    for (const auto& n : neighbors) {
        votes[n.second]++;
    }

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

ClassificationReport* Knn::predict(Data* testData) {
    ClassificationReport* report = new ClassificationReport();
    for (int i = 0; i < testData->nbSamples(); ++i) {
        const Sample& current = testData->getSample(i);
        int predictedTag = predictSingle(current);
        report->add(predictedTag, current.tag());
    }
    return report;
}

double Knn::similarity(const Sample& a, const Sample& b) {
    double sum = 0.0;
    const std::vector<double>& featA = a.getFeatures();
    const std::vector<double>& featB = b.getFeatures();

    for (size_t i = 0; i < featA.size(); ++i) {
        double diff = a[i] - b[i]; // Utilise l'opérateur [] de Sample
        sum += diff * diff;
    }
    return std::sqrt(sum);
}