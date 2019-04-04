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
    public LinkedList<Subject> prerequisite_names = null;
    /*LinkedList<Subject> bfs_changed(Subject desired_subject){
        LinkedList<Subject> visited_subjects = new LinkedList<>();
        LinkedList<Subject> subjects_order = new LinkedList<>();
        LinkedList<Subject> to_visit = new LinkedList<>();
        String[] bfs_prerequisites = null;
        bfs_prerequisites[0]= desired_subject.name;
        int i = 1;
        to_visit.addLast(desired_subject);
        visited_subjects.addLast(desired_subject);
        subjects_order.addLast(desired_subject);
        Toast t = null;
        while(!to_visit.isEmpty()){
            Subject subject = to_visit.getFirst();
            to_visit.removeFirst();
            for (Subject prerequisite :subject.prerequisites) {
                if(visited_subjects.contains(prerequisite) != true){
                    visited_subjects.addLast(prerequisite);
                    to_visit.addLast(prerequisite);
                    subjects_order.addLast(prerequisite);
                    bfs_prerequisites[i] = prerequisite.name;
                    i++;

                    t.setText(i);

                }
            }
            t.show();
        }
        return subjects_order;
    }*/
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

    public String[] get_names_array(){
        int i;
        String[] names = null;
        for(i = 0; i < prerequisite_names.size(); i++){
            names[0] = prerequisite_names.get(i).name;
        }

        return names;
    }

    LinkedList<Subject> showSchedule(LinkedList<Subject> subjects_order, LinkedList<Subject> concluded_subjects) {
        boolean prerequisites_concluded = true;
        LinkedList<Subject> semester_subjects = new LinkedList<Subject>();
        while ((prerequisites_concluded == true) && (subjects_order.size() > 0)) {
            Subject subject = subjects_order.getFirst();
            if(subject.quantity_prerequisites>0) {
                for (Subject p: subject.prerequisites){


                    if (concluded_subjects.contains(p) == false) {
                        prerequisites_concluded = false;
                    }
                }
            }
            if (prerequisites_concluded) {
                if (concluded_subjects.contains(subject) == false) {
                    semester_subjects.addLast(subject);
                }
                subjects_order.removeFirst();
            }
        }
        return semester_subjects;

    }

}
