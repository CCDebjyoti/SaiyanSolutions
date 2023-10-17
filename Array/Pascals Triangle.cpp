class Solution {
public:
    vector<vector<int>> generate(int n/*no of rows */) {
        vector<vector<int>>ans(n);
       
        for(int i=0;i<n;i++){
            ans[i].resize(i + 1);// i+1 as =no of rows 
            ans[i][0]=1;//first element always 1
            ans[i][i]=1;// last element always 1
            for(int j=1;j<i;j++){
                ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
            }
           
        }
        return ans;
        
    }
 // TYPE 2 return row 

   vector<int> getRow(int rowIndex) {
        vector<int>ans;
        ans.push_back(1);
        if(rowIndex==0)return ans;
         long long res=1;
        for(int i=1;i<rowIndex;i++){
           res = res * (rowIndex-i+1) ;
            res=res/i;
            ans.push_back(res);
        }
        ans.push_back(1);
        return ans;
        
    }
};
