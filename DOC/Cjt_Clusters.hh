/** @file Cjt_Clusters.hh
    @brief Especificació de la clase Conjunt de Clústers
*/
#ifndef CONJ_CLUSTERS_HH
#define CONJ_CLUSTERS_HH

#include "Cluster.hh"

#ifndef NO_DIAGRAM

#include <iostream>
#include <map>
using namespace std;

#endif

/** @class Cjt_Clusters
 *  @brief Representa un conjunt de clústers
 * 
 *  Els clústers d'aquest conjunt només tenen una espècie a l'arrel i dos fills buits.
 *  Es pot consultar i afegir clústers en el conjunt, però no treure'n. Es pot omplir de nou el conjunt des de la classe Cjt_Especies i llavors s'eliminen els clústers que hi han. També pot generar una taula de distàncies o generar l'arbre filogenètic dels clústers del conjunt.
 * 
*/

class Cjt_Clusters {
    
private:
    map<string,Cluster> clu;
//i potser alguna cosa més...
    //algo de distàncies?
    
    
    
//Potser pot desaparèixer
/** @brief Actualitza distàncies
    \pre <em>Cert</em> 
    \post S'han recalculat les distàncies del p.i.
*/
void actualitzar_distancies();
    
    
public:
    
    //Constructores
    
/** @brief Creadora per defecte
    \pre <em>Cert</em> 
    \post Crea un conjunt de clústers buit
*/
    Cjt_Clusters();
    
    
    //Destructores?
    //Modificadores

/** @brief Afegir clúster
    \pre <em>Cert</em> 
    \post S'ha afegit el clúster <em>c</em> al p.i. i s'han actualitzat totes les distancies
*/
void afegir_cluster(Cluster c);


/** @brief Pas WPGMA
 * Consulta els dos clústers de menor distància (A,B) i genera un Clúster C = AUB.
    \pre El p.i. té com a mínim 2 clústers.
    \post S'ha afegit el clúster C al p.i., s'ha eliminat A i B, i s'han actualitzat totes les distancies
*/
void pas_WPGMA();


/** @brief Aplicar algorisme WPGMA
    \pre <em>Cert</em> 
    \post S'ha aplicat l'algorisme WPGMA
*/
void aplicar_algorisme_WPGMA();


    //Consultores

/** @brief Consulta si un clúster amb ID=id es troba al p.i.
    \pre <em>Cert</em> 
    \post Si retorna <em>true</em>, <em>c</em> és el clúster amb ID=id, si retorna <em>fals</em>, el clúster buscat no es troba al p.i. 
*/
bool consultar_cluster(string id, Cluster& c) const;


/** @brief Consultora del numero de clústers
    \pre <em>Cert</em> 
    \post Retorna el número de clústers del p.i.
*/
int numero_clusters() const;


    //Lectura y escriptura

/** @brief Operació d'escriptura de la taula de distancies
    \pre <em>Cert</em> 
    \post Imprimeix en el canal estàndard de sortida la taula de distancies.
*/
void escriure_taula_distancies() const;


/** @brief Operació d'escriptura de clústers
    \pre <em>Cert</em> 
    \post Imprimeix en el canal estàndard de sortida el conjunt de clústers (on l'espècie queda representada amb identificador i gen).
*/
void escriure_clusters() const;


/** @brief Operació d'escriptura de l'arbre filogenetic
    \pre <em>Cert</em> 
    \post Imprimeix en el canal estàndard de sortida el conjunt de clústers en forma d'arbre filogenetic: els clusters amb els seus identificadors (arrels), la distancia ente cada cluster i les fulles descendents
*/
void escriure_arbre_filogenetic() const;

};

#endif
