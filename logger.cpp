#include "functions.hpp"

fstream f;

// from example project
void writeLog(string log)
{
	
  std::string ss;
  time_t currentTime = time(NULL);
  std::string txttime = (std::string)asctime(localtime(&currentTime));
  txttime = txttime.substr(0, txttime.length() - 1);
  ss = (std::string)"T: " + txttime + " M: " + log + "\n";
  f << ss.c_str();
  f.flush();
  std::cout << ss.c_str();
  std::cout.flush();
}

void openLog(string filename)
{
  f.open(filename.c_str(), std::ios_base::app);
  f.open("log.log", std::fstream::out);
  if(!f.is_open())
  {
      cerr << "Unable to open log file\n";
  }
}

void closeLog()
{
  if(f.is_open())
  {
      writeLog("Closing log file\n*************************\n\n");
      f.close();
  }
  else
  {
      cerr << "File is already closed";
  }
}
