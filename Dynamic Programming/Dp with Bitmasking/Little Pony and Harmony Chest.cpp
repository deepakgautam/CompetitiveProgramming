/*
https://codeforces.com/problemset/problem/453/B
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
int p[61];
int arr[100];
int dp[101][1 << 19];
int pr[17] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
int n;
void prime();
int ans[101];
int masked[101];
int mask_compute() {
  masked[1] = 0;
  for (int i = 2; i <= 60; i++) {
    int nm = 0;
    for (int j = 0; j < 17; j++) {
      if (i % pr[j] == 0) {
        nm |= 1 << j;
      }
    }
    masked[i] = nm;
  }
}
int solve(int pos, int mask) {
  if (pos >= n) {
    return 0;
  } else if (dp[pos][mask] != -1) {
    return dp[pos][mask];
  } else {
    int ret = INT_MAX;
    int val;
    for (int i = 1; i <= 59; i++) {
      if (!(mask & masked[i]) || i == 1) {
        int nm = mask | masked[i];
        int th = solve(pos + 1, nm) + abs(arr[pos] - i);
        if (ret > th) {
          ret = th;
          val = i;
        }
      }
    }
    dp[pos][mask] = ret;
    return ret;
  }
}
int backTrack(int mask, int pos, int tot, int used) {
  if (pos > n) {
    return 0;
  } else {
    int flag = 0;
    for (int i = 1; i <= 59; i++) {
      if (!(mask & masked[i]) || i == 1) {
        int nm = mask | masked[i];
        int th = solve(pos + 1, nm) + abs(arr[pos] - i);
        if (th + used == tot) {
          flag = 1;
          ans[pos] = i;
          backTrack(nm, pos + 1, tot, used + abs(arr[pos] - i));
        }
      }
      if (flag == 1) break;
    }
  }
}
int main() {
  mask_compute();
  memset(dp, -1, sizeof dp);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int an = solve(0, 0);

  backTrack(0, 0, an, 0);
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
}
