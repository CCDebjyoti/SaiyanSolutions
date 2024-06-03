int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];//first elem pivot
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) i++;//find greater than pivot int left

        while (arr[j] > pivot && j >= low + 1) j--;//find less than pivot in right

        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);//leaving partiton solve as partion in correct positon 
        qs(arr, pIndex + 1, high);
    }
}

vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    qs(arr,0,arr.size()-1);
    return arr;
}
