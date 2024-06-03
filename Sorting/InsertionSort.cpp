void insertionSort(int n, vector<int> &arr){
    //till i elements sorted or in correct postion 
   //2 8 5 3 9 4 --> i=2 - 5 -- 8>5 so swap till it reches correct pos -- 2 5 8 3 9 4 -- i=3 -- 3 8>3 -- swap-> 8,3  5,3 -- 2 3 5 8 9 4
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}
