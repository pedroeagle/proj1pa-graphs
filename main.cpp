#include "graphs.hpp"
#include "functions.hpp"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    
    Subject *rs, *pi2, *eps, *tppe, *ts, *mds, *oo, *apc, *comp, *ed1, *pp, *ads, *gces, *fse, *fso, *fac, *ted_ped, *ial, *pspd, *ed2, *frc, *sbd2, *sbd1, *md2, *md1, *pa, *qs, *gpq, *ee, *ihc, *diac, *hc, *mne, *c2, *c1, *f1, *f1e, *peae, *ea, *ie, *pi1;
    set<Subject> materias;
    //cadastro de matérias
    pi2 = new Subject("Projeto Integrador 2", 208175, 6);
    eps = new Subject("Engenharia de Produto de Software", 203874, 4);
    tppe = new Subject("Técnicas de Programação em Plataformas Emergentes", 206601, 4);
    ts = new Subject("Testes de Software", 206580, 4);
    mds = new Subject("Métodos de Desenvolvimento de Software", 193640, 4);
    oo = new Subject("Orientação a Objetos", 195341, 4);
    apc = new Subject("Algorítmos e Programação de Computadores", 12345, 4);
    comp = new Subject("Compiladores 1", 101095, 4);
    ed1 = new Subject("Estrutura de Dados 1", 193704, 4);
    pp = new Subject("Paradigmas de Programação", 203904, 4);
    ads = new Subject("Arquitetura e Desenho de Software", 203882, 4);
    gces = new Subject("Gerência de configuração e evolução de software", 206598, 4);    
    fse = new Subject("Fundamentos de Sistemas Embarcados", 127701, 4);
    fso = new Subject("Fundamentos de Sistemas Operacionais", 201286, 4);
    fac = new Subject("Fundamentos e Arquitetura de Computadores", 193674, 4);
    ted_ped = new Subject("Teoria e Prática de Eletrônica Digital 1", 119482, 6);
    ial = new Subject("Introdução a Álgebra Linear", 113093, 4);
    pspd = new Subject("Programação para Sistemas Paralelos e Distribuídos", 206610, 4);
    ed2 = new Subject("Estrutura de Dados 2", 103209, 4);
    frc = new Subject("Fundamentos de Redes de Computadores", 203912, 4);
    sbd2 = new Subject("Sistemas de Banco de Dados 2", 115576, 4);
    sbd1 = new Subject("Sistemas de Banco de Dados 1", 193631, 4);
    md2 = new Subject("Matemática Discreta 2", 127698, 4);
    md1 = new Subject("Matemática Discreta 1", 120669, 4);
    pa = new Subject("Projeto de Algorítmos", 130508, 4);
    qs = new Subject("Qualidade de Software", 208698, 4);
    gpq = new Subject("Gestão da Produção e Qualidade", 201626, 4);
    ee = new Subject("Engenharia Econômica", 193321, 4);
    ihc = new Subject("Interação Humano Computador", 201316, 4);
    diac = new Subject("Desenho Industrial Assistido por computador", 199176, 6);
    hc = new Subject("Humanidades e Cidadania", 199133, 4);
    mne = new Subject("Métodos Númericos para Engenharia", 195413, 4);
    c2 = new Subject("Cálculo 2", 113042, 6);
    c1 = new Subject("Cálculo 1", 113034, 6);
    f1 = new Subject("Física 1", 118001, 4);
    f1e = new Subject("Física 1 Experimental", 118010, 2);
    peae = new Subject("Probabilidade e Estatística Aplicada à Engenharia", 195332, 4);
    ea = new Subject("Engenharia e Ambiente", 198005, 4);
    ie = new Subject("Introdução a Engenharia", 198013, 2);
    pi1 = new Subject("Projeto Integrador de Engenharia 1", 193861, 4);
    rs = new Subject("Requisitos de Software", 201308, 4);   

    //inserção de pré-requisitos
    pi2->insert_prerequisite(eps);
    eps->insert_prerequisite(tppe);
    gces->insert_prerequisite(ts);
    tppe->insert_prerequisite(ts);
    tppe->insert_prerequisite(ads);
    pp->insert_prerequisite(comp);
    pp->insert_prerequisite(oo);
    fse->insert_prerequisite(fso);
    pspd->insert_prerequisite(frc);
    qs->insert_prerequisite(ihc);
    qs->insert_prerequisite(gpq);
    ts->insert_prerequisite(mds);
    ads->insert_prerequisite(rs);
    frc->insert_prerequisite(fso);
    sbd2->insert_prerequisite(sbd1);
    pa->insert_prerequisite(ed1);
    pa->insert_prerequisite(c1);
    ihc->insert_prerequisite(mds);
    ihc->insert_prerequisite(diac);
    rs->insert_prerequisite(mds);
    sbd1->insert_prerequisite(md2);
    fso->insert_prerequisite(fac);
    comp->insert_prerequisite(ed1);
    ed2->insert_prerequisite(ed1);
    gpq->insert_prerequisite(ee);
    mds->insert_prerequisite(oo);
    ed1->insert_prerequisite(apc);
    fac->insert_prerequisite(ted_ped);
    md2->insert_prerequisite(md1);
    pi1->insert_prerequisite(oo);
    mne->insert_prerequisite(c2);
    ted_ped->insert_prerequisite(ial);
    oo->insert_prerequisite(apc);
    c2->insert_prerequisite(c1);
    peae->insert_prerequisite(c1);    
    
    //Contagem de pré requisitos
    pi2->count_prerequisites(*pi2);
    eps->count_prerequisites(*eps);
    tppe->count_prerequisites(*tppe);
    ts->count_prerequisites(*ts);
    mds->count_prerequisites(*mds);
    oo->count_prerequisites(*oo);
    apc->count_prerequisites(*apc);
    comp->count_prerequisites(*comp);
    ed1->count_prerequisites(*ed1);
    pp->count_prerequisites(*pp);
    ads->count_prerequisites(*ads);
    gces->count_prerequisites(*gces);
    fse->count_prerequisites(*fse);
    fso->count_prerequisites(*fso);
    fac->count_prerequisites(*fac);
    ted_ped->count_prerequisites(*ted_ped);
    ial->count_prerequisites(*ial);
    pspd->count_prerequisites(*pspd);
    ed2->count_prerequisites(*ed2);
    frc->count_prerequisites(*frc);
    sbd2->count_prerequisites(*sbd2);
    sbd1->count_prerequisites(*sbd1);
    md2->count_prerequisites(*md2);
    md1->count_prerequisites(*md1);
    pa->count_prerequisites(*pa);
    qs->count_prerequisites(*qs);
    gpq->count_prerequisites(*gpq);
    ee->count_prerequisites(*ee);
    ihc->count_prerequisites(*ihc);
    diac->count_prerequisites(*diac);
    hc->count_prerequisites(*hc);
    mne->count_prerequisites(*mne);
    c2->count_prerequisites(*c2);
    c1->count_prerequisites(*c1);
    f1->count_prerequisites(*f1);
    f1e->count_prerequisites(*f1e);
    peae->count_prerequisites(*peae);
    ea->count_prerequisites(*ea);
    ie->count_prerequisites(*ie);
    pi1->count_prerequisites(*pi1);
    rs->count_prerequisites(*rs);

    materias.insert(*pi2);
    materias.insert(*eps);
    materias.insert(*tppe);
    materias.insert(*ts);
    materias.insert(*mds);
    materias.insert(*oo);
    materias.insert(*apc);
    materias.insert(*comp);
    materias.insert(*ed1);
    materias.insert(*pp);
    materias.insert(*ads);
    materias.insert(*gces);
    materias.insert(*fse);
    materias.insert(*fso);
    materias.insert(*fac);
    materias.insert(*ted_ped);
    materias.insert(*ial);
    materias.insert(*pspd);
    materias.insert(*ed2);
    materias.insert(*frc);
    materias.insert(*sbd2);
    materias.insert(*sbd1);
    materias.insert(*md2);
    materias.insert(*md1);
    materias.insert(*pa);
    materias.insert(*qs);
    materias.insert(*gpq);
    materias.insert(*ee);
    materias.insert(*ihc);
    materias.insert(*diac);
    materias.insert(*hc);
    materias.insert(*mne);
    materias.insert(*c2);
    materias.insert(*c1);
    materias.insert(*f1);
    materias.insert(*f1e);
    materias.insert(*peae);
    materias.insert(*ea);
    materias.insert(*ie);
    materias.insert(*pi1);
    materias.insert(*rs);

    

    for(auto p: materias){
        p.show_subject();
        cout << "quantity_prerequisites: " << p.quantity_prerequisites << endl;
        cout<<"pre-requisites:"<<endl;
        p.show_prerequisites();
        cout<<"--------------------"<<endl;
    } 
  
    priority_queue<Subject> subject_order = bfs_changed(*eps);
    show_schedule(subject_order);
  
    return 0;
}