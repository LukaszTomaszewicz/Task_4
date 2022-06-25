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
      writeLog("Processing...");
      if(diff)
      {
          // function to print ber
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
