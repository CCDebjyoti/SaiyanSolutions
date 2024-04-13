class Solution {
public:
    int func(vector<int>& nums, int goal){
        if(goal<0)return 0;//edge case if goal =0 so 0-1 =-1 overflow error 
        int i=0,j=0,ans=0;
        long long sum=0;
        while(j<nums.size()){//subarrays with sum atmost goal sum<=goal
            sum+=nums[j];
            while(sum>goal){
                sum-=nums[i];
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return func(nums,goal)-func(nums,goal-1);
    }
};
