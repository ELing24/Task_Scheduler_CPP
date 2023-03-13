#include "../header/Task.hpp"
#include <iostream>

using namespace std;

Task::Task() {
	name = "";
	description = "";
	status = false;
    date = 0;
    priority = 0;
}


Task::Task(string name, string description, int date, int priority, bool status){
    this->name = name;
    this->description = description;
    this->date = date;
    this->priority = priority;
    this->status = status;
}

int Task::getDeadline(){
    return date;
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
int Task::getPriority(){
    return priority;
}

void Task::changePriority(int priority){
    this->priority = priority;
}

void Task::setPriority(int priority){
    priority.push_back(priority);
    this->priority = priority;
}

void Task::undoPriority(){
    if(priority.size() > 0){
        priority = priority.back();
        priority.pop_back;
    }
}

Task::~Task(){
    for (int i = 0; i < subs.size(); ++i)
    {
        delete subs[i];
    }
}

void Task::addSubtask(string name, string description, bool status){
    Subtask *tmp = new Subtask(name, description, status);
    subs.push_back(tmp);
}

void Task::outputsubs(){
    stringstream os;
    for (int i = 0; i < subtask.size(); ++i)
    {
        Subtask* sub = subs[i];
        os << "Name: " << sub->getName() << endl;
        os << "Description: " << sub->getDescriptions() << endl;
        os << "Status: " << (sub->getStatus() ? "Complete" : "Incomplete") << endl;
        os << "----------------------" << endl;
    }
    return os.str();
}

void Task::deleteSubtask(string name){
    for (auto s = subs.begin(); s != subs.end()){
        if((*s)->getName() == name){
            delete (*s);
            s = subs.erase(s);
            return;
        }
        else{
            ++s;
        }
    }
}

bool Task::doesSubtaskExist(string findSubName){
    bool isTrue = false;
    for (int i =0; i < subs.size(); ++i){
        if(subs[i]->name == findSubName)
        {
            isTrue = true;
        }
    }
    return isTrue;
}