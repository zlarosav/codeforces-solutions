#include <bits/stdc++.h>

#ifdef LOCAL
#include "../debug.cpp"
#else
#define dbg(...)
#endif

#define ll long long

using namespace std;

void solve() {
  ll a, b; cin >> a >> b;
  if (a == b) {
    cout << a << endl;
    return;
  }
  string strA = to_string(a), strB = to_string(b);
  int n = strB.size();
  while (strA.size() < n) strA = '0' + strA;
  
  string prefix = "";
  int i = 1;
  while (i <= n && strA[i - 1] == strB[i - 1]) {
    prefix += strA[i - 1];
    i++;
  }
  
  string subA = strA.substr(i - 1, min(2, n - i + 1));
  string subB = strB.substr(i - 1, min(2, n - i + 1));
  int subAnum = stoi(subA);
  int subBnum = stoi(subB);

  int mxLex = subAnum;
  int mxProduct = 1;

  int currNum = subAnum;
  while (currNum <= subBnum) {
    int currProduct = 1;
    string currNumStr = to_string(currNum);
    for (int j = 0; j < currNumStr.size(); j++) currProduct *= (currNumStr[j] - '0'); 
    if (currProduct >= mxProduct) {
      mxProduct = currProduct;
      mxLex = currNum;
    }
    currNum++;
  }
  
  cout << prefix << mxLex;
  for (int j = i + 1; j < n; j++) cout << 9;
  //dbg(mxLex);
  //dbg(subA, subB);
  //dbg(prefix);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}

// 