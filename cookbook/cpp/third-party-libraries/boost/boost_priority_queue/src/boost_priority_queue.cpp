#include <iostream>

// PriorityQueue is expected to be a max-heap of integer values
template <typename PriorityQueue>
void basic_interface(void)
{
    PriorityQueue pq;

    pq.push(2);
    pq.push(3);
    pq.push(1);

    cout << "Priority Queue: popped elements" << endl;
    cout << pq.top() << " "; // 3
    pq.pop();
    cout << pq.top() << " "; // 2
    pq.pop();
    cout << pq.top() << " "; // 1
    pq.pop();
    cout << endl;
}
