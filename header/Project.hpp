#ifndef PROJECT_HPP
#define PROJECT_HPP
#include "../header/Task.hpp"
#include <vector>
#include <iostream>
using namespace std;
class Project{
    private:
        vector<string> names;
        vector<Task*> tasks;
        vector<string> descriptions;
        string name;
        string description;
    public:
        Project(string, string);
        ~Project();
        void addTask(string,string,string,int,bool);
        int completedTasks();
        bool iscompleted(string);
        void editProjectName(string);
        void editProject_Description(string);
        void undo_Names();
        void undo_Description();
        void deleteTask(string);
        Task* getTask(string);
        void outputTasks();
        void sortByPriority();
        bool doesTaskExist(string);
};
#endif