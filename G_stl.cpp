/*av20099
* 04.03.2021
* STL::list

Ab�s realiz�cij�s ir j�izveido pras�t� specifisk� v�rt�bu virknes apstr�des funkcija un j�nodemonstr� t� darb�b�,
cita starp� par�dot gan s�kotn�j�s, gan rezult�jo��s v�rt�bas. 
Ab�s programm�s:   
  a) j�b�t iesp�jai ievad�t saraksta elementus (izveidot patva��gu sarakstu),
  b) j�pielieto uzrakst�t� funkcija sarakstam,  
  c) j�izdruk� saraksts p�c funkcijas darb�bas.  
  d) beig�s j�izn�cina saraksts - korekti j�atbr�vo izdal�t� atmi�a(lietojot delete vai clear).
S�k�kas pras�bas sk. Laboratorijas darbu noteikumos.
G9. Uzrakst�t funkciju, kas p�rbauda, vai sarakst� ir  vismaz divi elementi ar vien�d�m v�rt�b�m.


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