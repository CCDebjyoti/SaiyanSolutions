void selectionSort(vector<int>& arr, int n)
{   
    // Write your code here.
    int maxi=0;
    for(int i=0;i<n;i++){//min index first 
        maxi=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[maxi]){
                maxi=j;
            }
        }
        swap(arr[maxi],arr[i]);
    }
}
