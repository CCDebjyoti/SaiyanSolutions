class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
    for(int i=0;i<arr.size()-(arr.size()/4);i++){//traverse 0->n-n/4
    if(arr[i]==arr[i+(arr.size()/4)])return arr[i];//as sorted if 
    }//arr[i]==arr[i+n/4] meaning that we got answer as 25% together element [1,2,2,2,2] means 2=2 so 25 percent 
    return -1;
    }
};
