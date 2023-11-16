class Solution {
public:
   string ans;
    int solve(unordered_set<string>&st,string str,int len){
    if (len==0) {//base case 
        if(st.find(str)==st.end()){//if not found in nums we got our answer 
                ans=str;
                return true;//note we can return string ans and empty string then check if size>0 we got ans return ans else continue we do true flase 
            }
            return false;//single output so O(n+1) time not 2^n
    }
      if(solve(st,str+'0',len-1))return true;  
       if(solve(st,str+'1',len-1))return true;
    return false;//using single op technique T or F
    }
    string findDifferentBinaryString(vector<string>& nums) {
         unordered_set<string>st;//put our ip in set ease in checking if str present in nums..
         for(int i=0;i<nums.size();i++){
             st.insert(nums[i]);
         }
         solve(st,"",nums[0].size());
         return ans;
    }
};
