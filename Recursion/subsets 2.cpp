class Solution {
public: 
    vector<vector<int>>ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>op;//3. We can achieve it by counting only one occurrence of an element and skipping all its rest occurrences in arr[]
        sort(nums.begin(),nums.end());//4. We need to first sort the given vector arr[]
        helper(0,nums.size(),op,nums);//5. For don't pick condition, we will first check whether arr[i]==arr[i+1] or not. If so, we will ignore the rest occurrences of that particular element.
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
