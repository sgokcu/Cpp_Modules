#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::map<std::string, float> priceData = loadCsv("data.csv");
    if (priceData.empty()) {
        std::cerr << "Error: price data is empty." << std::endl;
        return 1;
    }

    processInputLines(argv[1], priceData);
    return 0;
}
