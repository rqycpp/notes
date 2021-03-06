#include <iostream>
#include <cassert>
using namespace std;
class Queue {
private:
    int *data;
    int head, tail, length, count;
public:
    Queue(int length_input) {
        data = new int[length_input];
        length = length_input;
        head = 0;
        tail = -1;
        count = 0;
    }
    ~Queue() {
        delete[] data;
    }
    bool push(int element) {
        if (count < length) {
            tail = (tail + 1) % length;
            data[tail] = element;
            count++;
            return true;
        } else {
            return false;
        }
    }
    void output() {
        for (int i = head; i != tail + 1; i = (i + 1) % length) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    int front() {
        assert(count > 0);
        return data[head];
    }
    void pop() {
        assert(count > 0);
        head = (head + 1) % length;
    }
};
int main() {
    Queue queue(100); 
    for (int i = 1; i <= 10; i++) {
        queue.push(i);
    }
    queue.output();
    cout << queue.front() << endl;
    queue.pop();    
    queue.output();
    return 0;
}