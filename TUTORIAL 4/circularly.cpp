#include <iostream>
#include <string>

using namespace std;

class Node{
public: // Made public so main() can access name and next
    string name;
    Node* next = NULL;
    Node* prev = NULL; // ADDED: For doubly linked list capability
    
    // Constructor to allow creating nodes with or without default names
    Node(string n = "") {
        name = n;
        next = NULL;
        prev = NULL; // ADDED
    }
    
    //void insertion()
    void insertFirst(Node* &head, string name){ 
        Node* newNode = new Node(name); 
        
        if (head == NULL) {
            head = newNode;
            newNode->next = head; // Points to itself in circular
            newNode->prev = head;
            return;
        }
        
        Node* tail = head->prev; // In circular, head->prev is the tail
        
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
        return; 
        
    }
    
    void insertLast(Node* &head, string name){
        if(head == NULL){ 
            insertFirst(head, name);
            return;
        }
        Node* newNode = new Node(name); 
        Node* tail = head->prev; // Instant access to tail in circular!
        
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
    
    void insertMiddle(Node* &head, string name){
        
        if(head == NULL){
            cout<<"\nList is empty."; 
            return;
        }
        
        string target;
        cout<<"Insert "<<name<<" after what name? (exact spelling appreciated):  "; 
        cin>>target;
        
        Node* current = head; 
        while(current->name != target and current->next != head){ // Stop at head in circular
            current = current->next; 
        }
        
        if(current->name != target) {
            cout << target << " not found!\n";
            return;
        }
        
        Node* newNode = new Node(name); 
        newNode->next = current->next;
        newNode->prev = current;
        
        current->next->prev = newNode; // Update the back-link of the next node
        current->next = newNode;
    }
    
    //void deletetion()
    void deleteName(Node* &head, string name){
    if(head == NULL){
        return; 
    }
    
    if(head->name == name){
        Node* temp = head; 
        Node* tail = head->prev;
        
        if (head->next == head) { // Only one node in the list
            head = NULL;
        } else {
            head = head->next; 
            tail->next = head; // Re-link circle
            head->prev = tail;
        }
        delete temp; 
        return;
    }
    
    Node* current = head; 
    while(current->next != head && current->next->name != name){
        current = current->next;
    }
    
    if(current->next == head){
        cout << name << " not found in the list!\n";
        return;
    }
    
    Node* temp = current->next;
    current->next = temp->next; 
    temp->next->prev = current; // Update the back-link of the skipped node
    delete temp;
    }
    
    
    void display_list(Node* head){
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* display_node = head;
        do { // Changed to do-while so it handles the circular loop perfectly
            cout << display_node->name << endl;
            display_node = display_node->next;
        } while(display_node != head);
    }
    
    // ADDED: To prove your prev pointers form a perfect backward circle!
    void display_reverse(Node* head) {
        if (head == NULL) return;
        Node* display_node = head->prev; // Start at tail
        do {
            cout << display_node->name << endl;
            display_node = display_node->prev;
        } while(display_node != head->prev);
    }
};

int main() {
    // Setting up the initial manual chain using your style
    Node* node1 = new Node("Aiman");
    Node* node2 = new Node("Ahmad");
    Node* node3 = new Node("Anajana");
    Node* node4 = new Node("Jessy");
    Node* node5 = new Node("Ali");
    
    // Setting up head pointer for your functions
    Node* head = node1;
    
    // Manual setup modified to close the circular doubly loop links!
    node1->next = node2; node1->prev = node5;
    node2->next = node3; node2->prev = node1;
    node3->next = node4; node3->prev = node2;
    node4->next = node5; node4->prev = node3;
    node5->next = node1; node5->prev = node4;
    
    cout << "--- Initial Manual List ---" << endl;
    head->display_list(head);
    
    // Testing Delete Function
    cout << "\n--- Testing Delete: Removing Anajana ---" << endl;
    head->deleteName(head, "Anajana");
    head->display_list(head);
    
    // Testing Insert First Function
    cout << "\n--- Testing Insert First: Adding Zaki to front ---" << endl;
    head->insertFirst(head, "Zaki");
    head->display_list(head);
    
    // Testing Insert Last Function
    cout << "\n--- Testing Insert Last: Adding Abu to end ---" << endl;
    head->insertLast(head, "Abu");
    head->display_list(head);
    
    // Testing Insert Middle Function
    cout << "\n--- Testing Insert Middle ---" << endl;
    head->insertMiddle(head, "Sarah");
    
    cout << "\n--- Final Result List (Forward) ---" << endl;
    head->display_list(head);
    
    cout << "\n--- Final Result List (Reverse Track) ---" << endl;
    head->display_reverse(head);
    
    return 0;
}