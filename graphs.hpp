#ifndef GRAPHS_HPP
#define GRAPHS_HPP
#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    char *name;
    int code;
    int credits;
    int q_edges;
    vector <Graph> edges;
    Graph();
    Graph(char matter_name[20], int code, int credits);
    ~Graph();
    void Insert_Edge(Graph *matter = 0);
    void Remove_Edge(Graph *matter = 0);
    void Show();
};
#endif