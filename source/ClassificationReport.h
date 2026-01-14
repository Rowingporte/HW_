#ifndef CLASSIFICATIONREPORT_H
#define CLASSIFICATIONREPORT_H

#include <string>
#include <vector>

class ClassificationReport {
public:
    ClassificationReport();
    
    // Ajoute un résultat (prédiction vs vérité terrain)
    void add(int predicted, int actual);

    // Retourne un résumé textuel
    std::string toString();

    // Affiche le rapport (pour corriger l'erreur dans main.cpp)
    void show();

private:
    // Ce sont des VARIABLES, pas des fonctions : on utilise des types (int, etc.)
    int _ok;        // Nombre de bonnes prédictions
    int _nok;       // Nombre de mauvaises prédictions
    int _nbTags;    // Nombre de classes différentes
    
    // Matrice de confusion (ex: vecteur de vecteurs d'entiers)
    std::vector<std::vector<int>> _confusion;
};

#endif