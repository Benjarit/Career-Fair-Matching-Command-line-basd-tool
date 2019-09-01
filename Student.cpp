#include "Student.hpp"
using namespace std;

//default constructor
Student::Student(void){ 
    first_name = "";
    last_name = "";
    class_standing = 0;
    major = "\0";
    gpa = 0.0;
    //skills = "\0"; //don't need to initialize vector
    preferred_industry = "\0";
}

Student::Student(string newUsername, string newPassword, string firstName, string lastName, int classStrand, string newMajor, float newGpa, vector<string> skill, string preferred_ind){ //default constructor
    //assigns info with the values sent to the constructor:
    username = newUsername; 
    password = newPassword;
    first_name = firstName;
    last_name = lastName;
    class_standing = classStrand;
    major = newMajor;
    gpa = newGpa;
    this->skills = skill; //set vector in class student
    preferred_industry = preferred_ind;
}

Student::~Student(void){
    //destructor
}
void Student::print(void){
    cout << "\tMajor: " << major << endl;
    cout << "\tGPA: " << gpa << endl;
    cout << "\tSkills: ";
    for(unsigned i = 0; i < skills.size(); i++){
        cout << skills[i]; //loops through to print each skill
        if(i == skills.size() - 1){ //checks if the end becaus then prints newline
            cout << endl;
        } else{
            cout << ",";
        }
    }
    cout << "\tPreferred Industry: " <<  preferred_industry << endl;
}




void Student::printMatchedJobs(vector<Job> jobs){
    vector<Job>::iterator jobsIterator;
    int i;
    cout << endl << "-------------------- MATCHED JOBS --------------------" << endl << endl;
    while(jobs.size() != 0){
        cout << jobs[0].getEmployer()->getCompanyName() << ":" << endl;
        jobs[0].print();
        for(i=1;i<jobs.size();i++){ //print all other jobs in the vector from the same company
            //if (*(jobs[i].getEmployer()) == *(jobs[0].getEmployer())){ //if job is from same company
            if ((jobs[i].getEmployer())->getCompanyName() == (jobs[0].getEmployer())->getCompanyName()){ //if job is from same company
                jobs[i].print();
                //jobs.erase(i--); //remove job from vector because already printed, --i to look at the next job that is now in the same slot
                jobsIterator = jobs.begin() + (--i); //need to convert index to iterator for erase() function
                jobs.erase(jobsIterator);
            }
        }
        jobsIterator = jobs.begin();
        jobs.erase(jobsIterator);
    }
}

void Student::printMenu(){
    cout << "\n\nWhat would you like to do?\n\t1: Edit matching information\n\t2: View matched jobs\n\t3: Change password\n\t4: Logout" << endl << endl;
}

void Employer::printMenu(){
    cout << "\n\nWhat would you like to do?\n\t1: Add a job\n\t2: Delete a job\n\t3: View matched candidates\n\t4: Change Password\n\t5: Logout" << endl << endl;
}

