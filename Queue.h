#include <cassert>
class Queue {
private:
    int *data;
    int head, tail, length;
public:
    Queue(int length_input) {
        data = new int[length_input];
        length = length_input;
        head = 0;
        tail = -1;
    }
    ~Queue() {
        delete[] data;
    }
    void push(int element) {
        if (tail + 1 < length) {
            tail++;
            data[tail] = element;
        }
    }
    void output() {
        for (int i = head; i <= tail; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    int front(){
        assert(head <= tail); //队列是否为空
        return data[head];
    }
    void pop(){
        assert(head <= tail); //队列是否为空
        head += 1;
    }
    
};