#include <iostream>
#include <string>

using namespace std;

class Node{
public: // Made public so main() can access name, next, and prev
    string name;
    Node* next = NULL;
    Node* prev = NULL; // Your new backward pointer
    
    // Constructor to allow creating nodes with or without default names
    Node(string n = "") {
        name = n;
        next = NULL;
        prev = NULL;
    }
    
    //void insertion()
    void insertFirst(Node* &head, string name){ 
        Node* newNode = new Node(name); 
        newNode->next = head;
        
        if (head != NULL) {
            head->prev = newNode; // Connect old head backward to new node
        }
        
        head = newNode;
        return; 
        
    }
    
    void insertLast(Node* &head, string name){
        if(head == NULL){ 
            insertFirst(head, name);
            return;
        }
        Node* newNode = new Node(name); 
        Node* current = head; 
        while(current->next != NULL){
            current = current->next; 
        }
        current->next = newNode;
        newNode->prev = current; // Connect new node backward to old last node
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
        while(current->name != target and current->next != NULL){
            current = current->next; 
        }
        
        if(current->name != target) {
            cout << target << " not found!\n";
            return;
        }
        
        Node* newNode = new Node(name); 
        newNode->next = current->next;
        newNode->prev = current; // New node points backward to current
        
        if (current->next != NULL) {
            current->next->prev = newNode; // Next node points backward to new node
        }
        current->next = newNode;
    }
    
    //void deletetion()
    void deleteName(Node* &head, string name){
    if(head == NULL){
        return; 
    }
    
    if(head->name == name){
        Node* temp = head; 
        head = head->next; 
        if (head != NULL) {
            head->prev = NULL; // New head has nothing behind it
        }
        delete temp; 
        return;
    }
    
    Node* current = head; 
    while(current->next != NULL && current->next->name != name){
        current = current->next;
    }
    
    if(current->next == NULL){
        cout << name << " not found in the list!\n";
        return;
    }
    
    Node* temp = current->next;
    current->next = temp->next; 
    
    if (temp->next != NULL) {
        temp->next->prev = current; // Step over the deleted node backward too
    }
    delete temp;
    }
    
    
    void display_list(Node* head){
        Node* display_node = head;
        while(display_node != NULL){
            cout << display_node->name << endl;
            display_node = display_node->next;
        }
    }

    void display_reverse(Node* head){
        if (head == NULL) {
            return;
        }
        Node* current = head;
        while (current->next != NULL) {
            current = current->next; 
        }
        // Walk backward using your prev logic
        while (current != NULL) {
            cout << current->name << endl; 
            current = current->prev;
        } 
    }
};

int main() {
    // Setting up your initial manual chain using your style
    Node* node1 = new Node("Aiman");
    Node* node2 = new Node("Ahmad");
    Node* node3 = new Node("Anajana");
    Node* node4 = new Node("Jessy");
    Node* node5 = new Node("Ali");
    
    Node* head = node1;
    
    // Wire them up forward AND backward to start off right
    node1->next = node2; node1->prev = NULL;
    node2->next = node3; node2->prev = node1;
    node3->next = node4; node3->prev = node2;
    node4->next = node5; node4->prev = node3;
    node5->next = NULL;  node5->prev = node4;
    
    cout << "--- Initial Manual Doubly List ---" << endl;
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
    
    cout << "\n--- Final Result List (Forward order) ---" << endl;
    head->display_list(head);
    
    cout << "\n--- Final Result List (Reverse order) ---" << endl;
    head->display_reverse(head);
    
    return 0;
}