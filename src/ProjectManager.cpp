#include <vector>
#include <iostream>
#include "../header/Project.hpp"
#include "../header/ProjectManager.hpp"

ProjectManager::ProjectManager() {
     
}


ProjectManager::~ProjectManager() {
    for (int i = 0; i < projects.size(); ++i) {
        delete projects[i];
    }
}

void ProjectManager::editProject_Description(string d) {
    descriptions.push_back(this->descriptions);
    this->descriptions = d;
}


void ProjectManager::editProjectName(string n) {
    names.push_back(this->name);
    this->name = n;
}

void ProjectManager::deleteProject(string name) {
    for (auto p = projects.begin(); p != projects.end();) {
        if ((*p)->getName() == name) {
            delete (*p);
            p = projects.erase(t);
            return;
        }
        else {
            ++p;
        }
    }
}

/* void ProjectManager::outputProjects() {
    for (int i = 0; i < projects.size(); ++i) {
        Project project = projects[i];
        cout << "Name: " << projects.getName() << endl;
        cout << "Description: " << projects.getDescriptions() << endl;
        cout << "Deadline: " << projects.getDeadline() << endl;
        cout << "Priority: " << projects.getPriority() << endl;
        cout << "Status: " << (projects.getStatus() ? "Complete" : "Incomplete") << endl;
        cout << "----------------------" << endl;
    }
}
*/ 

/*int ProjectManager::ProjectSize() {

}
*/

Project* ProjectManager::getProject(string ProjectToFind) {
    bool foundName = false;
    Project* tmp = nullptr;

    for (int i = 0; i < projects.size(); ++i) {
        if (projects[i]->getName() == ProjectToFind) {
            tmp = projects[i];
            foundName = true;
            break;
        }
    }
   
   return tmp;
}
           
/*void ProjectManager::addProject(string projectName, string description) {
    string projectName, description;
    cout << "Enter project name: ";
    cin >> projectName;
    cout << "Enter project description: ";
    cin >> description;
            
    projects.push_back(Project(projectName, description));
    empty = false;
    cout << "Project " << projectName << " added." << endl;
}
*/
            
bool ProjectManager::doesProjectExist(string findProjectName) {
    bool isTrue = false;
    for (int i = 0; i < projects.size(); ++i) {
        if(projects[i]->name == findProjectName) {
            isTrue = true;
        }
    }
    return isTrue;
}            