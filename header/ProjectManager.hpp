#ifndef PROJECT_MANAGER_HPP
#define PROJECT_MANAGER_HPP
#include <vector> 
#include <iostream>
#include <sstream> 
#include "Project.hpp"

using namespace std;

class ProjectManager {
    private:
        vector<Project*> projects;

    public:
        ProjectManager();
        ~ProjectManager();
        void addProject(string, string);
        void deleteProject(string);
        void outputProjects();
        int ProjectSize();
        Project getProject(string);
        bool doesProjectExist(string);
};

#endif
