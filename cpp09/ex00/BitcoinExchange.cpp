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
            trim(date);
            trim(valueStr);
            float value = std::atof(valueStr.c_str());
            data[date] = value;
        }
    }

    return data;
}

bool isValidDate(const std::string& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') return false;

    int year, month, day;
    char dash1, dash2;
    std::stringstream ss(date);
    ss >> year >> dash1 >> month >> dash2 >> day;

    if (ss.fail() || dash1 != '-' || dash2 != '-') return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    if (month == 2  && (year % 4 != 0) && day > 29) return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;

    return true;
}

bool isValidNumber(const std::string& value) {
    std::stringstream ss(value);
    float f;
    if ((ss >> f) && ss.eof() && f >= 0.0f && f <= 1000.0f)
        return true;
    return false;
}

bool isValidLine(const std::string& line) {
    size_t pipePos = line.find('|');
    if (pipePos == std::string::npos) return false;

    std::string datePart = line.substr(0, pipePos);
    std::string valuePart = line.substr(pipePos + 1);

    trim(datePart);
    trim(valuePart);

    return isValidDate(datePart) && isValidNumber(valuePart);
}


void trim(std::string& s) {
    size_t start = s.find_first_not_of(" \t\n\r");
    size_t end = s.find_last_not_of(" \t\n\r");

    if (start == std::string::npos || end == std::string::npos)
        s = "";
    else
        s = s.substr(start, end - start + 1);
}

void processInputLines(const std::string& filename, const std::map<std::string, float>& priceMap) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open input file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Başlık satırını atla

    while (std::getline(file, line)) {
        if (!isValidLine(line)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        size_t pipePos = line.find('|');
        std::string date = line.substr(0, pipePos);
        std::string valueStr = line.substr(pipePos + 1);

        trim(date);
        trim(valueStr);

        float amount = std::atof(valueStr.c_str());
        
        if (amount < 0.0f) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (amount > 1000.0f) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        // Map’ten değeri bul
        std::map<std::string, float>::const_iterator it = priceMap.lower_bound(date);

        if (it == priceMap.end() || it->first != date) {
            // Eğer tam tarih yoksa bir önceki tarih
            if (it == priceMap.begin()) {
                std::cerr << "Error: no price data before => " << date << std::endl;
                continue;
            }
            --it;
        }

        float price = it->second;
        float result = price * amount;

        std::cout << date << " => " << amount << " = " << result << std::endl;
    }
}
