#include "processor.h"
#include "linux_parser.h"
using std::string;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  long idle = LinuxParser::IdleJiffies();
  string temp;
  string line;
  long nonidle = 0;
  std::ifstream stream(LinuxParser::kProcDirectory + LinuxParser::kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> temp;
    for(int i=0; i<8; i++){
      linestream >> temp;
      nonidle += stol(temp);
    }
  }
  float total = idle + nonidle;
  return (total - idle)/total;
}