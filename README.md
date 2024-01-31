# Socket labor

## Felkészülés
A laborra felkészüléshez olvassa el a segédletet és próbáljon meg válaszolni az ellenőrző kérdésekre.

## A labor teljesítése
Ebbe a könyvtárba készítsd el a **Socket labor** megoldásait. A labor teljesítéséhez a jelenléten felül az összes feladat elkészítésére szükség van. A gyakorlat során a feladatokat a laborvezetővel közösen kell megoldani. A beadott progamkódnak fordulnia kell az értékeléshez!

> [!IMPORTANT]
> A megoldásokat pull request formájában kell beadni a határidő előtt a Moodle alatt található **Git tudnivalók** leírásban található utasítások alapján.
> - Hozz létre egy **új branchet** `megoldas` néven, és ezen dolgozz.
> - Töltsd ki a `neptun.txt` fájlt a saját Neptun kódoddal.
> - Minden feladat után kommitolj, és használj értelmes kommit üzeneteket.
> - A feladat végeztével vagy a labor végén **pushold** a megoldásodat és hozz létre egy **pull requestet**.
> - Ellenőrizd a pull request tartalmát és rendeld hozzá a laborvezetődet **reviewernek**.

> [!CAUTION]
> A nem ilyen formában megadott megoldások nem lesznek értékelve!

## Előkészületek
A kiinduló solution alapértelmezetten nem fordul, mivel néhány függőség nincs beállítva. Ezért a feladat elkészítése előtt állítsa be a következőket a projektben:
- A projekt tulajdonságok beállításánál adja hozzá a `ws2_32.lib` fejlesztői könyvtárat a linkelési függőségekhez minden konfiguráció esetén! Ehhez válassza a `Project` > `socket Properties` menüpontot, majd keresse meg a `Configuration Properties` > `Linker` > `Input` > `Additional Dependencies` mezőt. Nyissa le a mezőt a szélén található gombbal és válassza az `<Edit..>` opciót, majd írja be, hogy `ws2_32.lib` és `OK`.
- Ugyanitt a projekt beállításainal keresse meg a `Configuration Properties` > `Debugging` > `Command Arguments` mezőt, és másolja be ide a következőt: `152.66.188.5 80 / fajl.html`. Ezzel könnyebbé válik a debugolás, mivel alapértelmezetten a Debugger ezekkel az atribútumokkal fogja meghívni az alkalmazást, és nem kell minden egyes alkalommal parancssorba beírni ezeket. 

## 1. feladat: TCP socket létrehozása
Hozza létre a kapcsolatot a szerverrel:
- Hozzon létre egy TCP socket-et!
- Állítsa össze a szerver címét!
- Kapcsolódjon a szerverhez!
- Zárja be a socketet!

### :bookmark_tabs: Beadandó

- [ ] Kommitold a változtatásokat.

## 2. feladat: HTTP kommunikáció megvalósítása
Küldje el egy oldal lekérést és írja ki a választ:
- A TCP kapcsolat létrejötte után állítson össze egy HTTP oldal lekérést! (Az `sprintf()` függvénnyel ez könnyen megtehető.)
- Küldje el a socket-en a kérést!
- Fogadja a válasz csomagot és írja ki a tartalmát a képernyőre! Figyeljen arra, hogy a kapott csomag nem szabványos C string vagyis nincs a végén 0. Ezért mielőtt megpróbálja kiírni a tartalmát zárja le egy 0 értékkel! Figyeljen arra, hogy a kapott adatok végére írja a 0-t és ugyanakkor ne írja túl a lefoglalt tömböt!

Dolgozza fel a szerver válaszát:
- A szerver válaszának eleje a HTTP protokoll szerint tartalmazza a szerver státusz visszajelzését. Ebből nyerje ki a státusz kódot és a státusz szöveget! A szöveg feldolgozásához használja az `sscanf()` függvényt. Írja ki a kinyert adatokat!
- A szerver válasza tartalmaz egy fejléc és egy adat részt. Keresse meg a fejléc rész végét, amit a `\r\n\r\n` szövegrészlet jelez. A kereséshez használhatja az `strstr()` függvényt.

> [!WARNING]
> A `sprintf()` és `sscanf()` függvény nem biztonságos, mert nem kezeli megfelelően a tömb méreteket. Ezért éles programokban a használata nem javasolt. A fordító is felhívja erre a figyelmünket. Azonban a gyakorlat során megengedett a használata.

### :bookmark_tabs: Beadandó

- [ ] Kommitold a változtatásokat.

## 3. feladat: Mentés állományba
A kapott válasz adat részét mentse le egy állományba:
- Hozzon létre és nyisson meg egy állományt írásra! Használhatja az `fopen()` függvényt.
- Írja bele az állományba a fejléc utáni részt a szerver válaszából! Használhatja az `fwrite()` függvényt.
- Fogadja a socket-en érkező további adatokat és írja ki az állományba egészen addig, amíg el nem fogynak, és a szerver lezárja a kapcsolatot!
- Zárja le az állományt!

### :bookmark_tabs: Beadandó

- [ ] Kommitold a változtatásokat.

## 4. feladat: Alkalmazás kipróbálása
- Indítsa el az alkalmazást és keresse meg a létrejövő `fajl.html`-t! Vesse össze a tartalmát a [https://avalon.aut.bme.hu/index.html](https://avalon.aut.bme.hu/index.html) címen elérhető fájl tartalmával!
- Indítsa el az alkalmazást paranccsorból és tesztelje a működését más paraméterekkel is!

### :bookmark_tabs: Beadandó

- [ ] Kommitold a változtatásokat.

