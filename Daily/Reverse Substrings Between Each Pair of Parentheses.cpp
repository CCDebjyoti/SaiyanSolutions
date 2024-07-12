class Solution {//wormhole teleportation 
public://https://www.youtube.com/watch?v=65wVufni3tg&t=1s
    string reverseParentheses(string s) {
        int n=s.size();
        string ans;
        stack<int>st;//stack to store opposite parenthesis index for eg ( -- 1   -- )--3 so store in array for O(1) traversal to get index
        vector<int>openindx(n,-1);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
             int x=st.top();
             st.pop();
             openindx[x]=i;
             openindx[i]=x;
            }
        }
        int dir=1;//dir changes based on bracked inward or outward 
        for(int i=0;i<n;i+=dir){
         if(s[i]=='(' || s[i]==')'){
          i=openindx[i];
          dir*=-1;
         }
         else ans.push_back(s[i]);
        }
        return ans;    
    }
};
