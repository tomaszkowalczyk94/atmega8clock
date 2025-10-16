* USBAsp drivers: https://zadig.akeo.ie/
* https://majsterkowo.pl/programowanie-mikrokontrolerow-za-pomoca-programatora-usbasp/
* https://www.youtube.com/watch?v=X01Nhq8TeY0&t=58s




	
LED4-AF-05643FG-B PBF

Wyświetlacz LED 14,20mm 0,56" cztery cyfry

zielony (570nm) , 4000 ucd (10mA) , wspólna anoda

aktywne wszystkie kropki (przy cyfrach i zegarkowe)


![alt text](image.png)

![alt text](image-1.png)


typ NPN zacznie przewodzić, gdy do bazy przyłożymy napięcie dodatnie względem emitera, czyli przy standardowym podłączeniu na bazę podamy wysoki potencjał (plus z baterii),
typ PNP zacznie przewodzić, gdy do bazy przyłożymy napięcie ujemne względem emitera, czyli przy standardowym podłączeniu na bazę podamy niski potencjał (masę, minus z baterii).


bc547 b (NPN)
 ![alt text](image-2.png)



 połączenie do atmega8:
 nr pinu wyświetlacza odpowiada pinowi cyfrowemu arduino