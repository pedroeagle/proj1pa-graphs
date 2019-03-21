#include <iostream>
#include "graphs.hpp"
Subject::Subject(){ 

}
Subject::Subject(string subject_name, int code, int credits){

	quantity_prerequisites = 0;

    this->name = subject_name;
    this->code = code;
    this->credits = credits;
}
Subject::~Subject(){
    //tenho que passar por todos os galhos para verificar a presença da matéria removida
}
void Subject::insert_prerequisite(Subject *subject){
    if(subject){
    	prerequisites.insert(*(subject));
		quantity_prerequisites++;
	}
    //tenho que passar por todas os galhos para verificar a presença da matéria removida
}

void Subject::remove_prerequisite(Subject *subject){
	if(subject){
		if(prerequisites.count(*subject)!=0){
			prerequisites.erase(*subject);
			quantity_prerequisites--;
		}
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