#include "kMeans.h"

int main(int argc, char const *argv[])
{
    std::string file = argv[1];
    std::ifstream fin;
    fin.open(argv[1]);

    std::vector<std::vector<double> > data;

    if(!fin) {
        std::cerr << "no input file\n";
        return 1;
    }

    else if(file.substr(file.find_last_of(".") + 1) == "txt")
        importTXT(fin, data);

    else if(file.substr(file.find_last_of(".") + 1) == "csv")
        importCSV(fin, data);

    else {
        std::cerr << "invalid file type. file muse be .txt or .csv\n";
        return 2;
    }

    printData(data);
    return 0;
}