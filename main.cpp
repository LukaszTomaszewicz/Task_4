#include "functions.hpp"

int main(int argc, char * argv[])
{
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
