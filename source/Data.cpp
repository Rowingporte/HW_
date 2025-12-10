#include "Data.h"

void Data::load(const string& file_name) {
    std::ifstream file(file_name);
    if (file) {
        file.close();
        return;
    }
    else {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        return;
    }
}
