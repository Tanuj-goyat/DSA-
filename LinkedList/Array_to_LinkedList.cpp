#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

node* arraytolinkedlist(int arr[], int n) {
    if(0 == n) return NULL;
    node* head = new node(arr[0]);
    node* temp = head;
    for(int i = 1; i < n; i++) {
        temp->next = new node(arr[i]);
        temp = temp->next;
    }
    return head;
}

void printlinkedlist(node* head) {
    node* temp = head;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    int n = 10;
    node* head = arraytolinkedlist(arr, n);
    printlinkedlist(head);
    return 0;
}