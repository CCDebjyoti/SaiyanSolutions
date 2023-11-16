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
//M - 2
//convert string to number eg -> 111 - 7 how ? stoi(nums[i],0,2) (str,starting pos,base) put in set 
//check for 0-> n+1 in set if not found convert back ans=bitset<16>(num).to_string();
//we only need last n digits so substr(16-n)


//M-3 Most optimal O(N) O(1) // we know we want diffrent to inp so why not change 1st place for 1st string 2nd for 2nd 
//eg -> 111 101 111 ->ans = 0 _ _ now 01 _ then 010 we got ans
//to make diffrent from ip we change one diffrence in curr string can be any here i changed if 1 -> 0 to get diff string 
string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        for(int i=0;i<nums.size();i++){
            ans+=nums[i][i]=='0'?'1':'0';
        }
        return ans;
    }

