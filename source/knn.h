#ifndef KNN_H
#define KNN_h

#include <vector>

// *******************************************************
// A SUPPRIMER PLUS TARD QUAND AUTRES FICHIERS FAITS
class Data;
class Sample;
class ClassificationReport;
// *******************************************************


class Knn {
    public:
        // Constructeur : on fixe k (nombre de voisins)
        Knn(int k);

        // Destructeur
        virtual ~Knn() {};

        // Stocke les données d'apprentissage (Lazy Learning)
        void lazy_train(Data* data);

        // Prédit les étiquettes pour un jeu de test complet et renvoie un rapport
        ClassificationReport* predict(Data* testData);

    protected:
        int _k;              // Le paramètre K
        Data* _trainData;    // Pointeur vers données d'apprentissage

         // Classe fille de KnnCosine
        virtual double similarity(const Sample& a, const Sample& b);

        // Récupère les k plus proches voisins (scores et étiquettes)
        // étiquette : chiffre de 0 à 9
        // score : résultat du calcul mathématique de la fonction similarity entre vecteur testé et celui la base de données
        //void getKnn(); J'AI PAS COMPRIS

        // Prédit l'étiquette (0 à 9) pour un seul exemple
        virtual int predictSingle(const Sample& sample);
};

#endif