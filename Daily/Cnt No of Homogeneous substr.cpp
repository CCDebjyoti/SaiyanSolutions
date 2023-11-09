//zzzzz -> ans -> 15 
//abbcccaa -> ans -> 13 a->1 bb->1+2 ccc->6 aa->1+2
class Solution {
public://two ptr and n*n+1 /2 
    int countHomogenous(string s) {
        int i=0,j=0;
        long long  sum=0 , m=1e9 +7;
        while(j<s.size()){
            long long cnt=1;
            j=i+1;
            if(s[i]==s[j]){
            while(s[i]==s[j] && j<s.size()){
                cnt++;
                j++;
            }
            i=j;
            }
            else {
                i++;
            }
            sum+=(cnt*(cnt+1)/2)%m;

            
        }
        return sum%m;
    }
};
