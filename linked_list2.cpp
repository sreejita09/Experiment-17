//Name: Sreejita Bhardwaj
//Prn: 23070123130
//Class: EnTC B 2

#include<iostream>
using namespace std; 
 
class Link {
    public:
    int data;
    Link* next;
    Link(int num) {
        data = num;
        next = NULL;
    }
};

// Function to insert a new node at the head of the list
void insert_head(Link* &head, int data) {
    Link* new_node = new Link(data);
    new_node->next = head; 
    head = new_node;
}

// Function to display the linked list
void disp(Link* head) {
    Link* temp = head;
    while(temp != NULL) { 
        cout << temp->data << "->";
        temp = temp->next;
    } 
    cout << "NULL" << endl;
}

// Function to delete a node with a specific value
void delete_node(Link* &head, int value) {
    if(head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    Link* temp = head;
    Link* prev = NULL;

    // If the node to be deleted is the head node
    if(temp != NULL && temp->data == value) {
        head = temp->next; // Change the head
        delete temp;       // Free memory
        return;
    }

    // Search for the node to be deleted, keeping track of the previous node
    while(temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the node was not found
    if(temp == NULL) {
        cout << "Node with value " << value << " not found." << endl;
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;

    // Free memory
    delete temp;
}

int main() {
    Link* head = NULL;
    insert_head(head, 30);
    disp(head);
    insert_head(head, 32);
    disp(head);
    insert_head(head, 35);
    disp(head);

    // Delete a node
    delete_node(head, 32); // Deleting node with value 32
    disp(head);

    delete_node(head, 35); // Deleting node with value 35
    disp(head);

    delete_node(head, 100); // Attempting to delete a non-existent node
    disp(head);
} 