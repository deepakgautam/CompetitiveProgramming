/********************************************************************************
*								Deepak gautam								   	*
*			codeforces - gautam27 		codechef - algorithmist2			   	*
*			Topcoder- gautam_27 		Spoj - nexus_d						   	*
*			hackerearth- https://www.hackerearth.com/@deepak.gautam.127648 	   	*
*			hackerrank - https://www.hackerrank.com/deepakgautam2701		   	*
* 		    linkedin-https://www.linkedin.com/in/deepak-gautam-a924908a/       	*	
*		    git -https://github.com/deepakgautam							   	*		
*********************************************************************************/
// https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/hasan-and-points-pairing/
// tutorial http://gautambitmaskdp.blogspot.com/2016/04/hasan-and-points-pairing-dp-bit-masking.html

#include<bits/stdc++.h >
using namespace std;
typedef long long int lli;
double dp[1 << 18];
vector < pair < int, int > > points;
double infi = 10000000000.00;
int maxi;
int n;
double dist(int id1, int id2) {
  double p1x = points[id1].first;
  double p1y = points[id1].second;
  double p2x = points[id2].first;
  double p2y = points[id2].second;
  double ret1 = (p1x - p2x) * (p1x - p2x);
  double ret2 = (p1y - p2y) * (p1y - p2y);
  return sqrt(ret1 + ret2);
}
double solve(int mask) {
  if (mask == maxi) {
    return 0.00;
  } else if (dp[mask] != -1) return dp[mask];
  else {
    vector < int > av;
    for (int i = 0; i < 2 * n; i++) {
      if (!(mask & 1 << i))
        av.push_back(i);
    }
    int sz = av.size();
    double ret = infi;
    for (int i = 0; i < sz - 1; i++) {
      int id1 = av[i];
      for (int j = i + 1; j < sz; j++) {
        int id2 = av[j];
        int temp = mask;
        temp = temp | (1 << id1);
        temp = temp | (1 << id2);
        ret = min(ret, solve(temp) + dist(id1, id2));
      }
    }
    dp[mask] = ret;
    return dp[mask];
  }
}
int main() {

  for (int i = 0; i < (1 << (18)); i++) {
    dp[i] = -(1.00);
  }
  cin >> n;
  maxi = 0;
  for (int i = 0; i < 2 * n; i++) {
    maxi = maxi | (1 << i);
    int a, b;
    cin >> a >> b;
    points.push_back({
      a,
      b
    });
  }
  double ans = solve(0);
  printf("%.6lf", ans);
}
