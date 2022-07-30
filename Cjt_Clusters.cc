/** @file Cjt_Clusters.cc */

#include "Cjt_Clusters.hh"

Cjt_Clusters::Cjt_Clusters() {}

Cjt_Clusters::~Cjt_Clusters() {}

void Cjt_Clusters::clear() {
    clu.clear();
}

void Cjt_Clusters::omple_taula_distancies(const map<string, map<string,double>>& dist) {
    this->dist = dist;
}

void Cjt_Clusters::afegir_cluster(string id) {
    Cluster c(id);
    clu[id] = c;
}

void Cjt_Clusters::actualitzar_taula_distancies(string id1, string id2, string id3) {   
    if (id1 > id2) { //per tenir-los en ordre
        string aux = id1;
        id1 = id2;
        id2 = aux;
    } 

    pair<string,map<string,double>> p;
    p.first = id3;
    dist.insert(p);
    
    map<string,map<string,double>>::iterator it1;
    
    for (it1 = dist.begin(); it1 != dist.end(); ++it1) {        
        double dist_aux;
        string id_act = it1->first;
        
        if (id_act < id3 and id_act != id1) {            
            dist_aux = (dist[id_act][id1] + dist[id_act][id2])/2;
            
            (*it1).second.insert(make_pair(id3, dist_aux));
            
            it1->second.erase(id1);
            it1->second.erase(id2);        
        }
        else if (id_act > id3 and id_act != id2) {
            
            if (id2 < id_act) dist_aux = dist[id2][id_act];
            else dist_aux = dist[id_act][id2];
            
            dist[id3][id_act] = (dist[id1][id_act] + dist_aux)/2;
            it1->second.erase(id2);
        }
    }
    dist.erase(id1);
    dist.erase(id2);
}

void Cjt_Clusters::pas_WPGMA() {
    string id1, id2;
    double distancia = identificar_ids_menor_distancia(id1,id2);
    
    Cluster c = Cluster::fusionar_clusters(clu[id1],clu[id2],distancia/2);

    actualitzar_taula_distancies(id1,id2,c.consultar_id());
    
    clu[c.consultar_id()] = c;
    clu.erase(id1);
    clu.erase(id2);
    
}

void Cjt_Clusters::aplicar_algorisme_WPGMA() {
    while (clu.size() > 1) pas_WPGMA();
}

double Cjt_Clusters::identificar_ids_menor_distancia(string& id1, string& id2) const {    
    map<string,map<string,double>>::const_iterator it1 = dist.begin();
    map<string,double>::const_iterator it2 = it1->second.begin();
    
    double dist_min = it2->second;
    id1 = it1->first;
    id2 = it2->first;

    while (it1 != dist.end()) {

        for (it2 = it1->second.begin(); it2 != it1->second.end(); ++it2) {
            if (it2->second < dist_min) {
                id1 = it1->first;
                id2 = it2->first;
                dist_min = it2->second;
            }
        }
        ++it1;
    }
    return dist_min;
}

bool Cjt_Clusters::consultar_cluster(string id, Cluster& c) const {
    map<string,Cluster>::const_iterator it = clu.find(id);
    if (it != clu.end()) {
        c = (*it).second;
        return true;
    }
    return false;
}

int Cjt_Clusters::numero_clusters() const {
    return clu.size();
}

void Cjt_Clusters::escriure_taula_distancies() const {
    map<string,map<string,double>>::const_iterator it;
    
    for (it = dist.begin(); it != dist.end(); ++it) { 
        cout << (*it).first << ":";
        
        map<string,double>::const_iterator itt;
        for (itt = (*it).second.begin(); itt != (*it).second.end(); ++itt) {
            cout << ' ' << (*itt).first << " (" << (*itt).second << ")";
        
        }
        cout << endl;
    }
}

void Cjt_Clusters::escriure_arbre_filogenetic() const {
    map<string,Cluster>::const_iterator it = clu.begin();
    (*it).second.escriure();
}
