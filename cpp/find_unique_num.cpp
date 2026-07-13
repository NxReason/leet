#include <iostream>
#include <unordered_map>
#include <vector>

float find_uniq(const std::vector<float> &v) {
  std::unordered_map<float, int> uniqs{};

  for (const auto& value : v) {
    uniqs[value] = uniqs[value] + 1;
  }

  for (const auto& [key, value] : uniqs) {
    if (value == 1) return key;
  }

  return 0.0f;
}

int main() {
  std::cout << find_uniq(std::vector<float>{1, 1, 1, 2, 1, 1}) << '\n';
  std::cout << find_uniq(std::vector<float>{0, 0, 0.55, 0, 0}) << '\n';

  return 0;
}