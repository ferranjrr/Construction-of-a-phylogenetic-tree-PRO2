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
 *  Hi ha operacions per afegir i treure espècies del conjunt. Es pot consultar si una certa espècie hi és, consultar el <em>gen</em> d'una espècie donat un cert <em>id</em> i consultar la distància entre dues espècies del conjunt. El conjunt d'espècies té associada una taula de distancies entre les espècies del conjunt, que s'actualitza cada cop que s'afegeix/elimina una espècie. Totes les espècies del conjunt tenen les sequències <em>kmer</em> calculats segons el criteri de clàlcul que indica l'enter <em>k</em> >= 1, que per força també és criteri de càlcul de les distàncies. Des del primer moment que es crea el conjunt d'espècies, <em>k</em> queda associat a l'objecte.
 * 
 * La classe ofereix operacions de lectura i escriptura del conjunt i de la taula de distàncies.

 * També hi ha la opció d'omplir un conjunt de clústers amb les espècies del conjunt en aquell moment. 
*/

class Cjt_Especies {
    
private:
    
/** @brief Conjunt d'Espècies.
 * 
 *  Les claus són els <em>id</em> de cada espècie; on l'espècie és el valor associat del map. Cap <em>id</em> és un prefix d'un altre <em>id</em>. L'espècie té els <em>kmer</em> calculats i no hi ha dos espècies amb el mateix <em>gen</em>, ni cap <em>gen</em> de longitud < <em>k</em>.
*/    
    map<string,Especie> esp;

/** @brief Taula de distàncies
 * 
 *  Hi ha totes les distàncies entre les espècies del conjunt. Com que és una taula simètrica, per estalviar memòria només es guarda de la diagonal principal (no inclosa), cap amunt.
 *
 * Les claus del primer map són els <em>id</em>s de totes les espècies del conjunt. Les claus del segon map, són els <em>ID</em>s del conjunt > <em>id</em> de la clau del primer map corresponent. El double és la distància entre l'espècie amb <em>id</em> = clau del primer map, i l'espècie amb <em>ID</em> = clau del segon map.
*/ 
    map< string, map<string,double> > dist;
    
/** @brief Criteri de distàncies
 * 
 *  k >= 1
 * 
 *  Indica el criteri que es fa servir per calcular els <em>kmer</em> de les espècies, i per tant el criteri de distàncies.
*/
    int k;
    
    
/** @brief Generar taula distàncies
    \pre <em>Cert</em> 
    \post Si la taula de distàncies estaba plena, es buida. S'ha generat la taula de distàncies a través de les espècies que hi ha al p.i.
*/
void generar_taula_distancies();


/** @brief Afegir espècie a la taula de distàncies
    \pre <em>e</em> pertany al conjunt d'espècies
    \post S'ha actualitzat la taula de distàncies afegint <em>e</em>
*/
void afegir_especie_taula_distancies(const Especie& e);


/** @brief Elimina i actualitza les distàncies donat un <em>id</em>
    \pre Existeix un <em>ID</em>=<em>id</em> a la taula de distàncies
    \post S'ha actualitzat la taula de distàncies treient les de <em>ID</em>
*/
void eliminar_especie_taula_distancies(string id);
    
public:

    //Constructores
    
/** @brief Creadora per defecte
    \pre <em>k</em> >= 1
    \post El resultat és un Conjunt d'Espècies buit que té associat <em>k</em> al p.i.
*/
    Cjt_Especies(int k);
    
    
    //Destructora
    
/** @brief Destructora per defecte */   
    ~Cjt_Especies();
    
    
    //Modificadores
    
/** @brief Afegeix una espècie al p.i
    \pre <em>id</em> és l'identificador de la espècie <em>e</em>; No hi ha cap espècie al p.i. amb <em>id</em> = <em>ID</em>. 
    \post S'ha afegit <em>e</em> al p.i i <em>e</em> té calculat el <em>kmer</em>. S'ha actualitzat la taula de distàncies.
*/
void afegir_especie(Especie& e);


/** @brief Elimina una espècie del p.i.
    \pre Hi ha una espècie al p.i. amb <em>ID</em> = <em>id</em> 
    \post El p.i. queda sense l'espècie amb identificador <em>ID</em>; S'ha actualitzat la taula de distàncies
*/
void eliminar_especie(string id);


    //Consultores

/** @brief Consulta si hi ha una espècie al paràmetre implícit
    \pre  <em>Cert</em> 
    \post Si retorna <em>true</em> significa que hi ha una espècie en el p.i. amb <em>ID</em>=<em>id</em>, <em>fals</em> altrament
*/
bool hi_es(string id) const;


/** @brief Consultora del gen a través de id
    \pre Existeix una espècie amb <em>ID</em> = <em>id</em> 
    \post Retorna el <em>gen</em> de la espècie de <em>ID</em>
*/
string consultar_gen(string id) const;


/** @brief Consultora de la distància entre dos espècies
    \pre Existeix una espècie en el p.i. amb <em>ID1</em> = <em>id1</em> i una altra amb <em>ID2</em> = <em>id2</em>
    \post Retorna la distància entre elles
*/
double consultar_distancia(string id1, string id2) const;


/** @brief Omplir el Cjt_Clusters
    \pre <em>clu</em> és buit
    \post <em>clu</em> queda omplert amb les espècies del paràmetre implícit. La taula de distàncies entre clusters de <em>clu</em> és igual a la taula de distàncies del p.i.
*/
void omplir_cjt_clusters(Cjt_Clusters& clu) const;


    //Lectura y escriptura

/** @brief Operació de lecutra
    \pre Hi ha preparats al canal estàndard d'entrada un enter n ≥ 0 i a continuació una sequència de n espècies (parells de identificador-gen); Les n espècies donades tenen identificadors diferents entre si
    \post El conjunt previ d'espècies es descarta —les espècies deixen d'existir— i les n espècies llegides s'agreguen al conjunt de espècies. Cada espècie té els <em>kmer</em> calculats. Es buida la taula de distàncies i s'actualitza amb les noves espècies llegides.
*/
void llegir();


/** @brief Operació d'escriptura de la taula de distàncies
    \pre <em>Cert</em> 
    \post Imprimeix en el canal estàndard de sortida la taula de distàncies entre cada parell d'espècies del p.i.
*/
void escriure_taula_distancies() const;


/** @brief Operació d'escriptura del conjunt d'espècies
    \pre <em>Cert</em> 
    \post Imprimeix en el canal estàndard de sortida el conjunt d'especies (identificador i gen de cada una). Si p.i. és buit, no imprimeix res
*/
void escirure() const;

};

#endif
