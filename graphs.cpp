#include <iostream>
#include "graphs.hpp"
Subject::Subject(){ 

}
Subject::Subject(string subject_name, int code, int credits){
    this->name = subject_name;
    this->code = code;
    this->credits = credits;
}
Subject::~Subject(){
    //tenho que passar por todas os galhos para verificar a presença da matéria removida
}
void Subject::insert_prerequisite(Subject *subject){
    if(subject)
    	prerequisites.insert(*(subject));
}

void Subject::remove_prerequisite(Subject *subject){
	if(subject){
		if(prerequisites.count(*subject)!=0)
			prerequisites.erase(*subject);
	}
}

void Subject::show_prerequisites(){
    for(auto prerequisite: prerequisites){
    	prerequisite.show_subject();
    }
}

void Subject::show_subject(){
	cout << "Name: " << name << endl;
	cout << "Code: " << code << endl;
	cout << "Credits: " << credits << endl << endl;
}

bool Subject::operator<(const Subject &subject) const{
	return name < subject.name;
}