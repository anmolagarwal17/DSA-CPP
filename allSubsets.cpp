#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int arr[n];

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int total = (1 << n) - 1; // total subsets will be (2^n) -1
  int temp;

  // subset will have elements in boolean manner
  // 0 0 0
  // 0 0 1
  // 0 1 0
  // 0 1 1
  // 1 0 0
  // 1 0 1
  // 1 1 0
  // 1 1 1
  for (int i = 0; i <= total; i++)
  {
    vector<int> subset;
    temp = i;

    for (int j = 0; j < n; j++)
      if (i & (1 << j)) // taking number if corresponding bit is 1 for the number
        subset.push_back(arr[j]);

    cout << i + 1 << ":\t";

    // printing current subset
    for (int j = 0; j < subset.size(); j++)
      cout << subset[j] << "\t";

    cout << endl;
  }

  return 0;
}