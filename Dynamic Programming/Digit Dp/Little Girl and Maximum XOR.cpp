/********************************************************************************
 								Deepak gautam								   	
 			codeforces - gautam27 		codechef - algorithmist2			   	
 			Topcoder- gautam_27 		Spoj - nexus_d						   	
 			hackerearth- https://www.hackerearth.com/@deepak.gautam.127648 	   	
 			hackerrank - https://www.hackerrank.com/deepakgautam2701		   	
  		    linkedin-https://www.linkedin.com/in/deepak-gautam-a924908a/       		
		    git -https://github.com/deepakgautam							   			
**********************************************************************************/
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
string s1, s2;
lli dp[101][2][2][2][2];
int n;
// l1=tight_low1 for first num
// l2=tight_up1 for first num
// r1=tight_low2 for second num
// r2= tight_up2 for second num
lli solve(int pos, int l1, int l2, int r1, int r2) {
  if (pos == n) {
    return 0;
  } else if (dp[pos][l1][l2][r1][r2] != -1) {
    return dp[pos][l1][l2][r1][r2];
  } else {
    lli ret = 0;
    int minl = 0, maxl = 1, minr = 0, maxr = 1;
    // range  values that can be set
    // for both nums at ith position
    if (l1 == 1 && s1[pos] == '1') {
      minl = 1;
    }
    if (l2 == 1 && s2[pos] == '0') {
      maxl = 0;
    }

    if (r1 == 1 && s1[pos] == '1') {
      minr = 1;
    }

    if (r2 == 1 && s2[pos] == '0') {
      maxr = 0;
    }
    for (int i = minl; i <= maxl; i++) {
      for (int j = minr; j <= maxr; j++) {

        int nl1 = l1, nl2 = l2, nr1 = r1, nr2 = r2;

        if (s1[pos] < (i + '0')) {
          nl1 = 0;
        }
        if (s2[pos] > (i + '0')) {
          nl2 = 0;
        }

        if (s1[pos] < (j + '0')) {
          nr1 = 0;
        }
        if (s2[pos] > (j + '0')) {
          nr2 = 0;
        }

        int xr = (i ^ j);
        lli sum = 0;
        if (xr == 1) {
          int size = n - pos - 1;
          sum = (1 ll << size);
        }
        lli ret1 = (solve(pos + 1, nl1, nl2, nr1, nr2) + sum);

        ret = max(ret, ret1);
      }
    }
    dp[pos][l1][l2][r1][r2] = ret;
    return ret;
  }

}

string bin(lli num) {
  string temp;
  while (num != 0) {
    if (num % 2 == 0) {
      temp += '0';
    } else temp += '1';
    num /= 2;
  }
  reverse(temp.begin(), temp.end());
  return temp;

}
int main() {
  lli a, b;
  cin >> a >> b;
  s1 = bin(a);
  s2 = bin(b);
  n = s2.length();
  if (s1.length() < s2.length()) {
    string temp;
    int dif = s2.length() - s1.length();
    for (int i = 0; i < dif; i++) temp += '0';
    temp += s1;
    s1 = temp;
  }
  memset(dp, -1, sizeof dp);
  lli ans = solve(0, 1, 1, 1, 1);
  cout << ans << endl;
}
