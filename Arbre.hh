/** @file Arbre.hh
    @brief Especificiació de la classe Album en curs
*/

#ifndef _ARBRE_HH_
#define _ARBRE_HH_
#include "Album_en_curs.hh"
#include "Fotografia.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <iostream>
#include <string>
#include <stack>
#endif
using namespace std;

/** @class Arbre
    @brief Representa l'arbre creat de tipo token
 */

#ifndef NO_DIAGRAM
struct token {
    string tipo; // tipo de la consulta: TAG, DATE, AND, OR o NOT
    string etq; // si tipo == "TAG", esta es la etiqueta
    data fini, ffin; // si tipo == "DATE", estas son las fechas de inicio y fin
                      // se asume que existe una clase Fecha y que hay una operacion para
                      // leer fechas
};
#endif

class Arbre{

private:

    BinTree<token> tri; // Arbre de tokens
    
public:
    // constructores
    
    /** @brief Creador per defecte
      \pre "Cert"
      \post Crea un arbre no inicialitzat 
    */
    Arbre();
    
    /** @brief Destructor per defecte
      \pre "Cert"
      \post Destrueix un arbre no inicialitzat 
    */
    ~Arbre();
    
    /** @brief Creador amb un tag
      \pre "Cert"
      \post Crea un arbre amb un tag 
    */
    Arbre(const string&s);
    
    /** @brief Creador amb data
      \pre "Cert"
      \post Crea un arbre amb data d'inici i de fi 
    */
    Arbre(const data& inici, const data& fi);
    
    /** @brief Creador de NOT
      \pre "Cert"
      \post Crea un arbre de tipo NOT 
    */
    Arbre NOT();
    
    /** @brief Creador de AND
      \pre "Cert"
      \post Crea un arbre de tipo AND
    */
    Arbre AND (const Arbre& q2);
    
    /** @brief Creador de OR
      \pre "Cert"
      \post Crea un arbre de tipo OR
    */
    Arbre OR (const Arbre& q2);
    
    // modificadores 
    
    /** @brief Llegeix l'arbre
      \pre "Cert"
      \post Crea l'arbre 
    */
    void read(istream& is);
    
    /** @brief Llegeix el contigut de l'arbre
      \pre "Cert"
      \post Llegeix el contigut de l'arbre i ho va posan al vector
    */
    void read_input(istream& is, vector<token>& l);
    
    // consultores
    
    /** @brief Arbre buit
      \pre "Cert"
      \post Ens diu si l'arbre esta buti o no
    */
    bool empty()  const;
    
    /** @brief Fill esquerra
      \pre "Cert"
      \post Retorna l'arbre fill de l'esquerra
    */
    Arbre left() const;
    
    /** @brief Fill dret
      \pre "Cert"
      \post Retorna l'arbre fill de la dreta
    */
    Arbre right() const;
    
     /** @brief Fulla arbre
      \pre "Cert"
      \post Retorna cert si l'arbre es fulla o no
    */
    bool es_fulla() const;
    
     /** @brief Obte el tipus de contingut de l'arbre
      \pre "Cert"
      \post Retorna l'string tipo
    */
    string obte_tipus() const;
    
     /** @brief Obte el tag
      \pre "Cert"
      \post Retorna el tag de l'arbre
    */
    string obte_tag() const;
    
     /** @brief Obte data inicial
      \pre "Cert"
      \post Retorna la data fini de l'arbre
    */
    data obte_ini() const;

     /** @brief Obte data final
      \pre "Cert"
      \post Retorna la data ffin de l'arbre
    */
    data obte_fi() const;

    
    
};
istream& operator>>(istream& is, Arbre& q);
#endif
