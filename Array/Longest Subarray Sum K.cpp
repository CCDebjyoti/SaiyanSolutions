#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
   
    unordered_map<long long ,int>Map;
    long long sum=0;
    int ans=0;
    for(int i=0;i<nums.size();i++){
      
        sum+=nums[i];
      
        if(sum==k)
        ans=max(ans,i+1);
        
        if(Map.find(sum-k)!=Map.end())//Map[nums[sum-k]] dosenot work as index 0 so false for it 
        ans=max(ans,i-Map[sum-k]);
        
        if(Map.find(sum)==Map.end())
        Map[sum]=i;
    }
    return ans;
}
