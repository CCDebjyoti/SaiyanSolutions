class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
          unordered_map<int,int>Map;
        Map[0]=1;
        int presum=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            int rem=presum%k;//storing remainder idea is same remainder
            // difference will  be divisible by k 
            if(rem<0)rem=rem+k;//if negative add k to make (+) as -5->2 for 7
            if(Map.find(rem)!=Map.end()){
                cnt+=Map[rem];
            }
            Map[rem]++;
        }
        return cnt;
    }
};
