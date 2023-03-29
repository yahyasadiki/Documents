#include <iostream>
#include <string>
using namespace std;

class Documents{
    string titre;
    float prix;
    int codeD;
    static int code;
public:
    Documents(){}
    Documents(string t, float p ){
        this->titre = t;
        this->prix = p;
        code ++;
        this->codeD = code;
    };

    const string &getTitre() const {
        return titre;
    }

    float getPrix() const {
        return prix;
    }
    static const int getCode (){
        return code;
    }

    void setTitre(const string &titre) {
        this->titre = titre;
    }

    void setPrix(float prix) {
        this->prix = prix;
    }
    void setcode(int code){
        this->code = code;
    }
    void afficher(){
        cout << "titre :" << titre << endl << "prix :" << prix << endl << codeD <<endl;
    }
    Documents operator==( Documents &d){
        if(codeD == d.codeD ){
            cout << "egaux";
        }
        else{
            cout << "non egaux";
        }
    }
    Documents operator<( Documents &d){
        if(prix < d.prix ){
            cout << "gauche est inferieur";
        }
        if(prix > d.prix ){
            cout << "gauche est superieur";
        }
        if(prix == d.prix ){
            cout << "egaux";
        }
    }
    void solder(float promotion){
        prix = prix - promotion;
        cout << "le nouveau prix est :" << prix << endl;
    }
    friend ostream &operator<<(ostream &out, const Documents &documents) {
        out << "titre: " << documents.titre << " prix: " << documents.prix << " codeD: " << documents.codeD;
        return out;
    }
};
class livre: public Documents{
    string autheur;
    int pages;
public:
    livre(string a, int pa, string t, float p ){
        autheur = a; pages =pa;
        setTitre(t);
        setPrix(p);
        setcode(getCode()+1);
    }

    friend ostream &operator<<(ostream &out, livre &livre);
};
  ostream &operator<<(ostream &out, livre &livre) {
  out << "titre:" << livre.getTitre() << " prix: " << livre.pages<< " autheur: " << livre.autheur << " pages: " << livre.pages;
  return out;}

class dictionnaire: private Documents{
    string langue;
    int nombredetomes;
public:
    dictionnaire(string t, float p , string l, int n){
        setTitre(t);
        setPrix(p);
        langue = l; nombredetomes = n;
        setcode(getCode()+1);

    }
    friend ostream &operator<<(ostream &out, dictionnaire &d);
};
ostream &operator<<(ostream &out, dictionnaire &dictionnaire){
    out<< "titre :" << dictionnaire.getTitre() << endl
    << "prix: " << dictionnaire.getPrix() <<"dhs"<< endl
    << "langue: " << dictionnaire.langue << endl
    << "nbr : " << dictionnaire.nombredetomes <<endl
    << "code :" << dictionnaire.getCode() <<endl;
    return out;
}


  int Documents::code = 0;
int main() {
//    livre l1("kbjl.", 30, "rihab", 12);
//    cout << l1;
      dictionnaire d1("Larousse", 350, "francais", 3);
      cout << d1;





    return 0;
}
