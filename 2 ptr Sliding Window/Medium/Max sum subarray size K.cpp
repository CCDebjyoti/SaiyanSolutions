  int i=0,j=0;
        long long int sum=0;
        long long int ans=Arr[0];
        while(j<N){
            if(j-i==k){
                sum-=Arr[i++];
            }
            else {
                sum+=Arr[j++];
            }
            ans=max(sum,ans);
        }
        return ans;
