/** @mainpage  Construcció d'un arbre filogenètic.
 * 
 * Aquest programa modular ofereix un menú d'opcions per construir un arbre filogenètic basat en el mètode WPGMA. S'utilitzen les classes Especie, Cjt_Especies, Cluster i Cjt_Clusters.
*/
/** @file main.cc
 *  @brief Programa principal per la construcció d'un arbre filogenètic.
*/

#ifndef NO_DIAGRAM
#include <iostream>
#endif

#include "Cjt_Especies.hh" 
#include "Cjt_Clusters.hh"
using namespace std;

int main() {
    cout.setf(ios::fixed); 
    cout.precision(4);
    
    int k;
    cin >> k;
    Cjt_Especies esp(k);  
    Cjt_Clusters clu;  
    string op;
    
    while (cin >> op and op != "fin") {
        if (op == "crea_especie") {
            Especie e;
            e.llegir();            

            if (not esp.hi_es(e.consultar_id())) {
                esp.afegir_especie(e);
            }
            else {
                cout << "Error: existe una especie con el mismo identificador." << endl;
            }
        }
        else if (op == "obtener_gen") {
            string id;
            cin >> id;
            if (esp.hi_es(id)) {
                cout << esp.consultar_gen(id) << endl;
            }
            else {
                cout << "Error: no existe una especie con el identificador dado." << endl;
            }
        }
        else if (op == "distancia") {
            string id1, id2;
            cin >> id1 >> id2;
            
            if (esp.hi_es(id1) and esp.hi_es(id2)) {
                cout << esp.calcular_distancia(id1,id2) << endl;
            }
            else {
                cout << "Error: alguna de las dos especies representadas por los identificadores dados no existen." << endl;
            }
        }
        else if (op == "elimina_especie") {
            string id;
            cin >> id;
            if (esp.hi_es(id)) {
                esp.eliminar_especie(id);
            }
            else {
                cout << "Error: la especie con el identificador dado no existe." << endl;
            }
        }
        else if (op == "existe_especie") {
            string id;
            cin >> id;
            cout << "La espeice " << id; 
            
            if (esp.hi_es(id)) cout << " está";
            else cout << " no está";
            cout << " en el conjunto de especies" << endl;
        }
        else if (op == "lee_cjt_especies") esp.llegir();
        else if (op == "imprime_cjt_especies") esp.escirure();
        else if (op == "tabla_distancias") {
            esp.escriure_taula_distancies();
        }
        else if (op == "inicializa_clusters") {
            esp.omplir_cjt_clusters(clu);
            clu.escriure_clusters();
            clu.escriure_taula_distancies();
        }
        else if (op == "ejecuta_paso_wpgma") {
            if (clu.numero_clusters() >= 2) {
                clu.pas_WPGMA();
                clu.escriure_taula_distancies();
            }
            else {
                cout << "Error: El número de clústers del conjunto es menor o igual que uno" << endl;
            }
        }
        else if (op == "imprime_cluster") {
            string a;
            cin >> a;
            Cluster c;
            if (clu.consultar_cluster(a,c)) c.escriure();
            else {
                cout << "Error: no existe un clúster con dicho identificador en el conjunto de clústers" << endl;
            }
        }
        else if (op == "imprime_arbol_filogenetico") {
            esp.omplir_cjt_clusters(clu);
            clu.aplicar_algorisme_WPGMA();
            clu.escriure_arbre_filogenetic();
        }
    }
}
