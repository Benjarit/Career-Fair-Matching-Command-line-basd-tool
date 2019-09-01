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
        Employer* getEmployer(){return company;};
        string getTitle(){return title;};
        int getClassStanding(){return class_standing_req;};
        vector <string> getPreferredMajors(){return preferred_majors;};
        float getPreferredGPA(){return preferredGPA;};
        float getSalary(){return salary;};
        vector <string> getRequiredSkills(){return requiredSkills;};
        
        //setters
        void setCompany(Employer* newCompany){company = newCompany;};
        void setTitle(string newTitle){title = newTitle;};
        void setClassStanding(int newClassStanding){class_standing_req = newClassStanding;};
        void addPreferredMajor(string newMajor){preferred_majors.push_back(newMajor);};
        void setPreferredGPA(float newGPA){preferredGPA = newGPA;};
        void setSalary(float newSalary){salary = newSalary;};
        void addRequiredSkill(string newSkill){requiredSkills.push_back(newSkill);};
        
        void print(void);
};
