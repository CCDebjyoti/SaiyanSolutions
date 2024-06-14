class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        vector<int>Map(*max_element(nums.begin(),nums.end())+(int)nums.size()+1,0);//max el+n+1
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            Map[nums[i]]++;
        }
        for(int i=0;i<Map.size();i++){
            if(Map[i]<=1)continue;
             int extra=Map[i]-1;
             Map[i+1]+=extra;// transfer extra freq to next element dont worry about it  1 2 2 2 3 --> 1 2 3 3 3 -> 1 2 3 4 4 -> 1 2 3 4 5 
             cnt+=extra;
        }
        return cnt;
    }
};
//Nlogn
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int cnt=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){// 1 2 2 -- 1 2 3 
                cnt+=nums[i-1]-nums[i]+1;
                nums[i]+=nums[i-1]-nums[i]+1;
            }
        }
        return cnt;
    }
};
