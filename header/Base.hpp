#include <iostream>
#include <vector>

using namespace std;

class Base{
    private:
        vector<string> descriptionList;
        vector<string> nameList;
        vector<bool> statusList;
        string name;
        string description;
        bool status;
    public:
        Base();
        void changeStatus(bool newStatus);
        void setName(string newName);
        void setDescription(string newDescription);
        void setStatus(bool newStatus);
        string getName();
        string getDescription();
        void changeName(string newName);
        void changeDescription(string newDescription);
        void undoName();
        void undoDescription();
        void undoStatus();
        bool getStatus();
};
