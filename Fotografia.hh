/** @file Fotografia.hh
    @brief Especificiació de la classe Fotografia
*/

#ifndef _FOTOGRAFIA_HH_
#define _FOTOGRAFIA_HH_



#ifndef NO_DIAGRAM
#include <set>
#include <iostream>
#include <string>
#endif
using namespace std;

/** @class Fotografia
    @brief Representa una fotografia amb nom o id, per identificar-la, i data de quan es va fer la foto
 */

#ifndef NO_DIAGRAM
struct data {
    int dia; // 1 <= dia <= 31
    int mes; // 1 <= mes <= 12
    int any; // 1700 <= any <= 2299
};
#endif 

class Fotografia

{
private:
    string id;  //identificador de la foto
    
    
    data data_foto; //data de la foto
    set<string> etiquetes; //set d'etiquetes


public: 
    // constructores
    
    /** @brief Creador per defecte
      \pre "Cert"
      \post Crea una foto no inicialitzada 
    */
    Fotografia();
    
    /** @brief Destructora per defecte
      \pre "Cert"
      \post Destrueix una foto no inicialitzada 
    */
    ~Fotografia();

    /** @brief Creadora amb valors especifics
      \pre 1 <= dia <= 31, 1 <= mes <= 12, 1700 <= any <= 2299
      \post Crea una foto amb els valors especifics 
    */
    void crear_foto(const string& id,const  data& d);
    
    /** @brief Afageix una etiqueta
      \pre "Cert"
      \post Afegeix una etiqueta a la fotografia donada
    */    
    
    // modificadores 
    
    void agregar_etiqueta(const string& et);
    
    /** @brief Elimina una etiqueta
      \pre "Cert"
      \post Elimina una etiqueta a la fotografia donada
    */
    void elimina_etiqueta(const string& et);
    
     /** @brief Llegeix la foto
      \pre "Cert"
      \post Llegeix totoa la informació de la foto
    */ 
    void leer_foto(const string& idf);
    
    
    // consultores
    
    /** @brief Consulta etiqueta
      \pre "Cert"
      \post Retorna true si la etiqueta coincideix amb la donada 
    */
    bool contiene_etiqueta(const string& et) const;
    
    /** @brief Consulta id de fotografia
      \pre "Cert"
      \post Retorna la id de la foto donada 
    */
    string id_foto() const;
    
    /** @brief Consulta data de la foto
      \pre "Cert"
      \post Retorna la data de quan esta datada la fotografia 
    */
    data fecha_toma() const;
    
    /** @brief Consulta numero de etiquetes
      \pre "Cert"
      \post Retorna el tota de etiquetes que te la fotografia donada  
    */    
    int nr_etiquetas() const;    
    
    /** @brief Imprimeix la foto
      \pre "Cert"
      \post Escriu tota la informació de la foto amb les etiquetes ordendes ascendentment lexicograficament
    */ 
        
    void imprime_foto() const;
    
    
    /** @brief Compara dates
      \pre "Cert"
      \post mira si la data x esta dins del rang donat
    */ 
    bool rangdata(const data& x,const data& ini,const data& fi) const;
    
    /** @brief Compara dates
      \pre "Cert"
      \post mira si la data d1 es <= amb d2
    */ 
    bool comp_data(const data& d1, const data& d2) const;
    
};
#endif
