/*
https://www.codechef.com/problems/ANUBGC
http://discuss.codechef.com/problems/ANUBGC
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
lli dp[20][2][2][2];//index, tight_bound, is_covered , used_nonzero no or not,
int n;
string s;
lli solve(int idx,bool tight,bool is_covered,bool nz,int num) {
	if(idx==n) { 
    	return is_covered;
    }
	else if(dp[idx][tight][is_covered][nz]!=-1) {
   		return dp[idx][tight][is_covered][nz];
	}
	int max_loop_index = tight ? s[idx]-'0' : 9;
    lli ret=0;
   	for(int i=0;i<=max_loop_index;i++) {
   	 	bool nzz= nz || i;
   	 	bool is_cove =(is_covered   || (num == i)) && (nzz!=0);
   	 	bool is_at_upper_limit = tight && i== max_loop_index ? 1: 0;
	 	ret+=solve(idx+1,is_at_upper_limit,is_cove,nzz,num);
    }
    dp[idx][tight][is_covered][nz]=ret;
   	return ret;
}
int main() {
	int t;
	cin>>t;
	while(t--) {
 		memset(dp,-1,sizeof dp);
 	  	cin>>s;
 	  	lli ans=0;
 	  	n=s.length();
 	  	lli num=0;
 	  	for(int i=0;i<n;i++) {
 	  	   	num=num*10+(s[i]-'0');
		 }
 	  	 for(int i=0;i<=9;i++) {
 	  	    memset(dp,-1,sizeof dp);
 	  	   	ans+=solve(0,1,0,0,i);
		 }
 	  	 num=num*10;
 	  	 lli gc=__gcd(num,ans);
 	  	 cout<<ans/gc<<"/"<<num/gc<<endl;
	 }
	return 0;
 }
