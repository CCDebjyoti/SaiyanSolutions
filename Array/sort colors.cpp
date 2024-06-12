class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0;//low points to 0 track if 0 low++
        int high=nums.size()-1;//high tracks 2 so if 2 high --
        int mid =0;//mid tracks 1
        while(mid<=high){
            if(nums[mid]==0)swap(nums[low++],nums[mid++]);
            else if(nums[mid]==1)mid++;
            else swap(nums[mid],nums[high--]);
        }
    }
};
