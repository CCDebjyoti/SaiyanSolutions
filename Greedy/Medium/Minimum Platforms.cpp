//another method is to make a hash array of size 2360 and put all elements between the time in that 
//now find max count of elments 2360*N 
int findPlatform(vector<int>& S, vector<int>& F) {//line sweep algo
        // Your code here
        int N=S.size();
        sort(S.begin(),S.end());
        sort(F.begin(),F.end());
        int i=1;
        int j=0;
        int ans=1;
        int cnt=1;
        while(i<N && j<N){
            if(S[i]<=F[j]){
                cnt++;
                i++;
            }
            else {
                cnt--;
                j++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
