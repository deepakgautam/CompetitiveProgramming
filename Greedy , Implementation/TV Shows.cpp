/********************************************************************************
 								Deepak gautam								   	
 			codeforces - gautam27 		codechef - algorithmist2			   	
 			Topcoder- gautam_27 		Spoj - nexus_d						   	
 			hackerearth- https://www.hackerearth.com/@deepak.gautam.127648 	   	
 			hackerrank - https://www.hackerrank.com/deepakgautam2701		   	
  		    linkedin-https://www.linkedin.com/in/deepak-gautam-a924908a/       		
		    git -https://github.com/deepakgautam							   			
**********************************************************************************/
// https://codeforces.com/contest/1061/problem/D
// https://codeforces.com/blog/entry/63384
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define mod 1000000007
vector<pair<lli,lli> > v;
int main() {
	lli n,x,y;
	cin>>n>>x>>y;
	for(int i=0;i<n;i++) {
		lli a,b;
		cin>>a>>b;
		v.push_back({a,b});
	}
	sort(v.begin(),v.end());
	multiset<lli> av_tv;
	lli ans=0;
	for(int i=0;i<n;i++) {
		lli a= v[i].first;
		lli b=v[i].second;
		if(av_tv.empty()) {
			av_tv.insert(b);
			ans=(ans+x+(b-a)*y)%mod;
		} else {
			multiset<lli> ::iterator it;
			it=av_tv.lower_bound(a);
			if(it==av_tv.begin()) {
				av_tv.insert(b);
				ans =(ans+ (x+((b-a)*y)%mod)%mod)%mod;
			} else {
				it--;
				if(x<=(a-*it)*y){
					ans =(ans+ (x+((b-a)*y)%mod)%mod)%mod;
					av_tv.insert(b);
				} else {
					av_tv.erase(it);
					ans=(ans+(b-*it)*y%mod)%mod;
					av_tv.insert(b);
				}
			}
		}
	}
	cout<<ans<<endl; 
}
