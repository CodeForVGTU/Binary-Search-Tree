# Binary-Search-Tree

Užduotis:
Parašyti programą, kuri iš duotos skaičių aibės suformuotų dvejetainį paieškos medį. Dvejetainį paieškos medį realizuoti dinaminiu masyvu. Parašyti atskiras funkcijas, kurios realizuotų operacijas: pridėti naują elementą, pašalinti elementą, surasti elementą, nustatyti aukštį, išvesti dvejetainį paieškos medį ekrane. Programoje realizuoti dialogą su naudotoju: aiškus ir patogus meniu operacijų pasirinkimui, galimybė pasirinkti duomenų įvedimą konsolėje ar iš failo, išvedimą į ekraną ar failą. Dvejetainį paieškos medį po bet kurio pakeitimo vizualiai aiškiai išvesti ekrane. Programa turi skaičiuoti kiek žingsnių buvo atlikta tam tikro veiksmo vykdymui. Šie duomenys reikalingi programos sudėtingumui ir efektyvumui nustatyti.

Programos naudojimas:
Pradėjus programos darbą, vartotojas turi suvesti pradinius duomenis į konsolės langą arba nuskaityti iš atitinkamo failo.
Teisingai suvedus duomenis, būsime nukelti į pagrindinį menių, kur galėsime:
1. Pridėti naują elementą į medį.
2. Ištrinti esamą elementą.
3. Surasti elementą.
4. Parodyti medžio aukštį.
5. Išvesti dvejetainį paieškos medį ekrane.
6. Išsaugoti medį į failą.
7. Baigti darbą.
Į menių funkcijas galima kreiptis neribotą kartų kiekį.


Užduoties atlikimo algoritmas:
Menu() - funkcijoje atvaizduojama vartotojo sąsaja. Menių realizavimui naudojamas dinaminis masyvas (jame išsaugomos reikalingos reikšmės), if sąlyginiai sakiniai bei reikalingų funkcijų kvietimai.

    1. Naujas elementas visada pridedamas į lapo poziciją. Paieška vyksta nuo dvejetainio medžio šaknies iki kol randamas lapas. Suradus lapą, nauja viršūnė pridedama į to lapo vaiko poziciją.
Naudojama rekursyvi insert() funkcija.

    2. Viršūnės šalinimo algoritmas
- Rekursijos  pagalba, kuri nukreipia paiešką į dešinįjį arba kairįjį pomedį, surandame viršūnę kurią norime ištrinti.
- Jei iš medžio šaliname viršūnę – lapą (neturi vaikų) arba kuri turi tik vieną vaiką, tai šią viršūnę atkabiname nuo jos tėvo ir sunaikiname (jei turi vaiką tai pakeičiame vaiku saugodami jį temp kintamajame).
- Jei šaliname dešiniojo pomedžio viršūnę, kuri turi abu vaikus, tai šią viršūnę keičiame jos dešinės šakos mažiausią reikšmę turinčia viršūne (randama naudojant minValueNode), o pačią sunaikiname.
- Jei šaliname kairiojo pomedžio viršūnę, kuri turi abu vaikus, tai šią viršūnę keičiame jos kairės šakos didžiausią reikšmę turinčia viršūne (randama naudojant maxValueNode), o pačią sunaikiname.
Naudojama deleteNode() funkcija. Į ją taip pat įeina minValueNode ir MaxValueNode funkcijos.

    3. Norint surasti įvestą elementą, pirmiausia palyginame jį su viršūne. Jei įvestis atitinka viršūnę – ją grąžiname. Jei įvestis didesnė už viršūnę, atliekama rekursija dešiniajam pomedžiui. Priešingu atveju, einame į kairįjį pomedį.
Naudojama rekursyvi ifNodeExists() funkcija.

    4. Jeigu medis tuščias, grąžinamas 0;
Kitu atveju:
    - Rekursyviai gaunamas maksimalus kairiojo pomedžio gylis.
Kviečiama maxDepth( node->left )
    - Rekursyviai gaunamas maksimalus dešiniojo pomedžio gylis.
Kviečiama maxDepth( node ->right )
    - Iš kairiojo ir dešinio pomedžio gylių dydžių paimamas didesnis ir pridedamas 1-as, kadangi neužskaityta esama viršūnė.
Naudojama rekursyvi maxDepth() funkcija.


    5. Paieškos medžio atvaizdavimas
- Rekursija naudojama suskaičiuoti kiek tarpų pridėti prieš kiekvienos medžio reikšmės skaičiaus atvaizdavimą, pirma paimant dešiniąsias pomedžio reikšmes (pirma  dešinės, veliau kairės pusės elementus), šaknį ir kairiojo pomedžio reikšmes.
- Atvaizduotos reikšmės paskirstomos taip, kad pirma reikšmė kairėje konsolės (failo) pusėje yra medžio šaknis; į viršų nuo jos pasiskirsto dešiniojo pomedžio viršūnės; į apačią (nuo šaknies) pasiskirsto kairiojo pomedžio viršūnės.
Naudojama print2D() apglėbiamoji funkcija, kurioje yra rekursyvi print2DUtil() funkcija.

    6. Medis išsaugojamas tokiu pat principu kaip ir dvejetainio paieškos medžio atvaizdavimas t.y. praeitas, 5 punktas. Tiesiog čia vaizdas neatvaizduojamas konsolėje, o įrašomas į failą.
Naudojama rekursyvi print_to_File() funkcija.

Programos sudėtingumas ir efektyvumas:
Programos sudėtingumas ir efektyvumas priklauso nuo pradinių duomenų dydžio.
Dvejetainiame paieškos medyje sudėtingumas ir efektyvumas vertinamas O(n).  O(n) gali būti pats sudėtingiausias ir neefektyviausias atvejis.
Kiekvienos funkcijos žingsniams skaičiuoti sukurtas globalusis kintamasis counter su reikšme 0. Counter reikšmė didinama po 1-ą kiekvienoje funkcijoje.
Pasibaigus funkcijai žingsnių kiekis išvedamas vartotojui į ekraną ir vėl atstatomas į 0.
