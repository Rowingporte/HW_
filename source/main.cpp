#include "knn.h"
#include "Data.h"
#include "ClassificationReport.h"
#include <iostream>

int main() {
    Data trainData;
    trainData.load("../data/Digits/digits.svm");

    Knn classifier(5); // k = 5
    classifier.lazy_train(&trainData);

    std::cout << "Calcul des prédictions en cours..." << std::endl;
    // On teste sur les données d'entraînement pour cet exemple
    ClassificationReport* report = classifier.predict(&trainData);

    report->show();

    delete report;
    return 0;
}