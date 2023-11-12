#include<bits/stdc++.h>
int findKRotation(vector<int> &nums){
        int n=nums.size();
        int low=0,high = n-1;
        int ans=INT_MAX;
        int indx;
       while(low<=high){
        int mid =low +(high -low)/2; // same find minimum element and just return index and equal to no of rotations 
         if(nums[low]<=nums[high]){
              if(nums[low]<ans){
                indx=low;
                ans=nums[low];
            }
             break;
         }
         if(nums[high]>=nums[mid]){
            if(nums[mid]<=ans){
                indx=mid;
                ans=nums[mid];
            }
            high=mid-1;
         }
        else {
            if(nums[low]<=ans){
                indx=low;
                ans=nums[low];
            }
            low=mid+1;
          }
       }
       return indx;
}
