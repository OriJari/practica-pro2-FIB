#include "Coleccio.hh"
#include <iostream>
#include <set>
#include <map>
using namespace std;

/** @class Coleccio.cc
    @brief Implementació de la classe Coleccio
*/

Coleccio::Coleccio(){
    albums.insert(make_pair("ALL",set<string>()));
}

Coleccio::~Coleccio(){
}

void Coleccio::afegir_foto_a_ALL(const string& idf){
    map<string,set<string>>::iterator itA;
    itA = albums.find("ALL");
    (*itA).second.insert(idf);
}
    
void Coleccio::agrega_album( Album_en_curs& a){
    if((a.ida_album()) != "ALL" and (albums.find(a.ida_album())) == albums.end()){
        map<string,set<string>>::iterator ita;
        ita = albums.find(a.ida_album());
        set<string> s;
        a.iniciar();
        while(not a.es_ultima()){
            Fotografia foto;
            foto = a.foto_actual();
            map<string,Fotografia>::iterator itf;
            itf = fotos.find(foto.id_foto());
            if(itf != fotos.end()){
                a.modificar_foto((*itf).second);
            }
            else{
                fotos.insert(make_pair(foto.id_foto(),foto));
                afegir_foto_a_ALL(foto.id_foto());
            }   
            s.insert(foto.id_foto());
            a.avanzar();
        }
        albums.insert(make_pair(a.ida_album(),s));
        cout << "Album en curso agregado a la coleccion." << endl;
        cout << "Album en curso, despues de agregar:" << endl;
        a.imprime_album();
    }
    else cout << "Identificador de album incorrecto. No se puede agregar." << endl;
    
}
    

bool Coleccio::elimina_album(const string& ida){
    if(ida != "ALL"){
        map<string,set<string>>::iterator it;
        it = albums.find(ida);
        if(it != albums.end()){
            albums.erase(it);
            return true;
        }
        else return false;
    }
    return false;
}
    

bool Coleccio::contiene_album(const string& ida)const{
    map<string,set<string>>::const_iterator ita;
    ita = albums.find(ida);
    if(ita == albums.end()) return false;
    else return true;
}
  
    
bool Coleccio::obten_album(const string& ida,Album_en_curs &a){
    map<string,set<string>>::iterator itA;
    itA = albums.find(ida);
    if(itA != albums.end()){ 
        a.clear();
        a.cambiar_id(ida);
        set<string> s = (*itA).second;
        set<string>::iterator itss;
        itss = s.begin();
        while(itss != s.end()){
            string idf = *itss;
            map<string,Fotografia>::iterator itff;
            itff = fotos.find(idf);
            Fotografia foto = ((*itff).second);
            a.agrega_foto_obj(foto);
            ++itss;
            
            
        }
        
        return true;
        
    }
    else return false;
    
}
    
    
int Coleccio::nr_albumes()const{
    return albums.size();
}
    

void Coleccio::lista_albumes(){
    map<string,set<string>>::iterator it = albums.begin();
    cout << (*it).first;
    ++it;
    while(it != albums.end()){
        cout << ' ' << (*it).first;
        ++it;
    }
    cout << endl;
} 
    
   
bool Coleccio::agrega_foto(const string& id){
    Fotografia foto;
    foto.leer_foto(id);
    map<string,Fotografia>::iterator itt;
    itt = fotos.find(id);
    if(itt == fotos.end()){ //no hi es la foto 
        fotos.insert(make_pair(id,foto));
         afegir_foto_a_ALL(foto.id_foto());
        return true;
    }
    else return false;
    
}
    
   
bool Coleccio::elimina_foto(const string& id){
    map<string,Fotografia>::iterator itt;
    itt = fotos.find(id);
    if(itt == fotos.end()) return false;
    else{
        fotos.erase(itt); //borrem foto de la coleccio 
        map<string,set<string>>::iterator it = albums.begin();
        while(it != albums.end()){ // borrar id de album 
            set<string>::iterator its;
            its = ((*it).second).find(id);
            if(its != ((*it).second).end()){
                ((*it).second).erase(its);
            }
           
            ++it;
        }
        return true;
    }
}
    

bool Coleccio::modifica_foto(const string& id){
    map<string,Fotografia>::iterator itf;
    itf = fotos.find(id);
    Fotografia f;
    f.leer_foto(id);
    if(itf != fotos.end()){ // hi es per tant la modifico
        fotos.erase(id); //borro la foto
        
        fotos.insert(make_pair(id,f)); // aixi al posarla al map no m'ignora
    return true;
    }
    else return false;
}
    

void Coleccio::nr_albumes_foto(const string& id)const{ 
    int n = 0;
    map<string,Fotografia>::const_iterator it = fotos.find(id);
    if(it != fotos.end()){
        map<string,set<string>>::const_iterator ita = albums.begin();
        
        while(ita != albums.end()){
            
            if((*ita).second.find(id) != (*ita).second.end()) {
                
              ++n;
            }
            ++ita;
        }
        cout << n << endl;
    
    }
    else{
        cout << "No existe una foto con el id dado." << endl;
    }
}
    

