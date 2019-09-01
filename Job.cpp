#include <cstdlib>
#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include "Job.hpp"
using namespace std
    
class Student;
class Job;
class Employer;    
    
Job::Job(Employer* comp){ //constructor
    company = comp;
    class_standing_req = 0;
    vector <string> preferred_majors; //what to initialize to?
    preferredGPA = 0.0;
    salary = 0.0;
    vector <string> requiredSkills; //what to initialize to?
}

Job::~Job(void){
    //don't delete company here
}

//getters
Employer* Job::getEmployer(){
  return company;
}
string Job::getTitle(){
  return title;
}
int Job::getClassStanding(){
  return class_standing_req;
}
vector<string> Job::getPreferredMajors(){
  return preferred_majors;
}
float Job::getPreferredGPA(){
  return preferredGPA;
}
float Job::getSalary(){
  return salary;
}
vector<string> Job::getRequiredSkills(){
  return requiredSkills;
}

//setters
void Job::setCompany(Employer* newCompany){
  company = newCompany;
};
void Job::setTitle(string newTitle){
  title = newTitle;
}
void Job::setClassStanding(int newClassStanding){
  class_standing_req = newClassStanding;
}
void Job::addPreferredMajor(string newMajor){
  preferred_majors.push_back(newMajor);
}
void Job::setPreferredGPA(float newGPA){
  preferredGPA = newGPA;
}
void Job::setSalary(float newSalary){
  salary = newSalary;
}
void Job::addRequiredSkill(string newSkill){
  requiredSkills.push_back(newSkill);
}
