class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4)return 0;
        priority_queue<int>maxh;
        priority_queue<int,vector<int>,greater<int>>minh;
        for(int i=0;i<nums.size();i++){
           maxh.push(nums[i]);
           minh.push(nums[i]);
           if(maxh.size()>4)maxh.pop();
           if(minh.size()>4)minh.pop();
        }
        int ans=INT_MAX;
        int n=nums.size();//kind of partial sort only need last 3 elements and first 3 elements as 
        int r=3;//combination of them only -- xxx- or -xxxx-- or xxxx--- or ---xxx
        int l=n-4;//min heap from 4th last to end fill up 
        while(!maxh.empty()){
            nums[r--]=maxh.top();
            maxh.pop();
            nums[l++]=minh.top();
            minh.pop();
        } 
        ans=min(ans,abs(nums[n-1] - nums[3]));
        ans=min(ans,abs(nums[n- 2] - nums[2]));
        ans=min(ans,abs(nums[n- 3] - nums[1]));
        ans=min(ans,abs(nums[n- 4] - nums[0]));
        return ans;
    }
};
