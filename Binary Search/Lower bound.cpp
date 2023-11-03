int lowerBound(vector<int> arr, int n, int x) {
	vector<int>::iterator low = lower_bound(arr.begin(),arr.end(),x);
	return low-arr.begin();
}
