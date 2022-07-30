/** @file Cluster.cc */

#include "Cluster.hh"

Cluster::Cluster() {}

Cluster::Cluster(string id) {
    c = BinTree<pair<string,double>> (make_pair(id,0));
}

Cluster::~Cluster() {}

Cluster Cluster::fusionar_clusters(const Cluster& a, const Cluster& b, double distancia) {
    string id_a = a.consultar_id();
    string id_b = b.consultar_id();
    Cluster C;
    
    if (id_a < id_b) {
        for (int i = 0; i < id_b.size(); ++i) id_a.push_back(id_b[i]);
        pair<string,double> arrel(id_a,distancia);
        C.c = BinTree<pair<string,double>> (arrel,a.c,b.c);
    }
    else {
        for (int j = 0; j < id_a.size(); ++j) id_b.push_back(id_a[j]);
        pair<string,double> arrel(id_b,distancia);
        C.c = BinTree<pair<string,double>> (arrel,b.c,a.c);
    }
    return C;
}

string Cluster::consultar_id() const {
    return c.value().first;
}

void Cluster::escriure_BinTree(const BinTree<pair<string,double>>& c) {
    pair<string,double> arrel = c.value();
    cout << '[';
        
    if (c.left().empty()) cout << arrel.first << ']';    //si el subarbre esquerre és buit, el dret també.
    else {
        cout << '(' << arrel.first << ", " << arrel.second << ") ";
        escriure_BinTree(c.left());
        escriure_BinTree(c.right());
        cout << ']';
    }
}

void Cluster::escriure() const {
    if (not c.empty()) escriure_BinTree(c);
    cout << endl;
}
