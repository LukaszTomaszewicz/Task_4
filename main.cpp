int main(int argc, char * argv[])
{
    if(argc >3 && argc < 2)
    {
        cerr << " Provided wrong number of args! " << endl;
        exit(1);
    }
    readFile(argv[1], argv[2]);
    
    return 0;
}
