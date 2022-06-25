#include "functions.hpp"

void readFile(string path1, string path2)
{
    uint fileSize1{0};
    uint fileSize2{0};
    bool diff { 0 };
    
    fileSize1 = file_size(path1);
    fileSize2 = file_size(path2);

    if(fileSize2 != fileSize1)
    {
      openLog();
      writeLog("Size of provided files is different!");
      closeLog();
    }
    else
    {
      openLog();
      berResults results;
      writeLog("Processing...");
      results = compareBits(path1, path2, diff);
      if(diff)
      {
          printDiffs(results);
      }
      else
      {
          writeLog("No differences found");
      }
      closeLog();
    }
}

// from example project
uint8_t hammingDistance(uint8_t n1, uint8_t n2)
{
    uint8_t x = n1 ^ n2; // XOR
    uint8_t setBits = 0;
    while (x > 0)
    {
        setBits += x & 1;
        x >>= 1;
    }
    return setBits;
}

// based on example project
berResults compareBits(string path1, string path2, bool &diff)
{
    ifstream file1(path1, std::ios::binary | std::ios::in);
    ifstream file2(path2, std::ios::binary | std::ios::in);
    berResults results;
    results.t1 = 0;
    results.t2 = 0;
    results.ber = 0;
    results.err = 0;
    results.tot = 0;

    writeLog("Calculating BER...");
    char a = 0x00;
    char b = 0x00;
    results.t1 = clock();

    while (!file1.eof())
    {
        file1 >> a; //read 1 char from file 1
        file2 >> b; //read 1 char from file 2
        if (!file1.eof()) // till the end of the 1st file
        {
            results.err += hammingDistance(a, b); //add to the .err the number of different bits
            results.tot += 8; //add to the .tot the number of compared bits
        }
    }

    results.ber = (float)results.err / results.tot; // calculate ber
    results.t2 = clock();
    writeLog("BER calculations are done");
    if(results.err > 0)
    {
        diff = true;
    }
    file1.close();
    file2.close();
    return results; //return structure with all results
}

// from project example
void printDiffs(berResults results)
{
    std::stringstream message;
    message << "Results are: " << std::endl;
    message << "BER: " << results.ber << std::endl;
    message << "Tot: " << results.tot << std::endl;
    message << "Err: " << results.err << std::endl;
    message << "Calc time: " << ((float)results.t2 - results.t1) / CLOCKS_PER_SEC << " sec " << std::endl;
    writeLog(message.str());
}

// function based on project example, create desired bins, if the provided value is other than 0x55
// and file size is set to 100 B then first 5 chars are set to 0x56, so 10 bits are different than when u would insert just 0x55 values  
void createFile1(const std::string name, const int count, char value)
{
    char value1 = 0x55;
    bool dif = false;
    if (value != 0x55 && count == 100)
    {
        value = 0x56;
        dif = true;
        value ^= value1;
        value1 ^= value;
        value ^= value1;
    }
    std::fstream f;
    f.open(name.c_str(), std::ios::binary | std::ios::out);
    for (int i = 0; i < count; i++)
    {
        if(dif && i < 5)
        {
            f.write((char*)&value1,1);
        }
        else
        {
            f.write((char*)&value,1);
        }
    }
    f.close();
}