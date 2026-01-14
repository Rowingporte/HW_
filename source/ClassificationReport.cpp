#include "ClassificationReport.h"
#include <iomanip>
#include <iostream>  // <--- L'inclusion manquante est ici
#include <sstream>

ClassificationReport::ClassificationReport() : _ok(0), _nok(0) {
    // Initialisation de la matrice 10x10 pour les chiffres 0-9
    _confusion.resize(10, std::vector<int>(10, 0));
}

void ClassificationReport::add(int predicted, int actual) {
    if (predicted == actual) {
        _ok++;
    } else {
        _nok++;
    }

    // Mise à jour de la matrice de confusion [Réel][Prédit]
    if (predicted >= 0 && predicted < 10 && actual >= 0 && actual < 10) {
        _confusion[actual][predicted]++;
    }
}

void ClassificationReport::show() {
    std::cout << toString() << std::endl;
}

std::string ClassificationReport::toString() {
    std::stringstream ss;
    ss << "\n--- Rapport de Classification ---\n";
    ss << "Succès : " << _ok << " | Échecs : " << _nok << "\n";
    
    double acc = (_ok + _nok > 0) ? (double)_ok / (_ok + _nok) * 100.0 : 0.0;
    ss << "Précision : " << std::fixed << std::setprecision(2) << acc << "%\n";
    
    ss << "\nMatrice de Confusion (Lignes: Réel, Col: Prédit) :\n";
    ss << "    0  1  2  3  4  5  6  7  8  9\n";
    ss << "    ---------------------------\n";
    for(int i=0; i<10; ++i) {
        ss << i << " |";
        for(int j=0; j<10; ++j) {
            ss << std::setw(3) << _confusion[i][j];
        }
        ss << "\n";
    }
    return ss.str();
}