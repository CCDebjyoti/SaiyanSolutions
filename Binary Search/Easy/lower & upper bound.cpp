   //LOWER BOUND STL
	vector<int>::iterator low = lower_bound(arr.begin(),arr.end(),x);
        auto low=lower_bound(arr.begin(),arr.end(),x); //works also
	return low-arr.begin();
    //Implementation
    int lowerBound(vector<int> nums, int n, int target) {
    int low=0,high = n-1;
    int ans=n;
       while(low<=high){
           int mid =low +(high -low)/2;
           
           if(nums[mid]>=target){
                ans=mid;
               high=mid-1;
           }
           else{
               low =mid+1;
           }
       }
       return ans;
}
	//UPPER BOUND STL
	vector<int>::iterator upeer=upper_bound(arr.begin(),arr.end(),x);
	return upeer-arr.begin();
        //Implementation
         int lowerBound(vector<int> nums, int n, int target) {
    int low=0,high = n-1;
    int ans=n;
       while(low<=high){
           int mid =low +(high -low)/2;
           
           if(nums[mid]>target){
                ans=mid;
               high=mid-1;
           }
           else{
               low =mid+1;
           }
       }
       return ans;
}
}
