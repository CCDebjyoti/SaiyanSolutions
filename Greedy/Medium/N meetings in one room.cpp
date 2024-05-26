int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>time;
        for(int i=0;i<n;i++){
            time.push_back({end[i],start[i]});
        }
        sort(time.begin(),time.end());
        int ans=1,endx=time[0].first;
        for(int i=1;i<n;i++){
            if(time[i].second>endx){//start > last end time
                ans++;
                endx=time[i].first;//last ending saving so not equal to start 
            }
        }
        return ans;
    }
// multi map
int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        multimap<int,int> mp;
        for(int i=0;i<n;i++)
            mp.insert(pair<int, int>(end[i], start[i]));
        int cnt = 1;
        int temp = mp.begin()->first;
        for(auto it:mp)
        {
            if(temp< it.second)
            {    
                cnt++;
                temp = it.first;
            }
        }
        return cnt;
    }
