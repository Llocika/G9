//lab- zZuters
/*#include <fstream>
#include <iostream>
using namespace std;

int main ()
{
    fstream fin;
    char c;
    int filesize = 0;
    fin.open ("lab19in.txt", ios::in);
    fin.get (c);
    while (fin)
    {
        filesize++;
        cout << c;
        fin.get (c);
    };
    fin.close ();
    cout << endl << filesize << endl;
    return 0;
}*/



//#include <fstream>
//#include <iostream> 
//using namespace std;
//

/*#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    char c;
    fstream fin("lab19in.txt", ios::in);
    fstream fout("lab19out.txt", ios::out);
    fin.get(c);
    while (fin)
    {
        fout.put(c);
        fin.get(c);
    };
    fin.close();
    fout.close();
    return 0;
}
*/


////






/*1[6]. Programma addLineNumbering, kas pārraksta faila saturu otrā failā, katrai rindai priekšā pieliekot tās kārtas numuru, sākot ar 1. Rindas numuram jābūt ievietotam pirmajās 3 pozīcijās, pielīdzinot labajai pusei, pēc kā jāseko vienam tukšumam, pēc kā seko rindas saturs. Drīkst pieņemt, ka ieejas failā ir mazāk nekā 1000 rindiņu. Piemēram,
*/

//#include <fstream>
//#include <iostream>
//#include <string>
//#include <iomanip>
//using namespace std;
//
//int main()
//{
//   
//    fstream fin("in.txt", ios::in);
//    fstream fout("out.txt", ios::out);
//    string s;
//    getline(fin, s);
//    int it = 1;
//    while (fin)
//    {
//        fout << setw(3) << it <<' '<< s<<'\n';
//        getline(fin, s);
//        it++;
//    };
//    fin.close();
//    fout.close();
//    return 0;
//}









/*B1[6]. Funkcija maxSpaceSequence, kas izskaita, cik gara ir garākā tukšumu virkne. Piemēram ('*' apzīmē tukšumu (' ')), “*alpha*beta***gamma*******delta” → 7*/

//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//
//int countExtraAdjacentSpaces(fstream &fin) {
//    
//    string s;
//    int gar = 0;
//    while (fin) {
//        getline(fin, s, '\n');
//        int skaits = 0;
//        for (int i = 0; i < s.length(); ++i) {
//            if (s[i] == ' ') {
//                skaits = 1;
//                int k = ++i;
//                while (s[k] == ' ' && k < s.length()) {
//                    skaits++;
//                    k++;
//                }
//                if (skaits > gar) {
//                    gar = skaits;
//                }
//            }
//        }
//       
//        return gar;
//    }
//}
//int main(){
//    fstream fin("in.txt", ios::in);
//    
//    if (fin.is_open())
//    {
//        cout<<countExtraAdjacentSpaces(fin);
//        fin.close();
//    }
//}
//


/*B1[5]. Funkcija countExtraAdjacentSpaces, kas izskaita, cik failā ir lieku atkārtotu tukšumu
(katrā tukšumu virknē garumā n ir n-1 lieki atkārtoti tukšumi).
Piemēram (* apzīmē tukšumu), “alpha***beta**gamma” → 3
*/
//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//
//int countExtraAdjacentSpaces(fstream &fin) {
//    int cnt = 0;
//    string s;
//    while (getline(fin, s, '\n')) {
//        for (int i = 1; i < s.length(); ++i) {
//            if (s[i - 1] == ' ' and s[i] == ' ') ++cnt;
//        }
//    }
//    return cnt;
//    
//
//}
//int main() {
//    fstream fin("in.txt", ios::in);
//    
//    if (fin.is_open())
//    {
//        cout<<countExtraAdjacentSpaces(fin);
//        fin.close();
//    }
//}

/*B2[9]. Funkcija removeExtraAdjacentSpaces, kas otrā failā izdrukā faila f tekstu pārveidotu tā, lai tas būtu bez atkārtotiem tukšumiem (vairāku tukšumu virkni aizstājot ar vienu tukšumu).
Piemēram (* apzīmē tukšumu), “*alpha*beta***gamma*******delta” → “*alpha*beta*gamma*delta”
*/
//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//
//
//void removeExtraAdjacentSpaces(ifstream &fin, ofstream &fout) {
//    string s;
//    while (getline(fin, s, '\n')) {
//        string t;
//        if (s.length() > 0)
//        {
//            t += s[0];
//            for (int i = 1; i < s.length(); ++i) {
//                if (s[i - 1] != ' ' or s[i] != ' ') t += s[i]; //ja s[i-1]!=' ', tad s[i] var būt gan tukšums, gan burts -> jāliek
//                //ja s[i-1] ir tukšums, bet s[i]- nav, tad liekam s[i]
//            }
//        }
//        fout << t << endl;
//    }
//    fin.close();
//}
//
//
//
//int main() {
//    ifstream fin("in.txt");
//    ofstream fout("out.txt");
//    //string s;
//    if (fin.is_open())
//    {
//        removeExtraAdjacentSpaces(fin, fout);
//        
//    }
//}
//
//

//int main() {
//    ifstream fin("in.txt");
//    ofstream fout("out.txt");
//    string s;
//    if (fin.is_open())
//    {
//        while (getline(fin, s, '\n')) {
//            string t;
//            if (s.length() > 0)
//            {
//                t += s[0];
//                for (int i = 1; i < s.length(); ++i) {
//                    if (s[i - 1] != ' ' or s[i] != ' ') t += s[i]; //ja s[i-1]!=' ', tad s[i] var būt gan tukšums, gan burts -> jāliek
//                    //ja s[i-1] ir tukšums, bet s[i]- nav, tad liekam s[i]
//                }
//            }
//            fout << t << endl;
//        }
//        fin.close();
//    }
//}
//















/*tikai ar int*/
//int main() {
//    int i;
//    fstream fin("in.txt", ios::in);
//    fin >> i;
//    while (!fin.eof()) {  //faila objekta beigu pārbaude
//        cout << i << endl;
//        fin >> i;
//    };
//    fin.close();
//    return 0;
//}


/*saskaita, cik rindas beizas ar . , ;*/
//#include<string>
//
//int main() {
//	string s;
//	fstream fin("in.txt", ios::in);
//	getline(fin, s);
//	int skaits = 0;
//	while (fin)
//	{
//		if ((s[s.length() - 1]==';')|| (s[s.length() - 1] == ',')|| (s[s.length() - 1] == '.')) {
//			skaits++;
//		}
//		cout << s << endl;
//		getline(fin, s);
//	};
//	cout << skaits << endl;
//	fin.close();
//
//}
/*Saskaitīt, cik ir burtu S*/
//int main()
//
//{
//
//    fstream kk;
//    char c;
//    int filesize = 0;
//    kk.open("lab19in.txt", ios::in);
//    kk.get(c);
//    while (kk) {
//        if (c == 'S') filesize++;
//        kk.get(c); //spēj nolasīt \n simbolu un saglabāt oriģinālo struktūru
//
//    };
//
//    kk.close();
//
//    cout << "S burtu skaits " << filesize << endl;
//
//    return 0;
//
//}
