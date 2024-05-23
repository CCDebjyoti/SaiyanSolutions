class Solution {
public://always use largest denomination money first for giving the change.
    bool lemonadeChange(vector<int>& bills) {
        //sort(bills.begin(),bills.end());//cust in queue no sort 
        int five=0,ten=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5)five++;
            else if(bills[i]==10){
                if(five){
                    five--;
                    ten++;
                }
                else return false;
            }
            else {
                if(five>=1 && ten>=1){//this is must first as lower den money used last
                    five--;//giving 5x3 first can casue prob if 10 after that 
                    ten--;//we can always make a 10 from 2 5's
                }
                else if(five>=3){
                    five-=3;//choose 10 and 5 over 3x5 preserve 5 greedyly
                }
                else return false;
            }
        }
        return true;
    }
};
