#include "BitcoinExchange.hpp"

std::map<std::string, float> loadCsv(const std::string& filename) {
    std::map<std::string, float> data;
    std::ifstream file(filename.c_str());

    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return data;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date, valueStr;

        if (std::getline(ss, date, ',') && std::getline(ss, valueStr)) {
            float value = std::atof(valueStr.c_str());
            data[date] = value;
        }
    }

    return data;
}