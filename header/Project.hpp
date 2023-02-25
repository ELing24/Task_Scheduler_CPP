#ifndef PROJECT_HPP
#define PROJECT_HPP

class Project{
    private:
        vector<string> names;
        vector<Task*> tasks;
        vector<string> descriptions;
        string name;
        string description;
    public:
        Project(string, string);
        void addTask(string,string,string,int,bool);
        int completedTasks();
        bool iscompleted(string);
        void editProjectName(string);
        void editTask(Task*);
        void editSubtask(subtask*);
        void editProject_Description(Project*);
        void undo_Names();
        void undo_Description();
        void deleteTask();
        subtask findSubtask(Task*);
        Task getTask();
        void outputTasks();
        void sortByPriority();
}