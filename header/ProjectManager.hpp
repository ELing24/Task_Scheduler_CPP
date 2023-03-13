#ifndef PROJECT_MANAGER_HPP
#define PROJECT_MANAGER_HPP
#include <vector> 
#include <iostream>
#include "Project.hpp"

using namespace std;

class ProjectManager {
    private:
        vector<Project*> projects;
    public:
        ProjectManager();
        ~ProjectManager();
        void deleteProject(string);
        void outputProjects();
        int ProjectSize();
        Project getProject(string);
        void addProject(string, string);
        bool doesProjectExist(string);
};

#endif
