//brute -> calc bits two loops while O(Nlog(max)) N*32 bits while(t!=0){
     // if((t&1)==1)cnt++;
   //    t=t>>1;

vector<int> countBits(int n) {//O(n)
        vector<int>ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++){
        if(i%2==1){//if num odd its bits equal to /2 +1 eg-> 7 - 0111 7/2=3 - 0011 
            ans.push_back(ans[i/2]+1); //this is becuase /2 is right shift by 1 
        }
        else {
            ans.push_back(ans[i/2]);// even same bits 4-100 2-010 using this count bits of larger value 
        }
        }
        return ans;
    }
