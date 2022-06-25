#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

// QOL
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::ifstream;
using std::fstream;
using std::filesystem::file_size;

void readFile(string path1, string path2);
void writeLog(string log);
void openLog();
void closeLog();
uint8_t hammingDistance(uint8_t n1, uint8_t n2);
