
class Solution {
  public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        // code here
         int n=id.size();
        vector<pair<pair<int, int>, int>> jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({{ profit[i],deadline[i]}, id[i]});
        }//sorting based on profit only care about top deadline profits
        sort(jobs.begin(), jobs.end(), greater<pair<pair<int, int>, int>>());
        
        int maxdeadline=0;
        for(int i=0;i<n;i++){
            maxdeadline=max(maxdeadline, jobs[i].first.second);
        }
        vector<int>slots(maxdeadline+1, -1);//hash map of max size deadline as +1 coz 0 index so..
        int totalprofit=0, count=0;
        for(int i=0;i<n;i++){ //put max profit elements first hash change from -1 as used up now if that hash[i] is already in use just traverse back to find 
          //a index before deadline not 0.. which is not -1 so we can use that time slot for our profit 
            for(int j=jobs[i].first.second;j>0;j--){//j=deadline
                if(slots[j]==-1){
                    slots[j]=i;
                    totalprofit+=jobs[i].first.first;
                    count++;//cnt no of jobs
                    break;
                }
            }
        }
        return {count, totalprofit};
    }
};
