#include "../header/Project.hpp"

Project::Project(string n, string d)
{
    this->name = n;
    this->description = d;
}
Project::~Project()
{
    for (int i = 0; i < tasks.size(); ++i) {
        delete tasks[i];
    }
}
void Project::addTask(string n, string d, int dead, int p, bool status)
{
    Task *tmp = new Task(n, d, dead, p, status);
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
    descriptions.push_back(this->description);
    this->description = d;
}
void Project::editProjectName(string n)
{
    names.push_back(this->name);
    this->name = n;
}
void Project::undo_Description()
{
    if (descriptions.size() > 0) {
        description = descriptions.back();
        descriptions.pop_back();
    }
}
void Project::undo_Names()
{
    if (names.size() > 0) {
        name = names.back();
        names.pop_back();
    }
}
Task* Project::getTask(string TaskToFind)
{
   bool foundName = false;
   Task* tmp = nullptr;

    for (int i = 0; i < tasks.size(); ++i)
    {
        if (tasks[i]->getName() == TaskToFind)
        {
            tmp = tasks[i];
            foundName = true;
            break;
        }
    }
   

   return tmp;
}

void Project::sortByPriority() {
    sort(tasks.begin(), tasks.end(), [](Task* t1, Task* t2) {
        return t1->getPriority() < t2->getPriority();
    });
}
string Project::outputTasks() {
    sortByPriority();
    stringstream os;
    for (int i = 0; i < tasks.size(); ++i) {
        Task* task = tasks[i];
        os << "Name: " << task->getName() << endl;
        os << "Description: " << task->getDescriptions() << endl;
        os << "Deadline: " << task->getDeadline() << endl;
        os << "Priority: " << task->getPriority() << endl;
        os << "Status: " << (task->getStatus() ? "Complete" : "Incomplete") << endl;
        os << "----------------------" << endl;
    }
    return os.str();
}
void Project::deleteTask(string name)
{
    for (auto t = tasks.begin(); t != tasks.end();)
    {
        if ((*t)->getName() == name)
        {
            delete (*t);
            t = tasks.erase(t);
            return;
        }
        else
        {
            ++t;
        }
    }
}
bool Project::doesTaskExist(string findTaskName)
{
    bool isTrue = false;
    for(int i = 0; i < tasks.size(); ++i)
    {
        if(tasks[i]->name == findTaskName)
        {
            isTrue = true;
        }
    }
    return isTrue;
}
