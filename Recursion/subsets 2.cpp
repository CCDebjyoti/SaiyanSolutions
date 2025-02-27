class Solution {
public: 
    vector<vector<int>>ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>op;
        sort(nums.begin(),nums.end());
        helper(0,nums.size(),op,nums);
        return ans;
    }
    void helper(int ind,int n,vector<int>&op,vector<int>&nums){
        if(ind==n){
        ans.push_back(op);//we dont skip calling no pick for indexes where 
        return;
        }
        op.push_back(nums[ind]);
        helper(ind+1,n,op,nums);//pick 
        op.pop_back();
        while(ind+1<n && nums[ind]==nums[ind+1])ind++;
            helper(ind+1,n,op,nums);//dont pick 
        }
};
