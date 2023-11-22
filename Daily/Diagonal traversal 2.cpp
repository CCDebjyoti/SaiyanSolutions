//return diagonal elements of the matrix 
//sum of matrix diagonal same 
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
      vector<int>ans;
      int maxsum=0;
      map<int,vector<int>>Map;
      for(int i=nums.size()-1;i>=0;i--){
          for(int j=0;j<nums[i].size();j++){
              Map[i+j].push_back(nums[i][j]);
              maxsum=max(maxsum,i+j);//to travel how much in map 
          }
      }
     /*  for(auto it:Map){
           reverse(it.second.begin(),it.second.end()); 
          for(auto i:it.second){
              ans.push_back(i);
          }
      } */
      for(int i=0;i<=maxsum;i++){
      for(auto it:Map[i]){
          ans.push_back(it);
      }
      }
      return ans;
    }
};
