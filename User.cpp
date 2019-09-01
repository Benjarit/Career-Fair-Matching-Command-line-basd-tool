#include "User.hpp"
using namespace std;

User::User(void){ //default user constructor
    username = "\0"; //initializes to null
    password = "\0"; //initializes to null
}

User::~User(void){
    //destructor
}

// getters
string User::getUsername(){
  return username;
};
string User::getPassword(){
  return username;
};

// setters
void User::setUsername(string newUsername){
  username = newUsername;
};
void User::setPassword(string newPassword){
  password = newPassword;
};

void User::changePassword(void){
    string newPassword1; 
    string newPassword2;
    string currentPassword;
    int flag = 0;
    int counter = 0;
    int flag2 = 0;
    do{  
        cout << "\nPlease enter your current password: "; //asks for current password to verify user
        cin >> currentPassword;

        if(currentPassword != password){
            cout << "\nIncorrect Password. " << endl;
            flag = 0;
            counter++; //increments counter
        }
        else{
            flag = 1;
        }
        
        if(counter==3){ //if entered incorrectly three times then go back to the menu
            cout << "\nPassword entered incorrectly 3 times. Returning to the main menu...." << endl;
            return;
        }
        
    }while(flag==0);
    
    do{
        cout << "\nPlease enter your new password: ";
        cin >> newPassword1;
        
        cout << "\nPlease re-enter your new password: ";
        cin >> newPassword2;
        
        if(newPassword1 != newPassword2){
            cout << "\nError. New passwords do not match. " << endl;
            flag2 = 0;
        }
        else{
            flag2 = 1;
            password = newPassword1; //assigns new password to password
        }
    }while(flag2==0);
    
    return;
}
