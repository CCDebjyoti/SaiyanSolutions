int solve(vector<int>& arr, int mid){
   int stu=1 ;
   long long pages=0;
   for(int i=0;i<arr.size();i++){
   if(pages+arr[i]<=mid){
       pages+=arr[i];
   }
   else {
       pages=arr[i];
       stu++;
   }
   }
   return stu;
  
}
int findPages(vector<int>& arr, int n, int m) {
   if(m>n)return -1;
    int high=0;
    int low=INT_MIN;
    for(int i=0;i<n;i++){
    high+=arr[i];
    low=max(low,arr[i]);
    }
    while(low<=high){
        int mid=(low+high)/2;
        if(solve(arr,mid)>m){
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
    return low;
  
}
