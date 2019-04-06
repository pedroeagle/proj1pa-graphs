package com.pa.fluxo;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.SimpleAdapter;
import android.widget.Spinner;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;

public class MainActivity extends AppCompatActivity {

    private Button button;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Main();

    }
    private void openWebPage() {
        Intent intent = new Intent(this, WebPage.class);
        startActivity(intent);
    }
    ArrayList<Subject> materias = new ArrayList<Subject>();
    Functions f = new Functions();

    //cadastro de matérias
    Subject pi2 = new Subject("Projeto Integrador 2", 208175, 6);
    Subject eps = new Subject("Engenharia de Produto de Software", 203874, 4);
    Subject tppe = new Subject("Técnicas de Programação em Plataformas Emergentes", 206601, 4);
    Subject ts = new Subject("Testes de Software", 206580, 4);
    Subject mds = new Subject("Métodos de Desenvolvimento de Software", 193640, 4);
    Subject oo = new Subject("Orientação a Objetos", 195341, 4);
    Subject apc = new Subject("Algorítmos e Programação de Computadores", 113476, 4);
    Subject comp = new Subject("Compiladores 1", 101095, 4);
    Subject ed1 = new Subject("Estrutura de Dados 1", 193704, 4);
    Subject pp = new Subject("Paradigmas de Programação", 203904, 4);
    Subject ads = new Subject("Arquitetura e Desenho de Software", 203882, 4);
    Subject gces = new Subject("Gerência de configuração e evolução de software", 206598, 4);
    Subject fse = new Subject("Fundamentos de Sistemas Embarcados", 127701, 4);
    Subject fso = new Subject("Fundamentos de Sistemas Operacionais", 201286, 4);
    Subject fac = new Subject("Fundamentos e Arquitetura de Computadores", 193674, 4);
    Subject ted_ped = new Subject("Teoria e Prática de Eletrônica Digital 1", 119482, 6);
    Subject ial = new Subject("Introdução a Álgebra Linear", 113093, 4);
    Subject pspd = new Subject("Programação para Sistemas Paralelos e Distribuídos", 206610, 4);
    Subject ed2 = new Subject("Estrutura de Dados 2", 103209, 4);
    Subject frc = new Subject("Fundamentos de Redes de Computadores", 203912, 4);
    Subject sbd2 = new Subject("Sistemas de Banco de Dados 2", 115576, 4);
    Subject sbd1 = new Subject("Sistemas de Banco de Dados 1", 193631, 4);
    Subject md2 = new Subject("Matemática Discreta 2", 127698, 4);
    Subject md1 = new Subject("Matemática Discreta 1", 120669, 4);
    Subject pa = new Subject("Projeto de Algorítmos", 130508, 4);
    Subject qs = new Subject("Qualidade de Software", 208698, 4);
    Subject gpq = new Subject("Gestão da Produção e Qualidade", 201626, 4);
    Subject ee = new Subject("Engenharia Econômica", 193321, 4);
    Subject ihc = new Subject("Interação Humano Computador", 201316, 4);
    Subject diac = new Subject("Desenho Industrial Assistido por computador", 199176, 6);
    Subject hc = new Subject("Humanidades e Cidadania", 199133, 4);
    Subject mne = new Subject("Métodos Númericos para Engenharia", 195413, 4);
    Subject c2 = new Subject("Cálculo 2", 113042, 6);
    Subject c1 = new Subject("Cálculo 1", 113034, 6);
    Subject f1 = new Subject("Física 1", 118001, 4);
    Subject f1e = new Subject("Física 1 Experimental", 118010, 2);
    Subject peae = new Subject("Probabilidade e Estatística Aplicada à Engenharia", 195332, 4);
    Subject ea = new Subject("Engenharia e Ambiente", 198005, 4);
    Subject ie = new Subject("Introdução a Engenharia", 198013, 2);
    Subject pi1 = new Subject("Projeto Integrador de Engenharia 1", 193861, 4);
    Subject rs = new Subject("Requisitos de Software", 201308, 4);

    protected void Main() {
        //inserção de pré-requisitos
        pi2.addPrerequisite(eps);
        eps.addPrerequisite(tppe);
        gces.addPrerequisite(ts);
        tppe.addPrerequisite(ts);
        tppe.addPrerequisite(ads);
        pp.addPrerequisite(comp);
        pp.addPrerequisite(oo);
        fse.addPrerequisite(fso);
        pspd.addPrerequisite(frc);
        qs.addPrerequisite(ihc);
        qs.addPrerequisite(gpq);
        ts.addPrerequisite(mds);
        ads.addPrerequisite(rs);
        frc.addPrerequisite(fso);
        sbd2.addPrerequisite(sbd1);
        pa.addPrerequisite(ed1);
        pa.addPrerequisite(c1);
        ihc.addPrerequisite(mds);
        ihc.addPrerequisite(diac);
        rs.addPrerequisite(mds);
        sbd1.addPrerequisite(md2);
        fso.addPrerequisite(fac);
        comp.addPrerequisite(ed1);
        ed2.addPrerequisite(ed1);
        gpq.addPrerequisite(ee);
        mds.addPrerequisite(oo);
        ed1.addPrerequisite(apc);
        fac.addPrerequisite(ted_ped);
        md2.addPrerequisite(md1);
        pi1.addPrerequisite(oo);
        mne.addPrerequisite(c2);
        ted_ped.addPrerequisite(ial);
        oo.addPrerequisite(apc);
        c2.addPrerequisite(c1);
        peae.addPrerequisite(c1);

        //Contagem de pré requisitos
        pi2.countPrerequisites(pi2);
        eps.countPrerequisites(eps);
        tppe.countPrerequisites(tppe);
        ts.countPrerequisites(ts);
        mds.countPrerequisites(mds);
        oo.countPrerequisites(oo);
        apc.countPrerequisites(apc);
        comp.countPrerequisites(comp);
        ed1.countPrerequisites(ed1);
        pp.countPrerequisites(pp);
        ads.countPrerequisites(ads);
        gces.countPrerequisites(gces);
        fse.countPrerequisites(fse);
        fso.countPrerequisites(fso);
        fac.countPrerequisites(fac);
        ted_ped.countPrerequisites(ted_ped);
        ial.countPrerequisites(ial);
        pspd.countPrerequisites(pspd);
        ed2.countPrerequisites(ed2);
        frc.countPrerequisites(frc);
        sbd2.countPrerequisites(sbd2);
        sbd1.countPrerequisites(sbd1);
        md2.countPrerequisites(md2);
        md1.countPrerequisites(md1);
        pa.countPrerequisites(pa);
        qs.countPrerequisites(qs);
        gpq.countPrerequisites(gpq);
        ee.countPrerequisites(ee);
        ihc.countPrerequisites(ihc);
        diac.countPrerequisites(diac);
        hc.countPrerequisites(hc);
        mne.countPrerequisites(mne);
        c2.countPrerequisites(c2);
        c1.countPrerequisites(c1);
        f1.countPrerequisites(f1);
        f1e.countPrerequisites(f1e);
        peae.countPrerequisites(peae);
        ea.countPrerequisites(ea);
        ie.countPrerequisites(ie);
        pi1.countPrerequisites(pi1);
        rs.countPrerequisites(rs);

        materias.add(pi2);
        materias.add(eps);
        materias.add(tppe);
        materias.add(ts);
        materias.add(mds);
        materias.add(oo);
        materias.add(apc);
        materias.add(comp);
        materias.add(ed1);
        materias.add(pp);
        materias.add(ads);
        materias.add(gces);
        materias.add(fse);
        materias.add(fso);
        materias.add(fac);
        materias.add(ted_ped);
        materias.add(ial);
        materias.add(pspd);
        materias.add(ed2);
        materias.add(frc);
        materias.add(sbd2);
        materias.add(sbd1);
        materias.add(md2);
        materias.add(md1);
        materias.add(pa);
        materias.add(qs);
        materias.add(gpq);
        materias.add(ee);
        materias.add(ihc);
        materias.add(diac);
        materias.add(hc);
        materias.add(mne);
        materias.add(c2);
        materias.add(c1);
        materias.add(f1);
        materias.add(f1e);
        materias.add(peae);
        materias.add(ea);
        materias.add(ie);
        materias.add(pi1);
        materias.add(rs);
        materias = f.Sort(materias);

        //prepara os dados a serem mostrados no spinner
        ArrayList<String> names = new ArrayList<String>();
        int i;
        for(i = 0; i < materias.size(); i++){
            names.add(materias.get(i).name);
        }

        final ArrayAdapter<String> dataAdapter = new ArrayAdapter<String>(this,
                android.R.layout.simple_spinner_item, names);
        dataAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);


        final Spinner select_subject = (Spinner) findViewById(R.id.my_spinner);
        select_subject.setAdapter(dataAdapter);

        Button button = (Button) findViewById(R.id.make_flow);
        button.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                showList(getSubject(select_subject.getSelectedItem().toString()));
            }
        });
    }

    private void showList(Subject subject) {

        final LinkedList<Subject> s = f.sortLinked(f.BfsChanged(getSubject(subject.name)));
        LinkedList<Integer> semesterOrder = f.semesterSeparator(s);
        final ArrayList<HashMap<String, String>> data;
        data = new ArrayList<HashMap<String, String>>();
        //final String[] prerequisites = new String[s.size()];
        int i;
        for(i = 0; i < s.size(); i++){
            HashMap<String,String> aux = new HashMap<String, String>();
            aux.put("Subject", s.get(s.size()-i-1).name);
            aux.put("Semester", semesterOrder.get(i).toString()+"º semestre");
            data.add(aux);
        }
        final ListView list =  (ListView) findViewById(R.id.listView);
        //ArrayAdapter<String> flow_array = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, prerequisites);
        SimpleAdapter flow_array = new SimpleAdapter(this, data, android.R.layout.simple_list_item_2, new String[] {"Subject", "Semester"}, new int[]{android.R.id.text1, android.R.id.text2});
        list.setAdapter(flow_array);


        list.setOnItemClickListener(new AdapterView.OnItemClickListener() {

            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                showWebPage(getId(s.get(s.size()-position-1).name));
            }
        });

    }

    private void showWebPage(int code) {
        WebPage.code = code;
        openWebPage();
    }

    Subject getSubject(String name){
        Subject found = null;
        for(Subject i: materias){
            if(i.name.compareTo(name) == 0){
                found = i;
            }
        }
        return found;
    }

    int getId(String name){
        int found = 0;
        for(Subject i: materias){
            if(i.name.compareTo(name) == 0){
                found = i.code;
                break;
            }
        }
        return found;
    }
}
