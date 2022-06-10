// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
#include  <string>

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::ifstream file(filename);
  if (!file) {
    std::cout << "Error!" << std::endl;
    throw std::string("Can not open file!");
  }
  std::string word = "";
  while (!file.eof()) {
    char chr = file.get();
    int ascii = chr;
    if ((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122)) {
      word += tolower(ascii);
    } else {
      if (word != "") {
        tree.add(word);
      }
    }
  }
  file.close();
  return tree;
}
