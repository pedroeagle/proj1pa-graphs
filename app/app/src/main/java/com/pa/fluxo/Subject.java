package com.pa.fluxo;

import java.util.ArrayList;
import java.util.LinkedList;

public class Subject {
    public String name;
    int code;
    int credits;
    int quantity_prerequisites;
    public ArrayList<Subject> prerequisites = new ArrayList<Subject>();

    public Subject(String subject_name, int code, int credits){
        quantity_prerequisites = 0;
        this.name = subject_name;
        this.code = code;
        this.credits = credits;
    }
    public void addPrerequisite(Subject subject){
        if(subject!=null) {
            prerequisites.add(subject);
        }
    }

    void countPrerequisites(Subject subject){
        LinkedList<Subject> visited_subjects = new LinkedList<>();
        LinkedList<Subject> to_visit = new LinkedList<>();

        to_visit.addLast(subject);
        visited_subjects.addLast(subject);
        while(!to_visit.isEmpty()) {
            Subject s = to_visit.getFirst();
            to_visit.removeFirst();
            for (Subject prerequisite : s.prerequisites) {
                if (!visited_subjects.contains(prerequisite)) {
                    visited_subjects.addLast(prerequisite);
                    to_visit.addLast(prerequisite);
                }
            }
        }
        subject.quantity_prerequisites = visited_subjects.size()-1;
    }
}
