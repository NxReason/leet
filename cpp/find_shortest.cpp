#include <iostream>
#include <string>
#include <sstream>

int find_shortest(std::string str) {
  if (str == "") return 0;

  int result = -1;

  std::stringstream ss(str);
  std::string word;
  while (ss >> word) {
    if (word.size() < result || result == -1) result = word.size();
  }

  return result;
}

int main() {
  std::cout << find_shortest("asdfwqer zxcvqwer asdfxcv wqerert qwer") << '\n';
  return 0;
}