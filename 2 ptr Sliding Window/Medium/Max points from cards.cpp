class Solution {//can pick from front or back kindoff max subarray sum from beg or end 
public:
    int maxScore(vector<int>& nums, int k) {// 6 2 3 4 7 2 1 7 1  k=4
        int lsum=0,rsum=0,maxS;       /// add frist 4 -> 15 then subtract one from end lsum+rsum  max 16
        for(int i=0;i<k;i++){
            lsum+=nums[i];
        }
        maxS=lsum;
        int j=nums.size()-1;
        for(int i=k-1;i>=0;i--){
         lsum-=nums[i];
         rsum+=nums[j--];
         maxS=max(maxS,lsum+rsum);
        }
        return maxS;
    }
};
