#include <vector>
#include <iostream>
#include "../header/Project.hpp"
#include "../header/ProjectManager.hpp"

ProjectManager::ProjectManager() {
    empty = true;
}

void ProjectManager::deleteProject() {
    string projectName;
    cout << "Enter project name to delete: ";
    cin >> projectName;
            
    for (int i = 0; i < projects.size(); i++) {
        if (projects[i].getProjectName() == projectName) {
            projects.erase(projects[i]);
            cout << "Project " << projectName << " deleted." << endl;
            return;
            }
    }
            
    cout << "Project " << projectName << " not found." << endl;
}

void ProjectManager::outputProjects() {
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

void ProjectManager::setProjectName(string newName) {
    //ProjectName = newName;
}
    if (projects.empty()) {
        cout << "No projects to rename." << endl;
    } 
    else {
        string new_name;
        cout << "Enter the new name for project " << name << ": ";
        cin >> new_name;
        for (int i = 0; i < projects.size(); i++) {
            if (projects[i].getName() == name) {
                projects[i].setName(new_name);
                cout << "Project renamed to " << new_name << "." << endl;
                return;
            }
        }
        cout << "Project " << name << " not found." << endl;
    }
}


void ProjectManager::setDescription(string newDescription) {
    description = newDescription;
}
    /*if (projects.empty()) {
        cout << "No projects to set description." << endl;
    } else {
        string desc;
        cout << "Enter the description for project " << name << ": ";
        cin >> desc;
        for (int i = 0; i < projects.size(); i++) {
            if (projects[i].getName() == name) {
                projects[i].setDescription(desc);
                cout << "Project description set." << endl;
                return;
            }
        }
        cout << "Project " << name << " not found." << endl;
    }
}
*/

bool ProjectManager::isComplete(string name) {
    if (projects.isEmpty()) {
        return false;
    } 
    else {
        for (int i = 0; i < projects.size(); i++) {
            if (projects[i].getName() == name) {
                return projects[i].isComplete();
            }
            else {
                cout << "Project not found" <<endl;
                return false;
            }
        }
    }
}

bool ProjectManager::isEmpty() {
    if(projects[]=0){
        cout<<"No Projects" <<endl;
        return true;
    }
    else{ return false;}
}

Project ProjectManager::getProject(string name) {
    for (int i = 0; i < projects.size(); i++) {
        if (projects[i].getProjectName() == projectName) {
            return projects[i];
        }
    }
    cout << "Project " << projectName << " not found." << endl;
    return projects[i];
}
        
           
void ProjectManager::addProject() {
    string projectName, description;
    cout << "Enter project name: ";
    cin >> projectName;
    cout << "Enter project description: ";
    cin >> description;
            
    projects.push_back(Project(projectName, description));
    empty = false;
    cout << "Project " << projectName << " added." << endl;
}
            