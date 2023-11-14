int floorSqrt(int n)
{
    long long low=0,high=n;
    long long ans=1;
    while(low<=high){
        long long mid=low+(high-low)/2;
         long long val=mid*mid;
        if(val>n){
            high=mid-1;
        }
        else {
            ans=mid;
            low=mid+1;
        }
    }
    return ans;
}
