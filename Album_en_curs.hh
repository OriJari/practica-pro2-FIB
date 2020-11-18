/** @file Album_en_curs.hh
    @brief Especificiació de la classe Album en curs
*/

#ifndef _ALBUM_EN_CURS_HH_
#define _ALBUM_EN_CURS_HH_
#include "Fotografia.hh"

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#endif
using namespace std;

/** @class Album_en_curs
    @brief Representa l'album en curs, un id, per identificar-lo, i el conjut de fotografies que el formen
    */

class Album_en_curs

{
private:
    
    string ida; // identificador de l'album
    map<string,Fotografia> fotos; // map de fotografies de l'album
    map<string,Fotografia>::const_iterator It; // iterador del map de fotos per accdedir-hi desde fora la classe

public: 
    // constructores
    
    /** @brief Creador per defecte
      \pre "Cert"
      \post Crea un album no inicialitzat 
    */
    Album_en_curs();
    
    /** @brief Destructor per defecte
      \pre "Cert"
      \post Destrueix un album no inicialitzat 
    */
    ~Album_en_curs();
    
    
    // modificadores 
    
    /** @brief Cambia l'id
      \pre "Cert"
      \post Cambia l'ida album per al donat
    */
    void cambiar_id(const string& id);
    
    /** @brief Afageix una foto a l'album en curs
      \pre "Cert"
      \post Retorna true si la etiqueta coincideix amb la donada un boolea que indica si la operació ha tingut exit o no 
    */
    bool agrega_foto(const string& id);
    
    /** @brief Elimina foto de l'album en curs
      \pre "Cert"
      \post Eliminem la foto si esta a l'album en curs, sino no
    */    
    bool elimina_foto(const string& id);
    
    /** @brief Busca una foto 
      \pre "Cert"
      \post Si la foto hi es retorna la foto,sino no
    */
    bool obten_foto(const string& id) const;
    
    /** @brief Legeix album i el crea 
      \pre "Cert"
      \post Crea album en curs
    */
    void lee_album(const string& ida);
    
    /** @brief Inicia l'iterador
      \pre "Cert"
      \post Col·loca l'iterador a l'inici del map
    */
    void iniciar();
    
    /** @brief Avança l'iterador
      \pre "Cert"
      \post Avança una posició l'iterador 
    */
    void avanzar();
    
    /** @brief Cambia de foto
      \pre "Cert"
      \post Canvia la informació de la foto
    */
    void modificar_foto(const Fotografia &f);
    
    /** @brief Netejar la foto
      \pre "Cert"
      \post Buida el contingut de la foto
    */
    void clear();
    
    /** @brief Agrega una fotografia
      \pre "Cert"
      \post Modifica l'id de la foto
    */
    void agrega_foto_obj(const Fotografia &f);
    
    // consultores
    
    /** @brief Consulta numero fotos
      \pre "Cert"
      \post Retorna el numero de fotos que te l'album en curs
    */
    int nr_foto()const;
    
    /** @brief Imprimeix album en curs
      \pre "Cert"
      \post Escriu tota la informació de l'album en curs amb les fotos ordenades ascendentment
    */
    void imprime_album()const ;
    
    /** @brief Ultima foto del map
      \pre "Cert"
      \post Retorna true si és l'ultima foto, i false si no
    */
    bool es_ultima()const;
    
    /** @brief Foto actual que apunta l'iterador
      \pre "Cert"
      \post Foto actual que apunta l'iterador
    */
    Fotografia foto_actual() const;
    
    /** @brief Consulta id de l'album
      \pre "Cert"
      \post Retorna la ida de l'album donat
    */
    string ida_album()const;
    
    //statics 
    
     /** @brief Uneix dos Albums, OR
      \pre "Cert"
      \post Retorna un album que es la unio de dos albums
    */
    static Album_en_curs unio_album(Album_en_curs& a, Album_en_curs& b); 

    /** @brief Conjunt comu de dos albums, AND
      \pre "Cert"
      \post Retorna un album que es la interseccio entre els dos 
    */
    static Album_en_curs interseccio_album(Album_en_curs& a, Album_en_curs& b);

    /** @brief Complementari del subconjunt, NOT
      \pre Donat un album i un subconjunt seu
      \post Retrona el complementari del subconjunt
    */
    static Album_en_curs complementari_album( Album_en_curs& a, Album_en_curs& b);

};
#endif
