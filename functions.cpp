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
		cerr << "Entrou no while\n";
		auto subject = to_visit.front();
		to_visit.pop();
		cout << "Subject: " << subject.name << endl;
		subject.show_prerequisites();
		for(auto prerequisite : subject.prerequisites){
			cerr << "Entrou no for auto\n";
			cerr << "Prerequisite: " << prerequisite.name << endl;
			if(visited_subjects.count(prerequisite) == 0){
				cerr << "Entrou no if\n";
				visited_subjects.insert(prerequisite);
				to_visit.push(prerequisite);
				subjects_order.push(prerequisite);
			}
		}
	}

	return subjects_order;
}

void show_schedule(stack<Subject> subjects_order){
	set<Subject> concluded_subjects;
	for(int semester = 1; !subjects_order.empty(); semester++){
		bool prerequisites_concluded = true;
		while(prerequisites_concluded){
			auto subject = subjects_order.top();
			for(auto prerequisite : subject.prerequisites){
				if(concluded_subjects.count(prerequisite) == 0){
					prerequisites_concluded = false;
				}
			}

			if(prerequisites_concluded){
				cout << semester << "º semester: " << subject.name << " ";
				concluded_subjects.insert(subject);
				subjects_order.pop();
			}
		}
		cout << endl;
	}
}