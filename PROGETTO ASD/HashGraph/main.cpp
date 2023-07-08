#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "HashGraph.h"
#include "HashTable.h"
#include "Node.h"

using namespace std;


int main()
{

    ifstream file("Hashgraph.txt");
    int dim, edge, n1, n2;
    file >> dim;
    file >> edge;
    string s;
    vector<Node> vn;

    for(int i = 0; i < dim; i++)
        vn.push_back(Node(i));
    HashGraph hg(701,vn);

    while(getline(file,s)) {
        file >> n1;
        file >> n2;
    if(n1 < dim && n2 < dim && edge > 0)     //il nodo letto deve essere stato effettivamente allocato, altrimenti l'arco non verrà inserito
    hg.AddEdge(&vn.at(n1),&vn.at(n2));
    edge--;
}

    file.close();



cout<<"BENVENUTO NEL MENU HASHGRAPH, LE OPERAZIONI TRA CUI PUO' SCEGLIERE SONO :"<<endl;
cout<<"1) PER AGGIUNGERE UN ARCO TRA DUE NODI (ADD EDGE)."<<endl;
cout<<"2) PER RIMUOVERE UN ARCO TRA DUE NODI (REMOVE EDGE)."<<endl;
cout<<"3) PER CONOSCERE SE DUE NODI DEL GRAFO SONO COLLEGATI DA UN ARCO (FIND EDGE)."<<endl;
cout<<"4) PER ESPLORARE I NODI DEL GRAFO CON UNA VISITA DFS."<<endl;
cout<<"0) PER USCIRE DAL PROGRAMMA."<<endl;
cout<<endl;


int scelta;

do {

cin>>scelta;

    switch(scelta) {
        default:
            cout<<"OPERAZIONE NON VALIDA"<<endl;
            cout<<endl;
            cout<<"QUALE ALTRA OPERAZIONE SI DESIDERA EFFETTUARE?"<<endl;
        break;

        case 0:
        exit(0);
        break;

        case 1:
        cout<<"SELEZIONARE IL NODO SORGENTE E DESTINAZIONE (INTERI) TRA CUI AGGIUNGERE UN NUOVO ARCO"<<endl;
        int n1, n2;
        cin>>n1;
        cin>>n2;

        if(n1 < (int)vn.size() && n2 < (int)vn.size() && hg.FindEdge(&vn.at(n1),&vn.at(n2)) != true) {     //se i due nodi esistono e non sono già collegati, è possibile aggiugere l'arco
            hg.AddEdge(&vn.at(n1),&vn.at(n2));
            cout<<"ARCO AGGIUNTO CON SUCCESSO"<<endl;
        }

        else
            cout<<"IMPOSSIBILE COLLEGARE I DUE NODI. SICURO NON SIANO GIA' COLLEGATI O CHE SIANO PRESENTI NELL'HASH?"<<endl;
        cout<<endl;
        cout<<"QUALE ALTRA OPERAZIONE SI DESIDERA EFFETTUARE?"<<endl;
        break;

        case 2:
        cout<<"SELEZIONARE DUE NODI (INTERI) TRA CUI RIMUOVERE UN NUOVO ARCO"<<endl;
        int n3, n4;
        cin>>n3;
        cin>>n4;
        if(n3 < (int)vn.size() && n4 < (int)vn.size() && hg.FindEdge(&vn.at(n3),&vn.at(n4)) == true) {
            hg.RemoveEdge(&vn.at(n3),&vn.at(n4));
            cout<<"ARCO RIMOSSO CON SUCCESSO"<<endl;
        }
        else
            cout<<"L'ARCO SELEZIONATO NON ESISTE"<<endl;
        cout<<endl;
        cout<<"QUALE ALTRA OPERAZIONE SI DESIDERA EFFETTUARE?"<<endl;
        break;

        case 3:
        cout<<"SELEZIONARE DUE NODI (INTERI) PER SAPERE SE SONO COLLEGATI DA UN ARCO"<<endl;
        int n5, n6;
        cin>>n5;
        cin>>n6;
        if(n5 < (int)vn.size() && n6 < (int)vn.size() && hg.FindEdge(&vn.at(n5),&vn.at(n6)) == true)
            cout<<"I DUE NODI SONO COLLEGATI DA UN ARCO"<<endl;
        else
            cout<<"I DUE NODI NON SONO COLLEGATI DA UN ARCO"<<endl;
        cout<<endl;
        cout<<"QUALE ALTRA OPERAZIONE SI DESIDERA EFFETTUARE?"<<endl;
        break;

        case 4:
         cout<<"SELEZIONARE UN NODO SORGENTE (INTERO) DA CUI COMINCIARE LA VISITA DFS"<<endl;
        int s;
        cin>>s;
        if(s < (int)vn.size()) {
        hg.DFS(&vn.at(s));
        cout<<endl<<"VISITA DFS EFFETTUATA CORRETTAMENTE"<<endl;
        }
        else cout<<"NODO INESISTENTE, IMPOSSIBILE EFFETTUARE LA DFS"<<endl;
        for(int i = 0; i < (int)vn.size(); i++) {
            vn.at(i).setColor(0);
            vn.at(i).setP(nullptr);
        }
        cout<<endl;
        cout<<"QUALE ALTRA OPERAZIONE SI DESIDERA EFFETTUARE?"<<endl;
        break;

    }

} while(scelta != 0);


    return 0;
}
