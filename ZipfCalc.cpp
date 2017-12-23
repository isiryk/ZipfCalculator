#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

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
      count++;
    }
    std::cout << "Total words: " << count << "\n";
  }
}

int main(int argc, char* argv[]){
  if(argc > 1){
    std::string filename = argv[1];
    std::cout << "This is the filename: " << filename << "\n";
    readFile(filename);
    return 0;
  } else {
    std::cout << "Please include filename as an argument" << "\n";
    return 0;
  }
}
