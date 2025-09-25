#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <climits>
#include <cmath>

bool isCharLiteral(const std::string &literal);
bool isIntLiteral(const std::string &literal);
bool isFloatLiteral(const std::string &literal);
bool isDoubleLiteral(const std::string &literal);
bool isPseudoLiteral(const std::string &literal);

void convertFromChar(char c);
void convertFromInt(int i);
void convertFromFloat(float f);
void convertFromDouble(double d);

#endif
