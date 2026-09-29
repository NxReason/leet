#include <cstddef>
#include <iostream>
#include <string>

using std::string;

bool isPalindrome(const string& str) {
  // should empty string be true or false?
  if (str.length() == 0) return false;

  int begin = 0, end = str.length() - 1;
  while (begin <= end) {
    if (str[begin] != str[end]) return false;
    begin++;
    end--;
  }
  return true;
}

string longestPalindromeSlow(const string& s) {
  if (s.length() == 0) return "";
  size_t longest_begin = 0;
  size_t longest_length = 1;
  for (size_t begin = 0; begin < s.length() - 1; begin++) {
    for (size_t end = s.length(); end > begin + 1; end--) {
      size_t current_length = end - begin;
      // break inner loop if remaining string shorter than current longest
      if (current_length < longest_length) break;

      if (isPalindrome(s.substr(begin, current_length))) {
        longest_begin = begin;
        longest_length = current_length;
      }
    }
  }
  return s.substr(longest_begin, longest_length);
}

string longestPalindrome(const string& s) {
  int longest_start = 0;
  int longest_length = 1;
  int len = static_cast<int>(s.length());
  // check odd length palindromes
  for (int i = 1; i < len; i++) {
    int start = i - 1;
    int end = i + 1;
    bool isValidRange = (start >= 0) && (end < len);
    while (isValidRange) {
      if (s[start] != s[end]) break;
      start--;
      end++;
      isValidRange = (start >= 0) && (end < len);
    }

    int current_length = (--end) - (++start) + 1;
    if (current_length > longest_length) {
      longest_start = start;
      longest_length = current_length;
    }
  }

  // check even length palindromes
  for (int i = 0; i < len - 1; i++) {
    if (s[i] != s[i + 1]) continue;

    // if longest palindrome still length=1
    // set to first found couple 
    // otherwise have to change reverting start/end logic later
    if (longest_length == 1) {
      longest_start = i;
      longest_length = 2;
    }

    int start = i - 1;
    int end = i + 2;
    bool isValidRange = (start >= 0) && (end < len);
    while (isValidRange) {
      if (s[start] != s[end]) break;
      start--;
      end++;
      isValidRange = (start >= 0) && (end < len);
    }

    int current_length = (--end) - (++start) + 1;
    if (current_length > longest_length) {
      longest_start = start;
      longest_length = current_length;
    }
  }

  return s.substr(longest_start, longest_length);
}


int main() {
  std::cout << longestPalindrome("babad") << std::endl;
  std::cout << longestPalindrome("cbbd") << std::endl;
  std::cout << longestPalindrome("bb") << std::endl;
  std::cout << longestPalindrome("abaab") << std::endl;

  return 0;
}