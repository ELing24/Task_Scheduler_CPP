#ifndef SUBTASK_HPP
#define SUBTASK_HPP

#include "Base.hpp"

class Subtask : public Base
{
    public:
        Subtask();
        Subtask(string newName, string newDescription, bool newStatus);
};
#endif