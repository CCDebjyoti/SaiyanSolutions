class Solution {
  public:
    int maxMeetings(vector<int>& S, vector<int>& F) {
        int N=S.size();//if we choose a meeting we cant have another meeting before the end time of last meeting 
        vector<vector<int>>str;
        for(int i=0;i<N;i++){
            str.push_back({F[i],S[i]});
        }
        sort(str.begin(),str.end());//sorting based on end times as earliest finish one
        int ans1=1;//min one meeting will occur
        int freetime=str[0][0];//meeting that ends the quickest
        for(int i=1;i<N;i++){
            if(str[i][1]>freetime){//strict freetime
                ans1++;
                freetime=str[i][0];//update new freetime
            }
        }
        return ans1;
    }
   
};
