#include<bits/stdc++.h>
int kDistinctChars(int k, string &s)//O(2N)
{
    // Write your code here
    unordered_map<char,int>Map;
    int i=0,j=0,ans=0;
    while(j<s.size()){
        Map[s[j]]++;
        while(Map.size()>k){//use if for O(N)
            Map[s[i]]--;
            if(Map[s[i]]==0)Map.erase(s[i]);
            i++;
        }
        ans=max(ans,j-i+1);//if(Map.size()<=k) ans.. 
        j++;
    }
    return ans;
}
