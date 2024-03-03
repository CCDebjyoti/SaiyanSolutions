class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        for(int i=0;i<(1<<n);i++){
            vector<int>op;
            for(int j=0;j<n;j++){
            if((i>>j)&1==1){// i right shift j times 
                op.push_back(nums[j]);
            }
            }
            ans.push_back(op);
        }
        return ans;
    }
};
