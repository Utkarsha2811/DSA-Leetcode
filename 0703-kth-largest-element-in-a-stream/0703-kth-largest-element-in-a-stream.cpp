class KthLargest {
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int maxCapacity;

public:
    KthLargest(int k, vector<int>& nums) {
        maxCapacity = k;
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > maxCapacity) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */