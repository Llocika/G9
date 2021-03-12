/*B1[5]. Funkcija countExtraAdjacentSpaces, kas izskaita, cik failā ir lieku atkārtotu tukšumu (katrā tukšumu virknē garumā n ir n-1 lieki atkārtoti tukšumi).
Piemēram (* apzīmē tukšumu), “alpha***beta**gamma” → 3

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main() {
    fstream fin("in.txt", ios::in);
    int cnt = 0;
    string s;
    if (fin.is_open())
    {
        while (fin) {
            getline(fin, s, '\n');
            for (int i = 1; i < s.length(); ++i) {
                if (s[i - 1] == ' ' and s[i] == ' ') ++cnt;
            }
        }
        cout << cnt << endl;
        fin.close();
    }
}*/
/*B2[9]. Funkcija removeExtraAdjacentSpaces, kas otrā failā izdrukā faila f tekstu pārveidotu tā, lai tas būtu bez atkārtotiem tukšumiem (vairāku tukšumu virkni aizstājot ar vienu tukšumu).
Piemēram (* apzīmē tukšumu), “*alpha*beta***gamma*******delta” → “*alpha*beta*gamma*delta”

#include<iostream>
#include<fstream>
using namespace std;
int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    string s;
    if (fin.is_open())
    {
        while (fin) {
            getline(fin, s, '\n');
            string t;
            if (s.length() > 0)
            {
                t += s[0];
                for (int i = 1; i < s.length(); ++i) {
                    if (s[i - 1] != ' ' or s[i] != ' ') t += s[i];
                }
            }
            fout << t << endl;
        }
        fin.close();
    }
}*/

/*C1[5]. Funkcija incDecOdd, kas sarakstā palielina par 1 negatīvos nepāra skaitļus, bet samazina par 1 pozitīvos nepāra skaitļus. Piemēram, {-2,3,-7,-4,5}→{-2,2,-6,-4,4}

#include<iostream>
using namespace std;
struct elem {
    int num;
    elem* next;
    elem(int n) { num = n; next = NULL; }
};
void print(elem* first) {
    elem* p = first; /// (1)
    while (p) { /// (2)
        cout << p->num << " ";
        p = p->next; /// (3)
    }
    cout << endl;
}
void rem(elem*& first) {
    while (first) {
        elem* p = first->next;
        delete first;
        first = p;
    }
}
void append(elem*& first, elem*& last, int n) {
    elem* p = new elem(n);
    if (first == NULL) {
        first = last = p;
    }
    else {
        last->next = p; /// (1)
        last = p; /// (2)
    }
}
void incDecOdd(elem* first) {
    elem* p = first;
    while (p) {
        if (p->num % 2 != 0) {
            if (p->num < 0) ++p->num;
            else --p->num;
        }
        p = p->next;
    }
}
int main() {
    int aa[] = { -2,3,-7,-4,5 };
    elem* first = NULL, * last;
    for (int i = 0; i < 5; i++) {
        append(first, last, aa[i]);
    }
    print(first);
    incDecOdd(first);
    print(first);
    rem(first);
}

*/
/*

C2[9]. Funkcija deleteFirstEvenBeforeOdd, kas izmet no saraksta pirmo pāra skaitli, kurš atrodas pirms nepāra skaitļa. Piemēram, {2,3,8,4,5}→{3,8,4,5}; {2,4,8,6,5}→{2,4,8,5}; {2,4,8,6,-2}→{2,4,8,6,-2} (nemainās, jo tikai pāra); {1,3,5,9}→{1,3,5,9} (nemainās, jo tikai nepāra)

#include<iostream>
using namespace std;
struct elem {
    int num;
    elem* next;
    elem(int n) { num = n; next = NULL; }
};
void print(elem* first) {
    elem* p = first; /// (1)
    while (p) { /// (2)
        cout << p->num << " ";
        p = p->next; /// (3)
    }
    cout << endl;
}
void rem(elem*& first) {
    while (first) {
        elem* p = first->next;
        delete first;
        first = p;
    }
}
void append(elem*& first, elem*& last, int n) {
    elem* p = new elem(n);
    if (first == NULL) {
        first = last = p;
    }
    else {
        last->next = p; /// (1)
        last = p; /// (2)
    }
}
void deleteFirstEvenBeforeOdd(elem*& first) {
    elem* p = first;
    if (first->num % 2 == 0 and first->next and first->next->num % 2 != 0) {
        first = first->next;
        delete p;
    }
    else if (p->next and p->next->next)
    {
        while (p->next->next) {
            elem* q = p->next;
            elem* r = q->next;
            if (q->num % 2 == 0 and r->num % 2 != 0) {
                p->next = r;
                delete q;
                return;
            }
            p = p->next;
        }
    }
}
int main() {
    {
        int aa[] = { 2,3,8,4,5 };
        elem* first = NULL, * last;
        for (int i = 0; i < 5; i++) {
            append(first, last, aa[i]);
        }
        print(first);
        deleteFirstEvenBeforeOdd(first);
        print(first);
        rem(first);
    }
    {
        int aa[] = { 2,4,8,6,5 };
        elem* first = NULL, * last;
        for (int i = 0; i < 5; i++) {
            append(first, last, aa[i]);
        }
        print(first);
        deleteFirstEvenBeforeOdd(first);
        print(first);
        rem(first);
    }
    {
        int aa[] = { 2,4,8,6,-2 };
        elem* first = NULL, * last;
        for (int i = 0; i < 5; i++) {
            append(first, last, aa[i]);
        }
        print(first);
        deleteFirstEvenBeforeOdd(first);
        print(first);
        rem(first);
    }
    {
        int aa[] = { 1,3,5,9 };
        elem* first = NULL, * last;
        for (int i = 0; i < 4; i++) {
            append(first, last, aa[i]);
        }
        print(first);
        deleteFirstEvenBeforeOdd(first);
        print(first);
        rem(first);
    }
}

*/
/*
D. Uzrakstīt C++ funkciju, kas apstrādā STL list sarakstu no int vērtībām.

D1[5]. (tas pats uzdevums, kas aprakstīts C1)
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
void incDecOdd(list<int>& a) {
    for (auto i = a.begin(); i != a.end(); i++) {
        if (*i % 2 != 0) {
            if (*i < 0)++* i;
            else --* i;
        }
    }
}
void incDecOdd_v2(list<int>& a) {
    for (auto& i : a) {
        if (i % 2 != 0) {
            if (i < 0) ++i;
            else --i;
        }
    }
}
int main() {
    {
        list<int> a = { -2,3,-7,-4,5 };
        print(a);
        incDecOdd(a);
        print(a);
    }
    {
        list<int> a = { -2,3,-7,-4,5 };
        print(a);
        incDecOdd_v2(a);
        print(a);
    }
}

*/

/*

D2[9]. (tas pats, uzdevums kas aprakstīts C2)
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
    {
        list<int> a = { 2,3,8,4,5 };
        print(a);
        deleteFirstEvenBeforeOdd(a);
        print(a);
    }
    {
        list<int> a = { 2,4,8,6,5 };
        print(a);
        deleteFirstEvenBeforeOdd(a);
        print(a);
    }
    {
        list<int> a = { 2,4,8,6,-2 };
        print(a);
        deleteFirstEvenBeforeOdd(a);
        print(a);
    }
    {
        list<int> a = { 1,3,5,9 };
        print(a);
        deleteFirstEvenBeforeOdd(a);
        print(a);
    }
}
*/