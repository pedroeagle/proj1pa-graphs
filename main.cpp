#include "graphs.hpp"
#include <iostream>
using namespace std;
int main(){
    Subject *opa, *other, *mais_um;
    opa = new Subject("eda", 12345, 4);
    other = new Subject("c3", 54321, 6);
    mais_um = new Subject("c2", 12312, 6);
    opa->insert_prerequisite(other);
    opa->insert_prerequisite(mais_um);
    opa->show_prerequisites();
    opa->show_subject();
    return 0;
}