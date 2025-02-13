bool comp(vector<int> &a,vector<int> &b) {
	return a[1]<b[1];
}//sort using end times as priority to intervals finish early 
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& ix) {
        //if(ix.size()==1)return 0;
        vector<pair<int,int>>stor;//sort based on first index 
        sort(ix.begin(),ix.end(),comp);
        stor.push_back({ix[0][0],ix[0][1]});
        int ans=0;
        int j=0;
        for(int i=1;i<ix.size();i++){
          if(stor[j].second<=ix[i][0]){
          stor.push_back({ix[i][0],ix[i][1]});
            j++;
          }
        }
        ans=ix.size()-stor.size();
        return ans;
    }
};
