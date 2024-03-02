class Solution {
public://every num 3 times except 1 number so adding all bits mod 3 gives left over 
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int sum=0;
            for(int j=0;j<nums.size();j++){// array [ 2 2 2 1 ]--> 2 = 0 1 0  3 times add 0 3 0  adding 1 --> 0 3 1 mod 3--> 0 0 1 ans we got 
                if((nums[j]>>i)&1==1){
                    sum++;
                }
            }
            sum=sum%3;//multiple of 3 adding up all bits in ith position 
            if(sum!=0){
                ans|=sum<<i;
            }
        }
        return ans;
    }
};
//M-2
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int i = 0; i < nums.size(); i++){
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};
