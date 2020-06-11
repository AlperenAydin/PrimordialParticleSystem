#pragma once

#include <algorithm>
#include <sstream>
#include <string>

template <typename T>
void extractOption(char **begin, char**end, std::string option, T *value) {
  auto* option_val = std::find(begin, end, option);
  if( option_val == end || option_val +1 ==end)
    return;
  option_val += 1;
  std::stringstream ss;
  ss << *option_val; 
  ss >> *value;
}

class Config {
public:
  Config(int argc, char *argv[])
  {
    char** begin = argv;
    char** end = argv+argc;

    if(argc >1 && strcmp(argv[1], "--help") == 0)
      {
        help = true; 
        helpText();
        return;
      }
    
    extractOption(begin, end, "--width", &width);
    extractOption(begin, end, "--height", &height);
    extractOption(begin, end, "-W", &width);
    extractOption(begin, end, "-H", &height);
    
    extractOption(begin, end, "-N", &N);
    extractOption(begin, end, "-V", &v);

    extractOption(begin, end, "--alpha", &alpha);
    extractOption(begin, end, "-A", &alpha);

    extractOption(begin, end, "--alpha", &alpha);
    extractOption(begin, end, "-A", &alpha);

    extractOption(begin, end, "--beta", &beta);
    extractOption(begin, end, "-B", &beta);

    extractOption(begin, end, "--radius", &radius);
    extractOption(begin, end, "-R", &radius);
  }

  void helpText()
  {
    std::cout << "Default parameters:" << std::endl;
    showConfig();
  }
  void showConfig()
  {
    std::cout << "width: " << width
              << ", height: " << height
              << ", N: " << N
              << ", v: " << v
              << ", alpha: " << alpha
              << ", beta: " << beta
              << ", radius: " << radius
              << std::endl;
  }

  bool help = false;
  
  int width = 1000;
  int height = 1000; 
  
  int N = 800;
  float v = 6;
  float alpha = 120;
  float beta  = -6;
  float radius = 70;
};
