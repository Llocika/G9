/*av20099
* 04.03.2021
* STL::list

Abâs realizâcijâs ir jâizveido prasîtâ specifiskâ vçrtîbu virknes apstrâdes funkcija un jânodemonstrç tâ darbîbâ,
cita starpâ parâdot gan sâkotnçjâs, gan rezultçjoðâs vçrtîbas. 
Abâs programmâs:   
  a) jâbût iespçjai ievadît saraksta elementus (izveidot patvaïîgu sarakstu),
  b) jâpielieto uzrakstîtâ funkcija sarakstam,  
  c) jâizdrukâ saraksts pçc funkcijas darbîbas.  
  d) beigâs jâiznîcina saraksts - korekti jâatbrîvo izdalîtâ atmiòa(lietojot delete vai clear).
Sîkâkas prasîbas sk. Laboratorijas darbu noteikumos.
G9. Uzrakstît funkciju, kas pârbauda, vai sarakstâ ir  vismaz divi elementi ar vienâdâm vçrtîbâm.
*/

#include<iostream>
#include<fstream>
#include<list>
#include <stdlib.h>     
#include <time.h>      

using std::cout; using std::endl;  using std::cin; using std::list;

bool isUnique(list <int>& mylist) {
    list<int>::iterator it1, it2;
    it1 = mylist.begin();
    for (it1; it1 != mylist.end(); ++it1) {
        for (it2 = it1; ; ) {
            if (it2 != --mylist.end()) { it2++; }
            else break;
            if (*it1 == *it2) return 0;
            
        }
    } return 1;
}


//template <typename T>
//void print(const list <T>& param) {
//    for (auto& a : param) cout << a << " ";
//    cout << endl;
//}

void print(const list<int>& a) {
    for (auto& i : a) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    srand(time(NULL));
    list<int> mylist;
    int size;
    bool pats = 1;
    cout << "Vai gribat pasi ievadit saraksta elementus? (1-ja, 0-ne)" << endl;
    cin >> pats;
    cout << "Ievadiet elementu skaitu: ";
    cin >> size;
    while (size < 1) {
        cout << "Elementu skaitam jabut >0. Meginiet velreiz." << endl;
        cin >> size;

    }
    if (pats) {
        cout << "Ievadiet " << size << " elementus: ";
        int el;
        for (int i = 0; i < size; i++) {
            cin >> el;
            mylist.push_back(el);
        }

    }
    else {
        int apRob, augRob, tmp;
        cout << "Ievadiet apaksejo un augsejo robezu (ar astarpi): ";
        cin >> apRob >> augRob;
        if (apRob > augRob) {
            tmp = augRob;
            augRob = apRob;
            apRob = tmp;
        }
        
        for (int i = 0; i < size; i++) {

            mylist.push_back(rand()%augRob +apRob);
        }

    }
    bool ir = isUnique(mylist);
    if (ir) cout << "Saraksts sastav no unikaliem elementiem"<<endl;
    else cout << "Saraksta ir duplikati" << endl;
    print(mylist);
    mylist.clear();
}
/***************************Testu plāns*******************
izvēlētā opcija          el. skaits          ievads              sagaidāmais rezultāts           faktiskais rezultāts        vai sakrīt?
(1)
pašam ievadīt               5               11 2 -10 9 2        Saraksta ir duplikati           Saraksta ir duplikati           +
pašam ievadīt               7               1 2 3 4 5 6 7       Saraksts sastav no unikaliem    Saraksts sastav no unikaliem    +
                                                                elementiem                      elementiem
pašam ievadīt               0               -                   El.skaitam jabut>0!             El.skaitam jabut>0!             +
pašam ievadīt               5               0 0 0 0             Saraksta ir duplikati           Saraksta ir duplikati           +

(0)
izvēlētā opcija          el. skaits          apakš. un augš.robeža      uzģenerētais saraksts       sagaidāmais rezultāts          faktiskais rezultāts        vai sakrīt?
ģenerēt automātiski         5                   0 10                        0 7 2 9 8               Sastav no unik.el.              Sastav no unik.el.              +    
ģenerēt automātiski         10                  1 25                 10 6 11 20 12 12 1 1 18 2      Saraksta ir duplikati           Saraksta ir duplikati           +
ģenerēt automātiski         5                   100 15               97 17 87 112 84                Sastav no unik.el.              Sastav no unik.el.              +    

*/