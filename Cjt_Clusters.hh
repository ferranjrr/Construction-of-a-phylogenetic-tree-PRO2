/** @file Cjt_Clusters.hh
    @brief Especificació de la classe Conjunt de Clústers
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
 *  Per omplir el conjunt de clústers, s'ha de fer des de la classe Cjt_Especies. Per tant, la idea seria que en el conjunt només hi hagi aquells clústers que representin les espècies que estiguin al Cjt_Especies en aquell instant.
 * 
 *  Hi ha una taula de distàncies que determina les distàncies entre els clústers del conjunt. Aquesta es pot omplir a través d'una donada o imprimir. En algunes operacions concretes, aquesta taula es va actualitzant.
 * 
 *  Es pot consultar els clústers del conjunt o saber quants n'hi ha. També es pot afegir clústers o buidar el conjunt, però llavors la taula de distàncies no quedarà actualitzada. 

 *  La classe ofereix realitzar l'algoritme WPGA (ja sigui tot de cop o pas a pas) i llavors imprimir l'arbre filogenètic.
 * 
*/

class Cjt_Clusters {
    
private:
    
/** @brief Conjunt de clústers
 * 
 *  L'string és <em>id</em> del clúster que l'acompanya (valor associat). Aquest <em>id</em> és la concatenació de tots els <em>id</em>s de les espècies que estan representades dins dels clústers del valor associat.
*/ 
    map<string,Cluster> clu;

/** @brief Taula de distàncies entre els clústers del conjunt
 * 
 *  Com que és una taula simètrica, per estalviar memòria només es guarda de la diagonal principal (no inclosa), cap amunt.
 *
 * Les claus del primer map són els <em>id</em>s de tots els clústers del conjunt. Les claus del segon map, són els <em>ID</em>s del conjunt > <em>id</em> de la clau del primer map corresponent. El double és la distància entre el clúster amb <em>id</em> = clau del primer map, i el clúster amb <em>ID</em> = clau del segon map.
*/ 
    map< string, map<string,double> > dist;
    
    
    

/** @brief Actualitza distàncies
    \pre <em>id3</em> és la concatenació de <em>id1</em> i <em>id2</em>, indiferent quin és el primer;
    \post S'han recalculat les distàncies del p.i. afegint <em>id3</em> i traient <em>id1</em> i <em>id2</em>
*/
void actualitzar_taula_distancies(string id1, string id2, string id3);


/** @brief Identificar clústers menor distancia
    \pre Com a mínim hi ha dos clústers al p.i. i taula de distàncies està actualitzada
    \post <em>id1</em> i <em>id2</em> són els identificadors dels dos clústers de menor distancia del p.i.; el resultat és la distància entre aquests dos.
*/
double identificar_ids_menor_distancia(string& id1, string& id2) const;
    
    
public:
    
    //Constructores
    
/** @brief Creadora per defecte
    \pre <em>Cert</em> 
    \post El resultat és un conjunt de clústers buit
*/
    Cjt_Clusters();
    
    
    //Destructora
    
/** @brief Destructora per defecte */   
    ~Cjt_Clusters();
    
    
    //Modificadores
    
/** @brief Buida el conjunt de clústers
    \pre <em>Cert</em> 
    \post No hi ha cap clúster al p.i.; La taula de distàncies no s'ha modificat.
*/
void clear();
    

/** @brief Omple taula distàncies del p.i.
    \pre <em>Cert</em> 
    \post La taula de distàncies del p.i. és igual a la del paràmetre.
*/
void omple_taula_distancies(const map<string,map<string,double>>& dist);


/** @brief Afegir clúster
    \pre No hi ha cap clúster al p.i. amb <em>ID</em>=<em>id</em>
    \post S'ha afegit al p.i. el clúster base <em>c</em> (sense fills) format per l'string <em>id</em> i amb distància = 0. No s'han actualitzat les distàncies del p.i.
*/
void afegir_cluster(string id);


/** @brief Pas WPGMA
 * Consulta els dos clústers de menor distància A,B i genera un Clúster C = AUB. Elimina A i B i afegeix C al p.i. i a la taula de distàncies.
    \pre El p.i. té com a mínim 2 clústers.
    \post S'ha executat un pas de l'algorisme WPGMA
*/
void pas_WPGMA();


/** @brief Aplicar algorisme WPGMA
 *  Executa pas_WPGMA() tantes vegades fins que el número de clústers del conjunt sigui <= 1.
    \pre <em>Cert</em> 
    \post S'ha aplicat l'algorisme WPGMA; El p.i. està format per un i només un clúster que conté totes les espècies (clústers) del p.i. previ i el seu identificador és la concatenació de totes aquestes espècies; Taula de distàncies només té un clúster;
*/
void aplicar_algorisme_WPGMA();


    //Consultores

/** @brief Consulta si un clúster amb ID=id es troba al p.i.
    \pre <em>Cert</em> 
    \post Si retorna <em>true</em>, <em>c</em> és el clúster amb ID=id, si retorna <em>false</em>, el clúster buscat no es troba al p.i. 
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
    \post S'ha imprès en el canal estàndard de sortida la taula de distàncies.
*/
void escriure_taula_distancies() const;


/** @brief Operació d'escriptura de l'arbre filogenètic
    \pre Hi ha un i només un cluster al p.i.
    \post S'ha imprès en el canal estàndard de sortida el conjunt de clústers en forma d'arbre filogenètic: els clusters amb els seus identificadors i la distància ente el clúster corresponent al clúster base; la distància dels clústers base (= 0) no s'ha escrit.
*/
void escriure_arbre_filogenetic() const;

};

#endif
