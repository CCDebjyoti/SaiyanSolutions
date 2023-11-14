int NthRoot(int n, int m) {
  // Write your code here.
  long long low=0,high=m;
    while(low<=high){
         long long mid=low+(high-low)/2;
        if(pow(mid,n)==m){
        return mid;
        }
        else if(pow(mid,n)>m){
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    return -1;
}
