/*
  i
abddbc
  k
  j
*/
#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) {
  int bestLength = 0;
  int length;
  bool success = false;
  string res;

  for (int i=0; i<s.length(); i++) {
    for (int j=i; j<s.length(); j++) {
      success = true;
      length = j-i+1;
      // abc <= return a/the 1st one
      // < return c all the bestLengths
      if (length <= bestLength) {
        continue;
      }
      for (int k=0; k<length; k++) {
        if (s[i+k] != s[j-k]) {
          success = false;
          // optimize break the loop once it finds unmatched
          break;
        }
      }
      if (success) {
        bestLength = length;
        res = s.substr(i, bestLength);
        std::cout << res << "\n";
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
