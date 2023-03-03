#include "../header/Task.hpp"
#include <iostream>

using namespace std;

Task::Task(string name, string description, string deadline,int priority, bool status){
    this->name = name;
    this->description = description;
    this->deadline = deadline;
    this->priority = priority;
    this->status = status;
}

string Task::getDeadline(){
    return deadline;
}

void Task::setDeadline(string deadline){
    this->deadline = deadline;
}
void Task::changeDeadline(string deadline){
    deadline.push_back(deadline);
    this->deadline = deadline;
}
void Task::undoDeadline(){
    if(deadline.size() > 0){
        deadline = deadline.back();
        deadline.pop_back;
    }
}
int Task::getpriority(){
    return priority;
}

void Task::changePriority(int priority){
    this->priority = priority;
}

void Task::setPriority(int priority){
    priority.push_back(priority);
    this->priority = priority;
}

void undoPriority(){
    if(priority.size() > 0){
        priority = priority.back();
        priority.pop_back;
    }
}

