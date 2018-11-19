/*
							Deepak gautam
		codeforces - gautam27			codechef - algorithmist2
		Topcoder- gautam_27 			Spoj - nexus_d
		hackerearth- https://www.hackerearth.com/@deepak.gautam.127648 
		hackerrank - https://www.hackerrank.com/deepakgautam2701
*/

// https://www.codechef.com/AUG14/problems/TSHIRTS
#include<bits/stdc++.h >
using namespace std;
typedef long long int lli;
lli dp[1 << 12][101];
int id[11][101] = {0};
#define mod 1000000007
int n;
#define iss(line) istringstream iss(line)
int maxi = 0;
lli solve(int mask, int cur) {
  if (mask == maxi) return 1;
  if (cur > 100) {
    return 0;
  }
  if (dp[mask][cur] != -1) return dp[mask][cur];
  else {
    lli ret = 0;
    ret = solve(mask, cur + 1);  // no one is wearing cur 
    for (int i = 0; i < n; i++) // TRYING TO ALLOCATE ITH TSIRT TO ALL POSSIBLE PERSONS
    {
      if (id[i][cur] != 0 && (!(mask & (1 << i)))) {
        ret = (ret + solve(mask | (1 << i), cur + 1)) % mod;
      }
    }
    dp[mask][cur] = ret;
    return ret;
  }
}
int main() {
  int t;
  scanf("%i", & t);
  while (t--) {
    scanf("%i", & n);
    int a[1025][101] = {
      0
    };
    memset(id, 0, sizeof id);
    memset(dp, -1, sizeof dp);
    string line;
    getline(cin, line);
    maxi = 0;
    for (int i = 0; i < n; i++) //  READING INPUR AS A STRING AND EXTRACTING 
    {
      maxi = maxi | (1 << i);
      getline(cin, line);
      iss(line);
      int k1;
      while (iss >> k1) {
        id[i][k1] = 1; // ITH PERSON HAVRE A TSIRT OF TYPE K
      }
    }
    lli ans = 0;
    ans = solve(0, 1);
    printf("%lld\n", ans);
  }
}

