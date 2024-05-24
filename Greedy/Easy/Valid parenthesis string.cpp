
    bool checkValidString(string s) {// we store index not values 
        stack<int>open;//store open bracket 
        stack<int>astr;//store star here 
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')open.push(i);
            else if(s[i]=='*')astr.push(i);
            else {//if ) then either opening bckt or astrxs should be avilable else not valid
                if(!open.empty())open.pop();
                else if(!astr.empty())astr.pop();
                else return false;
            }
        }
        while(!open.empty() && !astr.empty()){//we only want our open stack empty then its proff tha all valid 
            if(astr.top()<open.top())return false;// * can be treated as ) but only when it ocurrs after ) not before 
            open.pop();// (* true *( not true as index of astr before 
            astr.pop();
        }
        return open.empty();
    }
