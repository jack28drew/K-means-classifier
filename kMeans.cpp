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
        std::cout << i+1 << " - ";

        for (int j = 0; j < data[0].size(); j++)
            std::cout << std::setw(5) << data[i][j];

        std::cout << std::endl;
    }
}

double euclideanDistance(std::vector<double> pointA, std::vector<double> pointB) {
    double distance = 0;

    for(int i=0; i < pointA.size(); i++) {
        distance += pow(pointB[i] - pointA[i], 2);
    }

    return sqrt(distance);
}

std::vector<std::vector<double> > initializeCentroids(std::vector<std::vector<double> > data, int k) {
    std::vector<std::vector<double> > centroids;
    srand(time(NULL));

    int randomIndex = rand() % data.size();
    centroids.push_back(randomIndex);

    if(k > 1) {
        
    }

    return centroids;
}








double toDouble(std::string s) {
    double d;
    std::stringstream ss(s);
    ss >> d;
    return d;
}


























/*std::vector<std::vector<double> > initializeCentroids(std::vector<std::vector<double> > data) {
    double distanceMatrix[data.size()][data.size()];

    for(int i=0; i < data.size(); i++) {
        for(int j=0; j < data.size(); j++)
            distanceMatrix[i][j] = euclideanDistance(data[i], data[j]);
    }

    std::ofstream fout;
    fout.open("output.txt");

    for(int i=0; i < data.size(); i++) {
        for(int j=0; j < data.size(); j++) 
            fout << std::setw(10) << std::setprecision(4) <<  distanceMatrix[i][j];

        fout << std::endl;
    } 

    fout.close();

    std::vector<std::vector<double> > centroids;
    return centroids;
}*/