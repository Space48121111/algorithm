/*
g++ -std=c++11 palindrome.cpp -o p
 l
abba
  r

  l
abcba
  r
*/
#include <iostream>
#include <string>

using namespace std;


string longestPalindrome(string s) {
  int bestLength = 0;
  int l;
  int r;
  int length;
  string res;

  for (int i=0; i<s.length(); i++) {
    for (int j=0; j<2; j++) {
      l = i;
      r = i+j;
      while (l>=0 && r<s.length() && s[l] == s[r]) {
        length = r-l+1;
        if (length > bestLength) {
          bestLength = length;
          res = s.substr(l, bestLength);
          std::cout << res << "\n";
        }
        l -= 1;
        r += 1;
      }
    }
  }
  return res;
}

// arg count arg vector
int main(int argc, char *argv[]) {
  if (argc >= 2) {
    //  ./p baab
    string res = longestPalindrome(argv[1]);
    std::cout << "Final res " << res << std::endl;
  } else {
    std::cout << "+argv[1] Add an argument in the end." << std::endl;
  }

}










// end
