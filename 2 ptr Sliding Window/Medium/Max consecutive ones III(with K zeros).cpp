class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int cnt0=0;
        int cnt1=0;
        int ans=0;
        while(j<nums.size()){
         if(cnt0>k){
            ans=max(ans,j-i+1);
            while(cnt0!=k && i<j){
                if(nums[i]==0)cnt0--;
                else cnt1--;
                i++;
            }
         }
         ans=max(ans,cnt1+cnt0);
         if(nums[j]==0)cnt0++;
         else cnt1++;
        j++;
        }
        return ans;
    }
};
