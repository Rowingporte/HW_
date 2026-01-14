#ifndef KNNCOSINE_H
#define KNNCOSINE_H

#include "knn.h"
#include <vector>

class KnnCosine : public Knn {
    public:
        // Ajout de l'argument k
        KnnCosine(int k);
        
        // On redéfinit la similarité
        virtual double similarity(const Sample& a, const Sample& b) override;
        
        // Note: predictSingle n'a généralement pas besoin d'être redéfini 
        // si getKnn gère correctement le tri (voir explications plus bas).
};

#endif