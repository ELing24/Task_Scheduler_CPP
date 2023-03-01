#include "subtask.hpp"

Subtask::Subtask() {
	name = "";
	description = "";
	status = false;
}

Subtask::Subtask(string newName, string newDescription, bool newStatus){
	name = newName;
	description = newDescription;
	status = newStatus;
}