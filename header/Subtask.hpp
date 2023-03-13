#ifndef SUBTASK_HPP
#define SUBTASK_HPP

#include <vector>

using namespace std;

class Subtask{
    private:
        vector<string> names;
        vector<string> descriptions;
        vector<bool> statusList;
        string name;
        string description;
        bool status;
    public:
        Subtask();
        Subtask(string newName, string newDescription, bool newStatus);
        void setName(string newName);
        string getName();
        void changeName(string newName);
        void undoName();
        void setDescription(string newDescription);
        string getDescription();
        void changeDescription(string newDescription);
        void undoDescription();
        void setStatus(bool newStatus);
        bool getStatus();
        void changeStatus(bool newStatus);
        void undoStatus();
};

#endif
