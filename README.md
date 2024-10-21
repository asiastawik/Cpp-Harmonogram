# Projekt 1: Harmonogram

## Opis Projektu

Celem projektu jest zaprojektowanie systemu do planowania czasu, który pozwala na zarządzanie wydarzeniami i czynnościami w oparciu o ich czas trwania. System umożliwia podstawowe operacje na zestawieniach czasów, takie jak obliczanie całkowitego czasu wydarzeń oraz zliczanie ich ilości w zadanym okresie.

## Etapy Projektu

### Etap 1: Utworzenie klasy Czas

1. **Klasa Czas**  
   Stwórz klasę `Czas`, która zawiera informacje o ilości sekund, minut i godzin. Wszystkie wartości powinny być przechowywane jako liczby całkowite.

2. **Akcesory i walidacja**  
   Dodaj akcesory do klasy, umożliwiające podgląd i zmianę wartości atrybutów. Zaimplementuj zabezpieczenia na wypadek wprowadzenia niepoprawnych wartości.

3. **Metoda wypisująca stan obiektu**  
   Stwórz metodę, która wypisuje stan obiektu w formacie: `Czas: 1:23:34`.

### Etap 2: Operacje na obiektach

1. **Ustawianie czasu**  
   Umożliw ustawianie czasu w formie sekund, minut, godzin lub kombinacji tych wartości. Uczyń akcesory prywatnymi, aby były używane wewnątrz klasy.

2. **Operatory sumowania**  
   Oprogramuj operatory umożliwiające sumowanie czasów (np. `c1 + c2`) oraz zwiększenie czasu o zadaną ilość sekund (np. `c1 += 5`).

3. **Porównywanie czasów**  
   Rozszerz klasę `Czas` o operatory porównania, aby umożliwić porównywanie zarejestrowanych czasów.

### Etap 3: Klasa Harmonogram

1. **Dodanie konstruktorów**  
   Dodaj konstruktor(y) do klasy `Czas`, aby można było tworzyć obiekt tej klasy z podaniem czasu w różnych formatach, w tym bez podania czasu.

2. **Destruktor**  
   Zastanów się nad koniecznością utworzenia destruktora dla klasy `Czas`.

3. **Klasa Harmonogram**  
   Utwórz klasę `Harmonogram`, która zarządza zestawieniem obiektów `Czas`. Zrealizuj następujące zadania:
   - Dodaj możliwość dodawania czasu do zestawienia, zwracania ilości czasów oraz konkretnego czasu (DLA AMBITNYCH: operator `[]`).
   - Oprogramuj możliwość zsumowania wszystkich czasów z zestawienia, wyrażoną jako obiekt `Czas`.
   - Oprogramuj możliwość wypisania całego zestawienia.

### Etap 4: Zarządzanie obiektami

1. **Konstruktor kopiujący i operator przypisania**  
   Dodaj konstruktor kopiujący oraz operator przypisania do klasy `Harmonogram`, zgodnie z zasadą trzech.

2. **Kopia harmonogramu**  
   Oprogramuj funkcję, która tworzy nowy obiekt `Harmonogram` zawierający tylko pierwsze n czasów.

3. **Zakres sumy czasów**  
   Oprogramuj funkcję, zwracającą kopię harmonogramu zawierającą pierwsze czasy, których suma mieści się w podanym zakresie.

4. **Proste menu**  
   Dodaj proste menu do funkcji `main`, aby umożliwić użytkownikowi interakcję z programem.

5. **Początkowy harmonogram**  
   Program po włączeniu powinien mieć już wprowadzone czasy do początkowego zestawienia (minimum 5 czasów).
