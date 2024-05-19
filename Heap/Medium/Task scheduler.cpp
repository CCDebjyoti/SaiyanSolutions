class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>Map(26,0);
        for(int i=0;i<tasks.size();i++){
            Map[tasks[i]-'A']++;
        }
        sort(Map.begin(),Map.end(),greater<int>());
        int idle=(Map[0]-1)*n;//idle spaces for A--A--A n=2 idle spaces available 3-1*2 =4 
        for(int i=1;i<Map.size();i++){ //place elements in idle only
            idle=idle-min(Map[0]-1,Map[i]);//min as a=3 b=3 so 2 ,3 but we want to place in idle not outisde eg A B - A B - A B last b we dont want 
        }
        return max(0,idle)+tasks.size();//but we can have elem after idle so max we can have size of array elements 

    }
};
