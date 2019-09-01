#include <cstdlib>
#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>

class User{
    public:
        User();
        User(string t_usernamee, string t_password): m_username(t_usernamee), m_password(t_password){};
        virtual ~User();
        virtual void printMenu() = 0; //a pure virtual function, makes it an ABC
        void changePassword();
  
        // *getters
        string getUsername();
        string getPassword();
        
        // *setters
        void setUsername(string newUsername);
        void setPassword(string newPassword);
    protected:
        string m_username;
        string m_password;
};
