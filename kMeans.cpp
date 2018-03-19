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
        std::cout << i << " - ";

        for (int j = 0; j < data[0].size(); j++)
            std::cout << std::setw(5) << data[i][j];

        std::cout << std::endl;
    }
}

void printData(std::vector<std::vector<double> > data, std::vector<int> clusters) {
    for(int i=0; i < data.size(); i++) {
        for(int j=0; j < data[0].size(); j++)
            std::cout << std::setw(5) << data[i][j];

        std::cout << " -> " << clusters[i] << std::endl;
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
    std::vector<std::vector<double> > centroid;
    srand(time(NULL));

    int indexes[data.size()];

    for(int i=0; i < data.size(); i++)
        indexes[i] = i;

    std::random_shuffle(indexes, indexes + data.size());

    for(int i=0; i < k; i++) 
        centroid.push_back(data[indexes[i]]);

    return centroid;
}


void clusterData(std::vector<std::vector<double> > data, std::vector<std::vector<double> > centroid, std::vector<int> &clusters) {

    for(int i=0; i < data.size(); i++) {
        std::vector<double> distanceToCentroid(centroid.size());
        int nearestCentroid = 0;

        for(int j=0; j < centroid.size(); j++)
            distanceToCentroid[j] = euclideanDistance(centroid[j], data[i]);

        double shortestDistance = distanceToCentroid[0];

        for(int ii=1; ii < centroid.size(); ii++) {
            if(distanceToCentroid[ii] < shortestDistance) {
                shortestDistance = distanceToCentroid[ii];
                nearestCentroid = ii;
            }
        }

        clusters.push_back(nearestCentroid);
    }
}


double toDouble(std::string s) {
    double d;
    std::stringstream ss(s);
    ss >> d;
    return d;
}
