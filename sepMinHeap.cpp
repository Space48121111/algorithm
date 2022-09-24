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

  // delta: create 1001 trips array with the delta num and iterate 1001 times

  bool carPooling(vector<vector<int> > &trips, int capacity) {
    // static array
    int delta[1001];
    // memory memset(ptr, val, num)
    // bytes int sizeof 4
    // memset (str,'-',6); sizeof 1
    memset(delta, 0, 1001*sizeof(int));
    // cout << sizeof(int) << endl;

    for (vector<vector<int> >::iterator it=trips.begin(); it != trips.end(); it++)
    {
      int num = (*it)[0];
      int start = (*it)[1];
      int end = (*it)[2];
      // [[2,1,5],[3,3,7]]
      delta[start] += num;
      delta[end] -= num;
    }
    int curr = 0;
    for (int i=0; i<1001; i++)
    {
      curr += delta[i];
      if (curr > capacity)
      {
        cout << curr << " " << i << endl;
        return false;
      }
    }
    return true;
  }

  // minheap: sort, put [end, num], pop out the first one if end <= start O(nlogn)

  static bool comp(vector<int> i, vector<int> j) {
    return i[1] < j[1];
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
      // [[2,1,5],[3,3,7], [1,6,8]]
      // if end > start, keep addint num to curr
      // base case: when end <= start, the trip ends, drop off from curr
      while (minHeap.size()>0 && minHeap[0][0] <= start)
      {
        curr -= minHeap[0][1];
        minHeap.erase(minHeap.begin());
      }

      curr += num;
      if (curr > capacity)
        return false;
      minHeap.push_back(vector<int> {end, num});
      // [(5, 2), (7, 5)] [(7, 3), (8, 1)]

    }
    return true;
  }

  // brutal force: curr iterate over each (start[i] to end[j]) O(n^2)
  // & reference, similiar to pointer, not a copy
  bool carPooling2(vector<vector<int> > &trips, int capacity) {
    // use the largest end stop
    int end = 0;
    for (int j=0; i<trips.size(); i++)
    {
      if (trips[j][2] > end)
      {
        end = trips[j][2];
      }
    }
    for (int j=1; j<=end; j++)
    {
      // reset after each eval
      int curr = 0;
      for (int i=0; i<trips.size(); i++)
      {
        if (j >= trips[i][1] && j <= trips[i][2])
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
