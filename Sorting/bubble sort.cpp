void bubbleSort(vector<int>& nums, int n)
{   //swap adjacent element
     bool flag;
    for(int i=0;i<n;i++){
    flag=false;
        for(int j=0;j<n-1;j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
                flag=true;
            }
        }
        if(flag==false)break;
    }
}
