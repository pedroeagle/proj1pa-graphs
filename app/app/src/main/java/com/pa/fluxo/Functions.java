package com.pa.fluxo;

import android.widget.Toast;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

public class Functions {
    Functions(){

    }
    public List<String> prerequisite_names = null;
    LinkedList<Subject> bfs_changed(Subject desired_subject){
        LinkedList<Subject> visited_subjects = new LinkedList<>();
        LinkedList<Subject> subjects_order = new LinkedList<>();
        LinkedList<Subject> to_visit = new LinkedList<>();

        to_visit.addLast(desired_subject);
        visited_subjects.addLast(desired_subject);
        subjects_order.addLast(desired_subject);

        while(!to_visit.isEmpty()){
            Subject subject = to_visit.getFirst();
            to_visit.removeFirst();
            for (Subject prerequisite :subject.prerequisites) {
                if(!visited_subjects.contains(prerequisite)){
                    visited_subjects.addLast(prerequisite);
                    to_visit.addLast(prerequisite);
                    subjects_order.addLast(prerequisite);
                    prerequisite_names.add(prerequisite.name);
                }
            }
        }
        return subjects_order;
    }
    ArrayList<Subject> sort (ArrayList<Subject> s){
        int i, j;
        for(i = 0; i!= s.size(); i++){
            for(j = 0; j < s.size(); j++){
                if(s.get(i).name.compareTo(s.get(j).name) < 0){
                    Collections.swap(s, i, j);
                }
            }
        }
        return s;
    }

    public String[] get_names_array(){
        int i;
        String[] names = null;
        for(i = 0; i < prerequisite_names.size(); i++){
            names[0] = prerequisite_names.get(i);
        }

        return names;
    }

    /*void show_schedule(priority_queue<Subject> subjects_order){
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
            cout << semester << "º semester: ";
            while(!semester_subjects.empty()){
                auto subject = semester_subjects.front();
                cout << subject.name << " | ";
                concluded_subjects.insert(subject);
                semester_subjects.pop();
            }
            cout << endl;
        }
    }*/
}
