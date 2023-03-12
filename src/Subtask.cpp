#include "../header/Subtask.hpp"

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

void Subtask::setName(string newName){
	name = newName;
}

string Subtask::getName(){
	return name;
}

void Subtask::changeName(string newName){
	names.push_back(name);
	name = newName;	
}

void Subtask::undoName(){
	if(names.size() > 0){
		name = names.back();
		names.pop_back();
	}
}

void Subtask::setDescription(string newDescription){
	description = newDescription;
}

string Subtask::getDescription(){
	return description;
}

void Subtask::changeDescription(string newDescription){
	descriptions.push_back(description);
	description = newDescription;
}

void Subtask::undoDescription(){
	if(descriptions.size() > 0){
		description = descriptions.back();
		descriptions.pop_back();
	}
}

void Subtask::setStatus(bool newStatus){
	status = newStatus;
}

bool Subtask::getStatus(){
	return status;
}

void Subtask::changeStatus(bool newStatus){
	statusList.push_back(status);
	status = newStatus;
}

void Subtask::undoStatus(){
	if(statusList.size() > 0){
		status = statusList.back();
		statusList.pop_back();
	}
}
