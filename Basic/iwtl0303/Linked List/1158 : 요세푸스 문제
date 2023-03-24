#include <bits/stdc++.h>
using namespace std;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k, idx = 0;
  int arr[5001] = {
      0,
  };
  cin >> n >> k;
  list<int> L;
  for (int i = 1; i <= n; i++)
    L.push_back(i);
  auto p = L.begin();
  while (1)
  {
    for (int i = 0; i < k; i++)
    {
      if (p != L.end())
        p++;
      else
      {
        p = L.begin();
        p++;
      }
    }
    p--;
    arr[idx] = *p;
    p = L.erase(p);
    idx++;
    if (L.begin() == L.end())
      break;
  }
  cout << "<";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i];
    if (i != n - 1)
      cout << ", ";
    else
      cout << ">";
  }
  return 0;
}
