#include "graphs.hpp"
#include <iostream>
using namespace std;
int main(){
    Graph *opa, *other;
    opa = new Graph("eda", 12345, 4);
    other = new Graph("c3", 54321, 6);
    opa->Insert_Edge(other);
    opa->Show();
    cout<< opa->code <<endl;
    cout<< opa->credits <<endl;
    return 0;
}