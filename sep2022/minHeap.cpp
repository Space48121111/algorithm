# include <iostream>
# include <vector>

using namespace std;

/*
[num, start, end]
[[2,1,5],[3,3,7]]
4 false
5 true
sort ascending
for n < m in range(len(trips))
if trip[n].end > trip[m].start
  trip[n].num + trip[m].num > capacity return false
*/

class Solution {
public:
  bool carPooling(vector<vector<int> > &trips, int capacity) {
    // static array
    int deltaNum[1001];
    // memory memset(ptr, val, num)
    // bytes int sizeof 4
    // memset (str,'-',6); sizeof 1
    memset(deltaNum, 0, 1001*sizeof(int));
    // cout << sizeof(int) << endl;

    for (vector<vector<int> >::iterator it=trips.begin(); it != trips.end(); it++)
    {
      int num = (*it)[0];
      int start = (*it)[1];
      int end = (*it)[2];
      // [[2,1,5],[3,3,7]]
      deltaNum[start] += num;
      deltaNum[end] -= num;
    }
    int curr = 0;
    for (int i=0; i<=1000; i++)
    {
      curr += deltaNum[i];
      if (curr > capacity)
      {
        // cout << curr << " " << i << endl;
        return false;
      }
    }
    return true;
  }

  static bool comp(vector<int> i1, vector<int> i2) {
    return i1[1] < i2[1];
  }
  bool carPooling1(vector<vector<int> > &trips, int capacity) {
    sort(trips.begin(), trips.end(), comp);
    // for (auto i : trips)
    // {
    //   cout << i[1] << endl;
    // }

    vector<vector<int> > minHeap;
    int curr = 0;
    for (vector<vector<int> >::iterator it=trips.begin(); it != trips.end(); it++)
    {
      int num = (*it)[0];
      int start = (*it)[1];
      int end = (*it)[2];

      // minHeap[end, num]
      // keep adding num, as soon as the trip ends, drop off num
      while (minHeap.size()>0 && minHeap[0][0] <= start)
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

  // & reference, similiar to pointer, not a copy
  bool carPooling2(vector<vector<int> > &trips, int capacity) {
    // find the largest end stop
    int end = 0;
    for (int i=0; i<trips.size(); i++)
    {
      if (trips[i][2] > end)
      {
        end = trips[i][2];
      }
    }
    for (int j=0; j<end; j++)
    {
      // set to 0 for each j
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
  int capacity = 4;
  Solution sol;
  bool res = sol.carPooling(trips, capacity);
  bool res1 = sol.carPooling1(trips, capacity);
  bool res2= sol.carPooling2(trips, capacity);
  cout << (res ? "True": "False") << endl;
  cout << (res1 ? "True": "False") << endl;
  cout << (res2 ? "True": "False") << endl;


}



// end
