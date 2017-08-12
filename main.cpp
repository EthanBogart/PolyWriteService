#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "diff.h"

int main(int argc, char *argv[]) {
  if(argc != 3) {
    std::cout << "Wrong number of inputs\n";
    std::exit(0);
  }

  std::ifstream file1(argv[1]);
  std::ifstream file2(argv[2]);

  if(!file1.is_open() || !file2.is_open()) {
    std::cout << "File open error\n";
    std::exit(1);
  }
  
  std::vector<char> string1;
  std::vector<char> string2;
  std::vector<char> same;

  char ch;
  while(file1 >> std::noskipws >> ch) {
    string1.push_back(ch);
  }
  while(file2 >> std::noskipws >> ch) {
    string2.push_back(ch);
  }
  
  std::vector<char> answer = myers(string1, string2, 0, 0);

  std::cout << "length: " << answer.size() << std::endl;

  for(int i=0; i<answer.size(); i++) {
    std::cout << answer[i];
  }
}
