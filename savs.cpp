

#include <iostream>
#include <stdlib.h>     
#include <time.h>     
using std::cout; using std::endl;  using std::cin;

struct elem
{
    int num;
    elem* next;
};

/*C1[5]. Funkcija deleteAfterLastOdd, kas izdzēš no saraksta skaitli, kas novietots aiz pirmā no labās esošā nepāra skaitļa. 
Piemēram, {2,3,7,4,5}→{2,3,7,4,5}, {2,3,7,4,6}→{2,3,7,6}
*/
//neizmantojot palīgnorādi uz pēdējo elementu
void deleteAfterLastOdd(elem*& first) {
    elem* lastOdd = NULL;
    
    for (elem* p = first; p != NULL; p = p->next)
    {   
        
        if (p->num % 2 == 1) {
            lastOdd = p;
        }
       
    }
    if (lastOdd->next!=NULL) {
        
        elem* tbr = lastOdd->next;
        elem* right = tbr->next;
        delete tbr;
        lastOdd->next = right;
        
    }
    

}


/*
C2[8]. Funkcija deleteLastOdd, kas izdzēš no saraksta pirmo no labās esošo nepāra skaitli. Piemēram, {2,3,7,4,5}→{2,3,7,4}, {2,3,7,4,6}→{2,3,4,6}, {2,4,6,8}→{2,4,6,8}, {1,2,4,6,8}→{2,4,6,8}
*/

void  deleteLastOdd(elem*& first) {
  
    elem* lastOdd = NULL;
    elem* prev = first;
    for (elem* p = first; p != NULL; p = p->next)
    {

        if (p->num % 2 == 1) {
            lastOdd = p;
        }
    }
    for (elem* p = first; p != lastOdd; p = p->next)
    {
        prev = p;
    }
    if (lastOdd!=NULL) {

        prev->next = lastOdd->next;
        delete lastOdd;


    }


}

/*C1[5].Funkcija incOddBeforeEven, kas sarakstā palielina par 1 nepāra skaitļus, kas atrodas pirms pāra skaitļa.Piemēram, { 2,3,7,4,5 }→{ 2,3,8,4,5 }*/
void incOddBeforeEven(elem* first) {
    elem* p = first;
    while (p) {
        if (p->num % 2 == 1) {
            if (p->next!= NULL &&p->next->num%2==0) ++p->num;
            
        }
        p = p->next;
    }
}

/*C2[8].Funkcija eliminateNonAscending, kas, ejot no kreisās uz labo, izmet no saraksta visus elementus, kas ir pretrunā augošai sakārtotai secībai(tādējādi beigās iegūstot sakārtotu virkni).Piemēram, { 2,3,8,4,5,9,3 }→{ 2,3,8,9 }*/
void eliminateNonAscending(elem*& first) {
    for (elem* p = first; p != NULL and p->next != NULL; p = p->next)
    {
        if (p->num >= p->next->num) {
        //    elem* tbr = p->next; //tas, ko mēs dzēsīsim ārā
        //    elem* right = tbr->next;
        //    delete tbr;
        //    p->next = right;

            elem* right = p->next->next;
            delete p->next;
            p->next = right;
        }
    }

}

void remEl(elem*& left) {
    elem* tbr = left->next; //tas, ko mēs dzēsīsim ārā
    elem* right = tbr->next;
    delete tbr;
    left->next = right;

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
    //deleteAfterLastOdd(pirmais);
    //deleteLastOdd(pirmais);
    //incOddBeforeEven(pirmais);
    eliminateNonAscending(pirmais);
    printList(pirmais);



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
