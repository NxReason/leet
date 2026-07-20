#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::string stockSummary(std::vector<std::string>& lstOfArt, std::vector<std::string>& categories) {
  if (lstOfArt.size() == 0 || categories.size() == 0) return "";

  std::vector<int> totals(categories.size());
  for (size_t i = 0; i < totals.size(); i ++) {
    totals[i] = 0;
  }

  for (const auto& art : lstOfArt) {
    auto pos = art.find(' ') + 1;
    if (pos == std::string::npos) continue;

    int current = std::stoi(art.substr(pos));
    std::string category = art[0];

    auto catPos = std::find(categories.begin(), categories.end(), category);    
    if (catPos == categories.end()) continue;

    totals[catPos] += current;
  }

  std::ostringstream builder{""};
  for (size_t i = 0; i < categories.size(); i++) {
    builder << " - (" + categories[i] + " : " + std::to_string(totals[i]) + ")";
  }

  return builder.str();
}


int main() {

  return 0;
}