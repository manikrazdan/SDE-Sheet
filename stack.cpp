class Stack {
private:
    vector<int> v;
    int ind,siz;
public:
    Stack(int capacity) {
        v.resize(capacity);
        ind=0;
        siz=capacity;
    }
    void push(int num) {
        if (ind==siz) return;
        v[ind]=num;
        ind++;
    }
    int pop() {
        if (ind==0) return -1;
        ind--;
        return v[ind];
    }
    int top() {
        if (ind==0) return -1;
        return v[ind-1];
    }
    int isEmpty() {
        return (ind==0);
    }
    int isFull() {
        return (ind==siz);
    }
};
