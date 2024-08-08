#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <time.h>

int main() {

  //Load in the list of languages
  std::ifstream choiceFile;
  choiceFile.open("choices.txt");
  
  std::string line;
  std::vector<std::string> languages;

  while(std::getline(choiceFile, line)){ 
    languages.push_back(line);
  }  

  //Closing the file
  choiceFile.close();

  //Generate a random seed
  std::srand(time(NULL));

  //Generate a random item from the list
  int chosenLanguage = std::rand() % languages.size();

  //Show that item to the user
  std::cout << languages[chosenLanguage] << "\n";

  return 0;
}
