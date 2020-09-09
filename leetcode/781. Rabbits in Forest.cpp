/*
problem link - https://leetcode.com/problems/rabbits-in-forest/

Deepak gautam
leetcode - https://leetcode.com/deepakgautam270795/
codechef - https://www.codechef.com/users/algorithmist2
codeforces - https://codeforces.com/profile/gautam27
Spoj - https://www.spoj.com/users/nexus_d/
hackerearth- https://www.hackerearth.com/@deepak.gautam.127648 
hackerrank - https://www.hackerrank.com/deepakgautam2701
*/

class Solution {
 public:
  int numRabbits(vector<int> &answers) {
    int length = answers.size();
    map<int, int> colorCountMap;
    for (int i = 0; i < length; i++) {
      colorCountMap[answers[i]]++;
    }
    map<int, int>::iterator it;
    int ans = 0;
    for (it = colorCountMap.begin(); it != colorCountMap.end(); it++) {
      
      if(it->second %(it->first+1) ==0) {
          ans += it->second;
      }  else {
           ans += ((it->second / (it->first+1))+1) * (it->first+1) ;
      }
    }
    return ans;
  }
};