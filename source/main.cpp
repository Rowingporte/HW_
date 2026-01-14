#include "knn.h"
#include "KnnCosine.h"
#include "Data.h"
#include "ClassificationReport.h"
#include <iostream>

int main() {
    Data trainData;
    trainData.load("../data/Digits/digits.svm");

    // 1. Premier test : KNN Euclidien
    Knn classifier(5);
    classifier.lazy_train(&trainData);

    std::cout << "--- Test KNN Euclidien ---" << std::endl;
    // Déclaration initiale de 'report'
    ClassificationReport* report = classifier.predict(&trainData);
    report->show();
    delete report; // On libère la mémoire, mais le NOM 'report' reste connu du compilateur

    // 2. Deuxième test : KNN Cosine
    KnnCosine cosineClassifier(5); 
    cosineClassifier.lazy_train(&trainData);

    std::cout << "\n--- Test KNN Cosine ---" << std::endl;
    
    // CORRECTION : On ne remet pas "ClassificationReport*"
    // On réassigne simplement une nouvelle valeur à la variable existante
    report = cosineClassifier.predict(&trainData); 

    report->show();
    delete report;

    return 0;
}