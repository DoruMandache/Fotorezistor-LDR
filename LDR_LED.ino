/* Sketch testare LDR pe o placa Arduino cu vizualizare a cantitatii luminii 
   citite de LDR printr-un LED
   
   Materiale necesare testarii:
     - placa de dezvoltare Arduino (UNO, Mega 2560, Nano, Pro Mini ...)
     - LDR
     - LED
     - rezistor de 10K
     - rezistor de 220R
     - breadboard
     - cabluri de lagatura

   Interfatare LDR si LED cu Arduino:
   
    Se conecteaza un terminal al LDR - ului la +5V iar celalalt terminal 
    printr-o rezistenta de 10K la GND (masa), iar un punct (de pe breadboard) dintre LDR si 
    rezistenta fixa la un pin analogic (A0) al placii de dezvoltare, cum este Arduino.

    Se conecteaza anodul LED-ului la pinul 11 (sau oricare pin PWM) si
    catodul printr-o rezistenta de 220R la GND.
   
   Detalii despre fotorezistor (LDR) la: 
*/
 
int Pin_LDR = 0;          
int Citire_Analogica;     // variabila pentru citirea analogica de la divizorul cu LDR
int Pin_LED = 11;         
int Stralucire_LED;     
  
void setup(void) {
    Serial.begin(9600);   
}
 
void loop(void) {
    Citire_Analogica = analogRead(Pin_LDR);  
 
    Serial.print("Citire Analogica = ");
    Serial.println(Citire_Analogica);     // citirea analogica bruta
 
    // LED-ul devine mai luminos cu cât este mai întunecat senzorul
    // de acea se inverseaza citirea analogica de la 0-1023 la 1023-0
    
    Citire_Analogica = 1023 - Citire_Analogica;
    
    // se mapeaza 0-1023 la 0-255 deoarece aceasta este plaja utilizata de functia "analogWrite"
    Stralucire_LED = map(Citire_Analogica, 0, 1023, 0, 255);
    analogWrite(Pin_LED, Stralucire_LED);
 
    delay(100);
}
