#ifndef PROJECT_MANAGER_HPP
#define PROJECT_MANAGER_HPP
#include <vector> 
#include <iostream>

using namespace std;

class ProjectManager {
    private:
        vector<Projects> project;
        bool empty;
    public:
        void ProjectManager(project);
        void deleteProject();
        void outputProject();
        void setProjectName(string);
        void setDescription(string);
        bool isComplete();
        bool isEmpty();
        Project getProject(string);
        void addProject();
};

#endif