#include <iostream>
using namespace std;
/*
Ab�s realiz�cij�s ir j�izveido pras�t� specifisk� v�rt�bu virknes apstr�des funkcija un j�nodemonstr� t� darb�b�,
cita starp� par�dot gan s�kotn�j�s, gan rezult�jo��s v�rt�bas. 
Ab�s programm�s:   
  a) j�b�t iesp�jai ievad�t saraksta elementus (izveidot patva��gu sarakstu),
  b) j�pielieto uzrakst�t� funkcija sarakstam,  
  c) j�izdruk� saraksts p�c funkcijas darb�bas.  
  d) beig�s j�izn�cina saraksts - korekti j�atbr�vo izdal�t� atmi�a(lietojot delete vai clear).
S�k�kas pras�bas sk. Laboratorijas darbu noteikumos.
G9. Uzrakst�t funkciju, kas p�rbauda, vai sarakst� ir  vismaz divi elementi ar vien�d�m v�rt�b�m.
*/



struct elem
{
    int num;
    elem* next;
};

bool isUnique(elem* first) {
    elem* it1 = first;
    //elem* it2 = first;
    
    for (it1; it1->next != NULL; it1 = it1->next)
    {
        for (elem* it2 =it1->next; it2 != NULL; it2 = it2->next)
            if (it1->num == it2->num) {
                return false;
        }
    };
    return true;

}



void add_element(elem*& first, elem*& last, int i)
{
    elem* p = new elem;
    p->num = i;
    p->next = NULL;
    if (first == NULL) first = p;
    else last->next = p;
    last = p;
};

void print_list(elem* first)
{
    for (elem* p = first; p != NULL; p = p->next)
    {
        cout << p->num << endl;
    };
};

void delete_list(elem*& first)
{
    elem* p = first;
    while (p != NULL)
    {
        first = first->next;
        delete p;
        p = first;
    };
}


int main()
{
    elem* first = NULL, * last = NULL, * p;
    int i;
    cin >> i;
    while (i != 0)
    {
        add_element(first, last, i);
        cin >> i;
    };
    print_list(first);
    bool ir = isUnique(first);
    if (ir) cout << "Ir unikals!" << endl;
    else cout << "Nav unikals!" << endl;
    delete_list(first);
    return 0;
}









///*Ab�s realiz�cij�s ir j�izveido pras�t� specifisk� v�rt�bu virknes apstr�des funkcija un j�nodemonstr� t� darb�b�,
//cita starp� par�dot gan s�kotn�j�s, gan rezult�jo��s v�rt�bas.
//Ab�s programm�s :
//a) j�b�t iesp�jai ievad�t saraksta elementus(izveidot patva��gu sarakstu),
//b) j�pielieto uzrakst�t� funkcija sarakstam,
//c) j�izdruk� saraksts p�c funkcijas darb�bas.
//d) beig�s j�izn�cina saraksts - korekti j�atbr�vo izdal�t� atmi�a(lietojot delete vai clear).
//S�k�kas pras�bas sk.Laboratorijas darbu noteikumos.
//G9.Uzrakst�t funkciju, kas p�rbauda, vai sarakst� ir  vismaz divi elementi ar vien�d�m v�rt�b�m.*/
//#include<iostream>
//using namespace std;
//struct elem {
//    int num;
//    elem* next;
//    elem(int n) { num = n; next = NULL; }
//};
//void print(elem* first) {
//    elem* p = first; /// (1)
//    while (p) { /// (2)
//        cout << p->num << " ";
//        p = p->next; /// (3)
//    }
//    cout << endl;
//}
//void rem(elem*& first) {
//    while (first) {
//        elem* p = first->next;
//        delete first;
//        first = p;
//    }
//}
//void append(elem*& first, elem*& last, int n) {
//    elem* p = new elem(n);
//    if (first == NULL) {
//        first = last = p;
//    }
//    else {
//        last->next = p; /// (1)
//        last = p; /// (2)
//    }
//}
//void deleteFirstEvenBeforeOdd(elem*& first) {
//    elem* p = first;
//    if (first->num % 2 == 0 and first->next and first->next->num % 2 != 0) {
//        first = first->next;
//        delete p;
//    }
//    else if (p->next and p->next->next)
//    {
//        while (p->next->next) {
//            elem* q = p->next;
//            elem* r = q->next;
//            if (q->num % 2 == 0 and r->num % 2 != 0) {
//                p->next = r;
//                delete q;
//                return;
//            }
//            p = p->next;
//        }
//    }
//}
//int main() {
//    {
//        int size;
//        cout << "Ievadiet elementu skaitu: ";
//        cin >> size;
//        cout << "Ievadiet " << size << " elementus: ";
//        int* arr = new int[size];
//        int el;
//        cin >> el;
//        arr[0] = el;
//        //int arrSize = sizeof(arr)/sizeof(arr[0]);
//        for (int i = 1; i < size; i++) {
//            cin >> el;
//            arr[i] = el;
//
//
//        }
//        for (int i = 0; i < size; i++) {
//            mylist.push_back(arr[i]);
//
//        }
//
//
//
//
//
//
//        int aa[] = { 2,3,8,4,5 };
//        elem* first = NULL, * last;
//        for (int i = 0; i < 5; i++) {
//            append(first, last, aa[i]);
//        }
//        print(first);
//        deleteFirstEvenBeforeOdd(first);
//        print(first);
//        rem(first);
//    }
//    {
//        int aa[] = { 2,4,8,6,5 };
//        elem* first = NULL, * last;
//        for (int i = 0; i < 5; i++) {
//            append(first, last, aa[i]);
//        }
//        print(first);
//        deleteFirstEvenBeforeOdd(first);
//        print(first);
//        rem(first);
//    }
//    {
//        int aa[] = { 2,4,8,6,-2 };
//        elem* first = NULL, * last;
//        for (int i = 0; i < 5; i++) {
//            append(first, last, aa[i]);
//        }
//        print(first);
//        deleteFirstEvenBeforeOdd(first);
//        print(first);
//        rem(first);
//    }
//    {
//        int aa[] = { 1,3,5,9 };
//        elem* first = NULL, * last;
//        for (int i = 0; i < 4; i++) {
//            append(first, last, aa[i]);
//        }
//        print(first);
//        deleteFirstEvenBeforeOdd(first);
//        print(first);
//        rem(first);
//    }
//}
