#include <iostream>

using namespace std;

/*
decision tree bottom up
dynamic programming memoization
fibonacci sequence
*/

int climbStairs(int n)
{
  int one = 1;
  int two = 1;
  int tmp;
  int i;
  for (i=0; i<n-1; i++)
  {
    tmp = one;
    one = one + two;
    two = tmp;
  }
  return one;
}

int main(int argc, char *argv[])
{
  // expected: 5
  int c = climbStairs(4);
  std::cout << c << std::endl;
}








// end
