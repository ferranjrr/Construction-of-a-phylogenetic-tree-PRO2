/** @file Especie.cc */

#include "Especie.hh"

Especie::Especie() {}

Especie::~Especie(){}

string Especie::consultar_id() const {
    return id;
}

string Especie::consultar_gen() const {
    return gen;
}

void Especie::llegir() {
    cin >> id >> gen;
}

void Especie::escriure() const {
    cout << id << ' ' << gen << endl;
}

void Especie::calcular_kmer(int k) {
    kmer.clear();
    
    int n = gen.size();
    for (int i = 0; i < n - k + 1; ++i) {
        string aux = "";
        for (int j = 0; j < k; ++j) {
            aux.push_back(gen[j+i]);
        }
        ++kmer[aux];
    }
}

double Especie::calcular_distancia(const Especie& b) const {
    if (id == b.consultar_id()) return 0;
    
    double inter = 0, unio = 0;    
    map<string,int>::const_iterator it1 = kmer.begin();
    map<string,int>::const_iterator it2 = b.kmer.begin();
    
    while (it1 != kmer.end() and it2 != b.kmer.end()) { 
        
        if (it1->first > it2->first) {
            unio = unio + it2->second;
            ++it2;
        }
        else if (it1->first < it2->first) {
            unio = unio + it1->second;
            ++it1;
        }
        else { //it1->first == it2->first
            inter = inter + min(it1->second,it2->second);
            unio = unio + max(it1->second,it2->second);
            ++it1;
            ++it2;
        }
    }    
    
    if (it2 != b.kmer.end()) {
        while (it2 != b.kmer.end()) {
            unio = unio + it2->second;
            ++it2;
        }
    }
    else if (it1 != kmer.end()) {
        while (it1 != kmer.end()) {
            unio = unio + it1->second;
            ++it1;
        }
    }
    return (1-(inter/unio))*100;
}
