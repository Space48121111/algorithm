#include <iostream>
#include <vector>

using namespace std;

// [[num, start, end], [num, start, end]]

// brutal force: curr iterate over each (start[i] to end[j]) O(n^2)

bool carPooling(vector<vector<int> > &trips, int capacity) {
  int end = 0;
  for(int j=0; j<trips.size(); j++)
  {
    if (trips[j][2] > end) {
      end = trips[j][2];
    }
  }
  for (int j=1; j<=end; j++)
  {
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

// minheap: sort, put [end, num], pop out the first one if end <= start O(nlogn)
bool comp(vector<int> i, vector<int> j)
{
  return i[1] < j[1];
}

bool carPooling1(vector<vector<int> > &trips, int capacity) {
  sort(trips.begin(), trips.end(), comp);
  vector<vector<int> > minHeap;
  int curr = 0;

  for (vector<vector<int> >::iterator it=trips.begin(); it!=trips.end(); it++)
  {
    int num = (*it)[0];
    int start = (*it)[1];
    int end = (*it)[2];


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

// delta: create 1001 trips array with the delta num and iterate 1001 times

bool carPooling2(vector<vector<int> > &trips, int capacity) {
  int delta[1001];
  memset(delta, 0, 1001*sizeof(int));
  int curr = 0;

  for (vector<vector<int> >::iterator it=trips.begin(); it!=trips.end(); it++)
  {
    int num = (*it)[0];
    int start = (*it)[1];
    int end = (*it)[2];

    delta[start] += num;
    delta[end] -= num;
  }

  for (int i=0; i<1001; i++)
  {
    curr += delta[i];
    if (curr > capacity)
      return false;
  }
  return true;
}



int main(int argc, char* argv[]) {
  vector<int> trip1{2, 1, 5};
  vector<int> trip2{3, 3, 7};
  vector<vector<int> > trips{trip1, trip2};
  int capacity = 5;
  int res = carPooling(trips, capacity);
  int res1 = carPooling1(trips, capacity);
  int res2 = carPooling2(trips, capacity);

  cout << res << endl;
  cout << res1 << endl;
  cout << res2 << endl;

}








// end
