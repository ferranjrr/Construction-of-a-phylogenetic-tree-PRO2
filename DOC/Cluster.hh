/** @file Cluster.hh
 *  @brief Especificació de la classe Clúster
*/
/** @class Cluster
 *  @brief Representa un clúster
 *  
 *  L'estructura del cluster és d'arbre (BinTree.hh).
 *  El clúster base conté una sola espècie (només l'identificador de la espècie) i correspon un arbre amb només una fulla (una arrel que representa el clúster sense descendents).
 * 
*/

#ifndef CLUSTER_HH
#define CLUSTER_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include "BinTree.hh"
using namespace std;
#endif

class Cluster {
    
private: 
    BinTree<string> c;
    // On l'string és l'identificador de la Espècie
    
public:
    
    //Constructores
    
/** @brief Creadora per defecte
    \pre <em>Cert</em> 
    \post Crea un clúster buit, sense l'id de l'espècie
*/
    Cluster();
    

/** @brief Creadora del clúster base
    \pre <em>Cert</em> 
    \post Crea un clúster base amb arrel = id.
*/
    Cluster(string id);
    
    
    //Destructores?
    //Modificadores
    
/** @brief Fusió de dos clústers
 *  \pre Donat dos clústers A, B
    \post Retorna un clúster C = AUB
*/
Cluster fusionar_clusters(const Cluster& a, const Cluster& b);


    //Consultores
    
/** @brief Consultora d'identificador
    \pre El p.i. conté l'identificador d'una espècie
    \post Retorna <em>id</em>
*/
string consultar_id() const;


    //Lectura y escriptura
    
/** @brief Operació d'escriptura
    \pre <em>Cert</em> 
    \post Imprimeix en el canal estàndard de sortida l'estructura arbrobescent del clúster (on l'espècie queda representada per l'identificador).
*/
void escriure() const;
    
};

#endif
