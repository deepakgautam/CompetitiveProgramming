/*
							Deepak gautam
		codeforces - gautam27			codechef - algorithmist2
		Topcoder- gautam_27 			Spoj - nexus_d
		hackerearth- https://www.hackerearth.com/@deepak.gautam.127648 
		hackerrank - https://www.hackerrank.com/deepakgautam2701
*/

// https://vjudge.net/problem/LightOJ-1158
#include<bits/stdc++.h >
using namespace std;
typedef int lli;
int dp[1 << 10][1001];
int n;
int maxi;
int val;
char ms[100];
int factorial[11]={1,1,2,6,24,120,620,4340,34720,312480,3124800};
int has[1000];
lli solve(int mask, int mod) {
  if (mask == maxi) {
    if (mod == 0) return 1;
    else return 0;
  } else if (dp[mask][mod] != -1) {
    return dp[mask][mod];
  } else {

    lli ret = 0;
    for (int i = 0; i < n; i++) {
      if (!(mask & 1 << i)) {
        int num = mod;
        num = num * 10 + (ms[i] - '0');

        ret += solve(mask | (1 << i), num % val);

      }
    }
    dp[mask][mod] = ret;
    return ret;
  }
}
int main() {
  int t;
  scanf("%d", & t);
  int cas = 1;
  while (t--) {
    memset(dp, -1, sizeof dp);
    maxi = 0;

    scanf("%s %d", & ms, & val);
    n = strlen(ms);
    for (int i = 0; i < n; i++) {
      has[ms[i]]++;
    }
    for (int i = 0; i < n; i++) {
      maxi = maxi | (1 << i);
    }
    lli ans = 0;
    ans = solve(0, 0);
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
      ans = ans / factorial[has[ms[i]]];
      has[ms[i]] = 0;
    }
    cout << "case " << cas++ << ": " << ans << endl;
  }
}
