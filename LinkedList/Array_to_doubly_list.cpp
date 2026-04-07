#include <iostream>
#include <vector>
using namespace std;

struct node{
    int value;
    node*next;
    node*previous;

    node(int val) {
        value = val;
        next = NULL;
        previous = NULL;
    }
};

node* arr_to_list(vector<int> v, node* &head) {
    head = new node(v[0]);
    node* temp = head;
    node* tail = head;
    for(int i = 1; i < v.size(); i++) {
        temp->next = new node(v[i]);
        temp->next->previous = temp;
        temp = temp->next;
        tail = temp;
    }
    return tail;
}

void print_list(node* head) {
    node* temp = head;
    while(temp != NULL) {
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout << endl;
}

void print_back_list(node* tail) {
    node* temp = tail;
    while(temp != NULL) {
        cout << temp->value << "->";
        temp = temp->previous;
    }
    cout << endl;
}

int main() {
    vector<int> v = {1,2,3,4,5,6,7,8,9,0};
    node*head;
    node* tail = arr_to_list(v, head);
    print_back_list(tail);
    print_list(head);

    return 0;
}