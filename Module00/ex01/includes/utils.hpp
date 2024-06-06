#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

std::string getValidStringInput(const std::string &prompt);
std::string getValidStringInput(const std::string &prompt, const std::string &error_msg);
std::string trim(const std::string &str);
std::string stringSetSize(const std::string &str, size_t size);
std::string uIntToString(unsigned int idx);
void 		replaceTabs(std::string& str);

#endif // UTILS_HPP
