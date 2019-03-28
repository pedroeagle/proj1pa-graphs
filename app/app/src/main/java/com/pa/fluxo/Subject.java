package com.pa.fluxo;

import android.util.Log;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Vector;

import static java.sql.DriverManager.println;

public class Subject {
    public String name;
    int code;
    int credits;
    int quantity_prerequisites;
    HashSet<Subject> prerequisites = new HashSet<Subject>();

    public Subject() {

    }

    void Subject(){

    }
    public Subject(String subject_name, int code, int credits){
        quantity_prerequisites = 0;
        this.name = subject_name;
        this.code = code;
        this.credits = credits;
    }
    public void add_prerequisite(Subject subject){
        if(subject!=null) {
            prerequisites.add(subject);
        }
    }

    void remove_prerequisite(Subject subject){
        if(subject!=null){
            if(prerequisites.size() !=0 ){
                prerequisites.remove(subject);
            }
        }
    }

    void show_prerequisites(){

        for(Iterator it = prerequisites.iterator(); it.hasNext();){
            Subject element = new Subject();
            element = (com.pa.fluxo.Subject) it.next();
            element.show_subject();
        }
    }

    void show_subject(){
        System.out.println("Name: " + name );
        System.out.println("Code: " + code );
        System.out.println("Credits: " + credits );
    }
    void count_prerequisites(Subject subject){
        HashSet<Subject> visited_subjects = new HashSet<Subject>();
        Vector<Subject> to_visit = new Vector<Subject>();
        to_visit.add(subject);
        visited_subjects.add(subject);
        while(to_visit.size()>0){
            Subject sub = to_visit.firstElement();
            to_visit.remove(0);

            for(Iterator it = prerequisites.iterator(); it.hasNext();){
                if(visited_subjects.isEmpty()){
                    visited_subjects.add((com.pa.fluxo.Subject) it.next());
                    to_visit.add((com.pa.fluxo.Subject) it.next());
                }
            }
        }
        quantity_prerequisites = visited_subjects.size()-1;
    }

    /*
    bool Subject::operator<(const Subject &subject) const{
        if(quantity_prerequisites==subject.quantity_prerequisites){
            return name < subject.name;
        }
        return quantity_prerequisites > subject.quantity_prerequisites;
    }*/
}
