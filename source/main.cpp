#include "knn.h"
#include "KnnCosine.h"
#include "Data.h"
#include "ClassificationReport.h"
#include <iostream>

int main() {
    // --- 1. Load Datasets ---
    Data trainData;
    trainData.load("../data/test/train.svm");

    Data testData;
    testData.load("../data/test/test.svm");

    // --- 2. Setup KNN Euclidean ---
    // k=3 is often more robust than k=1
    Knn euclidianClassifier(3); 
    
    // We "train" on the training data
    euclidianClassifier.lazy_train(&trainData);

    std::cout << "--- Testing KNN Euclidean ---" << std::endl;
    // CRITICAL: We predict on the testData
    ClassificationReport* reportEuclidian = euclidianClassifier.predict(&testData);
    reportEuclidian->show();
    delete reportEuclidian;

    // --- 3. Setup KNN Cosine ---
    KnnCosine cosineClassifier(3); 
    cosineClassifier.lazy_train(&trainData);

    std::cout << "\n--- Testing KNN Cosine ---" << std::endl;
    ClassificationReport* reportCosine = cosineClassifier.predict(&testData); 
    reportCosine->show();
    delete reportCosine;

    return 0;
}