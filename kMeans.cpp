#include "kMeans.h"

void importTXT(std::ifstream& fin, std::vector<std::vector<double> > &data) {
    std::string line;

    while(getline(fin, line)) {
        std::stringstream ss(line);
        std::string value;

        std::vector<double> tempVector;

        while(ss >> value)
            tempVector.push_back(toDouble(value));

        data.push_back(tempVector);
    }
}

void importCSV(std::ifstream& fin, std::vector<std::vector<double> > &data) {
    std::string line;
    char delim = ',';

    while(getline(fin, line)) {
        std::stringstream ss(line);
        std::string value;

        std::vector<double> tempVector;

        while(getline(ss, value, delim))
            tempVector.push_back(toDouble(value));

        data.push_back(tempVector);
    }
}

void printData(std::vector<std::vector<double> > data) {
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[0].size(); j++)
            std::cout << std::setw(5) << data[i][j];

        std::cout << std::endl;
    }
}

double toDouble(std::string s) {
    double d;
    std::stringstream ss(s);
    ss >> d;
    return d;
}