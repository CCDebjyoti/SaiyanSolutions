bool comp(vector<int> &a,vector<int> &b) {
	return a[1]<b[1];
}//sort using end times as priority to intervals finish early 
class Solution {
public://we want to remove least no of intervals which is only possible when 
//we sort with end times as that leads to least no of intervals overlap 
    int eraseOverlapIntervals(vector<vector<int>>& ix) {
        //if(ix.size()==1)return 0;
        //sort based on first index 
        sort(ix.begin(),ix.end(),comp);
        int ans=0;
        int j=0;
        int compx=ix[0][1];
        for(int i=1;i<ix.size();i++){
          if(compx>ix[i][0])ans++;
          else compx=ix[i][1];
        }
        return ans;
    }
};
