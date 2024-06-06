void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array//to merge and store 
    int left = low;      // starting index of left half of arr// [0,2] left is 0
    int right = mid + 1;   // right is 2 as two arrays [0,1] and [2]
    //storing elements in the temporary array in a sorted manner//
    while (left <= mid && right <= high) {//store smaller element first 
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    // if elements on the left half are still left //elements still left on any arrays
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    // transfering all elements from temporary to arr //[3,5] arr[3]=temp[3-3]-->temp[0] for arr[4]=temp[4-3]--temp[1]
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}
//
void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}
