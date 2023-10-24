//M 1 ---> repating found in map s2=-repating now add sum to s2 now s2=n*n+1/2 now return {repeating,s1-s2} 
// M-2 Optimal --->
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
    long long n=a.size();
    // S1-Sn =x-y
    // S2-S2N =x^2 -Y^2
    
    int sn=(n*(n+1))/2;
    long long s2n=(n*(n+1)*(2*n+1))/6;
    
    int s2=0;
    int s1=0;
    for(int i=0;i<n;i++){
      s1+=a[i];
      s2+=(long long)a[i]*(long long)a[i];
    }
    int val1=s1-sn;
    int val2=s2-s2n;
    val2=val2/val1;
    
    int x=(val1+val2)/2;
    int y=val2-x;
    
    return {x,y};
    
}
