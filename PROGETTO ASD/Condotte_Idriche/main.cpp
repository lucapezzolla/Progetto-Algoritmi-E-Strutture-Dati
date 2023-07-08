#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Graph.h"

using namespace std;

int main()
{

    ifstream file("Condotte.txt");
    int dim, edge, n1, n2;
    string s;

    if(!file.fail())
    file >> dim;        //numero di nodi da allocare
    file >> edge;       //numero di archi da aggiungere

    Graph G;
    for(int i = 0; i <= dim; i++) {
        G.addNode(new Node(i));
    }

    while(getline(file,s)) {
        file>>n1;
        file>>n2;
        if(n1 <= dim && n2 <= dim && edge > 0)
        G.getNode(n1)->addEdge(G.getNode(n2));
        edge--;
    }

    file.close();


    for(int i = 0; i <= dim; i++) {
        if(G.getNode(i)->getColor() == 0)
        G.DFS(G.getNode(i));
    }

    int cont = 0;
    cout<<"LA SOLUZIONE DEL PROBLEMA DELLE CONDOTTE IDRICHE E' LA SEGUENTE :"<<endl;

    for(int i = 1; i <= dim; i++) {
        if(G.getNode(i)->getP() == nullptr || G.getNode(i)->getP()->getInfo() == G.getNode(i)->getInfo()){
            G.getNode(0)->addEdge(G.getNode(i));
       cout<<G.getNode(0)->getInfo()<<" "<<G.getNode(i)->getInfo()<<endl;
       cont++;
    }
}


   cout<<"IL MINIMO NUMERO DI CONDOTTE IDRICHE DA COSTRUIRE E' "<<cont;



    return 0;
}
