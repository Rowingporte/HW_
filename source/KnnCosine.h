#include "knn.h"
#include <cmath>
#include <algorithm>

class KnnCosine : public Knn {
    public:
        KnnCosine();
        virtual double similarity(const Sample& a, const Sample& b) override;
        virtual int predictSingle(const Sample& sample) override;
};