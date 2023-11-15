//Brute Force-> for every i from min to max check for solve if true return min TC->O(N*(max-min)) else i++;

class Solution {//TC-> O(N*log2(max-min))
public:
// flower will bloom during nums[i] day 
//[7,4,3,6] 0th flower will bloom on 7 th day n-1 flower will bloom on 6th day need adjacent k flowers in boque 
    int solve(vector<int>&nums,int mid,int k){
        int cnt=0;
        int kk=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid) kk++;  
            else kk=0;
            if(kk==k){
             kk=0;
             cnt++;
            }
        }
        return cnt;
    } 
     
    int minDays(vector<int>& nums, int m, int k) {
        int n=nums.size();
        if(n<(long long)m*k)return -1; 
         long long int low=1;//can start from min also as first flower will bloom on min day 
        long long high=*max_element(nums.begin(),nums.end());
         while(low<=high){
            int mid=(high+low)/2;
            int cnt=solve(nums,mid,k); 
            if(m>cnt){ //if not possible we cant have answer at left 
               low=mid+1;           
            }
            else {//check for more minimum minimize it check left more eliminate right
                high=mid-1;
                ans=mid;
            }
        }  
        return low; || return ans;//ans=-1 initialize
    }
};
