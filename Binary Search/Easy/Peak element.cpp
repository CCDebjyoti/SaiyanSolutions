class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || nums[0]>nums[1])return 0;//if size 1 or 1st element is peak eg -inf  5 4 3 2 1 -inf
        if(nums[n-1]>nums[n-2])return n-1;
        int low=1,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])return mid;//if mid is peak ie greater than both left and right return index
            else if(nums[mid]>nums[mid-1])low=mid+1;//if we lie on increasing curve peak on right 
            else high=mid-1; // if we are like mid -> 7  6 4 peak on left 
        }   // multiple peak go anywhere dont care 
        return -1;
    }
};
