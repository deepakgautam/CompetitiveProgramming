/*
http://lightoj.com/volume_showproblem.php?problem=1194&language=english&type=pdf
tutorial -> http://gautambitmaskdp.blogspot.com/2016/04/1194-colored-t-shirts-dpbitmasking.html
*/
/*
Deepak gautam - 
codeforces - gautam27
codechef - algorithmist2
Topcoder- gautam_27 
Spoj - nexus_d
hackerearth- https://www.hackerearth.com/@deepak.gautam.127648 
hackerrank - https://www.hackerrank.com/deepakgautam2701
*/
#include<bits/stdc++.h >
using namespace std;
typedef long long int lli;
int before[16][16];
lli dp[1 << 17];
int pre[16];
int n, m;
int maxi = 0;
lli solve(int mask) {
  if (mask == maxi) {
    return 0;
  } else if (dp[mask] != -1) {
    return dp[mask];
  } else {
    lli ret = 10000000000000000;
    for (int i = 0; i < m; i++) {
      if (!(mask & (1 << i))) {
        lli swaps = 0;
        for (int j = 0; j < m; j++) {
          if (!(mask & (1 << j)) && i != j)
          {
            swaps += before[i][j];
          }

        }
        ret = min(ret, solve(mask | (1 << i)) + swaps);
      }

    }
    dp[mask] = ret;
    return ret;
  }
}
int main() {
  int n;
  int t;
  cin >> t;
  int k = 0;
  while (t--) {
    cout << "Case " << ++k << ": ";
    maxi = 0;
    memset(dp, -1, sizeof dp);
    memset(before, 0, sizeof before);
    memset(pre, 0, sizeof pre);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      x--;

      for (int j = 0; j < m; j++) {
        maxi = maxi | (1 << j);
        before[x][j] += pre[j];
      }
      pre[x]++;
    }
    lli ans = 10000000000000000;
    for (int i = 0; i < m; i++) {
      lli swaps = 0;
      for (int j = 0; j < m; j++) // swaps needed to make ith number as the first 
      {
        if (j != i) {
          swaps += before[i][j];
        }
      }
      ans = min(ans, solve(0 | (1 << i)) + swaps);
    }
    cout << ans << endl;
  }
}
