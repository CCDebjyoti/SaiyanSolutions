class Solution {
public://fix l & i 
    // we only move 2 ptr at a time 3rd and 4th is constant 
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
for(int l=0;l<nums.size();l++){
  if(l>0 && nums[l]==nums[l-1])continue;//only considering first time
    for(int i=l+1;i<nums.size();i++){
        if(i!=l+1 && nums[i]==nums[i-1])continue;//for first element dnt chck last
             int j=i+1;
            int k=nums.size()-1;
            while(j<k){
             long long sum=nums[l];
             sum+=nums[j];
             sum+=nums[k];
             sum+=nums[i];
             if(sum<target){
                 j++;
             }
             else if(sum>target){
                 k--;
             }
             else{
               vector<int>tmp={nums[l],nums[i],nums[j],nums[k]};
                ans.push_back(tmp);
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1])j++;
                while(j<k && nums[k]==nums[k+1])k--;
             }
            }
            

        }
        }
        return ans;
    }
};
