#ifndef SAMPLE_H
#define SAMPLE_H

#include <string>

class Sample {
private:
    int _tag;  // Member variable to store the tag

public:
    // Constructor
    Sample(int tag);

    // Getter for the tag
    int getTag() const;

    // Method declarations
    void features();
    void operator[]() const;  // Overloading operator()
    void scale();
    std::string toString() const;  // Method to return string representation
};

#endif // SAMPLE_H
