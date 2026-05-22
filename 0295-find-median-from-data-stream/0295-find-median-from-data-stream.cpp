class MedianFinder {
public:
    priority_queue<int> pq_left; // max heap
    priority_queue<int, vector<int>, greater<>> pq_right; // min heap

    MedianFinder() {}

    void addNum(int num) {
        // insert in correct heap
        if (pq_left.empty() || num <= pq_left.top()) {
            pq_left.push(num);
        } else {
            pq_right.push(num);
        }

        // balance sizes
        if (pq_left.size() > pq_right.size() + 1) {
            pq_right.push(pq_left.top());
            pq_left.pop();
        }
        else if (pq_left.size() < pq_right.size()) {
            pq_left.push(pq_right.top());
            pq_right.pop();
        }
    }

    double findMedian() {
        if (pq_left.size() == pq_right.size()) {
            return (pq_left.top() + pq_right.top()) / 2.0;
        }
        return pq_left.top();
    }
};