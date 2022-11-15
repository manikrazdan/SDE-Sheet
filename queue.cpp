class Queue {
private:
    vector<int> v;
    int ind=0;
public:
    Queue() {
    }
    bool isEmpty() {
        return (ind==v.size());
    }
    void enqueue(int data) {
        v.push_back(data);
    }
    int dequeue() {
        if (ind==v.size()) return -1;
        ind++;
        return v[ind-1];
    }
    int front() {
        if (ind==v.size()) return -1;
        return v[ind];
    }
};
