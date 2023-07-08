#ifndef HASHGRAPH_H_INCLUDED
#define HASHGRAPH_H_INCLUDED
#include <iostream>
#include "HashTable.h"
#include "Node.h"
#include <vector>

using namespace std;

class HashGraph {
    private:
        int dim;
        vector<Node> vn; //vector contenente i nodi del grafo
        HashTable *hg;
    public:
        HashGraph(int dim, vector<Node> vn);
        void AddEdge(Node *i, Node *j);
        void RemoveEdge(Node *i, Node *j);
        bool FindEdge(Node *i, Node *j);
        void DFS(Node *s);
};

HashGraph::HashGraph(int dim, vector<Node> vn) {
    for(int i = 0; i < dim; i++)
        hg = new HashTable(dim);
    this->vn = vn;
    for(int j = 0; j < (int)vn.size(); j++)
        hg->hashInsert(vn.at(j),vn.at(j).getInfo());
}


int time = 0;
void DFS_visit(Node *u) {
    u->setColor(1);
    u->setD(time+=1);
    for(auto v : *u->getAdj()) {
        if(v->getColor() == 0) {
        cout<<v->getInfo()<<" ";
        v->setP(u);
        DFS_visit(v);
        }
    }
    u->setColor(2);
    u->setF(time+=1);
}


void HashGraph::AddEdge(Node *i, Node *j) {
     bool first = hg->hashSearch(i->getInfo());
     bool second = hg->hashSearch(j->getInfo());
     if(first && second == true)
        this->vn.at(i->getInfo()).getAdj()->push_back(j);
}



void HashGraph::RemoveEdge(Node *i, Node *j) {
     bool first = hg->hashSearch(i->getInfo());
     bool second = hg->hashSearch(j->getInfo());
     if(first && second == true)
        this->vn.at(i->getInfo()).getAdj()->remove(j);
}


bool HashGraph::FindEdge(Node *i, Node *j) {
    bool first = hg->hashSearch(i->getInfo());
    bool second = hg->hashSearch(j->getInfo());
    if(first && second == true)
    for(auto v : *i->getAdj()) {
        if(v == j)
            return true;
        }
    return false;
}


void HashGraph::DFS(Node *s) {
    if(hg->hashSearch(s->getInfo()) == true)   //controllo che il nodo sorgente sia effettivamente presente nell'HashGraph
    s->setColor(1);
    s->setD(time);
    for(auto v : *s->getAdj()) {
        if(v->getColor() == 0) {
            cout<<v->getInfo()<<" ";
            v->setP(s);
           DFS_visit(v);
        }
        }
    s->setColor(2);;
    s->setF(time+=1);
}






#endif // HASHGRAPH_H_INCLUDED
