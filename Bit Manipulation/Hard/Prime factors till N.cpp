vector<int> countPrimes(int n)
{
    // Write your code here.
    vector<int>ans;
    vector<int>spf(n+1);//0-n so n+1 as index 0 based
     for(int i=0;i<=n;i++){
      spf[i]=i;
    }
    for(int i=2;i*i<=n;i++){
        if(spf[i]==i){//if current i is intact not changed before eg i=4 s[i]=2
            for(int j=i*i;j<=n;j+=i){//2 4 6 8 
                if(spf[j]==j)//for 3 6 15 6->2 dont change with 3 as smallest prf
                spf[j]=i;
            }
        }
    }
    while(n!=1){
        if(ans.size()==0 or ans.back()!=spf[n])//unique char
        ans.push_back(spf[n]);
        n=n/spf[n];
    }
    return ans;


}
