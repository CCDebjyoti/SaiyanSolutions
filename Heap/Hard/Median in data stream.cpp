class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int> > minHeap;
	priority_queue<int> maxHeap;
    MedianFinder(){} // 1 2 3 4 5 we want 1 2 3 in max heap and 5 4 in mean heap so from top we get mid element 
    void addNum(int num) {
        if (maxHeap.empty() or maxHeap.top() > num) {//we want all elements of max heap to be less than min element of min heap
			maxHeap.push(num);
		} else minHeap.push(num);
		if (maxHeap.size() > minHeap.size() + 1) {
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		} else if (minHeap.size() > maxHeap.size() + 1) {
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
    }
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
			if (maxHeap.empty()) {
				return 0;
			} else {
				double avg = (maxHeap.top() + minHeap.top()) / 2.0;
				return avg;
			}
		} else {
			return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
		}
    }
};