void Coleccio::lista_albumes_foto(const string& id)const{
    map<string,Fotografia>::const_iterator it = fotos.find(id);
    if(it != fotos.end()){
        map<string,set<string>>::const_iterator ita = albums.begin();
        bool first = true;
        while(ita != albums.end()){
            
            if((*ita).second.find(id) != (*ita).second.end()) {
                
                if(first){
                    first = false;
                    cout << (*ita).first; 
                }
                else cout << " " << (*ita).first;
            }
            ++ita;
        }
        cout << endl;
    }
    else{
        cout << "No existe una foto con el id dado." << endl;
    }
    
} 

void Coleccio::imprime_coleccion()const{
    map<string,Fotografia>::const_iterator itf; //busca la foto
    map<string,set<string>>::const_iterator ita; // recorre els albums
    set<string>::const_iterator its; // recorre lstrings de fotos de lalbum
    Fotografia foto;
    
    ita = albums.begin();
    while(ita != albums.end()){
        its = ((*ita).second).begin();
        cout << (*ita).first << endl;
        while(its != ((*ita).second).end()){
            itf = fotos.find(*its);
            if(itf != fotos.end()){
                cout << "  ";set<string>::iterator its = (*ita).second.begin();
                (*itf).second.imprime_foto();
            }
                ++its;
        }
        ++ita;
    }
    
}

bool Coleccio::busca_por_fecha(const data& ini,const data& fi,const string& ida,const string& nouida, Album_en_curs& a)const{
    map<string,set<string>>::const_iterator ita = albums.find(ida);
    if(ita != albums.end()){
        a.clear();
        a.cambiar_id(nouida);
        set<string> s = (*ita).second;
        set<string>::const_iterator its = s.begin();
        while(its != s.end()){
            string idf = *its;
            map<string,Fotografia>::const_iterator itf;
            itf = fotos.find(idf);
            Fotografia f = ((*itf).second); 
            data d = f.fecha_toma();
            if(f.rangdata(d, ini, fi)){
                a.agrega_foto_obj(f);
            }
            ++its;
        }
        return true;
    }
    else return false;
}

 
    

bool Coleccio::busca_por_etiqueta(const string& eti,const string& ida,const string& nouida, Album_en_curs& a)const{
    map<string,set<string>>::const_iterator ita = albums.find(ida);
    if(ita != albums.end()){
        a.clear();
        a.cambiar_id(nouida);
        set<string> s = (*ita).second;
        set<string>::const_iterator its = s.begin();
        while(its != s.end()){
            string idf = *its;
            map<string,Fotografia>::const_iterator itf;
            itf = fotos.find(idf);
            Fotografia f = ((*itf).second); 
            if(f.contiene_etiqueta(eti)){
                a.agrega_foto_obj(f);
            }
            ++its;
        }
        return true;
    }
    else return false;
}


void Coleccio::recursio(const Arbre& pi,const string& ida, const string& nida, Album_en_curs& res){ 
    if(pi.es_fulla()){
       
        if(pi.obte_tipus() == "TAG"){
         
            string s;
            s = pi.obte_tag();
            busca_por_etiqueta(s,ida,nida,res);
        }
        else if(pi.obte_tipus() == "DATE"){
            
            data d1, d2;
            d1 = pi.obte_ini();
            d2 = pi.obte_fi();
            busca_por_fecha(d1,d2,ida,nida,res);
        }
    }
    else{
       
        
        if(pi.obte_tipus() == "AND"){
           Album_en_curs resl,resr;
            recursio(pi.left(),ida,nida,resl);
            recursio(pi.right(),ida,nida,resr);
            res.cambiar_id(nida);
            res = Album_en_curs::interseccio_album(resl,resr); 
            
        }
        else if(pi.obte_tipus() == "OR"){
          Album_en_curs resl,resr;
            recursio(pi.left(),ida,nida,resl);
            recursio(pi.right(),ida,nida,resr);
            res.cambiar_id(nida);
            res = Album_en_curs::unio_album(resl,resr); 
        }
        else if(pi.obte_tipus() == "NOT"){
            Album_en_curs resl,resr;
            recursio(pi.left(),ida,nida,resl);
            Album_en_curs hofcol;
            obten_album(ida,hofcol);
            res.cambiar_id(nida);
            res = Album_en_curs::complementari_album(hofcol,resl); 
        }
       
    }
}



bool Coleccio::evalua_consulta_booleana(Album_en_curs& al,const string& ida,const string& nida,const Arbre &ar){
    map<string,set<string>>::iterator ita = albums.find(ida);
    if(ita != albums.end()){
       
        
        recursio(ar,ida,nida,al);
        al.cambiar_id(nida);
        return true;
    }
    
    else return false;
       
        
    
}




