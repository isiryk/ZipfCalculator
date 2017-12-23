#include <iostream>
#include <string>

int main(int argc, char* argv[]){
  if(argc > 1){
    std::string filename = argv[1];
    std::cout << "This is the filename: " << filename << "\n";
    return 0;
  } else {
    std::cout << "Please include filename as an argument" << "\n";
    return 0;
  }
}
