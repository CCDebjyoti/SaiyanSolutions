class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        if(p.size()>s.size())return ans;
        vector<int>Map(26);
        vector<int>window(26);
        for(int i=0;i<p.size();i++){
            Map[p[i]-'a']++;
        }
        int i=0;
        int j=0;
        int w=p.size();
        while(j<s.size()){
             window[s[j]-'a']++;
            if(Map==window)ans.push_back(i);
            if(j-i+1==w){
                window[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
