#include <iostream>
#include <string>
#include <unordered_map>

const std::unordered_map<char, int> RIMap {
  { 'I', 1 },
  { 'V', 5 },
  { 'X', 10 },
  { 'L', 50 },
  { 'C', 100 },
  { 'D', 500 },
  { 'M', 1000 },
};

bool isPrefix(const std::string& s, size_t idx) {
  if (idx >= s.size() - 1) return false;

  return RIMap.at(s[idx]) < RIMap.at(s[idx + 1]);
}

int romanToInt(std::string s) {
  int num = 0;
  for (size_t i = 0; i < s.size(); i++) {
    char c = s[i];
    int value = RIMap.at(c);
    num += isPrefix(s, i) ? -value : value;
  }
  return num;
}

void runRomanToInt() {
  std::cout << romanToInt("III") << '\n';
  std::cout << romanToInt("LVIII") << '\n';
  std::cout << romanToInt("MCMXCIV") << '\n';
}

// parentheses matcher
#include <stack>
#include <unordered_map>

bool isValidParenthesis(const std::string& s) {
  std::stack<char> stack;
  static const std::unordered_map<char, char> pairs {
    {'(', ')'},
    {'[', ']'},
    {'{', '}'},
  };

  for (const char c : s) {
    if (c == '(' || c == '[' || c == '{')
      stack.push(c);
    else {
      if (stack.empty()) return false;
      if (c != pairs.at(stack.top())) return false;
      stack.pop();
    }
  }

  return stack.empty();
}

void runParenthesisMatcher() {
  std::cout << isValidParenthesis("()") << '\n';
  std::cout << isValidParenthesis("()[]{}") << '\n';
  std::cout << isValidParenthesis("(]") << '\n';
  std::cout << isValidParenthesis("([])") << '\n';
  std::cout << isValidParenthesis("([)]") << '\n';
  std::cout << isValidParenthesis(")]") << '\n';
}

int main() {
  runParenthesisMatcher();
  return 0;
}
