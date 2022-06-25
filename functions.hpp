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

// from example project
struct berResults
{
  double tot; //total number of bits
  double err; //error bits (different bits)
  float ber;  //ber calc result
  clock_t t1; //calc start time
  clock_t t2; //calc stop time
};

void readFile(string path1, string path2);
void writeLog(string log);
void openLog();
void closeLog();
uint8_t hammingDistance(uint8_t n1, uint8_t n2);
berResults compareBits(string path1, string path2, bool &diff);
void printDiffs(berResults results);
void createFile1(const std::string name, const int count, char value);
