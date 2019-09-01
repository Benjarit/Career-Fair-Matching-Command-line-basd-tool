class User{
    public:
        User();
        User(string newUsername, string newPassword){username = newUsername; password = newPassword;};
        virtual ~User();
        virtual void printMenu() = 0; //a pure virtual function, makes it an ABC
        void changePassword();
  
        // *getters
        string getUsername(){return username;};
        string getPassword(){return username;};
        
        // *setters
        void setUsername(string newUsername){username = newUsername;};
        void setPassword(string newPassword){password = newPassword;};
    protected:
        string username;
        string password;
};
