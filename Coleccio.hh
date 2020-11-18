/** @file Coleccio.hh
    @brief Especificiació de la classe Colecció
*/

#ifndef _COLECCIO_HH_
#define _COLECCIO_HH_

#include "Fotografia.hh"
#include "Album_en_curs.hh"
#include "Arbre.hh"

#ifndef NO_DIAGRAM
#include <map>
#endif
using namespace std;

/** @class Coleccio
    @brief Representa una colecció d'albums
    */

class Coleccio

{
private:
     
    map<string,Fotografia> fotos;  //map amb tots els identificadors de les fotos i les fotografies, album ALL
    map<string,set<string>> albums; //map amb els identificadors dels albums i set amb identificadors de les fotos de cada album
    
    /** @brief Funció recursiva
      \pre "Cert"
      \post Recorre l'arbre i va modificant l'album segons com sigui la consulta booleana
    */
    void recursio(const Arbre& pi, const string& ida,const  string& nida, Album_en_curs& res);
    
    

public: 
    // constructores 
    
    
    /** @brief Creador per defecte
      \pre "Cert"
      \post Crea una coleccio no inicialitzada 
    */
    Coleccio();
    
    /** @brief Destructor per defecte
      \pre "Cert"
      \post Destrueix una coleccio no inicialitzada 
    */
    ~Coleccio();
    
    // modificadores 
    
    /** @brief Afegeix foto a ALL
      \pre "Cert"
      \post Afegeix foto a ALL
    */
    void afegir_foto_a_ALL(const string& idf);
    
    /** @brief Afageix una album a una coleccio
      \pre Es donat un album que no es ALL
      \post Afageix la copia d'un album a una coleccio i sincronitza les fotos 
    */
    void agrega_album( Album_en_curs& a);
    
    /** @brief Elimina l'album de la coleccio
      \pre "Cert"
      \post Eliminem l'album si esta a la coleccio pero no les fotos
    */    
    bool elimina_album(const string& ida);
    
    /** @brief Afageix foto a la coleccio
      \pre "Cert" 
      \post Afegeix la foto a la coleccio si no hi es, no la posa a cap album
    */
    bool agrega_foto(const string& id);
    
    /** @brief Elimina foto de la coleccio
      \pre "Cert"
      \post si la foto hi es, es borrada de la coleccio i tots els albums a la qual pertany
    */
    bool elimina_foto(const string& id);
    
    /** @brief Cambia de foto
      \pre "Cert"
      \post Es substitueix la foto vella per la nova si id i idf son iguals
    */
    bool modifica_foto(const string& id);
    
    // consultores 
    
    /** @brief Mira si l'album forma part de la coleccio
      \pre "Cert"
      \post Si l'album hi es retorna true
    */
    bool contiene_album(const string& ida)const;
    
    /** @brief Mira si hi ha l'album a la coleccio 
      \pre "Cert"
      \post Retorna el nou album en curs
      */
    bool obten_album(const string& ida,Album_en_curs &a);
    
    /** @brief Consulta numero d'albums a la coleccio
      \pre "Cert"
      \post Retorna el numero d'albums a la coleccio 
    */
    int nr_albumes()const;
    
    /** @brief Escriu idas dels albums
      \pre "Cert"
      \post Escriu els identificadors de tots els albums que hi ha a la coleccio incluit ALL
    */
    void lista_albumes(); 
    
    /** @brief Numero de albums on esta a foto 
      \pre "Cert"
      \post retorna el numero d'albums on la foto es present
    */
    void nr_albumes_foto(const string& id)const;
    
    /** @brief Escriu idas d'albums on la foto forma part
      \pre "Cert"
      \post Escriu ordenat lexicografic acendetn, la llista de ida dels albums de la coleccio on la foto es present
    */
    void lista_albumes_foto(const string& id)const;
    
      /** @brief Imprimir la Colecció
      \pre "Cert"
      \post Imprimeix tots els Albums amb les seves fotos de la Colecció incluit el ALL
    */
    void imprime_coleccion()const;
    
    
    //cerques
    
    
    /** @brief Cerca per foto per dates 
      \pre "Cert"
      \post Crea un subalbum que conte les fotos fetes dins del rang de les dates
    */
    bool busca_por_fecha(const data& ini,const data& fi,const string& ida,const string& nouida, Album_en_curs& a)const;
    
    /** @brief Cerca fotos per etiquetes
      \pre "Cert"
      \post Crea un subalbum que conte les fotos amb l'etiqueta etiq
    */
    bool busca_por_etiqueta(const string& eti,const string& ida,const string& nouida, Album_en_curs& a)const;
    
    /** @brief Evalua la consutla booleana
      \pre "Cert"
      \post Crida a la funcio recursiva si ida existeix, sino no
    */
    bool evalua_consulta_booleana(Album_en_curs& al,const string& ida,const string& nida,const Arbre &ar);

    
 };
#endif
