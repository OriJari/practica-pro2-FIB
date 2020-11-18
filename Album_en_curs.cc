#include "Album_en_curs.hh"
#include <iostream>
#include <set>
#include <string>
using namespace std;

/** @class Album_en_curs.cc
    @brief Implementació de la classe Album en curs
*/

Album_en_curs::Album_en_curs(){}

Album_en_curs::~Album_en_curs(){}

void Album_en_curs::cambiar_id(const string& id){
    ida = id;
}
bool Album_en_curs::agrega_foto(const string& id){ // afegeix una foto nova
    Fotografia foto;
    foto.leer_foto(id);
    map<string,Fotografia>::iterator itt;
    itt = fotos.find(id);
    if(itt == fotos.end()){ //no hi es la foto 
        fotos.insert(make_pair(id,foto));
        return true;        
    }
    else return false;
    
    
}

void Album_en_curs::agrega_foto_obj(const Fotografia &f){ // afegeixx una foto existent
    string id = f.id_foto();
    fotos.insert(make_pair(id,f));
}


bool Album_en_curs::elimina_foto(const string& id){
    map<string,Fotografia>::iterator itt;
    itt = fotos.find(id);
    if(itt == fotos.end()) return false;
    else{
        fotos.erase(itt);   
        return true;
    }
}


bool Album_en_curs::obten_foto(const string& id)const{
    map<string,Fotografia>::const_iterator itt;
    itt = fotos.find(id);
    if(itt == fotos.end()) return false;
    else {
        ((*itt).second).imprime_foto();
        return true;
    }
}

void Album_en_curs::modificar_foto(const Fotografia &f){
    map<string,Fotografia>::iterator itt = fotos.find(f.id_foto());
    (*itt).second = f;
    
}
void Album_en_curs::lee_album(const string& ida){
    fotos.clear();
    this->ida = ida; 
    int n_fotos;
    cin >> n_fotos;
    for(int i = 0; i < n_fotos; ++i){
        Fotografia foto;
        string idf;
        cin >> idf;
        foto.leer_foto(idf);
        fotos.insert(make_pair(idf,foto));
        
    }
    
}


int Album_en_curs::nr_foto() const{
    return fotos.size();
}


void Album_en_curs::imprime_album()const{
    Fotografia foto;
   
    cout << ida << endl;
    map<string,Fotografia>::const_iterator itt = fotos.begin();
    while(itt != fotos.end()){
        cout << "  "; 
        ((*itt).second).imprime_foto();
        ++itt;
    }
    
}

    
void Album_en_curs::iniciar(){
    It = fotos.begin();
}
    
    
void Album_en_curs::avanzar(){
     ++It;   
}
    
    
bool Album_en_curs::es_ultima() const{
    if(It == fotos.end()) return true;
    else return false;
}
    
    
Fotografia Album_en_curs::foto_actual()const{
    return (*It).second;
}
    
string Album_en_curs::ida_album()const{
    return ida;
}

void Album_en_curs::clear(){
    fotos.clear();

}


Album_en_curs Album_en_curs::unio_album(Album_en_curs& a,Album_en_curs& b){ //interseccio de dos albums --> retorna un album OR
    map<string,Fotografia>::iterator ita = b.fotos.begin();
    while(ita != b.fotos.end()){
        Fotografia f = (*ita).second;
        a.agrega_foto_obj(f);
        ++ita;
    }
    return a;
}

Album_en_curs Album_en_curs::interseccio_album( Album_en_curs& a, Album_en_curs& b){ // unio dos albums -->retorna album AND
    map<string,Fotografia>:: iterator ia = a.fotos.begin();
    map<string,Fotografia>:: iterator ib;
    Album_en_curs c;
    while(ia != a.fotos.end()){
        /* recorrere a i anire comparant cada foto de a i buscar
         * si hi es a b, si es el cas afegir a c
         * sino, chao
         */
        string sa = (*ia).first;
        ib = b.fotos.find(sa);
        if(ib != b.fotos.end()){ // hi ha la foto de A a B
            Fotografia f = (*ib).second; // indifernet si es ia o ib pq es la mateixa foto
            c.agrega_foto_obj(f);
        }
        ++ia;
    }
    return c;
}

//a es un album i b es una suconjunt de a, i llavors amb aquesta funcio retorno el resto de a q no esta b
Album_en_curs Album_en_curs::complementari_album( Album_en_curs& a, Album_en_curs& b){ // complementari album --> retorna album NOT
    map<string,Fotografia>:: iterator ia = a.fotos.begin();
    map<string,Fotografia>:: iterator ib;
    Album_en_curs c;
    while(ia != a.fotos.end()){
        /* recorrere a i anire comparant cada foto de a i buscar
         * si no hi es a b, si es el cas afegir a c
         * sino, chao
         */
        string sa = (*ia).first;
        ib = b.fotos.find(sa);
        if(ib == b.fotos.end()){ // no hi ha la foto de A a B
            Fotografia f = (*ia).second; // ha  de ser si o si ia
            c.agrega_foto_obj(f);
        }
        ++ia;
    }
    return c;
}

