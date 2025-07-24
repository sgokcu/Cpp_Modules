#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>
#include <cctype>

std::map<std::string, float> loadCsv(const std::string& filename);
bool isValidDate(const std::string& date);
bool isValidNumber(const std::string& value);
bool isValidLine(const std::string& line);
void trim(std::string& str);
void processInputLines(const std::string& filename, const std::map<std::string, float>& priceMap);


#endif
