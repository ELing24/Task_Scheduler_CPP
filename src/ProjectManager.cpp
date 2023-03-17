#include <vector>
#include <iostream>
#include <sstream>
#include "../header/Project.hpp"
#include "../header/ProjectManager.hpp"

ProjectManager::ProjectManager(){}

ProjectManager::~ProjectManager(){
    for(int i = 0; i < projects.size(); ++i){
        delete projects[i];
    }
}

void ProjectManager::deleteProject(string ProjectToDelete){
    for (auto t = projects.begin(); t != projects.end();){
        if ((*t)->getProjectName() == ProjectToDelete){
            delete (*t);
            t = projects.erase(t);
            return;
        }
        else{
            ++t;
        }
    }
}

string ProjectManager::outputProjects(){
    stringstream os;
    for (int i = 0; i < projects.size(); ++i){
        Project* projectsToOutput = projects[i];
        os << "Name: " << projectsToOutput->getProjectName() << endl;
        os << "Description: " << projectsToOutput->getProjectDescription() << endl;
        os << endl;
    }
    return os.str();
}

int ProjectManager::ProjectSize(){
    return projects.size();
}

Project* ProjectManager::getProject(string ProjectToFind){
    bool foundName = false;
    Project* tmp = nullptr;

    for (int i = 0; i < projects.size(); ++i){
        if (projects[i]->getProjectName() == ProjectToFind){
            tmp = projects[i];
            foundName = true;
            break;
        }
    }
   return tmp;
}

void ProjectManager::addProject(string projectName, string projectDescription){
    Project* tmp = new Project(projectName, projectDescription);
    projects.push_back(tmp);
} 

bool ProjectManager::doesProjectExist(string projectToFind){
    bool isTrue = false;
    for(int i = 0; i < projects.size(); ++i){
        if (projects[i]->getProjectName() == projectToFind){
            isTrue = true;
        }
    }
    return isTrue;
}
