/********************************************************************************
 								Deepak gautam								   	
 			codeforces - gautam27 		codechef - algorithmist2			   	
 			Topcoder- gautam_27 		Spoj - nexus_d						   	
 			hackerearth- https://www.hackerearth.com/@deepak.gautam.127648 	   	
 			hackerrank - https://www.hackerrank.com/deepakgautam2701		   	
  		    linkedin-https://www.linkedin.com/in/deepak-gautam-a924908a/       		
		    git -https://github.com/deepakgautam							   			
**********************************************************************************/
// https://www.spoj.com/problems/CPCRC1C/
// editorial http://gautamdegitdp.blogspot.com/2016/04/cpcrc1c-sum-of-digits-digit-dp.html
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli dp[20][2]; // index, tight 
lli func(int idx, int last, string s) {
  lli num = 0;
  for (int i = idx; i < last; i++) {
    num = num * 10 + s[i] - '0';
  }
  return num;

}
lli solve(int idx, bool tight, string s, int n) {
  if (idx >= n)
    return 0;
  else if (dp[idx][tight] != -1)
    return dp[idx][tight];
  else if (tight == 1) {
    lli ret = 0;
    for (int i = 0; i <= s[idx] - '0'; i++) {
      if (i == s[idx] - '0')
        ret += solve(idx + 1, 1, s, n) + i * (func(idx + 1, s.length(), s) + 1);
      else
        ret += solve(idx + 1, 0, s, n) + i * pow(10, n - idx - 1);
    }
    dp[idx][tight] = ret;
    return ret;
  } else {
    lli ret = 0;
    for (int i = 0; i <= 9; i++) {
      ret += solve(idx + 1, 0, s, n) + i * pow(10, n - idx - 1);
    }
    dp[idx][tight] = ret;
    return ret;
  }
}
int main() {
  while (1) {
    memset(dp, -1, sizeof dp);
    string a, b;
    cin >> a >> b;
    lli as = 0;
    for (int i = 0; i < a.length(); i++)
      as += a[i] - '0';
    if (a == "-1" && b == "-1")
      break;
    else {
      lli ans1 = solve(0, 1, b, b.length());
      memset(dp, -1, sizeof dp);
      lli ans2 = solve(0, 1, a, a.length());;
      lli ans = ans1 - ans2 + as;
      cout << ans << endl;
    }
  }
}
