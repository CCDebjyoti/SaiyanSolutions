class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef pair<int,int>pi;
        unordered_map<int,int>Map;
        priority_queue<pi,vector<pi>,greater<pi>>pq;//min heap nlogk
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            Map[nums[i]]++;
        }
        for(auto it:Map){
            pq.push({it.second,it.first});
            if(pq.size()>k)pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
