int merge(vector <int> &arr, int low, int mid, int high){

    vector<int> temp;

    int left= low;
    int right= mid+1;
    int cnt=0;
    while(left<=mid && right<=high){

        if(arr[left]<=arr[right]){
        temp.push_back(arr[left++]);
        
        }

        else{
        temp.push_back(arr[right++]);
        cnt+=mid-left +1;
        }

    }

    while(left<=mid)temp.push_back(arr[left++]);
    while(right<=high)temp.push_back(arr[right++]);

        for(int i=low; i<= high; i++){
          arr[i]= temp[i-low];
        }
    return cnt;

}

int Solve(vector<int> & arr,int s,int e){
    
    int cnt=0;
    //base case
    if(s>=e)return cnt;
    //left sort 
    int mid=(s+e)/2;
    
    cnt+=Solve(arr,s,mid);
    //right
    cnt+=Solve(arr,mid+1,e);
    //Merge
    cnt+=merge(arr,s,mid,e);
    
  return cnt;

}

int numberOfInversions(vector<int>&a, int n) {
    // Write your code here.
    return Solve(a,0,n-1);
}
