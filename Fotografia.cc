#include "Fotografia.hh"
using namespace std;

/** @class Fotografia.cc
    @brief Implementació de la classe Fotografia
*/

Fotografia::Fotografia(){}

Fotografia::~Fotografia(){}
  
void Fotografia::crear_foto(const string& id,const data& d){
    data_foto = d;
    this->id = id;
}


void Fotografia::agregar_etiqueta(const string& et){
    set<string>::iterator It = etiquetes.find(et);
    if(It == etiquetes.end()){
        etiquetes.insert(et);
    }
    
}
    
   
void Fotografia::elimina_etiqueta(const string& et){
    set<string>::iterator It = etiquetes.find(et);
    if(It != etiquetes.end()){
        etiquetes.erase(It);
    }
}
    
bool Fotografia::contiene_etiqueta(const string& et) const{
    set<string>::const_iterator It = etiquetes.find(et);
    if (It != etiquetes.end()) return true;
    else return false;
}

string Fotografia::id_foto() const{
    return id;
}
    
   
data Fotografia::fecha_toma() const{
    return data_foto;
}
    
    
int Fotografia::nr_etiquetas() const{
    return etiquetes.size();
}    
  
  
void Fotografia::imprime_foto() const{
    cout << id << ' ';
    cout << data_foto.dia << '/' << data_foto.mes << '/' << data_foto.any << ' ';
    cout << etiquetes.size();
    if(etiquetes.size() > 0){
        set<string>::const_iterator It = etiquetes.begin();
        while(It != etiquetes.end()){
            cout << ' ' << *It;
            ++It;
        }
    }
    cout << endl;
}

void Fotografia::leer_foto(const string& idf){
    data d;
    cin >> d.dia >> d.mes >> d.any;
    crear_foto(idf,d);
    int n_eti;
    cin >> n_eti;
    for(int i = 0; i < n_eti; ++i){
        string eti;
        cin >> eti;
        agregar_etiqueta(eti);
    }
}

bool Fotografia::rangdata(const data& x,const data& ini,const data& fi) const{
    if(comp_data(ini, x) and comp_data(x,fi)) return true;
    else return false;
}
    
bool Fotografia::comp_data(const data& d1, const data& d2) const{
    if(d1.any == d2.any){
        if(d1.mes == d2.mes){
            return d1.dia <= d2.dia;
        }
        else return d1.mes <= d2.mes;
    }
    else return d1.any <= d2.any;
}

