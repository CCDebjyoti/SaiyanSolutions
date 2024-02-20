class Solution { // Nlogm
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m=mat[0].size();
        int low=0;
        int high=mat[0].size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            int a=0;
            for(int i=0;i<mat.size();i++){
                if(mat[i][mid]>mat[a][mid]){//max element of coloumn is greater than top and bottom
                    a=i;
                }
            }
            int left=mid-1>=0 ? mat[a][mid-1]:-1;
            int right=mid+1< m ? mat[a][mid+1]:-1;
            if( mat[a][mid]>left && mat[a][mid]>right){
                return {a,mid};
            }
            else if (mat[a][mid]<left)high=mid-1; //if left greater meaning peak present on left /\ 
            else low=mid+1;
        }
        return {-1,-1};
    }
};
