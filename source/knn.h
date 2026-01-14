#ifndef KNN_H
#define KNN_H

#include <vector>
#include <utility> // Nécessaire pour std::pair

// Forward declarations
class Data;
class Sample;
class ClassificationReport;

class Knn {
    public:
        // Constructeur
        Knn(int k);

        // Destructeur
        virtual ~Knn() {}

        // Stocke les données d'apprentissage (Lazy Learning)
        void lazy_train(Data* data);

        // Prédit les étiquettes pour un jeu de test complet et renvoie un rapport
        ClassificationReport* predict(Data* testData);

        // Prédit l'étiquette pour un seul exemple
        int predictSingle(const Sample& sample);

    protected:
        int _k;              // Le paramètre K
        Data* _trainData;    // Pointeur vers données d'apprentissage

        // Fonction de calcul de distance/similarité
        virtual double similarity(const Sample& a, const Sample& b);

        // Récupère les k plus proches voisins
        std::vector<std::pair<double, int>> getKnn(const Sample& sample);
};

#endif