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
            std::cout << std::setw(8) << std::left << std::setprecision(5) << data[i][j];

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

void printOutputFile(std::ofstream &fout, std::vector<std::vector<double> > data, std::vector<int> clusters) {
    for(int i=0; i < data.size(); i++) {
        for(int j=0; j < data[i].size(); j++)
            fout << std::setw(5) << data[i][j];

        fout << std::setw(3) << clusters[i] << std::endl;
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

void clusterData(std::vector<std::vector<double> > data, std::vector<std::vector<double> > centroid, std::vector<int> &cluster) {

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

        cluster[i] = nearestCentroid;
    }
}

void updateCentroids(std::vector<std::vector<double> > data, std::vector<int> cluster, std::vector<std::vector<double> > &centroid) {
    for(int i=0; i < centroid.size(); i++) {         //loop through each centroid
        for(int j=0; j < centroid[i].size(); j++) {         //loop through each dimension of current centroid 
            double dimensionMean = 0;
            int clusterCount = 0;

            for(int k=0; k < data.size(); k++) {                //loop through each data point at current dimension
                /* if cluster assignment at data point k == current centroid, add 
                current dimension at current data point to mean and increment count*/
                if(cluster[k] == i) {
                    dimensionMean += data[k][j];
                    clusterCount++;
                }
            }
            centroid[i][j] = dimensionMean / clusterCount;
        }
    }
}

void calculateFinalClusters(std::vector<std::vector<double> > data, std::vector<std::vector<double> > &centroid, std::vector<int> &clusters) {
    std::vector<std::vector<double> > oldCentroid(centroid.size());
    bool run = true;

    while(run) {
        oldCentroid = centroid;
        updateCentroids(data, clusters, centroid);
        clusterData(data, centroid, clusters);

        if(compareVector2d(centroid, oldCentroid) == true)
            run = false;
    }
}

bool compareVector2d(std::vector<std::vector<double> > vectorA, std::vector<std::vector<double> > vectorB) {
    if(vectorA.size() != vectorB.size() || vectorA[0].size() != vectorB[0].size())
        return false;
    else {
        for(int i=0; i < vectorA.size(); i++) {
            for(int j=0; j < vectorA[0].size(); j++) {
                if(vectorA[i][j] != vectorB[i][j])
                    return false;
            }
        }
    }
    return true;
}

double toDouble(std::string s) {
    double d;
    std::stringstream ss(s);
    ss >> d;
    return d;
}
