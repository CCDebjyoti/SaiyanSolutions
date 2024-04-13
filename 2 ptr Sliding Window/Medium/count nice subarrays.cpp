class Solution {//smilar to binary subarrays with sum
public:
 int func(vector<int>& nums, int goal){//no of subarray with exactly k oddd= no of subarray with atmost k odd - No of subarray with atmost k-1 odd
        if(goal<0)return 0;
        int i=0,j=0,ans=0;
        long long cnt=0;
        while(j<nums.size()){
            if(nums[j]%2==1)cnt++;
            while(cnt>goal){
                if(nums[i]%2==1)cnt--;
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
    }
};
