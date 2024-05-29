class Solution {
public:// 1101 - 13 --> 111 -7 one right shift and one add --> 11-3 --> 1
    int numSteps(string s) {
        int carry=0,ans=0;
        for(int i=s.size()-1;i>=1;i--){//i>=1 as for 10 ans++ -> 1 if i>=0 ans+2 so op-3 correct op 1 
            if((s[i]-'0'+carry)%2==1){
                carry=1;
                ans+=2;
            }
            else ans++;
        }
        return ans+carry;
    }
};
