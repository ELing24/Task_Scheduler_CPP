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

void Task::setDeadline(int deadline){
    deadlines.push_back(this->date);
    this->date = deadline;
}
void Task::changeDeadline(int deadline){
    deadlines.push_back(date);
    this->date = deadline;
}
void Task::undoDeadline(){
    if(deadlines.size() > 0){
        date = deadlines.back();
        deadlines.pop_back();
    }
}
int Task::getPriority(){
    return priority;
}

void Task::changePriority(int priority){
    priorities.push_back(this->priority);
    this->priority = priority;
}

void Task::setPriority(int priority){
    priorities.push_back(priority);
    this->priority = priority;
}

void Task::undoPriority(){
    if(priorities.size() > 0){
        priority = priorities.back();
        priorities.pop_back();
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

string Task::outputsubs(){
    stringstream os;
    for (int i = 0; i < subs.size(); ++i)
    {
        Subtask* sub = subs[i];
        os << "Name: " << sub->getName() << endl;
        os << "Description: " << sub->getDescription() << endl;
        os << "Status: " << (sub->getStatus() ? "Complete" : "Incomplete") << endl;
        os << "----------------------" << endl;
        os << endl;
    }
    return os.str();
}

void Task::deleteSubtask(string name){
    for (auto s = subs.begin(); s != subs.end();){
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
        if(subs[i]->getName() == findSubName)
        {
            isTrue = true;
        }
    }
    return isTrue;
}
int Task::subtaskNumber()
{
    return subs.size();
}
Subtask* Task::getSubtask(string findSubtask)
{
    bool foundName = false;
    Subtask* tmp = nullptr;

        for (int i = 0; i < subs.size(); ++i)
        {
            if (subs[i]->getName() == findSubtask)
            {
                tmp = subs[i];
                foundName = true;
                break;
            }
        }
   

   return tmp;
}