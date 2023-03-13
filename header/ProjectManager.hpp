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
        vector<string> names;
        vector<string> descriptions;

    public:
        ProjectManager();
        ~ProjectManager();
        void addProject(string, string);
        void editProject_Description(string, string);
        void editProjectName(string);
        void deleteProject(string);
        void outputProjects();
        int ProjectSize();
        Project getProject(string);
        bool doesProjectExist(string);
};

#endif