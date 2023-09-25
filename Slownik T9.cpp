#include <iostream>

using namespace std;

// Wezel standardowego drzewa TRIE do zapamietania wejscia leksykograficznie (oraz do poddrzew zmodyfikowanego drzewa - patrz nizej)

struct Wezel{
    struct Wezel *syn[26];
    int kl=0;
    bool koniec;
};

// Wezel zmodyfikowanego drzewa TRIE do zapamietania wyrazow (w poddrzewie - standardowym TRIE) wg kodow T9 tych wyrazow)

struct kod{
    struct kod *syn[10];
    bool koniec;
    struct Wezel *trie = nullptr;
};

/***************************************************************************************************************************************/

//Funkcja tworzaca nowy wezel standardowego drzewa TRIE

struct Wezel *utworz(){
    struct Wezel *nowy = new Wezel;
    nowy->koniec = false;
    for (int i=0; i<26; i++ )
        nowy->syn[i] =  nullptr;
    return nowy;
};
/***************************************************************************************************************************************/

//Funkcja tworzaca nowy wezel zmodyfikowanego drzewa TRIE

struct kod *utworz_kod(){
    struct kod *nowy = new kod;
    nowy->koniec = false;
    for (int i=0; i<10; i++ )
        nowy->syn[i] =  nullptr;
    return nowy;
};
/***************************************************************************************************************************************/

//Funkcja dodajaca wejsciowy wyraz do podstawowego drzewa TRIE wyrazow wejsciowych (oraz dodajaca wyrazy do poddrzew)

void dodaj_text_do_korz (struct Wezel *korzen,char *slowo){
    struct Wezel *idz = korzen;
        int i = 0;
        while (slowo[i] != '\0'){
            int index = slowo[i] - 'a';
            if (idz->syn[index] == nullptr)
                idz->syn[index] = utworz();
            idz = idz->syn[index];
            i++;
        }
        idz->koniec = true;
}
/***************************************************************************************************************************************/

//  Funkcja zamieniajaca wyrazy/slowa na ich kod T9 oraz dodajaca te wyrazy do poddrzewa (czyli standardowego drzewa TRIE)
//  nalezacego do wezla zmodyfikowanego drzewa TRIE (utworzonego z kodow T9), funkcja kroczy w zmodyfikowanym drzewie (czasem tworzy wezly -
//  do tworzenia wykorzystuje funkcje - utworz_kod)wg wlasnie obliczonego kodu (mozna skorzystac z kodu zapytania - bedzie latwiej))
//  po czym na koniec dodaje ten wyraz/slowo do odpowiedniego poddrzewa (do dodania wykorzystuje funkcje dodaj_text_do_korz)
// (wykorzystuje funkcje dodaj_text_do_korz)

void dodaj2 (struct kod *root,char *slowo, int licznik){
    struct kod *idz = root;
        int i = 0;
        char kodo[101];
        while (slowo[i] != '\0'){

            int index = slowo[i] - 'a';
            int t9;


            if ((index <3)&& (index >=0))     t9=2;
            if ((index <6) && (index >2))     t9=3;
            if ((index <9) && (index >5))     t9=4;
            if ((index <12) && (index >8))    t9=5;
            if ((index <15) && (index >11))   t9=6;
            if ((index <19) && (index >14))   t9=7;
            if ((index <22) && (index >18))   t9=8;
            if ((index >21))                  t9=9;

            kodo[i]=t9+'0';
            i++;
        }

        kodo[i]='\0';
        i=0;

        while (slowo[i] != '\0'){
               int t9=kodo[i]-'0';

               if (idz->syn[t9] == nullptr)
                      idz->syn[t9] = utworz_kod();

               idz=idz->syn[t9];
               i++;
               continue;
        }
        idz->koniec = true;
        if (idz->trie == nullptr) idz->trie = utworz();
        dodaj_text_do_korz(idz->trie,slowo);
}
/***************************************************************************************************************************************/

//Funkcja sprawdzajaca czy wezel standarodwego drzewa TRIE jest wezlem w ktorym nastepuje koniec wyrazu - chyba z niej nie korzystam

bool czy_koniec_slowa(struct Wezel *korzen){
        if (korzen->koniec == true) return true ;
        else return false;
}
/***************************************************************************************************************************************/

//  Funkcja przeszukujaca standardowe drzewo TRIE wyrazow wejsciowych i dodajaca (funkcja dodaj2) wszystkie wyrazy spelniajace zapytanie
//  do zmodyfikowanego drzewa TRIE

void root_dodaj(struct Wezel *korzen,kod *root, char *slowo, int kolej_znak, int licznik){
    if (czy_koniec_slowa(korzen) == true){
        slowo[kolej_znak] = '\0';
        dodaj2(root,slowo,licznik);
    }
    for (int i=0; i<26; i++){
           if (korzen->syn[i] != nullptr){
                slowo[kolej_znak] = 'a' + i;
                root_dodaj(korzen->syn[i], root, slowo, kolej_znak+1,licznik);
           }
    }
    return;
}
/***************************************************************************************************************************************/

