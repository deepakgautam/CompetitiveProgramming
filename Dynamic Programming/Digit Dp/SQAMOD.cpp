/*
https://www.spoj.com/problems/SQAMOD/
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

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli dp[100100][2][3];// index, tight, modval
int n;
string s;
lli solve(int idx,int tight ,int mod) {
	if(idx>=n) {
		int ret = idx>n || mod !=0 ? 0 : 1;
		return ret;
	}
   	if(dp[idx][tight][mod]!=-1)
	   	return dp[idx][tight][mod];
    int max_loop_index = tight ? s[idx]-'0' : 9;
	lli ret=0;
 	for(int i=0;i<=max_loop_index;i++) {
 		bool tight = tight && s[idx]-'0' == i ? 1 : 0;
    	ret=ret+ solve(idx+1,0,(mod+i*i)%3);
	}
	dp[idx][tight][mod]=ret;
	return ret;
 }
int main() {
	int t;
	cin>>t;
   	while(t--) {
		memset(dp,-1,sizeof dp);
    	cin>>s;
   		n=s.length();
  		lli ans=solve(0,1,0);
 		int temp=0;
  		for(int i=0;i<n;i++) {
    		temp+=(s[i]-'0')*(s[i]-'0');
    		temp%=3;
		}
    	if(temp==0) ans--;
     	cout<<ans<<endl;
    }
    return 0;
}
