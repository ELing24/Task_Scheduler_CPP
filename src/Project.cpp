#include "../header/Project.hpp"

Project::Project(string n, string d)
{
    this->name = n;
    this->description = d;
}
void Project::addTask(string n, string d, string dead, int p, bool status)
{
    Task *tmp = new Task(n, d, dead, p, status);
    sortByPriority();
    tasks.push_back(tmp);
}
int Project::completedTasks()
{
    int cnt = 0;
    for(int i = 0; i < tasks.size(); ++i)
    {
        if(tasks[i]->status == true)
        {
            ++cnt;
        }
    }
    return cnt;
}
void Project::editProject_Description(string d)
{
    descriptions.push_back(this->descriptions);
    this->descriptions = d;
}
void Project::editProjectName(string n)
{
    names.push_back(this->name);
    this->name = n;
}
void Project::undo_Description()
{
    if (descriptions.size() > 1) {
        descriptions.pop_back();
        description = descriptions.back();
    }
}
void Project::undo_Names()
{
    if (names.size() > 1) {
        names.pop_back();
        name = names.back();
    }
}
Task* Project::getTask()
{
    string findTask;
    bool foundName = false;
    cout << "Enter name of Task: " << endl;
    cin >> findTask;
    Task* tmp = nullptr;
    while(foundName == false)
    {
        for(int i = 0; i < tasks.size();++i)
        {
            if(tasks[i]->getName() == findTask)
            {
                tmp = tasks[i];
                foundName = true;
            }
        }
        if(foundName == false)
        {
            cout << "Task doesn't exist, Try Again: " << endl;
            cin >> findTask;
        }
        
    }
    return tmp;

}
void Project::editTask(){
    Task* tmp = getTask();
    string whichToChange = "";
    cout << "Enter name to modify name, description to modify description
        deadline to modify deadline, status to modify status, or 
        priority to change priority" << endl;
    cin >> whichToChange;
    while(true)
    {
        if(whichToChange == "name")
        {
            string NewName;
            cout << "Enter the name you want to change: " << endl;
            cin >> NewName;
            tmp->ChangeName(NewName);
            break;
        }
        else if(whichToChange == "description")
        {
            string newDescription;
            cout << "Enter the new description you want to change: " <<endl;
            getline(cin, newDescription);
            tmp->ChangeDescriptions(newDescription);
            break;
        }
        else if(whichToChange == "deadline")
        {
            string newDeadline;
            cout << "Enter the new deadline you want to change: " << endl;
            cin>>newDeadline;
            tmp->ChangeDeadline(newDeadline);
            break;

        }
        else if(whichToChange == "status")
        {
            bool status;
            string option;
            cout << "Enter one if you want to make the status of task " <<  tmp->GetName()
            << " complete or zero if status is uncomplete: " << endl;
            cin >> option;
            while(true)
            {
                if(option == "1")
                {
                    tmp->changeStatus(true);
                    break;
                }
                else if(option == "0"){
                    tmp->changeStatus(false);
                    break;
                }
                else{
                    cout << "Incorrect value, Try Again: " << endl;
                    cin >> option;
                }
                
            }
            break;
        }
        else if(whichToChange == "priority")
        {
            int newPriority;
            cout << "Enter the new priority of this task in digits: " << endl;
            cin >> newPriority;
            tmp->changePriority(newPriority);
            break;
            
        }
        else
        {
            cout << "Incorrect option, Try Again" << endl;
            cin >> whichToChange;
        }

    }
}
void Project::sortByPriority() {
    sort(tasks.begin(), tasks.end(), [](Task* t1, Task* t2) {
        return t1->getPriority() < t2->getPriority();
    });
}
void Project::printTasksByPriority() {
    sortByPriority();

    for (int i = 0; i < tasks.size(); ++i) {
        Task* task = tasks[i];
        cout << "Name: " << task->getName() << endl;
        cout << "Description: " << task->getDescriptions() << endl;
        cout << "Deadline: " << task->getDeadline() << endl;
        cout << "Priority: " << task->getPriority() << endl;
        cout << "Status: " << (task->getStatus() ? "Complete" : "Incomplete") << endl;
        cout << "----------------------" << endl;
    }
}
void Project::deleteTask()
{
    cout << "Enter the name of the Task that you want to delete: " << endl;
    string name = "";
    cin >> name;
    while(true)
    {
        for (auto t = tasks.begin(); t != tasks.end(); ++t)
        {
            if ((*t)->getName() == name)
            {
                delete (*t);
                tasks.erase(t);
                return;
            }
        }
        cout << "Name not found, Try Again: " << endl;
        cin >> name;
    }
}