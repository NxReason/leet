#include <iostream>
#include <string>

int largest_five_digits(const std::string& digits) {
  int max = 0;
  for (int i = 0; i + 4 < digits.length(); i++) {
    const std::string slice = digits.substr(i, 5);
    const int value = std::stoi(slice);
    if (value > max) max = value;
  }
  return max;
}

void do_test(const std::string& input, int result) {
  auto got = largest_five_digits(input);
  if (got == result) {
    std::cout << "[success]: for " << input << std::endl;
  }
  else {
    std::cout << "[failure]: for " << input << ", got " << got << ", expected " << result << std::endl;
  }
}

int main() {
  do_test("283910", 83910);
  do_test("1234567890", 67890);
  do_test("731674765", 74765);

  return 0;
}