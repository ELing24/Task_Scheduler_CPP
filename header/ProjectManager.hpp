#ifndef PROJECT_MANAGER_HPP
#define PROJECT_MANAGER_HPP
#include <vector> 
#include <iostream>
#include "Project.hpp"

using namespace std;

class ProjectManager {
    private:
        vector<Project> projects;
        bool empty;
    public:
        ProjectManager();
        void deleteProject();
        void outputProjects();
        void setProjectName(string);
        void setDescription(string);
        bool isComplete(string);
        bool isEmpty();
        Project getProject(string);
        void addProject();
};

#endif