# Powtarzające się symbole.

**Program wyszukujący najczęściej występujący symbol na obrazku. Symbol to zbiór czarnych punktów sąsiadujących ze sobą krawędzią (nie rogiem). Symbole różniące się obrotem czy będące swoimi odbiciami są różne.
Obrazek (0 to biały punkt, 1 to czarny punkt) -  Zadanie  z przedmiotu AiSD na drugim semestrze studiów, programowanie proceduralne bez STL.**

* Sugerowane rozwiązania: przeszukiwanie wszerz lub w głąb do identyfikacji symboli, tablica haszowana do ich zliczania.
* Pliki z przykładowymi danymi wejsciowymi i wyjściowymi znajdują się w dołączonym katalogu.
    
---

**Wejście**
---

W pierwszej linii wejścia podaną zostane wymiary obrazka: szerokość (w) i wysokość (h). Żaden z wymiarów nie przekroczy 1000, żaden z nich nie będzie mniejszy niż 4. Każda z następnych h linii będzie zawierała w cyfr opisujących obrazek: 0 oznacza biały punkt, 1 to czarny punkt (należący do symbolu). Wymiary pojedynczego symbolu nie przekroczą 128x128 punktów. Odpowiedź będzie zawsze jednoznaczna (nie wystąpią dwa symbole o maksymalnej liczności).

**Wyjście**
---
    
Na wejściu należy wypisać liczbę wystąpień najczęściej występującego symbolu oraz ten symbol w formacie takim jak obrazek, bez żadnej białej obwódki (w pierwszej i ostatniej kolumnie oraz w pierwszym i ostatnim wierszu symbolu powinien pojawić się przynajmniej jeden czarny punkt).

**Przykłady**
---
<code>
1110011
1000000
1010101
0000001
1100111
</code>

<br>zawiera 4 różne symbole:

<code>
111
100
100
<br>
001
001
111
<br>
1
<br>
11
</code>

---

**Wejście**
<code>
10 10
0101010100
0000000110
0100010000
0110011010
0000000011
1100000000
0110010011
0000011000
1001010010
1100000011
</code>

**Wyjście**
<code>
6
10
11
</code>

---
