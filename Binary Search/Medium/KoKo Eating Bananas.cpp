class Solution {
public:
   long long solve(vector<int>& nums, int k){
         long long cnt=0;
         for(int i=0;i<nums.size();i++){//calculate hours  for cureent mid  we want exactly as h
             cnt+=(nums[i]%k==0)?nums[i]/k:(nums[i]/k)+1;//if divisbile or mod=0 no need for cnt else add cnt
         }
         return cnt;       
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=0;
        int low = 1, high = *max_element(piles.begin(),piles.end()); // Search range is from [1 -> max ]
        while(low<=high){
            int mid = low+(high-low)/2;
            long long cnt= solve(piles, mid);//cnt stored 
            if(cnt<= h){ //if cnt is less or equal to h we can have answer eliminate right and minimise answer 
                ans = mid;
                high = mid-1;
            } 
            else low = mid+1;//if cnt is greater cnt have answer 
        }
        return ans;
    }
};
