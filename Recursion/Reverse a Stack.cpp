class Solution{
public:
    void Reverse(stack<int> &st){//draw tree or call stack or flow of program 
        if(st.size()==1){//we use smaller input and call rev it reverses the stack then we call insert which puts the ele in correct position in the stack 5 4 3  2 1 .. (4 3 2 1 ,5) insert puts 5 at bottom of st
            return;
        }
        int ele=st.top();
        st.pop();
        Reverse(st);
        insert(st,ele);
        
        
    }
    void insert(stack<int>&st,int ele){//ele goes to end of stack 
        if(st.size()==0){
        st.push(ele);
        return ;
        }
        int temp=st.top();
        st.pop();
        insert(st,ele);
        st.push(temp);
        
    }
};
