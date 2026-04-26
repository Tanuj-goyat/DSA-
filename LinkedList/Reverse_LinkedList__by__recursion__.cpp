#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:

    void change(ListNode* head, ListNode* h2) {
        if(head->next == NULL) {
            return;
        }
        head = head->next;
        change(head, h2);
        h2->next = head;
        h2 = head;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* h2 = new ListNode(-1);
        change(temp, h2);
        return h2->next;
    }
};


// Helper function to print list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}


int main() {

    // Create list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1,
                        new ListNode(2,
                        new ListNode(3,
                        new ListNode(4,
                        new ListNode(5)))));

    Solution obj;

    head = obj.reverseList(head);

    cout << "Reversed List:\n";
    printList(head);

    return 0;
}