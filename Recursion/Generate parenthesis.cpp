class Solution {
    public:
    vector<string>ans;
    void paren(int open ,int close,string op){
        if(open==0 && close==0){
            ans.push_back(op);
            return;
        }
        if(open>0){//as base case for both op and cl lead to tle if not this case op becomes negative no base condition 
           op.push_back('(');
            paren(open-1,close,op);
            op.pop_back();
             //paren(open+1,close,op+"(")
        }
        if(close>open){
            op.push_back(')');
            paren(open,close-1,op);
            op.pop_back();
            //paren(open,close-1,op+")")
           }
        
    }
    vector<string> generateParenthesis(int n) {
        
        paren(n,n,"");
        return ans;
    }
};
