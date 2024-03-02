int setBits(int N){
    // Write your code here.
    if((N&(N+1))==0)return N;//if 7 -> 111 so all set no need to set  if or turns 15 so 8-> 1000 & check
    return (N|(N+1));// unset is 5-> 101 add 1 -> 110 now or 
}
