class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>ans={nums[0]};
        for(int i=1;i<nums.size();i++){//idea is to get the size of the subseq we dont care about what acutal subseq
            if(nums[i]>ans.back()){// 1 7 8 == 1 4 5 same size so find the place to put the elment using LB as 4 is in 7 place 
                ans.push_back(nums[i]);
            }
            else{
            int lb=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
            ans[lb]=nums[i];
            }
        }
        return ans.size();
    }
};
