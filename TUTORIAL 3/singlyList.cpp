#include <iostream>
#include <string>

using namespace std;

class Node{
public: // Made public so main() can access name and next
    string name;
    Node* next = NULL;
    
    // Constructor to allow creating nodes with or without default names
    Node(string n = "") {
        name = n;
        next = NULL;
    }
    
    //void insertion()
    void insertFirst(Node* &head, string name){ 
        Node* newNode = new Node(name); 
        newNode->next = head;
        head = newNode;
        return; 
        
    }
    
    void insertLast(Node* &head, string name){
        if(head == NULL){ // Fixed missing closing parenthesis
            insertFirst(head, name);
            return;
        }
        Node* newNode = new Node(name); 
        Node* current = head; 
        while(current->next != NULL){
            current = current->next; 
        }
        current->next = newNode;
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
    delete temp;
    }
    
    
    void display_list(Node* head){
        Node* display_node = head;
        while(display_node != NULL){
            cout << display_node->name << endl;
            display_node = display_node->next;
        }
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
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    
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
    
    cout << "\n--- Final Result List ---" << endl;
    head->display_list(head);
    
    return 0;
}