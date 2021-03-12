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


#include<iostream>
#include<fstream>
#include<list>
using namespace std;

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


template <typename T>
void print(const list <T>& param) {
    for (auto& a : param) cout << a << " ";
    cout << endl;
}

//void print(const list<int>& a) {
 //   for (auto& i : a) {
   //     cout << i << " ";
    //}
    //cout << endl;
//}

int main() {
    list<int> mylist;
    int size;
    cout << "Ievadiet elementu skaitu: ";
    cin >> size;
    cout << "Ievadiet " << size << " elementus: ";
    int* arr = new int[size];
    int el;
    cin >> el;
    arr[0] = el;
    //int arrSize = sizeof(arr)/sizeof(arr[0]);
    for (int i = 1; i< size; i++) {
        cin >> el;
        arr[i] = el;
        

    }
    for (int i = 0; i < size; i++) {
        mylist.push_back(arr[i]);

    }
    bool ir = isUnique(mylist);
    if (ir) cout << "Saraksts sastav no unikaliem elementiem"<<endl;
    else cout << "Saraksta ir duplikati" << endl;
    //list<int> a = { 2,3,8,4,5 };
    print(mylist);
    delete [] arr;
    mylist.clear();
}
*/