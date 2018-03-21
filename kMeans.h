#ifndef KMEANS_H_
#define KMEANS_H_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

void importTXT(std::ifstream&, std::vector<std::vector<double> >&);
void importCSV(std::ifstream&, std::vector<std::vector<double> >&);
void printData(std::vector<std::vector<double> >, std::vector<int>);
void printData(std::vector<std::vector<double> >);
void printOutputFile(std::ofstream&, std::vector<std::vector<double> >, std::vector<int>);

double euclideanDistance(std::vector<double>, std::vector<double>);
std::vector<std::vector<double> > initializeCentroids(std::vector<std::vector<double> >, int);
void clusterData(std::vector<std::vector<double> >, std::vector<std::vector<double> >, std::vector<int>&);
std::vector<std::vector<double> > updateCentroids(std::vector<std::vector<double> >, std::vector<int>, std::vector<std::vector<double> >&);
void calculateFinalClusters(std::vector<std::vector<double> >, std::vector<std::vector<double> >&, std::vector<int>&);

bool compareVector2d(std::vector<std::vector<double> >, std::vector<std::vector<double> >);
double toDouble(std::string);

#endif /*KMEANS_H_*/