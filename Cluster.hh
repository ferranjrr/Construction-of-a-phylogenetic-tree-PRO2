/** @file Cluster.hh
 *  @brief Especificació de la classe Clúster
*/
/** @class Cluster
 *  @brief Representa un clúster
 *  
 *  Un clúster representa a un "grup d'espècies" i la seva estructura és d'arbre.
 * 
 *  El clúster base conté una sola espècie (només l'identificador del clúster = identificador de la espècie i una distància = 0) i correspon a un arbre amb només una fulla (una arrel que representa el clúster sense descendents). Ara bé, si no és un clúster base, és un clúster on els fills esquerre i dret també són clústers i així fins que a les últimes fulles trobarem els clústers base. És a dir, donats dos clústers, els podem unir per formar un de més gran que agrupi les espècies d'aquests dos. 
 * 
 *  Cada clúster té associat una distància que correspon a la distància entre el clúster corresponent i els clústers base. Evidentment, la distància que té associada un clúster base és 0. 
 * 
 *  L'arrel del clúster representa l'espècie més recent de totes les espècies que hi ha en el clúster.
 * 
 *  Donats dos clústers amb identificadors α i β tals que α < β en ordre lexicogràfic, la seva combinació és un clúster que té com a fill esquerre el clúster identificat per α, com a fill dret el clúster identificat per β i el seu identificador és γ = α · β , la concatenació dels identificadors dels seus fills. 
 * 
 *  La classe ofereix operacions per crear clústers base, fusionar clústers, consultar identificadors i escriure.
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
    
/** @brief Clúster
 * 
 *  L'string és <em>id</em> del clúster (consultar a la classe Especie com ha d'estar format aquest <em>id</em>). Si <em>c</em> representa un clúster base, <em>id</em> del clúster = <em>id</em> de l'espècie que repesenta, sinó serà la concatenació dels <em>id</em>s de les espècies que representa.
 * 
 *  I el double és la distància >= 0 des dels clústers base al clúster corresponent.
*/ 
    BinTree< pair<string, double>> c;

    
/** @brief Escriure BinTree
    \pre <em>c</em> no és buit 
    \post Escriu pel canal estàndard de sortida el BinTree del paràmetre en preordre.
*/
static void escriure_BinTree(const BinTree<pair<string,double>>& c);
    
public:
    
    //Constructores
    
/** @brief Creadora per defecte
    \pre <em>Cert</em> 
    \post El resultat és un clúster buit, sense id ni distància
*/
    Cluster();
    

/** @brief Creadora del clúster base
    \pre <em>Cert</em> 
    \post El resultat és un clúster base amb aquest <em>id</em> i distància 0.
*/
    Cluster(string id);
    
    
    //Destructora
    
/** @brief Destructora per defecte */   
    ~Cluster();
    
    
    //Modificadores
    
/** @brief Fusió de dos clústers
 *  \pre Donats dos clústers a=A, b=B i <em>distancia</em> >= 0.
    \post Retorna un clúster C = AUB; Si <em>id<em> de A < <em>ID<em> de B llavors el subarbre esquerre és A i el dret és B i viceversa; C conté la distancia del paràmetre.
*/
static Cluster fusionar_clusters(const Cluster& a, const Cluster& b, double distancia);


    //Consultores
    
/** @brief Consultora d'identificador
    \pre El p.i. conté l'identificador de l'espècie més recent de totes les espècies que hi ha en el clúster
    \post Retorna <em>id</em> de l'espècie que hi ha a l'arrel del clúster
*/
string consultar_id() const;


    //Lectura y escriptura
    
/** @brief Operació d'escriptura
    \pre <em>Cert</em> 
    \post S'ha imprimès en el canal estàndard de sortida l'estructura arborescent del clúster (on l'espècie queda representada per l'identificador i la distància); la distància dels clústers base no s'ha escrit.
*/
void escriure() const;
    
};

#endif
