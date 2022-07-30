/** @mainpage  Construcció d'un arbre filogenètic
 * 
 * Aquest programa modular ofereix un menú d'opcions per construir un arbre filogenètic basat en el mètode WPGMA. S'utilitzen les classes Especie, Cjt_Especies, Cluster i Cjt_Clusters. 
 * 
 * Els nodes d'aquest arbre filogenètic, anomenats clústers, estan formats per espècies. Els clústers que estan dins de l'arbre estan a una certa distància entre ells (llargada de les branques de l'arbre) que és equivalent a la distància entre les espècies que estan dins d'aquests clústers. 
 * 
 * Al principi del programa es llegeix un natural que servirà pel càlcul de distàncies. Després, es llegeix una sèrie d'instruccions que determinaran l'evolució del programa. 
 * 
 * Aquest programa té diverses opcions, però la idea principal és: primer es creen unes certes espècies que els hi pots consultar el gen i la distància entre elles. Aquestes espècies estan dins d'un conjunt d'espècies que té associada una taula de distàncies entre elles i es pot imprimir. Convertint les espècies en clústers i passant-los al conjunt de clústers, es pot imprimir també una taula de distàncies entre els clústers del conjunt. Des d'allà, s'aplica l'algorisme WPGMA i s'imprimeix l'arbre filogenètic. 
*/
/** @file main.cc
 *  @brief Programa principal per la construcció d'un arbre filogenètic.
*/

#ifndef NO_DIAGRAM
#include <iostream>
#endif

#include "Cjt_Especies.hh" 
using namespace std;

int main() {
    int k;
    cin >> k; 
    Cjt_Especies esp(k);  
    Cjt_Clusters clu;  
    string op;
    
    while (cin >> op and op != "fin") {
        cout << "# " << op;
        
        if (op == "crea_especie") {            
            Especie e;
            e.llegir();
            cout << ' ';
            e.escriure();
            string id = e.consultar_id();
            
            if (not esp.hi_es(id)) {
                esp.afegir_especie(e);
            }
            else {
                cout << "ERROR: La especie " << id << " ya existe." << endl;
            }
        }
        else if (op == "obtener_gen") {
            string id;
            cin >> id;
            cout << ' ' << id << endl;
            if (esp.hi_es(id)) {
                cout << esp.consultar_gen(id) << endl;
            }
            else cout << "ERROR: La especie " << id << " no existe." << endl;
            
        }
        else if (op == "distancia") {
            string id1, id2;
            cin >> id1 >> id2;
            cout << ' ' << id1 << ' ' << id2 << endl;
            
            bool b1 = esp.hi_es(id1);
            bool b2 = esp.hi_es(id2);
            
            if (b1 and b2) cout << esp.consultar_distancia(id1,id2) << endl;
            else {
                cout << "ERROR: La especie ";
                if (not b1 and not b2) {
                    cout << id1 << " y la especie " << id2 << " no existen." << endl;
                }
                else {
                    if (not b1) cout << id1;
                    else cout << id2;
                    cout << " no existe." << endl;
                }
            }
        }
        else if (op == "elimina_especie") {        
            string id;
            cin >> id;
            cout << ' ' << id << endl;
            if (esp.hi_es(id)) {
                esp.eliminar_especie(id);
            }
            else {
                cout << "ERROR: La especie " << id << " no existe." << endl;
            }
        }
        else if (op == "existe_especie") {
            string id;
            cin >> id;
            cout << ' ' << id << endl;
            
            if (esp.hi_es(id)) cout << "SI";
            else cout << "NO";
            cout << endl;
        }
        else if (op == "lee_cjt_especies") {
            cout << endl;
            esp.llegir();
        }
        else if (op == "imprime_cjt_especies") {
            cout << endl;
            esp.escirure();
        }
        else if (op == "tabla_distancias") {
            cout << endl;
            esp.escriure_taula_distancies();
        }
        else if (op == "inicializa_clusters") {
            cout << endl;
            clu.clear();
            esp.omplir_cjt_clusters(clu);
            clu.escriure_taula_distancies();
        }
        else if (op == "ejecuta_paso_wpgma") {
            cout << endl;
            if (clu.numero_clusters() > 1) {
                clu.pas_WPGMA();
                clu.escriure_taula_distancies();
            }
            else cout << "ERROR: num_clusters <= 1" << endl;
        }
        else if (op == "imprime_cluster") {
            string a;
            cin >> a;
            cout << ' ' << a << endl;
            
            Cluster c;
            if (clu.consultar_cluster(a,c)) c.escriure();
            else cout << "ERROR: El cluster " << a << " no existe." << endl;
        }
        else if (op == "imprime_arbol_filogenetico") {
            cout << endl;
            clu.clear();
            esp.omplir_cjt_clusters(clu);
            if (clu.numero_clusters() != 0) {
                clu.aplicar_algorisme_WPGMA();
                clu.escriure_arbre_filogenetic();
            }
            else cout << "ERROR: El conjunto de clusters es vacio." << endl;
        }

        cout << endl;
    }
}
