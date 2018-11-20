/********************************************************************************
*								Deepak gautam								   	*
*			codeforces - gautam27 		codechef - algorithmist2			   	*
*			Topcoder- gautam_27 		Spoj - nexus_d						   	*
*			hackerearth- https://www.hackerearth.com/@deepak.gautam.127648 	   	*
*			hackerrank - https://www.hackerrank.com/deepakgautam2701		   	*
* 		    linkedin-https://www.linkedin.com/in/deepak-gautam-a924908a/       	*	
*		    git -https://github.com/deepakgautam							   	*		
*********************************************************************************/
// https://www.spoj.com/problems/HIST2/

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli dp[16][1 << 16];
lli times[16][1 << 16];
int arr[20];
int n;
int c = 0;

lli solve(int current, int mask) //  curent means weare at current vertx  and now we have to visit vertex      not included in the mask  
{
  if (dp[current][mask] != -1) {
    return dp[current][mask];
  } else {
    for (int i = 1; i <= n; i++) // check which vertex are 
    {
      if ((mask & 1 << (i - 1)) == 0) {
        if (((mask | 1 << (i - 1)) == (1 << n) - 1)) // if after including ith building we coverd all                                            //building   than we need to add side length of last building also.
        {
          dp[current][mask] = abs(arr[i] - arr[current]) + arr[i];
          times[current][mask] = 1;
          return dp[current][mask];
        } else {
          int val = 0;
          val = solve(i, (mask | (1 << (i - 1)))) + abs(arr[current] - arr[i]);
          if (val > dp[current][mask]) // if new value > previous value than no of ways will    //be  equal to no of ways new value is computed  so first make it 0. 
          {
            times[current][mask] = 0;
            dp[current][mask] = val;
          }
          if (val == dp[current][mask]) {
            times[current][mask] += times[i][(mask | (1 << (i - 1)))];
          }
        }
      }
    }
    return dp[current][mask];
  }
}
int main() {

  while (1) {
    memset(dp, -1, sizeof dp);
    memset(times, 0, sizeof times);
    cin >> n;
    if (n == 0) break;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    lli ans = 0;
    lli cc = 0;
    lli max_ans = 0;
    for (int i = 1; i <= n; i++) {

      ans = max(ans, solve(i, 1 << (i - 1)) + arr[i]);
      if (ans > max_ans) {
        max_ans = ans;
        cc = times[i][1 << (i - 1)];
      } else if (ans == max_ans) cc += times[i][1 << (i - 1)];
    }
    cout << ans + 2 * n << " " << cc << endl;

  }

}
