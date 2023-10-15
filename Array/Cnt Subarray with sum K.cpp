class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>Map;
        Map[0]=1;// initialize zero as we may get pre sum of 3 arr[i]=3 as 0 cnt++
        int presum=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            if(Map.find(presum-k)!=Map.end()){
                cnt+=Map[presum-k];//add cnt to no of subarrays
            }
            Map[presum]++;
        }
        return cnt;
    }
};
