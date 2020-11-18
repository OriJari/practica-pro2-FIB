#include "Fotografia.hh"
#include "Album_en_curs.hh"
#include "Coleccio.hh"
#include "Arbre.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#endif
using namespace std;

int main(){
    
    Album_en_curs alb;
    Coleccio cole;
    string op;
    while(cin >> op and op != "acabar"){    
        
        if(op == "lee_album"){ // 1
            string s;
            cin >> s;
            cout << "# lee_album " << s << " ..." << endl;
            alb.lee_album(s);
            cout << "Album " << s << " leido." << endl;
        }
        
        else if(op == "agrega_foto"){ // 2
            string s;
            cin >> s;
            cout << "# agrega_foto " << s << " ..." << endl;
            if(alb.agrega_foto(s)) cout << "Foto " << s << " agregada al album en curso."; 
            else cout << "El album en curso ya contiene una foto con el identificador " << s;
            cout << endl;
        }
        
        else if(op == "elimina_foto"){ // 3
            string s;
            cin >> s;
            cout << "# elimina_foto " << s << endl;
            if(not alb.elimina_foto(s)) cout << "El album en curso no contiene una foto con el identificador " << s << endl;
            else cout << "Foto " << s << " eliminada del album en curso." << endl;
        }
        
        else if(op == "obten_foto"){ // 4
            string s;
            cin >> s;
            cout << "# obten_foto " << s << endl;
            if(not alb.obten_foto(s)) cout << "El album en curso no contiene una foto con el identificador " << s << endl;
        }
        
        else if(op == "nr_fotos"){ // 5
            cout << "# nr_fotos" << endl;
            cout << alb.nr_foto() << endl;
        }
        
        else if(op == "agrega_album"){ // 6
            cout << "# agrega_album" << endl;
            cole.agrega_album(alb);
            
        }
        
        else if(op == "elimina_album"){ // 7
            string s;
            cin >> s;
            cout << "# elimina_album " << s << endl;
            if(cole.elimina_album(s)) cout << "Album eliminado de la coleccion." << endl;
            else cout << "Identificador de album incorrecto. No se puede eliminar." << endl;
        }
        
        else if(op == "obten_album"){ // 8
            string s;
            cin >> s;
            cout << "# obten_album " << s << endl;
            if(cole.obten_album(s,alb)){
                alb.imprime_album();
            }
            else cout << "No existe un album con el id dado." << endl;
        }
        
        else if(op == "nr_albums"){ // 9
            cout << "# nr_albums" << endl;
            cout << cole.nr_albumes() << endl;
        }
        
        else if(op == "lista_albumes"){ // 10
            cout << "# lista_albumes" << endl;
            cole.lista_albumes();
            
        }
        
        else if(op == "agrega_foto_coleccion"){ // 11
            string s;
            cin >> s;
            cout << "# agrega_foto_coleccion " << s << " ..." << endl;
            if(cole.agrega_foto(s)) cout << "Foto " << s << " agregada a la coleccion."; 
            else cout << "Ya existe una foto con el mismo id. No se puede agregar.";
            cout << endl;
        }
        
        else if(op == "elimina_foto_coleccion"){ // 12
            string s;
            cin >> s;
            cout << "# elimina_foto_coleccion " << s << endl;
            if(cole.elimina_foto(s)) cout << "Foto " << s << " eliminada de la coleccion.";
            else cout << "No existe una foto con el id dado. No se puede eliminar.";
            cout << endl;
            
        }
        
        else if(op == "modifica_foto_coleccion"){ // 13 
            string s;
            cin >> s;
            cout << "# modifica_foto_coleccion " << s << " ..." << endl;
            if(cole.modifica_foto(s)) cout << "Foto " << s << " modificada en la coleccion.";
            else cout << "No existe una foto con el id dado. No se puede modificar.";
            cout << endl;
        }
        
        else if(op == "albumes_foto"){ // 14
            
            string s;
            cin >> s;
            cout << "# albumes_foto " << s << endl;
            
            cole.lista_albumes_foto(s);
        }
        
        else if(op == "busca_por_fecha"){ // 15 
            data d1, d2;
            string ida, nida;
            cin >> d1.dia >> d1.mes >> d1.any >> d2. dia >> d2.mes >> d2.any;
            cin >> ida >> nida;
            cout << "# busca_por_fecha " << d1.dia << '/' << d1.mes << '/'<< d1.any << '-';
            cout << d2.dia << '/' << d2.mes << '/' << d2.any << ' ' << ida << ' ' << nida << endl;
            if(cole.busca_por_fecha(d1,d2,ida,nida,alb)) alb.imprime_album();
            else cout << "No existe un album con el id dado." << endl;
        }
        
        else if(op == "busca_por_etiqueta"){ // 16 
            string et, ida, nida;
            cin >> et >> ida >> nida;
            cout << "# busca_por_etiqueta " << et << ' ' << ida << ' ' << nida << endl;
            if(cole.busca_por_etiqueta(et, ida, nida, alb)) alb.imprime_album();
            else cout << "No existe un album con el id dado." << endl;
        }
        
        else if(op == "evalua_consulta_booleana"){ // 17 
            string ida, ida_resul;
            Arbre ar;
            cin >> ida >> ida_resul ;
            ar.read(cin);
            cout << "# evalua_consulta_booleana " << ida << " " << ida_resul << endl;
            cout << "# BEGIN_QUERY ... END_QUERY"<< endl;
            if(cole.evalua_consulta_booleana(alb,ida,ida_resul,ar)){
                alb.imprime_album();
            }
            else cout << "No existe un album con el id dado." << endl;   
        }
        
        else if(op == "imprime_album_en_curso"){ // 18
             cout << "# imprime_album_en_curso" << endl;
            alb.imprime_album();
        }
        
        else if(op == "imprime_coleccion"){ // 19
            cout << "# imprime_coleccion" << endl;
            cole.imprime_coleccion();
        }
        
    }
}
