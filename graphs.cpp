#include <iostream>
#include "graphs.hpp"
Graph::Graph(){

}
Graph::Graph(char matter_name[20], int code, int credits){
    this->name = matter_name;
    this->code = code;
    this->credits = credits;
}
Graph::~Graph(){
    //tenho que passar por todas os galhos para verificar a presença da matéria removida
}
void Graph::Insert_Edge(Graph *matter){
    edges.push_back(*matter);
}
void Graph::Show(){
    cout<<edges.front().name<<endl;
}