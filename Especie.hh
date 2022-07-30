/** @file Especie.hh
 *  @brief Especifiació de la classe Especie
*/
/** @class Especie
 *  @brief Representa una espècie
 *  
 *  Cada espècie té associat dos strings, un identificador <em>id</em> i un <em>gen</em>. Els caràcters del string <em>gen</em> poden ser només 'A', 'C', 'T' i/o 'G'. Es pot calcular la distància entre l'espècie del p.i. i una altra. L'espècie té associada una seqüència <em>kmer</em> (que pot estar no calculada, per tant buida) que serveix per calcular les distàncies entre espècies. <em>kmer</em> conté uns certs strings i és generada a través del <em>gen</em> de l'espècie i l'enter <em>k</em> que indica el criteri de càlcul del Cjt_Especies el qual aquestes pertanyen. La classe té operacions de lectura i escriptura.
 * 
*/


#ifndef ESPECIE_HH
#define ESPECIE_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
using namespace std;
#endif

class Especie {
    
private:
    
/** @brief Identificador
 * 
 *  Està format exclusivament per lletres minúscules i majúscules (de la A a la Z, sense caràcters especials, ni vocals accentuades...), dígits i per caràcters de subratllat: '_' .
*/
    string id;

/** @brief Gen
 *  
 *  Els caràcters del string <em>gen</em> poden ser només 'A', 'C', 'T' i/o 'G'.
*/
    string gen;
    
/** @brief Seqüència <em>kmer</em>
 * 
 *  Conjunt de les subseqüències contínues (del <em>gen</em>) de longitud <em>k</em> >= 1 (criteri de càlcul donat); o també anomenat els k-mers de <em>gen</em>. Si <em>n</em> és la longitud de <em>gen</em>, els kmer és el conjunt: {g[i..j + k − 1] | 0 ≤ i < n + 1 − k}, on g[i..j] denota la subseqüència de <em>gen</em> entre els símbols i-èssim i j-èssim de <em>gen</em>, que assumim que s'indexen de 0 a n-1.
 * 
 *  Les claus (strings) són les sucessions de <em>k</em> caràcters del <em>gen</em>. L'enter > 0, és el número de cops que apareix cada element del conjunt. 
*/
    map<string,int> kmer;
    
public:
    
    //Constructores
    
/** @brief Creadora per defecte
    \pre <em>Cert</em> 
    \post El resultat és una Espècie buida
*/
    Especie();

    
    //Destructora
    
/** @brief Destructora per defecte */   
    ~Especie();
    
    
    //Modificadores

/** @brief Calula els <em>kmer</em> del p.i. segons el criteri <em>k</em>
    \pre El p.i. té <em>gen</em>. <em>k</em> >= 1.
    \post El p.i. té calculat el <em>kmer</em> segons el criteri de càlcul <em>k</em>
*/
void calcular_kmer(int k);


    //Consultores

/** @brief Consultora d'identificador
    \pre <em>id</em> del p.i. no és buit
    \post Retorna <em>id</em>
*/
string consultar_id() const;

    
/** @brief Consultora del gen
    \pre <em>gen</em> del p.i. no és buit
    \post Retorna el <em>gen</em> de la espècie
*/
string consultar_gen() const;   


/** @brief Consultora de la distància
    \pre <em>kmer</em> no és buit
    \post Retorna la distància entre l'espècie <em>b</em> i la espècie del p.i. consultant dels <em>kmer</em> de cadascún
*/
double calcular_distancia(const Especie& b) const;


    //Lectura y escriptura
    
/** @brief Operació de lectura
    \pre  Hi ha preparats al canal estandar d'entrada dos strings <em>id</em> i <em>gen</em>; <em>gen</em> està format pels caràcters 'A', 'C', 'T' i/o 'G';
    \post El paràmetre implícit passa a tenir els atributs llegits del canal estàndard d'entrada; 
*/
void llegir();
    

/** @brief Operació d'escriptura
    \pre  <em>id</em> i <em>gen</em> del p.i. no són buits 
    \post Imprimeix en el canal estàndard de sortida la espècie (identificador i gen)
*/
void escriure() const;

};

#endif
