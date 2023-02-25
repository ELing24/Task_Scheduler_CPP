#ifndef TASK_HPP
#define TASK_HPP
#include <vector>


class Task{
    private:
        vector<subtask> subs;
        int priority;
        string deadline;
        vector<int> priority;
        vecctor<string> deadline;
    public:
        void Task(string, string, string, bool, int);
        void addSubtask(string, string, bool);
        void undoDeadline();
        void undoPriority();
        void setDeadline(string);
        string getDeadline();
        int getpriority();
        void changeDeadline(string);
        void changePriority(int);
        subtask getSubtask(string);
        void outputsubs();
        void deleteSubtask(string);
};

#endif