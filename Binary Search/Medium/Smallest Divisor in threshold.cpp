class Solution {
public:
    long long solve(vector<int>& nums, int mid){
        long long cnt=0;
        for(int i=0;i<nums.size();i++){
         cnt+=ceil(nums[i]/(double)mid);
        }
        return cnt;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;// why 1 
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            long long cnt=solve(nums,mid);
            if(cnt<=threshold){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return low;
    }
};
