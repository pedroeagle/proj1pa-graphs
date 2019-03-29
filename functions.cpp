#include "graphs.hpp"
#include "functions.hpp"
#include <bits/stdc++.h>

using namespace std;

priority_queue<Subject> bfs_changed(Subject desired_subject){
	set<Subject> visited_subjects;
	priority_queue<Subject> subjects_order;
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
		}
	}

	return subjects_order;
}

void show_schedule(priority_queue<Subject> subjects_order, priority_queue<Subject> *subjets_to_do, int max_subjects){
	set<Subject> concluded_subjects;
	for(int semester = 1; !subjects_order.empty(); semester++){
		bool prerequisites_concluded = true;
		queue<Subject> semester_subjects;
		while(prerequisites_concluded&&!subjects_order.empty()){
			auto subject = subjects_order.top();
			for(auto prerequisite : subject.prerequisites){
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

		semester_subjects = complete_schedule(semester_subjects, subjets_to_do, &concluded_subjects, max_subjects);

		cout << semester << "º semester:\n";
		while(!semester_subjects.empty()){
			auto subject = semester_subjects.front();
			cout << subject.name << endl;
			concluded_subjects.insert(subject);
			semester_subjects.pop();
		}
		cout << endl;
	}
}

queue<Subject> complete_schedule(queue<Subject> semester_subjects, priority_queue<Subject> *subjets_to_do, set<Subject> *concluded_subjects, int max_subjects){
	bool prerequisites_concluded = true;
	while(int(semester_subjects.size())!=max_subjects&&!subjets_to_do->empty()&&prerequisites_concluded){
		auto subject = subjets_to_do->top();
		for(auto prerequisite : subject.prerequisites){
			if(concluded_subjects->count(*prerequisite) == 0){
				prerequisites_concluded = false;
			}
		}
		if(prerequisites_concluded){
			if(concluded_subjects->count(subject)==0){
				semester_subjects.push(subject);
			}
			subjets_to_do->pop();
		}
	}

	return semester_subjects;
}