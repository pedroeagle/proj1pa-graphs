#include "graphs.hpp"
#include "functions.hpp"
#include <bits/stdc++.h>

using namespace std;

stack<Subject> bfs_changed(Subject desired_subject){
	set<Subject> visited_subjects;
	stack<Subject> subjects_order;
	queue<Subject> to_visit;
	to_visit.push(desired_subject);
	visited_subjects.insert(desired_subject);
	subjects_order.push(desired_subject);

	while(!to_visit.empty()){
		auto subject = to_visit.front();
		to_visit.pop();
		for(auto prerequisite : subject.prerequisites){
			if(visited_subjects.count(*prerequisite) == 0){
				visited_subjects.insert(*prerequisite);
				to_visit.push(*prerequisite);
				subjects_order.push(*prerequisite);
			}
			if(subjects_order.top().name!=prerequisite->name){
				subjects_order.push(*prerequisite);
			}
		}
	}

	return subjects_order;
}

void show_schedule(stack<Subject> subjects_order){
	set<Subject> concluded_subjects;
	for(int semester = 1; /*!subjects_order.empty()*/ semester<10; semester++){
		bool prerequisites_concluded = true;
		queue<Subject> semester_subjects;
		while(prerequisites_concluded&&!subjects_order.empty()){
			auto subject = subjects_order.top();
			cout << subject.name << endl;
			for(auto prerequisite : subject.prerequisites){
				cout << "Analisando prerequisitos\n";
				if(concluded_subjects.count(*prerequisite) == 0){
					prerequisites_concluded = false;
				}
			}
			if(prerequisites_concluded){
				if(concluded_subjects.count(subject)==0){
					semester_subjects.push(subject);
				}
				subjects_order.pop();
			}
		}
		cout << semester << "º semester: ";
		while(!semester_subjects.empty()){
			auto subject = semester_subjects.front();
			cout << subject.name << " ";
			concluded_subjects.insert(subject);
			semester_subjects.pop();
		}
		cout << endl;
	}
}