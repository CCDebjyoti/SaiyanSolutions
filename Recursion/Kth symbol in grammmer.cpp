class Solution {
public:                              //K=1 observe that the after mid we have ! values  of it before n-1 th values 
    int kthGrammar(int n, int k) {//N=1  0 
        return solve(n,k);        //N=2  0 1 
    }                             //N=3  0 1 1 0 
    int solve(int n,int k){       //N=4  0 1 1 0 - 1 0 0 1 
        if(n==1 && k==1)return 0;
         int mid=(pow(2,n-1))/2; 
        if(k<=mid){
            return solve(n-1,k);
        }
        else return !(solve(n-1,k-mid));
    }
}; 
