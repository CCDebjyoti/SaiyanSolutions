class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {//max subarray with k swaps 
        vector<int>freespace;
        freespace.push_back(startTime[0]-0);//starting can have free space 
        for(int i=0;i<startTime.size()-1;i++){
         freespace.push_back(startTime[i+1]-endTime[i]);
        }
        freespace.push_back(eventTime-endTime.back());//end can have free space 
        int n=freespace.size();
        int ans=0;
        int sum=0;
        int i=0;
        int j=0;
        while(j<n){
            sum+=freespace[j];
            if(j-i+1>k){
                ans=max(ans,sum);
                sum=sum-freespace[i];
                i++;
            }
            ans=max(ans,sum); //redundant dont need to give 
            j++;
        }
        return ans;
    }
};
