class Student : public User{ //student is derived from user class
    private:
        string first_name;
        string last_name;
        int class_standing;
        string major;
        float gpa;
        vector <string> skills;
        string preferred_industry;
    public:
        void studentUpdate();
         Student(); //default constructor
         Student(string, string, string,string,int,string,float,vector<string>,string);
        ~Student(); //destructor
  
        void editStudentInfo(void);
        void viewJobs(vector<Employer*> employers);
        void printSkills(void);
        void printMatchedJobs(vector<Job> jobs); //print the list of matched jobs by company
        vector<Job> rankingJobs(Student,vector<Job>);
        vector<Job> studentQualification(Student student, vector <Employer*>);
        void printMenu(); //from the pure virtual function in user
  
        //  * setters
        void setFirstName(string entered_first_name){first_name = entered_first_name;};
        void setLastName(string entered_last_name){last_name = entered_last_name;};
        void setClassStanding(int chosen_class_standing){class_standing = chosen_class_standing;};
        void setMajor(string newMajor){major = newMajor;};
        void setGpa(float newGPA){gpa = newGPA;};
        void addSkill(string newSkill){skills.push_back(newSkill);};
        void setPreferred_industry(string new_preferred_industry){preferred_industry = new_preferred_industry;};
        
        //  * getters
        //returns the information
        string getFirstName(){return first_name;};
        string getLastName(){return last_name;};
        int getClassStanding(){return class_standing;};
        string getMajor(){return major;};
        float getGpa(){return gpa;};
        vector <string> getSkills(){return skills;};
        string getPreferred_industry(){return preferred_industry;};
        
        void print(void);
};
