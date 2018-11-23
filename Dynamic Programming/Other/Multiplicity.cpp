/********************************************************************************
 								Deepak gautam								   	
 			codeforces - gautam27 		codechef - algorithmist2			   	
 			Topcoder- gautam_27 		Spoj - nexus_d						   	
 			hackerearth- https://www.hackerearth.com/@deepak.gautam.127648 	   	
 			hackerrank - https://www.hackerrank.com/deepakgautam2701		   	
  		    linkedin-https://www.linkedin.com/in/deepak-gautam-a924908a/       		
		    git -https://github.com/deepakgautam							   			
**********************************************************************************/
// https://codeforces.com/contest/1061/problem/C
// https://codeforces.com/blog/entry/63384
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli dp[1000100];
#define mod 1000000007
int main() {
	int n,a,sq,len;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a;
		sq=sqrt(a);
		vector<int> v;
		for(int j=1;j<=sq;j++) {
			if(a%j==0){
				v.push_back(j);
				if(a/j != j) {
					v.push_back(a/j);
				}
			} 
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		len=v.size();
		dp[0]=1;
		for(int j =0; j<len;j++) {
			dp[v[j]]=(dp[v[j]]+dp[v[j]-1])%mod;
		}
	}	
	lli ans=0;
	for(int i=1;i<=n;i++) {
		ans=(ans+dp[i])%mod;
	}
	cout<<ans<<endl;
}
