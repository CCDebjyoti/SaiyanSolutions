class Solution{
public:
    vector<string>ans;
    void solve(int num,string op,int prev){
        if(num==0){
            ans.push_back(op);
            return;
        }
        op.push_back('0');
        solve(num-1,op,0);
        op.pop_back();
        if(prev!=1){
        op.push_back('1');
        solve(num-1,op,1);
        op.pop_back();
        }
    }
    vector<string> generateBinaryStrings(int num){
        //Write your code
        solve(num,"",0);
        return ans;
    }
};
