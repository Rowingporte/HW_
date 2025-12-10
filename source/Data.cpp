#include "Data.h"

int Data::load(const string& file_name) {
    std::ifstream file(file_name);
    if (file) {
        cout << "reussite ouverture" << endl;
        file.close();
        cout << "reussite fermeture" << endl;
        return 1;
    }
    else {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        return 0;
    }
}