//Funkcja ktora wyswietla standardowe drzewo TRIE (uzywana do wyswietlania poddrzew nalezacych do wezlow zmodyfikowanego drzewa TRIE)

void displa(struct Wezel *korzen, char *slowo, int kolej_znak){
    if (czy_koniec_slowa(korzen) == true){
        slowo[kolej_znak] = '\0';
        cout << slowo<<" ";
    }
    for (int i=0; i<26; i++){
           if(korzen->syn[i] != nullptr){
              slowo[kolej_znak] = 'a'+i;
              displa(korzen->syn[i],slowo,kolej_znak+1);
           }
    }
}
/***************************************************************************************************************************************/

//Funkcja kroczaca do wszystkich poddrzew wezlow nalezacych do zmodyfikowanego drzewa trie (zaczynajac od wezla wprowadzonego do funkcji)
// a nastepnie wyswietlajaca wszystkie poddrzewa (uzywa do tego funcji - displa)

void displa2(struct kod *korzen, char *slowo, int kolej_znak){
    if (korzen->koniec == true){
        char dis[101];
        displa(korzen->trie,dis,0);
    }
    for (int i=2; i<10; i++){
           if(korzen->syn[i] != nullptr){
              displa2(korzen->syn[i],slowo,0);
           }
    }
}
/***************************************************************************************************************************************/
void kasuj2(struct kod *korzen){
    if (korzen->koniec == true){
        delete korzen->trie;
    }
    for (int i=2; i<10; i++){
           if(korzen->syn[i] != nullptr){
              kasuj2(korzen->syn[i]);
           }
    }
}

/***************************************************************************************************************************************/

// Funkcja odnajdujaca wezel zmodyfikwanego drzewa TRIE ktory spelnia zapytanie wejsciowe po czym wyswietla wszsytkie wyrazy = kodowi T9
// zapytanie wejsciowego (uzywa do tego funkcji displa2), jesli szukany wezel nie istnieje to wyswietla " - "

void pokaz(struct kod *korzen, char *slowo, int kolej_znak, char *zap, int licznik){

    kod *temp;
    temp=korzen;
    for (int i=0; i<licznik; i++){
        int j = zap[i]-'0';
        if (temp->syn[j] == nullptr){
            cout<<"-";
            return;
        }
        temp=temp->syn[zap[i]-'0'];
    }
    displa2(temp,slowo,0);
}

/***************************************************************************************************************************************/

// Funkcja odnajdujaca wszystkie wyrazy w standardowym drzewie TRIE wyrazow wejsciowych, te wyrazy ktorych kod T9 jest rowny zapytaniu)
// oraz dodajaca te wyrazy do zmodyfikowanego drzewa TRIE (uzywa do tego funkcji root_dodaj)

void sprawdz(struct Wezel *korzen, struct kod *root, char *zap, int i, int licznik, char *aslo){
      if (korzen == nullptr) return ;
      struct Wezel *temp = korzen;

      int start = 0;
      int koniec = 0;
      int zak = zap[i]-'0';

      switch (zak){
          case 2:
                start = 0;
                koniec = 2;
              break;
          case 3:
                start = 3;
                koniec = 5;
              break;
           case 4:
                start = 6;
                koniec = 8;
              break;
           case 5:
                start = 9;
                koniec = 11;
              break;
           case 6:
                start = 12;
                koniec = 14;
              break;
          case 7:
                start = 15;
                koniec = 18;
              break;
           case 8:
                start = 19;
                koniec = 21;
              break;
           case 9:
                start = 22;
                koniec = 25;
              break;
           }

          for (int j = start ; j <= koniec; j++){
               if ((temp->syn[j] != nullptr) && (i != licznik-1)) {
                  aslo[i] = 'a' + j;
                  sprawdz(temp->syn[j],root,zap,i+1,licznik,aslo);
               }
               if ((temp->syn[j] != nullptr) && (i == licznik-1)) {
                     aslo[i] = 'a' + j;
                     root_dodaj(temp->syn[j],root,aslo,i+1,licznik);
                     if (j!=koniec)
                         continue;
                     if (j==koniec)
                         return;
               }
           }
return ;
}

/***************************************************************************************************************************************/
int main()
{
    int n,m;
    char zap[101]={};
    struct Wezel *korzen = utworz();

// WCZYTUJE WYRAZY

    cin>>n;
    for (int i=0; i<n; i++){
        char slowo[101]={};
        cin>>slowo;
        dodaj_text_do_korz(korzen, slowo);
    }

//WCZYTUJE ZAPYTANIA

    cin>>m;
    for (int i=0; i<m; i++){
        char aslo[101]={};
        struct kod *root = utworz_kod();

        cin>>zap;
        int z = 0;
        int licznik = 0;
        while (zap[z]!='\0'){
          licznik++;
          z++;
        }
   //DLA KAZDEGO ZAPYTANIA SPRAWDZAM I WYSWIETLAM

        sprawdz(korzen,root,zap,0,licznik,aslo);
        pokaz(root,aslo,0,zap,licznik);
        cout<<endl;

   //ZWALNIAM PAMIEC

    kasuj2(root);
    delete root;
    }
delete korzen;

return 0;
}
