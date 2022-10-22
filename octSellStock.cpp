#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int> prices) {
  int maxP = 0;
  int l = 0;
  int r = 1;
  if (!prices.size())
    return 0;
  while (r < prices.size())
  {
    int p = prices[r] - prices[l];
    if (p > 0)
    {
      maxP = max(p, maxP);
    }
    else
    {
      l = r;
    }
    r ++;
  }
  return maxP;
}

int main(int argc, char const *argv[]) {
  /* code */
  //  -std=c++11
  vector<int> v = {7,1,5,3,6,4};
  int x = maxProfit(v);
  cout << x << endl;

  // return 0;
}






// end
