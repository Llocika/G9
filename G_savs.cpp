
/*
av20099

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

#include <iostream>
#include <stdlib.h>     
#include <time.h>     
using std::cout; using std::endl;  using std::cin;

struct elem
{
    int num;
    elem* next;
};

bool isUnique(elem* pirmais) {
    elem* it1 = pirmais;
    
    for (it1; it1->next != NULL; it1 = it1->next)
    {
        for (elem* it2 =it1->next; it2 != NULL; it2 = it2->next)
            if (it1->num == it2->num) {
                return false;
        }
    };
    return true;

}



void addElem(elem*& pirmais, elem*& pedejais, int i)
{
    elem* p = new elem;
    p->num = i;
    p->next = NULL;
    if (pirmais == NULL) pirmais = p;
    else pedejais->next = p;
    pedejais = p;
};

void printList(elem* pirmais)
{
    for (elem* p = pirmais; p != NULL; p = p->next)
    {
        cout << p->num << " ";
    };
    cout << endl;
};

void delList(elem*& pirmais)
{
    elem* p = pirmais;
    while (p != NULL)
    {
        pirmais = pirmais->next;
        delete p;
        p = pirmais;
    };
}


int main()
{
    srand(time(NULL));
    elem* pirmais = NULL, * pedejais = NULL, * p;
    bool pats = 1;
    cout << "Vai gribat pasi ievadit saraksta elementus? (1-ja, 0-ne)" << endl;
    cin >> pats;
    if (pats) {
        int i;
        cout << "Ievadiet saraksta elementus (0-beigt ievadu):" << endl;
        cin >> i;
        while (i != 0)
        {
            addElem(pirmais, pedejais, i);
            cin >> i;
        };
    }
    else {
        int size;
        cout << "Ievadiet elementu skaitu: " << endl;
        cin >> size;
        while (size < 1) {
            cout << "Elementu skaitam jabut >0. Meginiet velreiz." << endl;
            cin >> size;
        }
        int apRob, augRob, tmp;
        cout << "Ievadiet apaksejo un augsejo robezu (ar astarpi): ";
        cin >> apRob >> augRob;
        if (apRob > augRob) {
            tmp = augRob;
            augRob = apRob;
            apRob = tmp;
        }

        for (int i = 0; i < size; i++) {
            //int el = rand() % augRob + apRob;
            addElem(pirmais, pedejais, rand() % augRob + apRob);   
        }

    }


    printList(pirmais);
    bool ir = isUnique(pirmais);
    if (ir) cout << "Saraksta elementi ir unikaali!" << endl;
    else cout << "Saraksta elementi atkaartojas!" << endl;
    delList(pirmais);
    return 0;


} 

/***************************Testu plāns*******************
izvēlētā opcija         ievads              sagaidāmais rezultāts           faktiskais rezultāts             vai sakrīt?
(1)
pašam ievadīt           11 2 -10 9 2 (0)    Saraksta elementi atkaartojas!  Saraksta elementi atkaartojas!      +
pašam ievadīt           1 2 3 4 5 6 7 (0)   Saraksta elementi ir unikaali!  Saraksta elementi ir unikaali!      +

(0)
izvēlētā opcija          el. skaits          apakš. un augš.robeža      uzģenerētais saraksts       sagaidāmais rezultāts          faktiskais rezultāts        vai sakrīt?
ģenerēt automātiski         5                   0 10                        1 7 4 0 9               El. ir unikaali!              El. ir unikaali!              +
ģenerēt automātiski         10                  1 6                      6 6 5 5 6 5 1 1 5 3        El. atkaartojas!              El. atkaartojas!              +
ģenerēt automātiski         5                   100 15                  56 82 49 15 84              El. ir unikaali!              El. ir unikaali!              +

*/