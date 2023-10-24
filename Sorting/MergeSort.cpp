//single temp array
void merge(vector <int> &arr, int low, int mid, int high){

    vector<int> temp;

    int left= low;
    int right= mid+1;

    while(left<=mid && right<=high){

        if(arr[left]<=arr[right]){
        temp.push_back(arr[left++]);
        }

        else{
        temp.push_back(arr[right++]);
        }

    }

         while(left<=mid)temp.push_back(arr[left++]);
         while(right<=high)temp.push_back(arr[right++]);

        for(int i=low; i<= high; i++){

        arr[i]= temp[i-low];

    }

}
//two array and join 
void mergeSorted(vector<int> &arr, int s, int mid, int e){

    int len1 = mid-s+1;
    int len2 = e-mid;

    vector<int> arr1(len1);
    vector<int> arr2(len2);

    for(int i=0; i<len1; i++){

        arr1[i] = arr[s+i];

    }

    for(int i=0; i<len2; i++){

        arr2[i] = arr[mid+i+1];

    }

    int i=0;
    int j=0;
    int k=s;
    while(i<len1 && j<len2 ){
        if(arr1[i]>arr2[j]){
            arr[k++]=arr2[j++];
        }
        else {
            arr[k++]=arr1[i++];
        }
    }
    while(i<len1)arr[k++]=arr1[i++];

    while(j<len2)arr[k++]=arr2[j++];

}

void Solve(vector<int> & arr,int s,int e){
    int mid=(s+e)/2;
    //base case
    if(s>=e)return;
    //left sort 
    Solve(arr,s,mid);
    //right
    Solve(arr,mid+1,e);
    //Merge
    mergeSorted(arr,s,mid,e);


}

void mergeSort(vector < int > & arr, int n) {

    // Write your code here.
    Solve(arr,0,n-1);
}
