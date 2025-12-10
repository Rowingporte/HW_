#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class Data {
public:
    struct Entry {
        std::vector<std::string> fields;
    };

    std::vector<Entry> entries;

    int load(const std::string& file_name);
};

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
