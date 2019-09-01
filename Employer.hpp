#pragma once

//forward declarations
class Job;
class Student;

class Employer : public User{ //derived from user
    private:
        string companyName;
        string industry;
        string companyDescription;
        vector<Job> openJobs;
        vector <Student> matchedStudents; //vector of matched students
    
    public:
        //constructor:
        Employer(string newUsername, string newPassword, string newCompanyName,string newIndustry,string newCompanyDescription):
        companyName(newCompanyName), industry(newIndustry), companyDescription(newCompanyDescription), username(newUsername), password(newPassword){}
        void addJob();
        void deleteJob();
        void studentList(vector <Student>); //method for list of students that match
        void printMenu();
        void employerUpdate();
        
        ~Employer(); //destructor
        
        // * getters
        string getCompanyName();
        string getIndustry();
        string getCompanyDescription();
        vector <Job> getOpenJobs();
        
        // * setters
        void setCompanyName(string newCompanyName);
        void setIndustry(string newIndustry);
        void setCompanyDescription(string newCompanyDescription);
        void pushJob(Job newJob);
        
        void viewMatchedCandidates(vector<Student*> students);
        void printMatchedStudents(vector<Student>); //print the list of matched jobs by company
        vector<Student> rankingStudent(Employer,vector<Student>);
        vector<Student> JobQualification(Employer, vector<Student*>);

        void print(void);
};
