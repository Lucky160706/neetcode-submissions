class MedianFinder {
public:
    MedianFinder() {
        
        
    }
    
    void addNum(int num) {
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }

        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        int total_size = left.size() + right.size();
        if (total_size % 2 == 0) {
            return ((double) left.top() + right.top()) / 2;
        } else {
            return left.top();
        }
    } 

private:
    // Max Heap: smaller half
        priority_queue<int> left;

        // Min Heap: larger half
        priority_queue<int, vector<int>, greater<int>> right;
};
