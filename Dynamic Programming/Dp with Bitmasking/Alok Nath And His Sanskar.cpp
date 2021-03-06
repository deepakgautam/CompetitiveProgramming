/*
https://www.codechef.com/problems/SANSKAR
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
#include <bits/stdc++.h >
using namespace std;
typedef long long int lli;
lli ms = 0;
int n, k;
int maxi = 0;
bool dp[1 << 22][10], used[1 << 22][10];
long long int arr[22];
bool solve(int mask, int pos, lli sum) {
  if (pos == k - 1 && sum == ms && mask == maxi) {
    return true;
  } else if (sum > ms) return false;
  else if (used[mask][pos] != false) {
    return dp[mask][pos];
  } else {
    used[mask][pos] = true;
    bool ret = false;
    if (sum == ms) {
      ret = ret | solve(mask, pos + 1, 0);
    } else {
      for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {

          ret = ret | solve(mask | (1 << i), pos, sum + arr[i]);
        }
      }
      dp[mask][pos] = ret;
      return ret;
    }
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    scanf("%d %d", & n, & k);
    memset(dp, false, sizeof dp);
    ms = 0;
    maxi = 0;
    memset(used, false, sizeof used);
    for (int i = 0; i < n; i++) {
      maxi = maxi | (1 << i);
      scanf("%lld", & arr[i]);
      ms += arr[i];
    }
    if (k > n || ms % k != 0) {
      cout << "no" << endl;
      continue;
    } else if (ms == 0 && n >= k) {
      cout << "yes" << endl;
      continue;
    } else {
      ms /= k;
      bool ans = solve(0, 0, 0);
      if (ans) {
        cout << "yes" << endl;

      } else {
        cout << "no" << endl;
      }
    }
  }
}
