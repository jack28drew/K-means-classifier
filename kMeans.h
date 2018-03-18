#ifndef KMEANS_H_
#define KMEANS_H_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

void importTXT(std::ifstream&, std::vector<std::vector<double> >&);
void importCSV(std::ifstream&, std::vector<std::vector<double> >&);
void printData(std::vector<std::vector<double> >);

double toDouble(std::string);

#endif /*KMEANS_H_*/