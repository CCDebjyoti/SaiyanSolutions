class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1)return 0;//base case [1],[] or i<n-1
        int maxreach=0,curreach=0;//max reachable point btw curreach and i traversal
        int jumps=0;
        for(int i=0;i<nums.size();i++){
           maxreach=max(maxreach,nums[i]+i);//update max reachable pont
           if(i==curreach){//if we have reached at currreach point then we can travel anymore so need to jump 
            jumps++;
            curreach=maxreach;//next travel is max reach point btw
           }
           if(curreach>=nums.size()-1)break;
        }
        return jumps;
    }
};
