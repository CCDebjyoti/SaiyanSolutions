class Solution {
  public://is elem atleast k dist away from index 
    string isKSortedArray(int arr[], int n, int k)
    {
        //code here.
        typedef pair<int,int>pi;
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        for(int i=0;i<n;i++){
            pq.push({arr[i],i});
        }
        int cnt=0;
        while(!pq.empty()){
            int left=pq.top().second-k;
            int right=pq.top().second+k;
            if(right<cnt || left>cnt){
             return "No";
            }
            cnt++;
            pq.pop();
        }
        return "Yes";
    }
};
