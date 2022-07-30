/** @file Especie.hh
 *  @brief Especifiació de la clase Espècie
*/
/** @class Especie
 *  @brief Representa una espècie
 *  
 *  Cada espècie té associat dos strings, un identificador <em>id</em> i un <em>gen</em>. Els caràcters del string <em>gen</em> poden ser només 'A', 'C', 'T' i/o 'G'. 
 * 
*/


#ifndef ESPECIE_HH
#define ESPECIE_HH
// Aquí s'haurà de calcular i emmagatzemar els k-mers d'una espècie. IMP. calcular també?
#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

class Especie {
    
private:
    string id, gen;
    double kmer; 
    
public:
    
    //Constructores
    
/** @brief Creadora per defecte
    \pre <em>Cert</em> 
    \post Crea una Espècie buida
*/
    Especie();

    
    //Destructores?
    //Modificadores
    //Consultores

/** @brief Consultora d'identificador
    \pre El p.i. no és buit
    \post Retorna <em>id</em>
*/
string consultar_id() const;

    
/** @brief Consultora del gen
    \pre El p.i. no és buit
    \post Retorna el <em>gen</em> de la espècie
*/
string consultar_gen() const;   


/** @brief Consultora de la distància
    \pre <em>Cert</em> 
    \post Retorna la distància entre l'espècie b i la espècie del p.i.
*/
double calcular_distancia(Especie b) const;


    //Lectura y escriptura
    
/** @brief Operació de lectura
    \pre  Hi ha preparats al canal estandar d'entrada dos strings <em>id</em> i <em>gen</em>; <em>gen</em> està format pels caràcters 'A', 'C', 'T' i/o 'G' 
    \post El paràmetre implícit passa a tenir els atributs llegits del canal estàndard d'entrada
*/
void llegir();
    

/** @brief Operació d'escriptura
    \pre  <em>Cert</em> 
    \post Imprimeix en el canal estàndard de sortida la espècie (identificador i gen)
*/
void escriure() const;

};

#endif
