int lowerBound(vector<int> arr, int n, int x) {
	//LOWER BOUND
	vector<int>::iterator low = lower_bound(arr.begin(),arr.end(),x);
	return low-arr.begin();
	//UPPER BOUND
	vector<int>::iterator upeer=upper_bound(arr.begin(),arr.end(),x);
	return upeer-arr.begin();
}
