class Solution {//comb sum 1
public:
    vector<vector<int>>ans;
    void solve(int i,vector<int>&op,vector<int>&nums,int t,int sum){
      if(sum==t){//good practice write this before ig
            ans.push_back(op);
            return ;
        }
        if(i==nums.size() || sum>t)return;
        op.push_back(nums[i]);
        solve(i,op,nums,t,sum+nums[i]);//stack and pick
        op.pop_back();
        solve(i+1,op,nums,t,sum);//move and dont pick 
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>op;
        solve(0,op,candidates,target,0);
        return ans;
    }
};
//comb sum 2
class Solution {
public:
     vector<vector<int>>ans;
    void solve(int i,vector<int>&op,vector<int>&nums,int t,int sum){
        if(sum==t){
            ans.push_back(op);
            return ;
        }
        if(i==nums.size())return;//do this after checking sum==target as if u dont ans.push_back wont be called for this op(last digit)
        if(sum>t)return;
        op.push_back(nums[i]);
        solve(i+1,op,nums,t,sum+nums[i]);
        op.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1])i++;//for no pick condition we ignore duplicate elements as we already have picked it once thats all
        solve(i+1,op,nums,t,sum);// 1 2 2 2 .. as i!=i+1 ..0!=1 so we pick 2 now if we pick more duplicate subs created so..
        
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int>op;
        sort(nums.begin(),nums.end());
         solve(0,op,nums,target,0);
        return ans;
    }
};
