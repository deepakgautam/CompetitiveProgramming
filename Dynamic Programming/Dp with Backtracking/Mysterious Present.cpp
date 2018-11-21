/********************************************************************************
 *								Deepak gautam								   	*
 *			codeforces - gautam27 		codechef - algorithmist2			   	*
 *			Topcoder- gautam_27 		Spoj - nexus_d						   	*
 *			hackerearth- https://www.hackerearth.com/@deepak.gautam.127648 	   	*
 *			hackerrank - https://www.hackerrank.com/deepakgautam2701		   	*
 * 		    linkedin-https://www.linkedin.com/in/deepak-gautam-a924908a/       	*	
 *		    git -https://github.com/deepakgautam							   	*		
 *********************************************************************************/
// https://codeforces.com/problemset/problem/4/D
#include<iostream>
using namespace std;#
include < bits / stdc++.h >
int n;
int next[1000000];
int dp[1000000];
vector < pair < int, int > > v;
int solve(int cur) {
  if (dp[cur] != -1) {
    return dp[cur];
  } else {
    int cur_w = v[cur].first;
    int cur_h = v[cur].second;
    int ret = 0;
    int par = cur;
    for (int j = 0; j <= n; j++) {
      if (v[j].first > cur_w && v[j].second > cur_h) {
        int val = solve(j);
        if (val > ret) {
          ret = val;
          par = j;
        }
      }
    }
    dp[cur] = ret + 1;
    next[cur] = par;
    return dp[cur];
  }
}
int main() {
  cin >> n;
  for (int i = 0; i <= n; i++) {
    dp[i] = -1;
    int a, b;
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }
  int ans = solve(0);
  cout << ans - 1 << endl;
  int start = next[0];
  for (int i = 0; i < ans - 1; i++) {
    cout << start << " ";
    start = next[start];
  }
}
