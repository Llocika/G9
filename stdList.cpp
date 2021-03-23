/*d*/

#include<iostream>
#include<fstream>
#include<list>
using namespace std;
void print(const list<int>& a) {
    for (auto& i : a) {
        cout << i << " ";
    }
    cout << endl;
}

/*/*C1[5]. Funkcija deleteAfterLastOdd, kas izdzēš no saraksta skaitli, kas novietots aiz pirmā no labās esošā nepāra skaitļa.
Piemēram, {2,3,7,4,5}→{2,3,7,4,5}, {2,3,7,4,6}→{2,3,7,6}
*/
void deleteAfterLastOdd(list<int>& a) {
    auto k = a.begin();
    bool irOdd = 0;
    auto lastOdd = a.begin();
    ++k;
    for (auto i = a.begin(); k != a.end(); i++, k++) {
        if (*i % 2 == 1) {
            irOdd = 1;
            lastOdd = i;

        }
    }
    if (irOdd) {
        ++lastOdd;
        a.erase(lastOdd);
    }
}

/*
C2[8]. Funkcija deleteLastOdd, kas izdzēš no saraksta pirmo no labās esošo nepāra skaitli. Piemēram, {2,3,7,4,5}→{2,3,7,4}, {2,3,7,4,6}→{2,3,4,6}, {2,4,6,8}→{2,4,6,8}, {1,2,4,6,8}→{2,4,6,8}
*/

void deleteLastOdd(list<int>& a) {
    auto k = a.begin();
    bool irOdd = 0;
    auto lastOdd = a.begin();
    
    for (auto i = a.begin(); i != a.end(); i++) {
        if (*i % 2 == 1) {
            irOdd = 1;
            lastOdd = i;

        }
    }
    if (irOdd) {
        a.erase(lastOdd);
    }
}
/*C1[5].Funkcija incOddBeforeEven, kas sarakstā palielina par 1 nepāra skaitļus, kas atrodas pirms pāra skaitļa.Piemēram, { 2,3,7,4,5 }→{ 2,3,8,4,5 }*/

void incOddBeforeEven(list<int>& a) {
    auto k = a.begin();
    ++k;
    for (auto i = a.begin(); k != a.end(); i++, k++) {
        if (*i % 2 == 1 and *k % 2 == 0) {
            (*i)++;
            
        }
    }
}

/*C2[8].Funkcija eliminateNonAscending, kas, ejot no kreisās uz labo, izmet no saraksta visus elementus, kas ir pretrunā augošai sakārtotai secībai(tādējādi beigās iegūstot sakārtotu virkni).
Piemēram, { 2,3,8,4,5,9,3 }→{ 2,3,8,9 }*/


void eliminateNonAscending(list<int>& mylist) {
    auto it = mylist.begin();
    int max = *it;
    it++;
    for (; it != mylist.end(); it++) {

        if (*it <= max) {
            it = mylist.erase(it);
            it--;
        }
        else {
            max = *it;
        }
    }
}


/*void eliminateNonAscending(list<int>& a) {
    auto k = a.begin();
    ++k;
    for (auto i = a.begin(); k != a.end(); i++, k++) {
        if (*i >= *k ) {
            a.erase(k);
            
            if (i != --a.end()) {
                k = i;
                k++;
            }
            else break;
        }
    }
}

*/


void deleteFirstEvenBeforeOdd(list<int>& a) {
    auto k = a.begin();
    ++k;
    for (auto i = a.begin(); k != a.end(); i++, k++) {
        if (*i % 2 == 0 and *k % 2 != 0) {
            a.erase(i);
            return;
        }
    }
}
int main() {

    //list<int> a = { 2,3,7,4,6 };
    //list<int> a = { 2, 3, 7, 4, 5 };
    //list<int> a = { 2,3,8,4,5,9,3 };
    list<int> a = { 2,3,5,3,2,1};

    print(a);
    //deleteAfterLastOdd(a);
    //deleteLastOdd(a);
    //incOddBeforeEven(a);
    eliminateNonAscending(a);
    print(a);


}
