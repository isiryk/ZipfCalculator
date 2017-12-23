#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>

  struct data {
    std::string readWord;
    int countWord;
    // data(std::string n, int c) : readWord(n), countWord(c) {}
  };

  std::vector<data> vec;

  void counter(std::string word){
    bool state = false;
    auto exists = [&](const std::string &s){
      state = std::find_if(begin(vec), end(vec), [&](const data &f){return f.readWord == word;}) != end(vec);
      std::cout << state;
    };
    if(state == true){
      int k = 0;
      while(vec[k].readWord != word){
        k++;
      }
      std::cout << vec[k].readWord;
      vec[k].countWord++;
      state = false;
    } else {
      data val;
      val.readWord = word;
      val.countWord = 1;
      vec.push_back(val);
    }
  }

  void readFile(std::string filename){
    std::ifstream inFile;
    inFile.open(filename.c_str());
    if(!inFile){
      std::cout << "Please enter a valid filename" << "\n";
    } else {
      std::cout << "Success" << "\n";
      std::string word;
      int count = 0;
      while(inFile >> word){
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        counter(word);
      }
    }
  }

  int main(int argc, char* argv[]){
    if(argc > 1){
      std::string filename = argv[1];
      std::cout << "This is the filename: " << filename << "\n";
      readFile(filename);
      // for(int ct = 0; ct < vec.size(); ct++){
      //   std::cout << "ReadWord: " << vec[ct].readWord << "\n";
      //   std::cout << "Count: " << vec[ct].countWord << "\n";
      // }
      return 0;
    } else {
      std::cout << "Please include filename as an argument" << "\n";
      return 0;
    }
  }
