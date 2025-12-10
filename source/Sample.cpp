#include "Sample.h"
#include <iostream>

using std::cout;
using std::endl;

Sample::Sample(int tag) : _tag(tag) {
    cout << "Sample object created with tag: " << _tag << endl;
}

int Sample::getTag() const {
    return _tag;
}

void Sample::features() {
    cout << "features function called." << endl;
}

void Sample::operator[]() const{
    cout << "operator() function called." << endl;
}

void Sample::scale() {
    cout << "scale function called." << endl;
}

std::string Sample::toString() const {
    return "This is a Sample object with tag: " + std::to_string(_tag);
}
