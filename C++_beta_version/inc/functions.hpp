#ifndef FUNCOES_HPP
#define FUNCOES_HPP

priority_queue<Subject> bfs_changed(Subject desired_subject);
void show_schedule(priority_queue<Subject> subjects_order, priority_queue<Subject> *subjets_to_do, int max_subjects);
queue<Subject> complete_schedule(queue<Subject> semester_subjects, priority_queue<Subject> *subjets_to_do, set<Subject> *concluded_subjects, int max_subjects);

#endif