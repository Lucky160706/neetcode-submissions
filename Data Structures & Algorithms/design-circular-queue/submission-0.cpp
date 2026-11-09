class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        capacity = k;
        queue.resize(k);    // Allocate k slots

        count = 0;
        front = 0;
        back = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;

        // Insert at the next available queue
        queue[front] = value;
        count++;
        front = (front + 1) % queue.size();
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;

        count--;

        // Remove the oldest element at back
        back = (back + 1) % queue.size();
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return queue[back];
    }
    

    int Rear() {
        if (isEmpty()) return -1;

        return queue[(front - 1 + capacity) % queue.size()];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }

private:
    vector<int> queue;
    int capacity;
    int front;
    int back;
    int count;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */