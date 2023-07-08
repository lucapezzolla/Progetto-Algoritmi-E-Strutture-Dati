#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <iostream>
#include <list>

using namespace std;


class Node {
    private:
        int color;
        int info;
        Node *p;
        int d;
        int f;
        list<Node *> *adj;
    public:
        Node(int info) {this->info=info;color=0;p=nullptr;d=0;f=0;adj=new list<Node *>;}
        void AddEdge(Node *w) {adj->push_back(w);}
        list <Node *> *getAdj() {return adj;}
        int getInfo() {return info;}
        void setColor(int color) {this->color=color;}
        int getColor() {return color;}
        void setD(int d) {this->d=d;}
        int getD() {return d;}
        void setF(int f) {this->f=f;}
        int getF() {return f;}
        void setP(Node *p) {this->p=p;}
        Node* getP() {return p;}
};





#endif // GRAPH_H_INCLUDED
