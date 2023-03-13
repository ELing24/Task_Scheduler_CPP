#ifndef TASK_HPP
#define TASK_HPP
#include <vector>
#include <string>
#include <sstream>
#include "../header/Subtask.hpp"


class Task : public Subtask{
    private:
        vector<Subtask*> subs;
        int priority;
        int date;
        vector<int> deadlines;
        vector<int> priorities;
    public:
        Task();
        Task(string, string, int, int, bool);
        ~Task();
        void addSubtask(string, string, bool);
        void undoDeadline();
        void undoPriority();
        void setDeadline(int);
        void setPriority(int);
        int getDeadline();
        int getPriority();
        void changeDeadline(int);
        void changePriority(int);
        Subtask* getSubtask(string);
        string outputsubs();
        void deleteSubtask(string);
        bool doesSubtaskExist(string);
        int subtaskNumber();
};

#endif