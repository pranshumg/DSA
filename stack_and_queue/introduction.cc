#include <bits/stdc++.h>

using namespace std;

/* introduction to stack and queue */

// stack implementation using array
class stack_arr {
private:
  int top = -1, sz = 10; 
  int sk[10];
  
public:
  // TC - O(1), SC - O(1)
  void push(int val) {
    if (top >= sz - 1) {
      cout << "stack overflow\n";
      return;
    }
    sk[++top] = val;
  }
  
  // TC - O(1), SC - O(1)
  int get_top() {
    if (top == -1) {
      return INT_MIN;
    }
    return sk[top];
  }
  
  // TC - O(1), SC - O(1)
  void pop() {
    if (top == -1) {
      cout << "stack underflow\n";
      return;
    }
    top--; 
  }
  
  // TC - O(1), SC - O(1)
  int size() {
    return top + 1;
  }
};

// queue implementation using array
class queue_arr {
private:
  int front = -1, rear = -1, sz = 10, cur_sz = 0;
  int qe[10];
  
public:
  // TC - O(1), SC - O(1)
  void push(int val) {
    if (cur_sz >= sz) {
      cout << "queue overflow\n";
      return;
    } 
    if (rear == -1) {
      front++;  
    }
    rear = (rear + 1) % sz;
    qe[rear] = val;
    cur_sz++;
  }
  
  // TC - O(1), SC - O(1)
  int get_front() {
    if (cur_sz == 0) {
      return INT_MIN;
    }
    return qe[front];
  }
  
  // TC - O(1), SC - O(1)
  void pop() {
    if (cur_sz == 0) {
      cout << "queue underflow\n";
      return;
    }
    if (cur_sz == 1) {
      front = rear = -1;
    } else {
      front = (front + 1) % sz;
    }
    cur_sz--;
  }
  
  // TC - O(1), SC - O(1)
  int size() {
    return cur_sz;
  }
};

class Node {
public:
  int info;
  Node* next;
  
  Node(int info, Node* next) {
    this->info = info; 
    this->next = next;
  }
};

// stack implementation using linked list
class stack_ll {
private:
  Node* top = nullptr;
  int cur_sz = 0;
  
public:
  // TC - O(1), SC - O(1)
  void push(int val) {
    top = new Node(val, top);
    cur_sz++;
  }
  
  // TC - O(1), SC - O(1)
  int get_top() {
    if (!top) {
      return INT_MIN;
    }
    return top->info;
  }
  
  // TC - O(1), SC - O(1)
  void pop() {
    if (!top) {
      cout << "stack underflow\n";
      return;
    }
    Node* del = top;
    top = top->next;
    delete del;
    cur_sz--;
  }
  
  // TC - O(1), SC - O(1)
  int size() {
    return cur_sz;
  }
};

// queue implementation using linked list
class queue_ll {
private:
  Node* front = nullptr;
  Node* rear = nullptr;
  int cur_sz = 0;

public:
  // TC - O(1), SC - O(1)
  void push(int val) {
    if (!rear) {
      rear = new Node(val, nullptr);
      front = rear;
    } else {
      rear->next = new Node(val, nullptr);
      rear = rear->next;
    }
    cur_sz++;
  }
  
  // TC - O(1), SC - O(1)
  int get_front() {
    if (!front) {
      return INT_MIN;
    }
    return front->info;
  }
  
  // TC - O(1), SC - O(1)
  void pop() {
    if (!front) {
      cout << "queue underflow\n";
      return;
    }
    Node* del = front;
    if (cur_sz == 1) {
      front = rear = nullptr;
    } else {
      front = front->next;
    }
    delete del;
    cur_sz--;
  }
  
  // TC - O(1), SC - O(1)
  int size() {
    return cur_sz;
  }
};

// stack implementation using queue
class stack_qe {
private:
  queue<int> qe;

public:
  // TC - O(n), SC - O(1)
  void Push(int val) {
    qe.push(val);
    for (int i = 0; i < int(qe.size()) - 1; i++) {
      qe.push(qe.front());
      qe.pop();
    }
  }

  // TC - O(1), SC - O(1)
  int get_top() {
    if (qe.empty()) {
      return INT_MIN;
    }
    return qe.front();
  }
  
  // TC - O(1), SC - O(1)
  void Pop() {
    if (qe.empty()) {
      cout << "stack underflow\n";
      return;
    }
    qe.pop();
  }
  
  // TC - O(1), SC - O(1)
  int size() {
    return int(qe.size());
  }
};

// queue implementation using stack
// approach 1
class queue_sk {
private:
  stack<int> sk1, sk2;

public:
  // TC - O(n), SC - O(1)
  void Push(int val) {
    while (!sk1.empty()) {
      sk2.push(sk1.top());
      sk1.pop();
    }
    sk1.push(val);
    while (!sk2.empty()) {
      sk1.push(sk2.top());
      sk2.pop();
    }
  }

  // TC - O(1), SC - O(1)
  int get_front() {
    if (sk1.empty()) {
      return INT_MIN;
    }
    return sk1.top();
  }
  
  // TC - O(1), SC - O(1)
  void Pop() {
    if (sk1.empty()) {
      cout << "queue underflow\n";
      return;
    }
    sk1.pop();
  }
  
  // TC - O(1), SC - O(1)
  int size() {
    return int(sk1.size());
  }
};

// approach 2
class queue_sk {
private:
  stack<int> sk1, sk2;

public:
  // TC - O(1), SC - O(1)
  void Push(int val) {
    sk1.push(val);
  }
  
  // TC - O(n), SC - O(1)
  int get_front() {
    if (sk1.empty() && sk2.empty()) {
      return INT_MIN;
    }
    if (sk2.empty()) {
      while (!sk1.empty()) {
        sk2.push(sk1.top());
        sk1.pop();
      }
    } 
    return sk2.top();
  }
  
  // TC - O(n), SC - O(1)
  void Pop() {
    if (sk1.empty() && sk2.empty()) {
      cout << "queue underflow\n";
      return;
    }
    if (sk2.empty()) {
      while (!sk1.empty()) {
        sk2.push(sk1.top());
        sk1.pop();
      }
    } 
    sk2.pop();
  }

  // TC - O(1), SC - O(1)
  int size() {
    return int(sk1.size()) + int(sk2.size());
  }
};