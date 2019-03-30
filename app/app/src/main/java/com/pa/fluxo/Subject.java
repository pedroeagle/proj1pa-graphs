package com.pa.fluxo;

import android.util.Log;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.Comparator;
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
    public ArrayList<Subject> prerequisites = new ArrayList<Subject>();
    TextView text;


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

        for(Iterator it = prerequisites.iterator(); it.hasNext();it.next()){
            Subject element = new Subject();
            element = (com.pa.fluxo.Subject) it.next();
            element.show_subject();
        }
    }

    ArrayList<String> show_subject(){
        ArrayList<String> s = new ArrayList<>();
        s.add("Name: "+name );
        s.add("Code: "+ code);
        s.add("Credits: " + credits);
        return s;
    }



    /*
    bool Subject::operator<(const Subject &subject) const{
        if(quantity_prerequisites==subject.quantity_prerequisites){
            return name < subject.name;
        }
        return quantity_prerequisites > subject.quantity_prerequisites;
    }*/
}