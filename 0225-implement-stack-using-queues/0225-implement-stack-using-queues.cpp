class MyStack {
public:
    queue<int> q;
    int size = 0;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for (int i=0; i< size; i++){
            q.push(q.front());
            q.pop();
        }
        size++;
    }
    
    int pop() {
        if(size == 0) return -1;
        int temp = q.front();
        q.pop();
        size--;
        return temp;
    }
    
    int top() {
        if(size == 0) return -1;
        return q.front();
    }
    
    bool empty() {
        if(size == 0) return true;
        return false;
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