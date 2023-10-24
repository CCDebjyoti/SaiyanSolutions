     void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // idea is simple check if last element of arr1 is greater than last 
            //element of arr2 if so swap move left -- right ++ 
            //if arr1 element smaller no need further as sorted 
            int left=n-1;
            int right=0;
            while(left>=0 && right<m){
                if(arr1[left]>arr2[right]){
                    swap(arr1[left--],arr2[right++]);
                }
                else { // arr1[left]<=arr2[right] sorted no need for more 
                    break;
                }
            }
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
        } 
