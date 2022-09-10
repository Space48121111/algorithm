# include<iostream>
# include<vector>

using namespace std;

class Solution {
public:
  bool carPooling(vector<vector<int> > &trips, int capacity) {
    int delta[1001];
    memset(delta, 0, 1001*sizeof(int));

    for (vector<vector<int> >::iterator it=trips.begin(); it != trips.end(); it++)
    {
      int num = (*it) [0];
      int start = (*it)[1];
      int end = (*it)[2];

      delta[start] += num;
      delta[end] -= num;
    }

    int curr = 0;
    for (int t=0; t<1001; t++)
    {
      curr += delta[t];
      if (curr > capacity)
        return false;
    }
    return true;
  }

  static bool comp(vector<int> i1, vector<int> i2) {
    return i1[1] < i2[1];
  }
  bool carPooling1(vector<vector<int> > &trips, int capacity) {
    sort(trips.begin(), trips.end(), comp);
    vector<vector<int> > minHeap;
    int curr = 0;
    for (vector<vector<int> >::iterator it=trips.begin(); it != trips.end(); it++)
    {
      int num = (*it) [0];
      int start = (*it)[1];
      int end = (*it)[2];

      while (minHeap.size() > 0 && minHeap[0][0] <= start)
      {
        curr -= minHeap[0][1];
        minHeap.erase(minHeap.begin());
      }
      curr += num;
      if (curr > capacity)
        return false;
      minHeap.push_back(vector<int> {end, num});
  }
  return true;
}

bool carPooling2(vector<vector<int> > &trips, int capacity) {
  int end=0;
  for (int j=0; j<trips.size(); j++)
  {
    if (trips[j][2] > end)
    {
      end = trips[j][2];
    }
  }
  for (int j=0; j<end; j++)
  {
    int curr = 0;
    for (int i=0; i<trips.size(); i++)
    {
      if (j >= trips[i][1] && j <= trips[i][2])
      {
        curr += trips[i][0];
      }
      if (curr > capacity)
        return false;
    }

  }
  return true;

}

};

int main(int argc, char* argv[]) {
  vector<int> trips1{2,1,5};
  vector<int> trips2{3,3,7};
  vector<vector<int> > trips{trips1, trips2};
  int cap = 5;
  Solution sol;
  bool res = sol.carPooling(trips, cap);
  bool res1 = sol.carPooling1(trips, cap);
  bool res2 = sol.carPooling2(trips, cap);
  cout << (res ? "True": "False") << endl;
  cout << (res1 ? "True": "False") << endl;
  cout << (res2 ? "True": "False") << endl;

}







// end
