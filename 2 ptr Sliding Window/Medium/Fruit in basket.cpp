class Solution {
public:
    int totalFruit(vector<int>& fruits) {// Longest subarray with 2 distinct character also K distinct 
       unordered_map<int,int>Map;
       int i=0,j=0,ans=0;
        while(j<fruits.size()){
            Map[fruits[j]]++;
                while(Map.size()>2 ){//map.size() return unique no char in the map 
                    Map[fruits[i]]--;//iterate till map size becomes equal to 2 
                    if(Map[fruits[i]]==0)Map.erase(fruits[i]);//erase from map if freq becomes zero 
                    i++;
                }
    
            ans=max(ans,j-i+1);
            j++;
        } 
        return ans;
    }
};
