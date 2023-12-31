class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         if(intervals.size()<=1) return intervals;
         sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        int j=0;

    for(int i=1;i<intervals.size();i++){
        // ans[j][1]=max(ans[j][1],intervals[i][1]); not stack (just chaning the last if bigger )
        if(ans[j][1]>=intervals[i][0]){ // if in range or merge possible [1,4][4,5] --> [1,5] 
            int t1=ans[j][0];
            int t2=max(intervals[i][1],ans[j][1]);//if one intervals lies within another [1,4] [2,3] --> [1,4] 
                ans.pop_back();
                ans.push_back({t1,t2});
            }
            else {
                ans.push_back(intervals[i]);
                j++;
            }

        }
        return ans;
    }
};
