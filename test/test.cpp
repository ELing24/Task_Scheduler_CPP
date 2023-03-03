#include <iostream>
#include "../header/Project.hpp"
#include "../header/ProjectManager.hpp"

using namespace std;

int main() {
    ProjectManager manager;

    while (true) {
        cout << "Enter a command (add, delete, rename, describe, complete, list, quit): ";
        string command;
        cin >> command;

        if (command == "add") {
            Project Project;
            cout << "Enter project name: ";
            string name;
            cin >> name;
            Project.setProjectName(name);
            manager.addProject();
        } else if (command == "delete") {
            manager.deleteProject();
        } else if (command == "rename") {
            cout << "Enter project name: ";
            string name;
            cin >> name;
            manager.setProjectName(name);
        } else if (command == "describe") {
            cout << "Enter project name: ";
            string descript;
            cin >> descript;
            manager.setDescription(descript);
        } else if (command == "complete") {
            cout << "Enter project name: ";
            string name;
            cin >> name;
            if (manager.isComplete(name)) {
                cout << "Project " << name << " is complete." << endl;
            } else {
                cout << "Project " << name << " is not complete." << endl;
            }
        } else if (command == "list") {
            manager.outputProjects();
        } else if (command == "quit") { 
            break;
        } else {
            cout << "Invalid command. Please try again." << endl;
        }
    }

    return 0;
}
