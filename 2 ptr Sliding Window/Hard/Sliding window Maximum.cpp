class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {//create nge array | greatest to smallest 
        deque<int>dq;
        vector<int>ans;
        for(int j=0;j<nums.size();j++){
        if(!dq.empty()&& dq.front()==j-k)dq.pop_front();//out of boundary condition
        while(!dq.empty()&& nums[j]>nums[dq.back()])dq.pop_back();
        dq.push_back(j);
        if(j>=k-1)ans.push_back(nums[dq.front()]);//only push from 2nd index for k==3 
        }
        return ans;

    }
};
