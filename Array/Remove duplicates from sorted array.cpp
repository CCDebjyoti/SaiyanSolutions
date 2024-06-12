class Solution {//[0,0,1,1,1,2,2,3,3,4]--> 0 1 0 1 1 .. --> 0 1 2 0 1 1..-> 0 1 2 3 0 1 1 ..-> 0 1 2 3 4 0 1 1  ...
public:
    int removeDuplicates(vector<int>& nums) {
        int j=1,i=0;
        while(i<nums.size() && j<nums.size()){
            if(nums[i]==nums[j]){
                j++;
            }
            else {
                swap(nums[j],nums[i+1]);
                i++;
                j++;
            }
        }
        return i+1;
    }
};
