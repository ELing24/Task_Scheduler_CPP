#ifndef TASK_HPP
#define TASK_HPP
#include <vector>
#include <string>


class Task : public Base{
    private:
        vector<subtask> subs;
        int priority;
        string deadline;
        vector<int> priority;
        vecctor<string> deadline;
    public:
        void Task(string, string, string, int, bool);
        void addSubtask(string, string, bool);
        void undoDeadline();
        void undoPriority();
        void setDeadline(string);
        void setPriority(int);
        string getDeadline();
        int getpriority();
        void changeDeadline(string);
        void changePriority(int);
        subtask getSubtask(string);
        void outputsubs();
        void deleteSubtask(string);
};

#endif