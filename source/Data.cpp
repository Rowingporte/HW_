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

int Data::load(const std::string& file_name) {
    std::ifstream file(file_name);
    if (file) {
        std::cout << "Réussite ouverture" << std::endl;

        std::string line;
        while (std::getline(file, line)) {
            Entry entry;
            std::istringstream iss(line);
            std::string field;

            while (iss >> field) { // Extracts space-separated fields
                entry.fields.push_back(field);
            }

            entries.push_back(entry);
        }

        file.close();
        std::cout << "Réussite fermeture" << std::endl;
        
        // Print loaded data
        for (const auto& entry : entries) {
            for (const auto& field : entry.fields) {
                std::cout << field << " ";
            }
            std::cout << std::endl; // New line for each entry
        }

        return 1; 
    } 
    else {
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
        return 0; 
    }
}
