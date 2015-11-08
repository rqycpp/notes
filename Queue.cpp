#include <iostream>
#include <cassert>
using namespace std;
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
        assert(head <= tail);
        return data[head];
    }
    void pop(){
        assert(head <= tail);
        head += 1;
    }
    
};
int main() {
    Queue queue(100);
    for (int i = 1; i <= 10; i++) {
        queue.push(i);
    }
    queue.output();
    cout<<queue.front()<<endl;
    queue.pop();
    queue.output();
    return 0;
}
