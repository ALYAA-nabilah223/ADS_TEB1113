
#include <iostream>
#include <string>
#include <limits> // Added this just to help clean cin safely
using namespace std; 

struct Student{
    string name, course; 
    int age = 0, ID = 0; 
};



int main(){
    
    Student s[5];
    //Get student input of 5 student 
    for( int i = 0; i < 5; i++){
        cout<<"Student "<<i+1<<"\nName: ";
        if(i > 0) cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Cleans buffer before next student getline
        getline(cin, s[i].name);
        cout<<"\nStudent ID: ";
        cin>>s[i].ID;
        if(s[i].ID<= 0){
            cout<<"\nInvalid Student ID. Please re Enter your details.";
            i--; 
            continue;
        }
        cout<<"\nAge: ";
        cin>>s[i].age; 
        if(s[i].age<= 0){
            cout<<"\nInvalid Age. Please re Enter your details.";
            i--; 
            continue;
        }
        cout<<"\nCourse: ";
        cin.ignore(); // Cleans buffer so course getline works cleanly
        getline(cin, s[i].course); 
        
    }
    
    //Show student details
    for(int i = 0; i<5; i++){
        cout<<"Student "<<i+1<<" Name: "<<s[i].name<<"\nAge: "<<s[i].age<<"\nStudent ID: "<<s[i].ID<<"\nCourse: "<<s[i].course<<"\n\n";
    }
    
    //Linear Search
    int search; 
    cout<<"\nSearch Student\nEnter student ID: "; 
    cin>>search;
    while (search <= 0) {
 
    cout << "Invalid ID. Please re-enter (positive numbers only): "; 
    cin >> search;
}
    
 
    for( int i = 0; i<5; i++){
        if(s[i].ID == search){
            cout<<"\nStudent found at index "<<i; 
            break; 
        }else if(i == 4){
            cout<<"Student not found!";
        }
    }

    int choiceContinue = 0;
    //Update info + search
    do{
        cout<<"\nSearch Student to Edit\nEnter student ID: "; 
        cin>>search;
        while(search<= 0){
            cout<<"\nInvalid ID. Please re-enter: "; 
            cin>>search;
        }
    
        int target = -1; // Changed to -1 to flag if not found safely
        for( int i = 0; i<5; i++){
            if(s[i].ID == search){
                cout<<"\nStudent found at index "<<i; 
                target = i;
                break; // Stop running once found so it doesn't trigger 'else if'
            }else if(i == 4 && target == -1){ // Added check to see if target was never found
                cout<<"Student not found!";
            }
        }
        
        // Skip edit loop if student wasn't found at all
        if(target == -1){
            cout<<"\nEnter 1 to stop search. 0 to continue: "; 
            cin>>choiceContinue;
            continue;
        }
        
        int choiceEdit;
        do{
           cout<<"\nEdit: \n1. Name\n2. Age\n 3. Student ID\n4. Course\n5. Quit Edit\nPlease select between 1-5"; 
           cin>>choiceEdit; 
           if(choiceEdit < 1 || choiceEdit > 5){ // Fixed the 0<= choiceEdit <= 6 logic bug
               cout<<"Invalid, please re-enter choice"; 
               continue;
           }
           switch(choiceEdit){
               case 1: 
               cout<<"Enter new name: "; 
               cin.ignore();
               getline(cin, s[target].name);
               break;
               case 2: 
               cout<<"Enter new Age: "; 
               cin>>s[target].age;
               break;
               case 3:
               cout<<"Enter new Student ID: "; 
               cin>>s[target].ID;
               break;
               case 4: 
               cout<<"Enter new Course: "; 
               cin.ignore();
               getline(cin, s[target].course); 
               break; // Added missing break so it doesn't slip down into case 5
               case 5:
               cout<<"All updates are saved!";
               break;
           }
        }while(choiceEdit != 5);
        
        cout<<"\nEnter 1 to stop search. 0 to continue: "; 
        cin>>choiceContinue;
    }while(choiceContinue !=1);
    
    
    
    
}

