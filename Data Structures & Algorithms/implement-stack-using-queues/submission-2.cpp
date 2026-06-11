class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {

    }
    
    void push(int x) {
        if (!q1.empty()) q1.push(x);
        q2.push(x);
    }
    
    int pop() {
        // Determine which queue has the elements and which is empty
        queue<int>& active = q1.empty() ? q2 : q1;
        queue<int>& empty_q = q1.empty() ? q1 : q2;
        
        // Transfer all but the last element
        while (active.size() > 1) {
            empty_q.push(active.front());
            active.pop();
        }
        
        // Pop and return the last element
        int temp = active.front();
        active.pop();
        
        return temp;
    }
    
    int top() {
        if (!q1.empty()) return q1.back();
        return q2.back();
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */