class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();//one ptr stays constant and one moves 
        int m=matrix[0].size();//two ptr for col traversal two for row
        int left =0;//points first col
        int right =m-1;//points to last col
        int top =0;//points first row
        int bottom=n-1;//points to last row 
        vector<int>ans;
        while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++){//
                ans.push_back(matrix[top][i]);
            }
            top++;//row 0(i)that top is pointing to has been traversedd
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;//last col(ith) has been traversedd 
            if(top<=bottom){//for single row elemts will get repeated
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            }
            if(left<=right){//for single col else it will print repeat elements 
            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
            }
        }
        return ans;
        
    }
};
