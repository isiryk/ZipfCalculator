#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>

  struct data {
    std::string readWord;
    int countWord;
    bool operator() (data i, data j) {return (i.countWord>j.countWord);}
  } data2;

  std::vector<data> vec;

  void counter(std::string word){
    bool state = false;
    int wordVal = 0;
    for(int ct = 0; ct < vec.size(); ct++){
      if(vec[ct].readWord == word){
        wordVal = ct;
        state = true;
        break;
      }else{
        ct++;
      }
    }
    if(state == true){
      vec[wordVal].countWord++;
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
      inFile.close();
    } else {
      std::cout << "Success" << "\n";
      std::string word;
      int count = 0;
      while(inFile >> word){
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        counter(word);
      }
      inFile.close();
    }
  }

  int main(int argc, char* argv[]){
    if(argc > 1){
      std::string filename = argv[1];
      std::cout << "This is the filename: " << filename << "\n";
      readFile(filename);
      std::sort(vec.begin(), vec.end(), data2);
      std::ofstream printOut;
      printOut.open("completed-"+filename);
      printOut << "Total Words: " << vec.size() << "\n";
      for(int ct = 0; ct < vec.size(); ct++){
        printOut << "------------------------\n" << "Word: " << vec[ct].readWord << "\nCount: " << vec[ct].countWord << "\n" << "------------------------\n";
      }
      printOut.close();
      return 0;
    } else {
      std::cout << "Please include filename as an argument" << "\n";
      return 0;
    }
  }
