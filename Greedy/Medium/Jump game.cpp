//left to right 
        bool canJump(vector<int>& nums) {
        int minjump=0;
        for(int i=nums.size()-2;i>=0;i--){//min jump from last index is 0 minjump+1 for to reach each index  
          minjump++;
          if(nums[i]>=minjump)minjump=0;// if we can reach the index then minjump=0
        }
        return minjump==0;//if we jumped all then 0
    }
 //right to left 
        bool canJump(vector<int>& nums) {
        int rech=0;
        for(int i=0;i<nums.size();i++){
            if(i>rech)return false;//if index greater than max reach 
            rech=max(rech,i+nums[i]);
        }
        return true;
