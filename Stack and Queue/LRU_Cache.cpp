#include <iostream>
#include <unordered_map>
using namespace std;

/*
========================================================
Problem: LRU Cache
Platform: LeetCode (146)
========================================================

Problem Statement:
Design an LRU (Least Recently Used)
Cache supporting the following
operations:

1. get(key)
   - Return the value if the key exists.
   - Otherwise return -1.

2. put(key, value)
   - Insert or update the key.
   - If the cache exceeds its capacity,
     remove the least recently used item.

Both operations should work in
O(1) average time.

========================================================
Approach Used (Hash Map + Doubly Linked List)

Step 1:
Maintain a doubly linked list to keep
track of recently used nodes.

- Front  -> Most Recently Used (MRU)
- Back   -> Least Recently Used (LRU)

Step 2:
Use a hash map to store:

key -> node address

Step 3:
For get():

- If key doesn't exist,
  return -1.
- Otherwise move the node to
  the front and return its value.

Step 4:
For put():

- If key already exists,
  remove the old node.

- If cache is full,
  remove the least recently used node.

- Insert the new node at the front.

Time Complexity:
get() : O(1)
put() : O(1)

Space Complexity: O(capacity)

========================================================
*/


// ------------------------------
// Doubly Linked List Node
// ------------------------------
struct Node {

    Node* next;

    Node* pre;

    int key;

    int val;

    Node() {

        key = -1;

        val = -1;

        next = NULL;

        pre = NULL;
    }

    Node(int keyy, int value) {

        key = keyy;

        val = value;

        next = NULL;

        pre = NULL;
    }
};


class LRUCache {
public:

    int capp = 0;

    int currCapp = 0;

    unordered_map<int, Node*> m;

    Node* head = new Node();

    Node* tail = new Node();

    // ------------------------------
    // Constructor
    // ------------------------------
    LRUCache(int capacity) {

        capp = capacity;

        head->next = tail;

        tail->pre = head;
    }

    // ------------------------------
    // Get value by key
    // ------------------------------
    int get(int key) {

        if (m.find(key) == m.end())
            return -1;

        Node* temp = m[key];

        // Remove node
        (temp->pre)->next = temp->next;

        (temp->next)->pre = temp->pre;

        // Move node to front
        (head->next)->pre = temp;

        temp->pre = head;

        temp->next = head->next;

        head->next = temp;

        m[key] = temp;

        return temp->val;
    }

    // ------------------------------
    // Insert / Update key
    // ------------------------------
    void put(int key, int val) {

        Node* temp = new Node(key, val);

        // Cache not full
        if (currCapp < capp && m.find(key) == m.end()) {

            currCapp++;
        }

        // Key already exists
        else if (m.find(key) != m.end()) {

            Node* dup = m[key];

            (dup->pre)->next = dup->next;

            (dup->next)->pre = dup->pre;
        }

        // Cache full
        else {

            int oldKey = (tail->pre)->key;

            m.erase(oldKey);

            Node* lst2 = (tail->pre)->pre;

            lst2->next = tail;

            tail->pre = lst2;
        }

        // Insert at front
        (head->next)->pre = temp;

        temp->pre = head;

        temp->next = head->next;

        head->next = temp;

        m[key] = temp;
    }
};


int main() {

    LRUCache obj(2);

    obj.put(1, 1);

    obj.put(2, 2);

    cout << obj.get(1) << endl;

    obj.put(3, 3);

    cout << obj.get(2) << endl;

    obj.put(4, 4);

    cout << obj.get(1) << endl;

    cout << obj.get(3) << endl;

    cout << obj.get(4) << endl;

    return 0;
}