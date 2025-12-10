#include "Data.h"

int main() {
    Data d;
    std::string filePath;
#ifdef _WIN32
    filePath = "C:\\Perso\\INSA_Rennes\\Cours\\S7\\Cpp\\Projet\\homework\\Digits\\lismoi.txt"; 
#else
    filePath = "../jeux_video-critiques/jv-train.ssvm";
#endif

    d.load(filePath);
    return 0;
}