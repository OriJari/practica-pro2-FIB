#include "Arbre.hh"
using namespace std;

/** @class Arbre.cc
    @brief Implementació de la classe Arbre
*/

Arbre::Arbre(){}

Arbre::~Arbre(){}

Arbre::Arbre(const string&s){
    token tk;
    tk.tipo = "TAG";
    tk.etq = s;
    tri = BinTree<token>(tk);
    
}
Arbre::Arbre(const data& inici, const data& fi){
    token tk;
    tk.tipo = "DATE";
    tk.fini = inici;
    tk.ffin = fi;
    tri = BinTree<token>(tk);
}
 
    
Arbre Arbre::NOT(){
    Arbre ar;
    token tk;
    tk.tipo = "NOT";
    BinTree<token> x;
    ar.tri = BinTree<token>(tk,tri,x);
    return ar;
}
Arbre Arbre::AND(const Arbre& q2){
    Arbre ar;
    token tk;
    tk.tipo = "AND";
    ar.tri = BinTree<token>(tk,tri,q2.tri);
    return ar;
}
Arbre Arbre::OR(const Arbre& q2){
    Arbre ar;
    token tk;
    tk.tipo = "OR";
    ar.tri = BinTree<token>(tk,tri,q2.tri);
    return ar;
}

string toupper(const string& s) {
    string res = "";
    for (int i = 0; i < s.length(); ++i)
        res += toupper(s[i]);
    return res;
}

int precedence(string oper) {
    if (oper == "OR") return 1;
    if (oper == "AND") return 2;
    if (oper == "NOT") return 3;
    return 0;
}


void convert_infix_to_postfix(const vector<token>& infix, vector<token>& postfix) {
    stack<token> S;
    token spc; spc.tipo = "#"; S.push(spc);
    for (int i = 0; i < infix.size(); ++i) {
        token tk = infix[i];
        if (tk.tipo == "DATE" or tk.tipo == "TAG")
            postfix.push_back(tk);
        else if (tk.tipo == "(" or tk.tipo == "NOT") 
            S.push(tk);
        else if (tk.tipo == ")") {
            while (S.top().tipo != "#" and S.top().tipo != "(") {
                postfix.push_back(S.top()); S.pop();
            }
            S.pop();
        } else {
            while (S.top().tipo != "#" and 
                precedence(tk.tipo) <= precedence(S.top().tipo)) {
                    postfix.push_back(S.top()); S.pop();
            }
            S.push(tk);
        }
    }
    while (S.top().tipo != "#") {
        postfix.push_back(S.top()); S.pop();
    } 
}
    
Arbre construct_bool_query(const vector<token>& postfix) {
    stack<Arbre> S;
    for (int i = 0; i < postfix.size(); ++i) {
        token tk = postfix[i];
        
        if (tk.tipo == "TAG") S.push(Arbre(tk.etq)); // apila una consulta TAG
        if (tk.tipo == "DATE") S.push(Arbre(tk.fini, tk.ffin)); // apila una consulta DATE
        if (tk.tipo == "AND" or tk.tipo == "OR") {
            Arbre q2 = S.top(); S.pop();
           
            Arbre q1 = S.top(); S.pop();
            
            
            if (tk.tipo == "AND") S.push(q1.AND(q2)); // apila una consulta 'q1 and q2'
            if (tk.tipo == "OR") S.push(q1.OR(q2)); // apila una consulta 'q1 or q2'
        }
        if (tk.tipo == "NOT") {
            Arbre q = S.top(); S.pop(); 
            S.push(q.NOT()); // apila una consulta 'not q'
        }
    }
    return S.top();
}
 


    
void Arbre::read(istream& is) {
    vector<token> infix, postfix;
  
    read_input(is, infix);
    
    if (infix.empty()) { 
        *this = Arbre(); 
        return; 
    }
 
    
    convert_infix_to_postfix(infix, postfix);
  
    
    *this = construct_bool_query(postfix);
}
 
    
void Arbre::read_input(istream& is, vector<token>& l) {
    string s; 
    is >> s; 
    while (s != "END_QUERY") {
        token tk;
        s = toupper(s);
        tk.tipo = s;
        if (s == "(" or s == ")" or s == "AND" or s == "OR" or s == "NOT") { 
            l.push_back(tk);
        }
        if (s == "DATE") { /** usad el metodo Fecha::llegir() o similar si no teneis
                            sobrecargado el operador >> para leer fechas **/
            is >> tk.fini.dia >> tk.fini.mes >> tk.fini.any;
            is >> tk.ffin.dia >> tk.ffin.mes >> tk.ffin.any;
            l.push_back(tk); // me lo havia dejaaoooo
        }
        if (s == "TAG") {
            is >> tk.etq;
            l.push_back(tk);
        }      
        is >> s;
    }
}    


    
bool Arbre::empty() const{
     return tri.empty();
}
    
Arbre Arbre::left() const{
    Arbre a;
    a.tri = tri.left();
    return a;
}

Arbre Arbre::right() const{
    Arbre a;
    a.tri = tri.right();
    return a;
}

bool Arbre::es_fulla() const{
    if(tri.left().empty() and tri.right().empty()) return true;
    else return false;
    
}

string Arbre::obte_tipus() const{
    string s;
    s = tri.value().tipo;
    return s;
}

string Arbre::obte_tag() const{
    string s;
    s = tri.value().etq;
    return s;
    
}

data Arbre::obte_ini() const{
    data d;
    d = tri.value().fini;
    return d;
}

data Arbre::obte_fi() const{
    data d;
    d = tri.value().ffin;
    return d;
}





istream& operator>>(istream& is, Arbre& q) {
   q.read(is);
  return is;
}

