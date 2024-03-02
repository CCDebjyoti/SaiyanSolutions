vector<int> twoOddNum(vector<int> arr){
    // Write your code here.
    int x=0;
     for(int i=0;i<arr.size();i++){// 22 44 1 3 
         x=x^arr[i]; // xor only 2 left 1^3  
     }//right most set bit will have either 1 or 3 as both different so only xor gives 1 
     //int rsbm=1;
    /*  while((x&rsbm)!=1){
         rsbm=rsbm<<1;
     } */
     int rsbm=x&-x;
     int one =0;
     int two=0;
     for(int i=0;i<arr.size();i++){
         if((rsbm&arr[i])==0)one=one^arr[i];//if mask & num gives 1 one category eg-> 2 2 1 xor gives 1 answeer 
         else two=two^arr[i];
     }
     if(one<two)return{two,one};
     return {one,two};
}
