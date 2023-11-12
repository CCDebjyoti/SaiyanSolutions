int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high = n-1;
        int ans=INT_MAX;
       while(low<=high){
        int mid =low +(high -low)/2;
         if(nums[low]<=nums[high]){//if array already sorted no need 
             ans=min(nums[low],ans);
             break;
         }
         if(nums[high]>=nums[mid]){ // eliminate sorted half keep the minimum 
            ans=min(ans,nums[mid]);
            high=mid-1;
         }
        else {
            ans=min(ans,nums[low]);
            low=mid+1;
          }
       }
       return ans;
    }
