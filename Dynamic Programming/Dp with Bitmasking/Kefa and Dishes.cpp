/********************************************************************************
*********************************************************************************   						 
**								Deepak gautam								   **
**			codeforces - gautam27 		codechef - algorithmist2			   **
**			Topcoder- gautam_27 		Spoj - nexus_d						   **
**			hackerearth- https://www.hackerearth.com/@deepak.gautam.127648 	   **
**			hackerrank - https://www.hackerrank.com/deepakgautam2701		   **
**			linkedin-https://www.linkedin.com/in/deepak-gautam-a924908a/       **	
**			git -https://github.com/deepakgautam							   **	
*********************************************************************************	
*********************************************************************************/

//https://codeforces.com/problemset/problem/580/D
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli dp[22][1 << 20];
lli val[22];
int n, m, k;
lli has[22][22];
int bc(int num) {
  return __builtin_popcountll(num);
}
lli solve(int mask, int last) {
  if (dp[last][mask] != -1)
    return dp[last][mask];
  else if (bc(mask) >= m) {
    return 0;
  } else {
    lli ret = -1;
    for (int i = 0; i < n; i++) {
      if (!(mask & (1 << i))) {
        ret = max(ret, solve(mask | (1 << i), i) + has[last][i] + val[i]);
      }
    }
    dp[last][mask] = ret;
    return ret;
  }
}
int main() {
  cin >> n >> m >> k;
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }
  for (int i = 0; i < k; i++) {
    lli a, b, c;
    cin >> a >> b >> c;
    has[a - 1][b - 1] = c; // last cur cost
  }
  if (m == 0) {
    cout << "0" << endl;
    return 0;
  }
  lli ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, solve(0 | (1 << i), i) + val[i]);
  }
  cout << ans << endl;
}
