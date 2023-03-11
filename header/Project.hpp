#ifndef PROJECT_HPP
#define PROJECT_HPP
#include "../header/Task.hpp"
#include <vector>
#include <iostream>
#include <sstream>
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
        void addTask(string,string,int,int,bool);
        int completedTasks();
        bool iscompleted(string);
        void editProjectName(string);
        void editProject_Description(string);
        void undo_Names();
        void undo_Description();
        void deleteTask(string);
        Task* getTask(string);
        string outputTasks(bool);
        void sortByPriority();
        bool doesTaskExist(string);
        int sizeOfTasksVector();
};
#endif