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