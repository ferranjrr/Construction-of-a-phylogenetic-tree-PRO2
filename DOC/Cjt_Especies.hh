/** @file Cjt_Especies.hh
    @brief Especificació de la clase Conjunt d'Espècies
*/
#ifndef CJT_ESPECIES_HH
#define CJT_ESPECIES_HH

#include "Especie.hh"
#include "Cjt_Clusters.hh"

#ifndef NO_DIAGRAM

#include <iostream>
#include <map>
using namespace std;

#endif

/** @class Cjt_Especies
 *  @brief Representa un conjunt d'espècies
 * 
 *  Hi ha operacions per afegir i treure espècies del conjunt. Es pot consultar si una certa espècie hi és, el <em>gen</em> d'una espècie amb un cert <em>id</em> i calcular les distàncies entre les espècies segons l'enter que indica el criteri de càlcul: <em>k</em> >= 1.
 *  Ofereix operacions de lecutra i escriptura.
 * 
*/

class Cjt_Especies {
    
private:
    map<string,Especie> esp;//i potser alguna cosa més...
    //suposo que la clau és id.
    int k; //criteri de distàncies
    //map< map<..,..>> // per poder calcular la taula de distancies?
    
    /*Invariant:
        k >= 1
    */
    
public:
    
    //Constructores
    
/** @brief Creadora per defecte
    \pre <em>k</em> >= 1
    \post Crea un Conjunt d'Espècies buit però té associat el criteri de distàncies <em>k</em>
*/
    Cjt_Especies(int k);
    
    
    //Destructores?
    //Modificadores
    
/** @brief Afegeix una espècie al p.i
    \pre <em>id</em> és l'identificador de la espècie <em>e</em>; No hi ha cap espècie al p.i. amb id = ID. 
    \post S'ha afegit <em>e</em> al p.i. 
*/
void afegir_especie(Especie e);


/** @brief Elimina una espècie del p.i.
    \pre Hi ha una espècie al p.i. amb ID = id 
    \post El p.i. queda sense l'espècie amb identificador ID
*/
void eliminar_especie(string id);


    //Consultores

/** @brief Consulta si hi ha una espècie al paràmetre implícit
    \pre  <em>Cert</em> 
    \post Si retorna <em>true</em> significa que hi ha una espècie en el p.i. amb <em>ID</em>=<em>id</em>, <em>fals</em> altrament
*/
bool hi_es(string id) const;


/** @brief Consultora del gen a través de id
    \pre Existeix una espècie amb ID = id
    \post Retorna el <em>gen</em> de la espècie de ID
*/
string consultar_gen(string id) const;


/** @brief Consultora de la distància entre dos espècies segons criteri de k
    \pre Existeix una espècie en el p.i. amb ID1 = id1 i una altra amb ID2 = id2
    \post Retorna la distància entre elles segons el criteri k (parametre impícit)
*/
double calcular_distancia(string id1, string id2) const;


/** @brief Omplir el cjt_Clusters
    \pre <em>Cert</em> 
    \post Cjt_Especies queda omplert amb les espècies del paràmetre implícit. S'han actualitzat totes les distàncies.
*/
void omplir_cjt_clusters(Cjt_Clusters& clu) const;


    //Lectura y escriptura

/** @brief Operació de lecutra
    \pre Hi ha preparats al canal estàndard d'entrada un enter n ≥ 0 i a continuació una sequència de n espècies (parells de identificador-gen); Les n espècies donades tenen identificadors diferents entre si
    \post El conjunt previ d'espècies es descarta —les espècies deixen d'existir— i les n espècies llegides s'egreguen al conjunt de especies
*/
void llegir();


/** @brief Operació d'escriptura de la taula de distàncies
    \pre <em>Cert</em> 
    \post Imprimeix en el canal estàndard de sortida la taula de distàncies entre cada parell d'espècies del p.i.
*/
void escriure_taula_distancies() const;


/** @brief Operació d'escriptura del conjunt d'espècies
    \pre <em>Cert</em> 
    \post Imprimeix en el canal estàndard de sortida el conjunt d'especies (identificador i gen de cada una)
*/
void escirure() const;

};

#endif
