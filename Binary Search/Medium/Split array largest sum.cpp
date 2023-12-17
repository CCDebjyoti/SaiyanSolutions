class Solution {
public:
    int solve(vector<int>& nums, int mid){
        int currsum=0;
        int cntsubarray=1;
        for(int i=0;i<nums.size();i++){
         if(currsum+nums[i]<=mid){
             currsum+=nums[i];
         }
         else {
             currsum=nums[i];
             cntsubarray++;
         }
        }
        return cntsubarray;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),high);
        while(low<=high){
            int mid=(low+high)/2;
            if(solve(nums,mid)>k){
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return low;
    }
};
