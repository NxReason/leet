#include <iostream>
#include <vector>
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

// index of first occurence
int strStr(std::string haystack, std::string needle) {
  return haystack.find(needle);
}

void runStrStr() {
  std::cout << strStr("sadbuthat", "but") << '\n';
  std::cout << strStr("sadbuthat", "sad") << '\n';
  std::cout << strStr("leetcode", "leeto") << '\n';
}

// add binary
std::string addBinary(const std::string& a, const std::string& b) {
  int len = std::max(a.size(), b.size());
  int aOffset = len - a.size();
  int bOffset = len - b.size();

  std::string out ( len + 1, '0' );
  int carry = 0;
  for (int i = len - 1; i >= 0; --i) {
    auto ax = i - aOffset;
    auto bx = i - bOffset;

    int an = ax >= 0 ? (a[ax] - '0') : 0;
    int bn = bx >= 0 ? (b[bx] - '0') : 0;

    int sum = an + bn + carry;
    switch (sum) {
      case 0:
        out[i + 1] = '0';
        carry = 0;
        break;
      case 1:
        out[i + 1] = '1';
        carry = 0;
        break;
      case 2:
        out[i + 1] = '0';
        carry = 1;
        break;
      case 3:
        out[i + 1] = '1';
        carry = 1;
        break;
    }
  }
  if (carry == 1) {
    out[0] = '1';
  }
  else {
    out.erase(0, 1);
  }
  return out;
}

void runAddBinary() {
  std::cout << addBinary("11", "1") << std::endl;
  std::cout << addBinary("1010", "1011") << std::endl;
}

int main() {
  runAddBinary();
  return 0;
}
