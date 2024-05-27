class Solution {
public://bubble sort compare if [3,30] is 330 greater or 303 greater ij or ji if ji greater swap (i,j)
    string largestNumber(vector<int>& nums) {
        string ans;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                string strj=to_string(nums[j])+to_string(nums[i]);;
                string stri=to_string(nums[i])+to_string(nums[j]);;
                if(strj>stri)swap(nums[j],nums[i]);
            }
            ans+=to_string(nums[i]);
        }
        
        return ans[0]=='0'?"0":ans;
    }
};
//M-2
bool compare(string a,string b){
    return a+b > b+a;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
	
        vector<string> container;
        for(int i : nums)  container.push_back(to_string(i));
        sort(container.begin(),container.end(),compare);

        string result;
        
        for(int i=0;i<container.size();i++)  result+=container[i];
        return result[0]=='0'? "0" : result;
    }
};
