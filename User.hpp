#pragma once

class User{
    public:
        User();
        User(string t_usernamee, string t_password): username(t_usernamee), password(t_password){};
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
        string username;
        string password;
};
