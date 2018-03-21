#include "kMeans.h"

int main(int argc, char const *argv[])
{
    std::ifstream fin;
    fin.open(argv[1]);

    if(!fin) {
        std::cerr << "no input file\n";
        return 1;
    }

    int k;
    std::stringstream ss(argv[2]);

    if(!(ss >> k) || k < 1) {
        std::cerr << "enter a valid number for k" << std::endl;
        return 2;
    }
        



    std::string file = argv[1];
    std::vector<std::vector<double> > data;

    if(file.substr(file.find_last_of(".") + 1) == "txt")
        importTXT(fin, data);

    else if(file.substr(file.find_last_of(".") + 1) == "csv")
        importCSV(fin, data);

    else {
        std::cerr << "invalid file type. file must be .txt or .csv\n";
        return 3;
    }

    std::vector<std::vector<double> > centroid = initializeCentroids(data, k);
    std::vector<int> clusters;

    clusterData(data, centroid, clusters);

    std::ofstream fout;
    fout.open("output.txt");

    printOutputFile(fout, data, clusters);

    fin.close();
    fout.close();

    return 0;
}