void Student::editStudentInfo(void){
    int choice;
    int preferred_industry_int; 
    int flag1=0;
    int i=0;
    int skillsLength=0;
    string editMore;
    do{
        //print info
        if(first_name != ""){ //if first_name is empty, assume first student has not entered info yet so we can't print current info
            cout << "\nCurrent information: " << "\n1) First Name: " << first_name 
                 << "\n2) Last Name: " << last_name << endl; 
             
            switch(class_standing){ //prints current class standing
                case 1:
                    cout << "3) Class Standing: Freshman" << endl;
                    break;
                case 2:
                    cout << "3) Class Standing: Sophomore" << endl;
                    break;
                case 3:
                    cout << "3) Class Standing: Junior" << endl;
                    break;
                case 4:
                    cout << "3) Class Standing: Senior" << endl;
                    break;
                default:
                    cout << "3) Class Standing: Not specified." << endl;
                    break;
            }
        
            cout << "4) Major: " << major << "\n5) GPA: " << gpa << endl; 
            
            skillsLength = skills.size(); //assigns the length of the skills vector 
            cout << "6) Skills: ";
            for(i=0;i<skillsLength;i++){
                 cout << skills[i] << "\n"; //prints the skills
            }
            
            cout << "7) Preferred Industry: " << preferred_industry << endl;
            cout << "8) Go back to the main menu" << endl;
        }
        //ask what to add/edit
        cout << "\nPlease enter the number of the information you would like to edit: ";
        cin >> choice;
        
        switch(choice){ //depends on which number they select based off the menu
            case 1:
                cout << "\nPlease enter your first name: ";
                cin >> first_name;
                break;
            case 2:
                cout << "\nPlease enter your last name: ";
                cin >> last_name;
                break;
            case 3:
                cout << "\n1) Freshman\n2) Sophomore\n3) Junior\n4) Senior";
                cout << "\nPlease enter the number associated with your class standing: ";
                cin >> class_standing;
                break;
            case 4:
                cout << "\nPlease enter your major: ";
                cin >> major;
                break;
            case 5:
                cout << "\nPlease enter your GPA: ";
                cin >> gpa;
                break;
            case 6:{ //skills
                //adding a skill to the vector
                int choice = 0;
                int flg = 1;
                string temp_skill;
                
                this->printSkills(); //displays current skills
                
                do{ //loops until the user no longer wants to add a skill
                    cout << "\nDo you wish to add a skill?\n1) Yes\n2) No"
                         << "\nEnter the number of the option you choose: ";
                         
                    cin >> choice;
                    
                    if(choice!=1 || choice!=2){ //error checks input
                        cout << "\nInvalid Option.";
                        flg = 1;
                    }
                    else if(choice==1){
                        cout << "\nPlease enter the skill you wish to add: ";
                        cin >> temp_skill; //reads into a temp
                        skills.push_back(temp_skill); //pushes temp onto th vector
                    }
                    else if(choice==2){
                        flg = 0; //breaks loop if choice is 2
                    }
                     
                }while(flg==1); 
                    
                break;
            }
            case 7:
            {
                int flag2=0;
                preferred_industry_int = 0;
                
                
                do{ //loops until correct preferred industry is selected
                    cout << "\nIndustries: \n1)Automotive\n2) Construction\n3) Technology" << endl;
                    cout << "\nPlease enter the number corresponding to your preferred industry: ";
                    cin >> preferred_industry_int;
                    
                    if(preferred_industry_int==1){
                        preferred_industry = "Automotive";
                        flag2 = 1;
                    }
                    else if(preferred_industry_int==2){
                        preferred_industry = "Construction";
                        flag2 = 1;
                    }
                    else if(preferred_industry_int==3){
                        preferred_industry = "Technology";
                        flag2 = 1;
                    }
                    else
                      flag2 = 0;
                }while(flag2==0);
                
                break;
            }
            case 8:
                    return;
                    break;
            default:
                cout << "\nInvalid option." << endl;
        }
        
        cout << "\nWould you like to edit another piece of information?" << endl
            << "Please enter yes/no: ";
        cin >> editMore;
        
        if(editMore == "yes")
            flag1 = 0; //keeps looping
        else
            flag1 = 1; //breaks loop
            
    }while(flag1==0);
    
    //call function to write to text file 
    this->studentUpdate();
    return;
}
void Student::studentUpdate(){
    fstream fp;
    fp.open(("users/" + username + ".txt"),ios::out);
    fp << first_name << endl;
    fp << last_name << endl;
    fp << class_standing << endl;
    fp << major << endl;
    fp << gpa << endl;
    for(unsigned i = 0; i < skills.size(); ++i){
        fp << skills[i] << ",";
    }
    fp << preferred_industry << endl; 
    fp.close();
    cout << "\nProfile Completed...." << endl;
    //------------------------------------------Read "StudentInfo.txt"------------------------------------------------
    fstream userFp;
    //userFp.open(userFile.c_str(),ios::in); //userFile not yet declared, commenting out for now to compile
}

