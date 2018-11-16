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
#define ff first
#define ss second
typedef long long int lli;
int dp[1<<17][20];
int maxi;
  int sz;
  int n,m;
  
vector<pair<int,int> > v;
int solve(int mask,int last)
 {
   //cout<<mask<<" "<<last<<endl;
   if(mask==maxi)
     {
      
       int xd=abs(v[0].ff-v[last].ff);
       int yd=abs(v[0].ss-v[last].ss);
       
        
         return max(xd,yd);
    }
    else if(dp[mask][last]!=-1)
    {
      return dp[mask][last];
    }
    else
    {
        int ret=100000;
         
         for(int i=0;i<sz;i++)
          {
            if(!(mask & (1<<i)))
                 {
                   int dis=0;
                    int xd=abs(v[i].ff-v[last].ff);
                       int yd=abs(v[i].ss-v[last].ss);
                     
                        dis=max(xd,yd);
                   ret=min(ret,solve(mask | (1<<i),i)+dis);
       }
           
    }
    dp[mask][last]=ret;
    return ret;
    }
 }
int main()
{
  int t;
   cin>>t;
   int cas=1;
   while(t--)
   {
    maxi=0;
    memset(dp,-1,sizeof dp);
    v.clear();
      cin>>n>>m;
      int sx,sy;
      v.push_back({0,0});
      for(int i=0;i<n;i++)
           {
             for(int j=0;j<m;j++)
             {
               char c;
                cin>>c;
                if(c=='g')
                 {
                   v.push_back({i,j});
                   
        }
        else if(c=='x')
        {
         sx=i;
         sy=j;
        }
       }
        
    }
    v[0].first=sx;
    v[0].second=sy;
      sz=v.size();
     for(int i=0;i<sz;i++)
     {
       maxi=maxi| (1<<i);
     }
    int ans=solve(1,0);
    cout<<"case "<<cas++<<": "<<ans<<endl;
   }
}
