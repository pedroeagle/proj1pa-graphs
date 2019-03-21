#include "graphs.hpp"
#include "functions.hpp"
#include <iostream>
using namespace std;
int main(){
    Subject *opa, *other, *mais_um, *outra_aqui;
    opa = new Subject("eda", 12345, 4);
    other = new Subject("oo", 54321, 6);
    mais_um = new Subject("c2", 12312, 6);
    outra_aqui = new Subject("c1", 12312, 6);
    mais_um->insert_prerequisite(outra_aqui);
    opa->insert_prerequisite(other);
    opa->insert_prerequisite(mais_um);
    
    opa->show_prerequisites();
    opa->show_subject();
    cout << "-----------\n";
    mais_um->show_prerequisites();

    stack<Subject> mds = bfs_changed(*opa);
    cout << "Size: " << mds.size() << endl;
 /*   while(!mds.empty()){
    	cout << mds.top().name << endl;
    	mds.pop();
    }
*/	
    show_schedule(mds);
    return 0;
}