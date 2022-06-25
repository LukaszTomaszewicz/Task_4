#include "functions.hpp"

int main(int argc, char * argv[])
{
    // createFile1("0x55_100BFile.bin",100,0x55);

    if(argc >3 && argc < 2)
    {
        openLog();
        writeLog("Provided wrong number of args!");
        closeLog();
        exit(1);
    }
    readFile(argv[1], argv[2]);
    
    return 0;
}
