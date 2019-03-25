#include "graphs.hpp"
#include "functions.hpp"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    
    Subject *pi2, *eps, *tppe, *ts, *mds, *oo, *apc, *comp, *ed1, *pp, *ads, *gces, *fse, *fso, *fac, *ted_ped, *ial, *pspd, *ed2, *frc, *sbd2, *sbd1, *md2, *md1, *pa, *qs, *gpq, *ee, *ihc, *diac, *hc, *mne, *c2, *c1, *f1, *f1e, *peae, *ea, *ie, *pi1;
    set<Subject> materias;
    //cadastro de matérias
    pi2 = new Subject("Projeto Integrador 2", 208175, 6);
    materias.insert(*pi2);

    eps = new Subject("Engenharia de Produto de Software", 203874, 4);
    materias.insert(*eps);

    tppe = new Subject("Técnicas de Programação em Plataformas Emergentes", 206601, 4);
    materias.insert(*tppe);

    ts = new Subject("Testes de Software", 206580, 4);
    materias.insert(*ts);

    mds = new Subject("Métodos de Desenvolvimento de Software", 193640, 4);
    materias.insert(*mds);

    oo = new Subject("Orientação a Objetos", 195341, 4);
    materias.insert(*oo);

    apc = new Subject("Algorítmos e Programação de Computadores", 12345, 4);
    materias.insert(*apc);

    comp = new Subject("Compiladores 1", 101095, 4);
    materias.insert(*comp);

    ed1 = new Subject("Estrutura de Dados 1", 193704, 4);
    materias.insert(*ed1);

    pp = new Subject("Paradigmas de Programação", 203904, 4);
    materias.insert(*pp);

    ads = new Subject("Arquitetura e Desenho de Software", 203882, 4);
    materias.insert(*ads);

    gces = new Subject("Gerência de configuração e evolução de software", 206598, 4);
    materias.insert(*gces);
    
    fse = new Subject("Fundamentos de Sistemas Embarcados", 127701, 4);
    materias.insert(*fse);

    fso = new Subject("Fundamentos de Sistemas Operacionais", 201286, 4);
    materias.insert(*fso);

    fac = new Subject("Fundamentos e Arquitetura de Computadores", 193674, 4);
    materias.insert(*fac);

    ted_ped = new Subject("Teoria e Prática de Eletrônica Digital 1", 119482, 6);
    materias.insert(*ted_ped);

    ial = new Subject("Introdução a Álgebra Linear", 113093, 4);
    materias.insert(*ial);

    pspd = new Subject("Programação para Sistemas Paralelos e Distribuídos", 206610, 4);
    materias.insert(*pspd);

    ed2 = new Subject("Estrutura de Dados 2", 103209, 4);
    materias.insert(*ed2);

    frc = new Subject("Fundamentos de Redes de Computadores", 203912, 4);
    materias.insert(*frc);

    sbd2 = new Subject("Sistemas de Banco de Dados 2", 115576, 4);
    materias.insert(*sbd2);

    sbd1 = new Subject("Sistemas de Banco de Dados 1", 193631, 4);
    materias.insert(*sbd1);

    md2 = new Subject("Matemática Discreta 2", 127698, 4);
    materias.insert(*md2);

    md1 = new Subject("Matemática Discreta 1", 120669, 4);
    materias.insert(*md1);

    pa = new Subject("Projeto de Algorítmos", 130508, 4);
    materias.insert(*pa);

    qs = new Subject("Qualidade de Software", 208698, 4);
    materias.insert(*qs);

    gpq = new Subject("Gestão da Produção e Qualidade", 201626, 4);
    materias.insert(*gpq);

    ee = new Subject("Engenharia Econômica", 193321, 4);
    materias.insert(*ee);

    ihc = new Subject("Interação Humano Computador", 201316, 4);
    materias.insert(*ihc);

    diac = new Subject("Desenho Industrial Assistido por computador", 199176, 6);
    materias.insert(*diac);

    hc = new Subject("Humanidades e Cidadania", 199133, 4);
    materias.insert(*hc);

    mne = new Subject("Métodos Númericos para Engenharia", 195413, 4);
    materias.insert(*mne);

    c2 = new Subject("Cálculo 2", 113042, 6);
    materias.insert(*c2);

    c1 = new Subject("Cálculo 1", 113034, 6);
    materias.insert(*c1);

    f1 = new Subject("Física 1", 118001, 4);
    materias.insert(*f1);

    f1e = new Subject("Física 1 Experimental", 118010, 2);
    materias.insert(*f1e);

    peae = new Subject("Probabilidade e Estatística Aplicada à Engenharia", 195332, 4);
    materias.insert(*peae);

    ea = new Subject("Engenharia e Ambiente", 198005, 4);
    materias.insert(*ea);

    ie = new Subject("Introdução a Engenharia", 198013, 2);
    materias.insert(*ie);

    pi1 = new Subject("Projeto Integrador de Engenharia 1", 193861, 4);
    materias.insert(*pi1);


    
    //inserção de pré-requisitos
    pi2->insert_prerequisite(eps);
    eps->insert_prerequisite(tppe);
    tppe->insert_prerequisite(ts);
    tppe->insert_prerequisite(comp);
    ts->insert_prerequisite(mds);
    mds->insert_prerequisite(oo);
    oo->insert_prerequisite(apc);
    comp->insert_prerequisite(ed1);
    ed1->insert_prerequisite(apc);
    pp->insert_prerequisite(ads);
    pp->insert_prerequisite(oo);
    gces->insert_prerequisite(ts);
    
    
    for(auto p: materias){
        p.show_subject();
        cout<<"pre-requisites:"<<endl;
        p.show_prerequisites();
        cout<<"--------------------"<<endl;
    } 
    
    stack<Subject> subject_order = bfs_changed(*tppe);

    show_schedule(subject_order);
  
    return 0;
}