class Solution {
public:
    bool possible(int mid, int k, vector<int> &arr){
        int cntcows=1;
        int last=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]-last>=mid){// can we place 4 cows 1 distance apart 
                cntcows++;//if no of cows can be placed with mid distacne true
                last=arr[i];//last chosen cow place distance 
            }
            if(cntcows==k)return true;
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls[n-1]-stalls[0];//feed distance to possible func range min is 1 can also be min of consequetive to max is Max-min
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(mid,k,stalls)){
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return high;
    }
};
