#include "graphs.hpp"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    Subject *eps, *tppe, *ts, *mds, *oo, *apc, *comp, *ed1;
    eps = new Subject("EPS", 12345, 4);
    tppe = new Subject("TPPE", 12345, 4);
    ts = new Subject("TS", 12345, 4);
    mds = new Subject("MDS", 12345, 4);
    oo = new Subject("OO", 12345, 4);
    apc = new Subject("APC", 12345, 4);
    comp = new Subject("COMP", 12345, 4);
    ed1 = new Subject("ED1", 12345, 4);
    eps->insert_prerequisite(tppe);
    tppe->insert_prerequisite(ts);
    ts->insert_prerequisite(mds);
    mds->insert_prerequisite(oo);
    oo->insert_prerequisite(apc);
    comp->insert_prerequisite(ed1);
    ed1->insert_prerequisite(apc);
    set<Subject> materias;
    materias.insert(*eps);
    materias.insert(*tppe);
    materias.insert(*ts);
    materias.insert(*mds);
    materias.insert(*oo);
    materias.insert(*apc);
    materias.insert(*comp);
    materias.insert(*ed1);
    for(auto p: materias){
        p.show_subject();
        cout<<"pre-requisites:"<<endl;
        p.show_prerequisites();
        cout<<"--------------------"<<endl;
    }
    return 0;
}