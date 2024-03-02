bool isPowerOfTwo(int n)
{	
    // Write your code here.
    if((n&(n-1))==0)return 1;// n==4 -> 100 
    return 0;                // n==3 -> 011 // & both we get 0 for power of 2 single 1 
}