void Employer::employerUpdate(){
    fstream fp;
    int i,j,k;
    fp.open(("employers/" + username + "/" + username + ".txt"),ios::out); //opens file
    fp << companyName << endl;
    fp << industry << endl;
    fp << openJobs.size() << endl;
    fp << companyDescription << endl;
    fp.close(); //closes file
    for(i=0;i<openJobs.size();i++){
        string title = "job" + to_string(i);
        fp.open(("employers/" + username + "/jobs/" + title + "/" + title + ".txt"),ios::out);
        //print to file
        fp << openJobs[i].getTitle() << endl;
        fp << openJobs[i].getClassStanding() << endl;
        fp << openJobs[i].getPreferredGPA() << endl;
        fp << openJobs[i].getSalary() << endl;
        fp << openJobs[i].getPreferredMajors().size() << endl;
        fp << openJobs[i].getRequiredSkills().size() << endl;
        fp.close();
        fp.open(("employers/" + username + "/jobs/" + title + "/majors.txt"),ios::out);
        for(j=0;j < openJobs[i].getPreferredMajors().size();j++){
            fp << openJobs[i].getPreferredMajors()[j] << endl; //write the vector to the file
        }
        fp.close();
        
        fp.open(("employers/" + username + "/jobs/" + title + "/skills.txt"),ios::out);
        for(k=0;k<openJobs[i].getRequiredSkills().size();k++){
            fp << openJobs[i].getRequiredSkills()[k] << endl; //write the required skills to the file
        }
        fp.close();
    }
}

void Job::print(void){
    int i;
    cout << "\t" << title << ":" << endl;
    cout << "\t\tRequired class standing: " << class_standing_req << endl;
    cout << "\t\tPreferred majors: ";
    for(i=0; i<preferred_majors.size(); i++){
        cout << preferred_majors[i];
        if(i+1 == preferred_majors.size()){ 
            cout << endl; //if there are no more elements
        } else {
            cout << ", "; //if there are still more then put a comma
        }
    }
    cout << "\t\tPreferred GPA: " << preferredGPA << endl;
    cout << "\t\tSalary: " << salary << endl;
    cout << "\t\tRequired skills:";
    for(i=0;i<requiredSkills.size();i++){ 
        cout << requiredSkills[i];
        if(i+1 == requiredSkills.size()){
            cout << endl; //if there are no more elements
        } else {
            cout << ", "; //if there are more elements
        }
    }
}

void Student::viewJobs(vector <Employer*> employers){
    printMatchedJobs(rankingJobs(*this, studentQualification(*this, employers))); //studentQualification returns a vector of jobs for the student, rankingJobs orders those jobs, printMatchedJobs prints the ordered jobs
}

vector<Job>  Student::rankingJobs(Student stud, vector<Job>jobsQualifiedFor){
    vector<Job> OrderedJob; 
    for(unsigned i = 0; i < jobsQualifiedFor.size(); ++i){
        if(!strcasecmp(stud.getPreferred_industry().c_str(),jobsQualifiedFor[i].getEmployer()->getIndustry().c_str())){
            OrderedJob.insert(OrderedJob.begin(),jobsQualifiedFor[i]); //insert if does not match
        }
        else{
            OrderedJob.push_back(jobsQualifiedFor[i]); //appends to vector if matched
        }
    }
    return OrderedJob;
}

void Student::printSkills(void){
    int i=0;
    int num_of_skills=0;
    
    num_of_skills = skills.size();
    
    cout << "\nSkills: " << endl;
    
    for(i=0;i<num_of_skills;i++){
        cout << skills[i] << endl; //loops through the skills
    }

    return;
}

