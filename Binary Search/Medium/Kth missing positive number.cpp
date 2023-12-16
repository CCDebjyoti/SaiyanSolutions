class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]-mid-1<k){//missing is arr[i]-i-1 logically so bs apply 
            low=mid+1;
            }
            else {
            high=mid-1;
            }
        }
        return  high+k+1;//low+k low 1 greater than high anyways
    }
};
