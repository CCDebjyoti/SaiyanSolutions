int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    //    Write your code here.
    int index=-1;
    int cnt_max=-1;
    for(int i=0;i<n;i++){
        int l=m-lowerBound(matrix[i],m,1);
        if(cnt_max<l){
            index=i;
            cnt_max=l;
        }
    }
    return index;
}
