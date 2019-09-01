#pragma once

//forward declarations
class Employer;
class Student;

class Job{
    private:
        //declares variables:
        Employer* company;
        string title;
        int class_standing_req;
        vector <string> preferred_majors;
        float preferredGPA;
        float salary;
        vector <string> requiredSkills;
        
    public:
        Job(Employer*); // constructor that assigns to employer right away.
        ~Job(); //destructor
        
        //getters
        Employer* getEmployer();
        string getTitle();
        int getClassStanding();
        vector <string> getPreferredMajors()
        float getPreferredGPA()
        float getSalary();
        vector <string> getRequiredSkills();
        
        //setters
        void setCompany(Employer* newCompany);
        void setTitle(string newTitle){title = newTitle;};
        void setClassStanding(int newClassStanding);
        void addPreferredMajor(string newMajor);
        void setPreferredGPA(float newGPA);
        void setSalary(float newSalary);
        void addRequiredSkill(string newSkill);
        
        void print(void);
};
