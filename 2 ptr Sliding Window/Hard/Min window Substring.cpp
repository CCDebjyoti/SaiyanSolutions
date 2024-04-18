class Solution {
public:
    string minWindow(string s, string t) {
        int m=t.size();
        int n=s.size();
        if(m>n)return ""; 
        int stri=0,strj=0;
        int i=0,j=0,cnt,mini=INT_MAX;
        unordered_map<int,int>Map;
        for(int i=0;i<m;i++)Map[t[i]]++;//hash t in map
        cnt=Map.size();
        while(j<n){
            if(Map.find(s[j])!=Map.end()){//sldiding window template eg->Map[s[j]]++
                Map[s[j]]--;
                if(Map[s[j]]==0)cnt--;
            }
            
         while(cnt==0){//optimise window size if possible shrink it 
        if(j-i+1<mini){//update answer 
                 mini=j-i+1;
                 stri=i;
                 strj=j;
            }
         if(Map.find(s[i])!=Map.end()){
                Map[s[i]]++;
                if(Map[s[i]]==1){
                cnt++;
                }
            }
         i++;
         }
        j++;
        }
        string r = s.substr(stri, strj-stri+1);
        return mini==INT_MAX?"":r;

    }
};
