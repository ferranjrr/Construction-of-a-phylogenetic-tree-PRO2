/** @file Cjt_Especies.cc */

#include "Cjt_Especies.hh"

Cjt_Especies::Cjt_Especies(int k) {
    this->k = k;
}

Cjt_Especies::~Cjt_Especies() {}

void Cjt_Especies::afegir_especie(Especie& e) {
    e.calcular_kmer(k);
    string id = e.consultar_id();
    esp.insert(make_pair(id,e));
    afegir_especie_taula_distancies(e);
}

void Cjt_Especies::eliminar_especie(string id) {
    esp.erase(id);
    eliminar_especie_taula_distancies(id);
}

void Cjt_Especies::generar_taula_distancies() {
    dist.clear();
    
    map<string,Especie>::const_iterator it;
    for (it = esp.begin(); it != esp.end(); ++it) {
        string id = (*it).first;
        
        map<string,Especie>::const_iterator itt = it;
        ++itt;
        while (itt != esp.end()) {
            double distancia = (*it).second.calcular_distancia((*itt).second);            
            dist[id][(*itt).first] = distancia;
            ++itt;
        }
    }
    if (it != esp.begin()) {
        --it;
        pair<string,map<string,double>> p;
        p.first = it->first;
        dist.insert(p);
    }
}

void Cjt_Especies::afegir_especie_taula_distancies(const Especie& e) {
    map<string,Especie>::const_iterator it;
    string id = e.consultar_id();
    
    for (it = esp.begin(); it != esp.end(); ++it) {
        if (it->first > id) {
            
            dist[id][(*it).first] = (*it).second.calcular_distancia(e);
        }
        else if (it->first < id) {
            
            dist[it->first][id] = (*it).second.calcular_distancia(e); 
        }
        else {
            pair<string,map<string,double>> p;
            p.first = it->first;
            dist.insert(p);
        }
    }        
    
}

void Cjt_Especies::eliminar_especie_taula_distancies(string id) {
    map<string,map<string,double>>::iterator it1, itt;
    itt = dist.find(id);
    map<string,double>::iterator it2;
    
    for (it1 = dist.begin(); it1 != itt; ++it1) it1->second.erase(id);
    dist.erase(itt);
}

bool Cjt_Especies::hi_es(string id) const {
    map<string,Especie>::const_iterator it = esp.find(id);
    return it != esp.end();
}

string Cjt_Especies::consultar_gen(string id) const {
    map<string,Especie>::const_iterator it = esp.find(id);
    return it->second.consultar_gen();
}

void Cjt_Especies::omplir_cjt_clusters(Cjt_Clusters& clu) const {
    map<string,Especie>::const_iterator it;
    for (it = esp.begin(); it != esp.end(); ++it) {
        clu.afegir_cluster(it->first);
    }
    clu.omple_taula_distancies(dist);
}

void Cjt_Especies::llegir() {
    int n;
    cin >> n;
    esp.clear();
    Especie e;
    
    for (int i = 0; i < n; ++i) {
        e.llegir();
        
        e.calcular_kmer(k);
        esp.insert(make_pair(e.consultar_id(),e));
    }
    generar_taula_distancies();
}

void Cjt_Especies::escirure() const {
    map<string,Especie>::const_iterator it;
    for (it = esp.begin(); it != esp.end(); ++it) {
        (*it).second.escriure();
    }
}

void Cjt_Especies::escriure_taula_distancies() const {
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

double Cjt_Especies::consultar_distancia(string id1, string id2) const {
    map<string,map<string,double>>::const_iterator it1;
    map<string,double>::const_iterator it2;
    
    if (id1 < id2) {
        it1 = dist.find(id1);
        it2 = (*it1).second.find(id2);
        return it2->second;
    }
    else if (id1 > id2) {
        it1 = dist.find(id2);
        it2 = (*it1).second.find(id1);
        return it2->second;
    }
    else return 0;
}

