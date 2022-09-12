# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
  bool carPooling(vector<vector<int> > trips, int capacity) {
    int delta[1001];
    memset(delta, 0, 1001*sizeof(int));
    int curr = 0;

    for (vector<vector<int> > ::iterator it=trips.begin(); it != trips.end(); it++) {
      int num = (*it)[0];
      int start = (*it)[1];
      int end = (*it)[2];

      delta[start] += num;
      delta[end] -= num;
    }

    for (int t=0; t<1001; t++) {
      curr += delta[t];
      if (curr > capacity)
        return false;
    }
  return true;
  }

  static bool comp(vector<int> a, vector<int> b) {
    return a[1] < b[1];
  }

  bool carPooling1(vector<vector<int> > trips, int capacity) {
    vector<vector<int> > minHeap;
    int curr = 0;

    sort(trips.begin(), trips.end(), comp);

    for (vector<vector<int> > :: iterator it=trips.begin(); it!=trips.end(); it++) {
      int num = (*it)[0];
      int start = (*it)[1];
      int end = (*it)[2];

      // base case
      while (minHeap.size()>0 && minHeap[0][0]<=start)
      {
        curr -= minHeap[0][1];
        minHeap.erase(minHeap.begin());
      }
      curr += num;
      if (curr > capacity)
      {
        cout << curr << endl;
        return false;
      }
      minHeap.push_back(vector<int> {end, num});
      // [(5, 2), (7, 5)] [(7, 3), (7, 1)]
    }
    return true;
  }

  bool carPooling2(vector<vector<int> > trips, int capacity) {
    int end = 0;
    for (int n=0; n<trips.size(); n++)
    {
      if (trips[n][2] > end)
      {
        end = trips[n][2];
      }
    }

    for (int j=0; j<end; j++)
    {
      int curr = 0;
      for (int i=0; i<trips.size(); i++)
      {
        if (j>=trips[i][1] && j<=trips[i][2])
        {
          curr += trips[i][0];
          if (curr > capacity)
            return false;
        }
      }
    }
    return true;
  }
};


int main(int argc, char* argv[]) {
  vector<int> trip1{2, 1, 5};
  vector<int> trip2{3, 3, 7};
  vector<int> trip3{1, 6, 8};
  vector<vector<int> > trips{trip1, trip2, trip3};
  int capacity = 5;
  Solution sol;
  bool res = sol.carPooling(trips, capacity);
  bool res1 = sol.carPooling1(trips, capacity);
  bool res2 = sol.carPooling2(trips, capacity);

  cout << res << endl;
  cout << res1 << endl;
  cout << res2 << endl;
}








// end
