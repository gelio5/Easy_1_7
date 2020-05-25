#include "Regular.h"
#include <fstream>

int vowelsCounting(const std::string& fileName) {
    int counter = 0;
    std::ifstream input;
    input.open(fileName);
    if (!input)
        throw std::invalid_argument("File with name \"" + fileName + "\" does not exist");
    char g;
    std::string str;
    std::regex rx("([AaOoUuIiEeYy])");
    while (input.get(g))
    {
        str = g;
        if (regex_search(str.data(), rx))
            counter++;
    }
    input.close();
    return counter;
}

int oneLetterCounting(const std::string& fileName) {
    int counter = 0;
    std::ifstream input;
    input.open(fileName);
    if (!input)
        throw std::invalid_argument("File with name \"" + fileName + "\" does not exist");
    std::string str;
    std::regex rx("([A-Za-z])");
    while (!input.eof())
    {
        input >> str;
        if (regex_match(str.data(), rx))
            counter++;
    }
    input.close();
    return counter;
}
