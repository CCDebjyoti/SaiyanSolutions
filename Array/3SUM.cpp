class Solution {
public:
        //TC -> Nlog(N)+O(N*N)
        //SC->  O(No of unique triplets)
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans; // can use set also then no need to check for j=j-1 and k at last ans(st.begin(),st.end())
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
             int sum=nums[i]+nums[j]+nums[k];
             if(sum<0){
                 j++;
             }
             else if(sum>0){
                 k--;
             }
             else{//triplet found
               vector<int>tmp={nums[i],nums[j],nums[k]};
                ans.push_back(tmp);
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1])j++;//no same elements dups
                while(j<k && nums[k]==nums[k+1])k--;//k+1 as check next movingback
             }
            }

        }
        return ans;
    }
};
