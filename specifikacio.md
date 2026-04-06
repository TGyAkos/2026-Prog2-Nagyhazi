# Specifikáció

## Titkosító osztály

Készítsen titkosító osztályt és azt felhasználó programot! Az osztály legyen képes tetszőleges hosszúságú szöveg kódolt formátumú tárolására. Valósítsa meg a szokásos string műveleteket! Az osztályt úgy tervezze meg, hogy az örökléssel könnyen felhasználható legyen, az algoritmus könnyen cserélhető legyen! Valósítsa meg az összes értelmes műveletet operátor átdefiniálással (overload), de nem kell ragaszkodni az összes operátor átdefiniálásához! Legyen az osztálynak iterátora is!
Specifikáljon egy egyszerű tesztfeladatot, amiben fel tudja használni az elkészített adatszerkezetet! A tesztprogramot külön modulként fordított programmal oldja meg!

## Feladatspecifikáció

A feladat egy tikosító program elkészítése, ami egy fájlban megadott ASCII szöveget képes, különböző egymás után kódolásokat applikálni a megadott szövegre, a kódolt szöveget kiírni egy másik fájlba. Valamint a kódolt szöveget tartalmazó fájlt visszafordítani az eredeti szövegre.
Az programnak el kell tudnia menteni a használt kódolásokat egy fájlba, amit később be kell tudnia olvasni dekódolás, másik kódolt szöveg készítésének céljából.

Az programban a cézár, a transzponált, valamint a MyCipher kódolást kell megvalósítani.

Az programot könnyen ki kell tudnia egészíteni a felhasználónak újabb kódolássokkal, amit egyből tudnia kell használni a kódolásláncok megalkotásakor.

Az programnak meg kell valósítania a szükséges nyelvi elemeket (értékadás, clone-ozás, másolás, létrehozás, megszüntetés).

Az programnak hibát kell dobnia, nem megfelelő formátumú, karakterű szöveg beolvasásakor figyelmeztetnie kell a felhasználót. Szintén hibát kell dobnia a túlindexelésnél.

A tesztelésnél olyan programot készítek ami az implementált kódolási láncok variációinak egyedi eseteit teszteli szimulált inputokkal, statikus elvárt eredményekkel szemben.

## A program használata

Ha dekódolni szeretnénk, a programot a `-r` flag-gel kell futtatnunk.

A program első paramétere a kódolandó/dekódolandó TXT fájl, a második a kódolásokat tartalmazó TXT fájl.

Példák a program használatára
```
./titkosito.exe kodolandoSzoveg.txt kodolasok.txt
./titkosito.exe -r dekodolandoSzoveg.txt kodolasok.txt
```

## Bemenetek

A program használatához, a felhasználónak meg kell adnia a kódolandó ASCII szöveget egy, egysoros TXT fájl formájában.

Példa a kódolandó szöveg TXT fájlra:
```
Hello world!
```

Példa a dekódolandó szöveg TXT fájlra:
```
Olssv dvysk!
```

---

### Kódolások

A felhasználandó szintén egysoros ASCII szövegű kódolásláncot, a kódolások applikálásának sorrendjében, ha van paramétereikkel, egy másik TXT fájl formájában kell megadnia a felhasználónak.

A kódolásokat tartalmazó TXT fájl formátuma:
- A `-` a kódolásokat választja el
- A `:` a kódolás nevét választja el a paramétereitől
- A `,` a paramétereket választja el egymástól, ha több paraméter van
- A paraméterek helyére a `\` karakter kerül, ha nincs paraméter.

Így a `-:,\` karakterek paraméterként vagy a kódolás nevében nem használhatók.

A kódolásokat tartalmazó TXT fájl formátuma:
```
KódolásNeve:param1,param2,param3-MásikKódolásNeve:\-HarmadikKódolás:param1
```

Példa a kódolásokat tartalmazó TXT fájl tartalmára:
```
CesarCipher:/-MyCipher:/-CesarCipher:/
```

# Kimenet

Kódoláskor és dekódoláskor az alkalmazás a `result.txt` fájlba helyezi az eredmény. A fájlt létrehozza, ha nem létezik, vagy felülírja, ha létezik.

Példa a `result.txt` fájlra:
```
Olssv dvysk!
```

Példa a `result.txt` fájlra dekódoló módban:
```
Hello world!
```

