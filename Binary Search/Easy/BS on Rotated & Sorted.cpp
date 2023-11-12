  int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high = n-1;
        
       while(low<=high){
        int mid =low +(high -low)/2;
        if(nums[mid]==target){
                return mid;
            }
        /*    if(v[i]==v[m] && v[m]==v[j]){   // for dups //shrink search space 
                i++;
                j--;
                continue;
            } */
        else if(nums[high]>=nums[mid]){ //right sorted
            if(nums[mid]<=target && nums[high]>=target){//target lies in right part 
                low=mid+1;
            }
            else {
            high=mid-1;
            }
         }
        else { //left sorted 
            if(nums[mid]>=target && nums[low]<=target){
            high=mid-1;
            }
            else {
                low=mid+1;
            }
          
          }
       }
       return -1;
    
    }
