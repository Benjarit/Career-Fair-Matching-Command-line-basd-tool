#include <cstdlib>
#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include "Employer.hpp"
using namespace std;
class Student;
class Job;
class Employer;

Employer::~Employer(void){
}
void Employer::viewMatchedCandidates(vector<Student*> students){ //sends vector to send to the print method
    printMatchedStudents(rankingStudent(*this,JobQualification(*this,students))); //matches before printing
}

void Employer::setCompanyName(string newCompanyName){
  companyName = newCompanyName;
}

void Employer::setIndustry(string newIndustry){
  industry = newIndustry;
}

void Employer::setCompanyDescription(string newCompanyDescription){
  companyDescription = newCompanyDescription;
}

void Employer::pushJob(Job newJob){
  openJobs.push_back(newJob);
}

vector<Job> Employer::getOpenJobs(){
  return openJobs;
}

string Employer::getCompanyName(){
  return companyName;
}

string Employer::getIndustry(){
  return industry;
}

string Employer::getCompanyDescription(){
  return companyDescription;
}

void Employer::printMatchedStudents(vector<Student> stud){
    vector<Student>::iterator studentIterator;
    int i;
    cout << endl << "-------------------- MATCHED Student --------------------" << endl << endl;
    for(i=0;i<stud.size();i++){
        cout << stud[i].getFirstName() << " " << stud[i].getLastName() << ":" << endl; //loops through vector of students
        stud[i].print();
    }
}

vector<Student> Employer::rankingStudent(Employer emp,vector<Student> stuQualifiedFor){
    vector<Student> OrderedStudent; 
    for(unsigned i = 0; i < stuQualifiedFor.size(); ++i){
        if(!strcasecmp(emp.getIndustry().c_str(),stuQualifiedFor[i].getPreferred_industry().c_str())){ //if the industries dont match
            OrderedStudent.insert(OrderedStudent.begin(),stuQualifiedFor[i]); //puts in the beginning of the vector
        }
        else{
            OrderedStudent.push_back(stuQualifiedFor[i]); //pushes onto the vector
        }
    }
    return OrderedStudent;
}

vector<Student> Employer::JobQualification(Employer empl, vector<Student*> student_vec){
     //declared variables:
    vector<Student> student; //new vector of potential matches
    //int i=0; //for loop counter
    int len;
    int flag1=0;
    int jobLen=0;
    int flag2=0;
    int z=0;
    int matched;
    
    len = student_vec.size(); //gets size of student vector
    
    for(int i=0;i<len;i++){
        jobLen = empl.getOpenJobs().size(); //gets size of the open jobs vector
        for(int j=0;j<jobLen;j++){ //goes through the open jobs vector
            int k=0;
            vector <string> preffered_maj;
            int len2=0;
            int h=0;
            int len3=0;
            
            //compares class standing
            if((student_vec[i]->getClassStanding()) < ((empl.getOpenJobs())[j].getClassStanding())){
                continue; //checks next job element
            } //compares gpa
            if((student_vec[i]->getGpa()) < ((empl.getOpenJobs())[j].getPreferredGPA())){ //is student gpa is less than preferred
                continue; //checks next job element
            }
            
            flag1 = 0;
            len2 = ((empl.getOpenJobs())[j].getPreferredMajors()).size(); //gets length of the preferred majors vector
            for(k=0;k<len2;k++){//compares majors
                if(!strcasecmp((student_vec[i]->getMajor().c_str()),((empl.getOpenJobs())[j].getPreferredMajors())[k].c_str())){ //|Done|..fix to disregard case when comparing major strings
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
            len3 = ((empl.getOpenJobs())[j].getRequiredSkills()).size();
            for(h=0;h<len3;h++){
                if(find(student_vec[i]->getSkills().begin(), student_vec[i]->getSkills().end(), (empl.getOpenJobs()[j].getRequiredSkills())[h]) != student_vec[i]->getSkills().end()){
                    flag2 = 1; //set flag if match found
                    break;
                }
            }
            
            //if match not found then move to next job
            if(flag2!=1){
                continue; //go to next job if didn't match any skills
            }
            
            //if makes it this far then it wont have had a cause to break loop
            matched = 0;
            for(z=0;z<student.size();z++){
                if(student[z].getFirstName() == student_vec[i]->getFirstName() && student[z].getLastName() == student_vec[i]->getLastName()){
                    matched = 1;
                    break;
                }
            }
            if(matched!=1){
            student.push_back(*student_vec[i]); //puts matched jobs onto a vector
            }
        }
    }
    
    return student; //returns list of matched students
}
void Employer::addJob(){
    int choice, counter, i;
    float gpa, salary;
    string enteredMajor, enteredSkill;
    string title;
    choice = 0;
    Job newJob(this);
    
    cout << "\nEnter job title (1 word only): ";
    cout.flush();
    cin >> ws;
    getline(cin, title);
    cout << title << endl;
    
    newJob.setTitle(title); //makes new title of job

    cout << "\n1) Freshman\n2) Sophomore\n3) Junior\n4)Senior\nEnter the minimum class standing required: ";
    cin >> choice;
    while(choice < 1 || choice > 4){
        cout << "\nInvalid choice, try again: ";
        cin >> choice;
    }
    newJob.setClassStanding(choice); //determines the required class standing
    
    cout << "\nEnter number of preferred majors: ";
    cin >> counter;
    getline(cin, enteredMajor); //chew up existing newline
    for(i=0;i<counter;i++){
        cout << "Enter preferred major #" + to_string(i+1) + " (multiple words accepted): ";
        getline(cin, enteredMajor);
        newJob.addPreferredMajor(enteredMajor); //adds the major
    }
    
    cout << "\nEnter minimum required GPA, between 0 and 4: ";
    cin >> gpa;
    while(gpa < 0 || gpa > 4){
        cout << "\nInvalid choice, try again: ";
        cin >> gpa;
    }
    newJob.setPreferredGPA(gpa);
    
    cout << "\nEnter hourly position salary: ";
    cin >> salary;
    newJob.setSalary(salary);
    
    cout << "\nEnter number of required skills: ";
    cin >> counter;
    for(i=0;i<counter;i++){ //loops for every skill based on the number provided
        cout << "\nEnter required skill #" << (i+1) << ": ";
        cin >> enteredSkill;
        newJob.addRequiredSkill(enteredSkill);
    }
    openJobs.push_back(newJob); //push onto the vector for the employer
    this->employerUpdate(); //updates the new info to the file
    cout << "Job saved successfully." << endl;
}

void Employer::deleteJob(){
    int i, choice;
    string oldTitle;
    if(openJobs.size() != 0){
        for(i=0;i<openJobs.size();i++){
            cout << endl << (i+1) << ") " << openJobs[i].getTitle(); //prints the current jobs
        }
        cout << "\nEnter the number of the job to delete: ";
        cin >> choice;
        while(choice < 1 || choice > openJobs.size()){
            cout << "\nInvalid choice, try again: ";
            cin >> choice;
        }
        oldTitle = openJobs[choice - 1].getTitle();
        openJobs.erase(openJobs.begin() + (choice - 1)); //necessary to add index to openJobs.begin() to avoid error when only one element is in the vector (http://stackoverflow.com/a/875117/5336262)
        cout << oldTitle << " deleted successfully.";
    } else {
        cout << "\nNo jobs to delete." << endl;
    }
    this->employerUpdate(); //write this object to a file
}
