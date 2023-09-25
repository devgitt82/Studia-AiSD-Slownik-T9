# Słownik T9.

Większość telefonów pozwala wprowadzać tekst przy pomocy słownika T9. Wprowadzanie polega na wpisywaniu cyfr przyporządkowanym literom. Słownik automatycznie przekształca ciąg cyfr na wyraz. Słownik potrafi także domyślać się dalszego ciągu słowa - na podstawie początkowego ciągu cyfr próbuje domyślić się, jaka będzie końcówka. Kodowanie to jest niestety niejednoznaczne (np. i mam i nam mają kody 626). Przyporządkowanie cyfr do liter jest następujące: abc = 2, def = 3, ghi = 4, jkl = 5, mno = 6, pqrs = 7, tuv = 8, wxyz = 9. Zatem np. wyraz pies ma kod T9 równy 7437. 

**Program dla zadanego początkowego fragmentu kodu T9 znajdzie wszystkie pasujące do niego słowa ze słownika. -  Zadanie  z przedmiotu AiSD na drugim semestrze studiów, programowanie proceduralne bez STL.**

---

**Wejście**
---

Na wejściu pojawi się: liczba n określająca, ile słow jest w słowniku, n wyrazów, każdy w osobnej linii, należących do słownika, składających się wyłącznie z małych liter, liczba m określająca liczbę zapytań, m napisów określających zapytania, składających się wyłącznie z cyfr, każde w osobnej linii. Długości wyrazów i zapytań nie przekroczą 100 znaków.

**Wyjście**
---
    
Dla każdego zapytania, na wyjściu należy wypisać wszystkie pasujące słowa, w kolejności leksykograficznej ich kodów T9 (kod 123 jest zatem mniejszy niż kod 33). Słowa o takim samym kodzie powinny być uporządkowane leksykograficznie i rozdzielone spacją. Jeżeli do zapytania nie pasują żadne wyrazy, należy wypisać znak - (minus). Odpowiedź na każde zapytanie powinien kończyć znak nowej linii.

**Przykłady**
---


**Wejście**
<code>
10
ccc
bbb
aaa
aba
abc
pies
samochod
samolot
potrzebny
paliwo
10
2
22
222
2222
7
72
726
743
7437
744
</code>

**Wyjście**

<code>
aaa aba abc bbb ccc 
aaa aba abc bbb ccc 
aaa aba abc bbb ccc 
-
paliwo samochod samolot pies potrzebny 
paliwo samochod samolot 
samochod samolot 
pies 
pies 
-
</code>

---
