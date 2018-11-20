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
//https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/when-the-integers-got-upset/
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli p[20];
lli a[20];
lli dp[1 << 13][13][13];
int n;
int maxi = 0;
#define infi 100000000000000
int bc(int mask) {
  int ind = 0;
  for (int i = 0; i <= 16; i++) {
    if (mask & (1 << i)) ind++;
  }
  return ind;
}
lli solve(int mask, int id1, int id2) {
  if (mask == maxi) return 0;
  if (dp[mask][id1][id2] != -1) {
    return dp[mask][id1][id2];
  } else {
    lli ret = infi;
    for (int i = 1; i <= n; i++) {
      if (!(mask & (1 << i))) {
        if (id1 != 0 && id2 != 0) {
          int index = bc(mask);
          lli t1 = a[i] ^ a[id2];
          t1 = t1 ^ a[id1];
          lli val = (t1) * p[index];
          ret = min(ret, val + solve((mask | (1 << i)), id2, i));
        } else {
          ret = min(ret, solve(mask | (1 << i), id2, i));
        }
      }
    }
    dp[mask][id1][id2] = ret;
    return ret;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(dp, -1, sizeof dp);

    cin >> n;
    maxi = 0;
    for (int i = 1; i <= n; i++) {
      maxi = maxi | (1 << i);
      cin >> a[i];
    }
    for (int j = 1; j <= n; j++) {
      cin >> p[j];
    }
    long long int ans = solve(0, 0, 0);
    cout << ans << endl;
  }
}
