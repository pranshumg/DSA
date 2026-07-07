#include <bits/stdc++.h>

using namespace std;

/* Length of cycle */

class Node {
public:
    int info;
    Node* next;

    Node(int info) {
        this->info = info; 
        this->next = nullptr;
    }

    Node(int info, Node* next) {
        this->info = info;  
        this->next = next;
    }
};

// TC - O(n log n), SC - O(n)
int length_cycle(Node* head) {
    map<Node*, int> mp;
    Node* cur = head;
    for (int i = 1; cur; i++) {
        if (mp.count(cur)) {
            return i - mp[cur];
        }
        mp[cur] = i;
        cur = cur->next;
    }
    return 0;
}

// TC - O(n), SC - O(1)
int length_cycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) {
            int len = 1;
            slow = slow->next;
            while (slow != fast) {
                len++;
                slow = slow->next;
            }
            return len;
        }
    }
    return 0;
}