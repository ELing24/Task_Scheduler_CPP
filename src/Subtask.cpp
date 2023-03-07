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

void Base::setName(string newName){
	name = newName;
}

string Base::getName(){
	return name;
}

void Base::changeName(string newName){
	names.push_back(name);
	name = newName;	
}

void Base::undoName(){
	if(names.size() > 0){
		name = names.back();
		names.pop_back();
	}
}

void Base::setDescription(string newDescription){
	description = newDescription;
}

string getDescription(){
	return description;
}

void Base::changeDescription(string newDescription){
	descriptions.push_back(description);
	description = newDescription;
}

void Base::undoDescription(){
	if(descriptions > 0){
		description = descriptions.back();
		descriptions.pop_back();
	}
}

void Base::setStatus(bool newStatus){
	status = newStatus;
}

bool Base::getStatus(){
	return status;
}

void Base::changeStatus(bool newStatus){
	statusList.push_back(status);
	status = newStatus;
}

void Base::undoStatus(){
	if(statusList.size() > 0){
		status = statusList.back();
		statusList.pop_back();
	}
}