void Employer::studentList(vector <Student> list_of_students){
    //declared variables:
    //int i=0; //for loop counter
    int len;
    int flag1=0;
    int jobLen=0;
    int flag2=0;
    
    len = list_of_students.size(); //length of the student vector
    
    for(int i=0;i<len;i++){
        jobLen = openJobs.size(); //length of the available jobs vector
        
        for(int j=0;j<jobLen;j++){
            int k=0;
            vector <string> preffered_maj;
            int len2=0;
            int h=0;
            int len3=0;
            
            if((list_of_students[i].getClassStanding()) < (openJobs[j].getClassStanding())){
                continue; //checks next job element
            }
            if((list_of_students[i].getGpa()) < (openJobs[j].getPreferredGPA())){ //is student gpa is less than preferred
                continue; //checks next job element
            }
            
            flag1 = 0;
            len2 = (openJobs[j].getPreferredMajors()).size(); //gets length of the preferred majors vector
            for(k=0;k<len2;k++){
                if((list_of_students[i].getMajor()) == (openJobs[j].getPreferredMajors())[k]){
                    flag1 = 1; //passes that has matching major 
                    break;
                }
            }
            
            //if there was not a matching major
            if(flag1!=1){
                continue; //goes to next job if didn't match any major
            }
            
            flag2 = 0;
            //http://stackoverflow.com/questions/571394/how-to-find-if-an-item-is-present-in-a-stdvector
            len3 = (openJobs[j].getRequiredSkills()).size();
            for(h=0;h<len3;h++){
                if(find(list_of_students[i].getSkills().begin(), list_of_students[i].getSkills().end(), (openJobs[j].getRequiredSkills())[h]) != list_of_students[i].getSkills().end()){
                    flag2 = 1; //set flag if match found
                    break;
                }
            }
            
            //if match not found then move to next job
            if(flag2!=1){
                continue; //go to next job if didn't match any skills
            }
            
            //check if student prefers the same industry
            if(list_of_students[i].getPreferred_industry() == openJobs[i].getEmployer()->getIndustry()){
                matchedStudents.push_back(list_of_students[i]); //puts matched students onto a vector
            }
         
            
        }
    }
    
    return;
}

vector <Job> Student::studentQualification(Student stu, vector <Employer*> employer_vec){
    //declared variables:
    vector <Job> matchedJobs; //new vector of potential matches
    //int i=0; //for loop counter
    int len;
    int flag1=0;
    int jobLen=0;
    int flag2=0;
    
    len = employer_vec.size();
    
    for(int i=0;i<len;i++){
        jobLen = employer_vec[i]->getOpenJobs().size();
        
        for(int j=0;j<jobLen;j++){
            int k=0;
            vector <string> preffered_maj;
            int len2=0;
            int h=0;
            int len3=0;
            
            if((stu.getClassStanding()) < ((employer_vec[i]->getOpenJobs())[j].getClassStanding())){
                continue; //checks next job element
            }
            if((stu.getGpa()) < ((employer_vec[i]->getOpenJobs())[j].getPreferredGPA())){ //is student gpa is less than preferred
                continue; //checks next job element
            }
            
            flag1 = 0;
            len2 = ((employer_vec[i]->getOpenJobs())[j].getPreferredMajors()).size(); //gets length of the preferred majors vector
            for(k=0;k<len2;k++){
                if(!strcasecmp((stu.getMajor().c_str()),((employer_vec[i]->getOpenJobs())[j].getPreferredMajors())[k].c_str())){ //|Done|..fix to disregard case when comparing major strings
                    flag1 = 1; //passes that has matching major 
                    break;
                }
            }
            
            //if there was not a matching major
            if(flag1!=1){
                continue; //goes to next job if didn't match any major
            }
            
            flag2 = 0;
            //http://stackoverflow.com/questions/571394/how-to-find-if-an-item-is-present-in-a-stdvector
            len3 = ((employer_vec[i]->getOpenJobs())[j].getRequiredSkills()).size();
            for(h=0;h<len3;h++){
                if(find(stu.getSkills().begin(), stu.getSkills().end(), employer_vec[i]->getOpenJobs()[j].getRequiredSkills()[h]) != stu.getSkills().end()){
                    flag2 = 1; //set flag if match found
                    break;
                }
            }
            
            //if match not found then move to next job
            if(flag2!=1){
                continue; //go to next job if didn't match any skills
            }
            
            //if makes it this far then it wont have had a cause to break loop
            matchedJobs.push_back((employer_vec[i]->getOpenJobs())[j]); //puts matched jobs onto a vector
        }
    }
    
    return matchedJobs; //returns list of matched jobs/companies
}
