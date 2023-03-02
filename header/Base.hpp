#ifndef BASE_HPP
#define BASE_HPP

#include <vector>

using namespace std;

class Base{
    private:
        vector<string> names;
        vector<string> descriptions;
        vector<bool> statusList;
        string name;
        string description;
        bool status;
    public:
        Base();
        Base(string newName, string newDescription, bool newStatus);
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
