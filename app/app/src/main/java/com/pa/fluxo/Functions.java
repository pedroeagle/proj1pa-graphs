package com.pa.fluxo;

import android.util.Log;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;
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
                }
            }
        }
        return subjects_order;
    }
    ArrayList<Subject> sort (ArrayList<Subject> s){
        int i, j;
        for(i = 0; i < s.size(); i++){
            for(j = 0; j < s.size(); j++){
                if(s.get(i).name.compareTo(s.get(j).name) < 0){
                    Collections.swap(s, i, j);
                }
            }
        }
        return s;
    }
    LinkedList<Subject> sortLinked(LinkedList<Subject> s){
        int i, j;
        for(i = 0; i < s.size(); i++){
            for(j = 0; j < s.size(); j++){
                if(s.get(i).quantity_prerequisites > s.get(j).quantity_prerequisites){
                    Collections.swap(s, i, j);
                }
            }
        }
        return s;
    }

    LinkedList<Integer> semesterSeparator(LinkedList<Subject> subjects_order) {
        LinkedList<Subject> concluded_subjects = new LinkedList<Subject>();
        LinkedList<Integer> semester_number = new LinkedList<Integer>();
        LinkedList<Subject> semester_subject = new LinkedList<Subject>();
        LinkedList<Subject> new_list = new LinkedList<>();
        new_list = (LinkedList) subjects_order.clone();
        for (int semester = 1; new_list.size() > 0; semester++){
            boolean prerequisites_concluded = true;
            while ((prerequisites_concluded == true) && (new_list.size() > 0)) {
                Subject subject = new_list.getLast();
                if (subject.quantity_prerequisites > 0) {
                    for (Subject p : subject.prerequisites) {
                        if (concluded_subjects.contains(p) == false) {
                            prerequisites_concluded = false;
                        }
                    }
                }
                if (prerequisites_concluded) {
                    if (concluded_subjects.contains(subject) == false) {
                        semester_number.addLast(semester);
                        semester_subject.addLast(subject);
                    }
                    new_list.removeLast();
                }
            }
            while(semester_subject.size()>0){
                concluded_subjects.add(semester_subject.getLast());
                semester_subject.removeLast();
            }
        }
        return semester_number;

    }
}
