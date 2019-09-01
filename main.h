
using namespace std;

class User{
    public:
        User(string newUsername, string newPassword){username = newUsername; password = newPassword;};
        User();
        virtual ~User();
        void changePassword();
        virtual void printMenu() = 0; //a pure virtual function, makes it an ABC
        
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

class Employer; //forward declarations
class Job;
class Student;

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

class Employer : public User{ //derived from user
    private:
        string companyName;
        string industry;
        string companyDescription;
        vector<Job> openJobs;
        vector <Student> matchedStudents; //vector of matched students
    
    public:
        //constructor:
        Employer(string newUsername, string newPassword, string newCompanyName,string newIndustry,string newCompanyDescription){ 
            companyName = newCompanyName; 
            industry = newIndustry;
            companyDescription = newCompanyDescription;
            username = newUsername;
            password = newPassword;
        };
        void addJob();
        void deleteJob();
        void studentList(vector <Student>); //method for list of students that match
        void printMenu();
        void employerUpdate();
        
        ~Employer(); //destructor
        
        // * getters
        string getCompanyName(){return companyName;};
        string getIndustry(){return industry;};
        string getCompanyDescription(){return companyDescription;};
        vector <Job> getOpenJobs(){return openJobs;};
        
        // * setters
        void setCompanyName(string newCompanyName){companyName = newCompanyName;};
        void setIndustry(string newIndustry){industry = newIndustry;};
        void setCompanyDescription(string newCompanyDescription){companyDescription = newCompanyDescription;};
        void pushJob(Job newJob){openJobs.push_back(newJob);};
        
        void viewMatchedCandidates(vector<Student*> students);
        void printMatchedStudents(vector<Student>); //print the list of matched jobs by company
        vector<Student> rankingStudent(Employer,vector<Student>);
        vector<Student> JobQualification(Employer, vector<Student*>);
        
        void print(void);
};

