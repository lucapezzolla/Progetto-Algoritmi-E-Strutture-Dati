#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include<iostream>
#include <vector>
#include "Node.h"

class Graph {
    private:
        vector<Node *> *g;
        void DFS_visit(Node *u);

public:
    Graph(){g = new vector<Node *>;}
    void addNode(Node *w){g->push_back(w);}
    Node *getNode(int v){return g->at(v);}
    void printAdj();
    void DFS(Node *s);
};


void Graph::DFS_visit(Node *u) {
    u->setColor(1);
    for(auto v : *u->getAdj()) {
        if(v->getColor() == 2)
        v->setP(u);
        if(v->getColor() == 0) {
        v->setP(u);
        DFS_visit(v);
    }
}
    u->setColor(2);
}


void Graph::DFS(Node *s) {
    s->setColor(1);
    for(auto v : *s->getAdj()) {
       if(v->getColor() == 2)   //arco trasversale
        v->setP(s);
        if(v->getColor() == 0) {
        v->setP(s);
        DFS_visit(v);
    }
    }
    s->setColor(2);
}


void Graph::printAdj(){
    for(auto v:*g){
        cout<<"Adj("<<v->getInfo()<<"):";
        for(auto vv:*v->getAdj())
            cout<<" "<<vv->getInfo();
        cout<<endl;
    }
}


#endif // GRAPH_H_INCLUDED
