/*
   Fundacion Kinal
   Centro Educativo Tecnico Laboral KINAL
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital 
   Proyecto: Cancion StarWars
   Byron Renato Dávila Santiago
   2019618
*/

int trig = 2; // Pin del sensor ultrasónico TRIG
int eco = 3; // Pin del sensor ultrasónico ECHO
int ZumbadorPin = 11; // Pin del zumbador
int f=349;//esta 
int a=440;// esta 
int cH=523;//esta
int eH=659;//esta

 void setup() {
  pinMode(trig, OUTPUT);
  pinMode(eco, INPUT);
  pinMode(ZumbadorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long duracion, distancia;
  digitalWrite(trig, LOW);
  delay(2);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  duracion = pulseIn(eco, HIGH);
  distancia = duracion / 58;

  if (distancia > 0 && distancia <= 2) { // Si la distancia está entre 0 y 5 cm
    tone(ZumbadorPin, a, 500);
    delay(500+50);
    
  } else if (distancia > 2 && distancia <= 4) { // Si la distancia está entre 5 y 10 cm
    tone(ZumbadorPin, a, 500);
    delay(500+50);     
    
  } else if (distancia > 4 && distancia <= 6) { // Si la distancia está entre 10 y 15 cm
    tone(ZumbadorPin, a, 500);
    delay(500+50);
    
  } else if (distancia > 6 && distancia <= 8) { // Si la distancia está entre 15 y 20 cm
    tone(ZumbadorPin, f, 350);  
    delay(350+50);
    
  } else if (distancia > 8 && distancia <= 10) { // Si la distancia está entre 20 y 25 cm
    tone(ZumbadorPin, cH, 150);
    delay(150+50); 
    
    
  } else if (distancia > 10 && distancia <= 12) { // Si la distancia está entre 25 y 30 cm
    tone(ZumbadorPin, a, 500);
    delay(500+50);
    
  } else if (distancia > 12 && distancia <= 14) { // Si la distancia está entre 30 y 35 cm
    tone(ZumbadorPin, f, 350);
    delay(350+50);  
    
  } else if (distancia > 14 && distancia <= 16){  // Si la distancia es 35 cm o 40
     tone(ZumbadorPin, cH, 150);
    delay(150+50);
    
  }
  else if ( distancia > 16 && distancia <= 20){
    tone(ZumbadorPin, a, 1000);   
    delay(1000+50);
   
    }
   else if ( distancia > 20 && distancia <= 22){
    tone(ZumbadorPin, eH, 500);
    delay(500+50);
    }
    else if ( distancia > 22 && distancia <= 24){
    tone(ZumbadorPin, eH, 500);
    delay(500+50);
    } 
    else if ( distancia > 24 && distancia <= 26){
       tone(ZumbadorPin, eH, 500);
    delay(500+50);
    }
    else if ( distancia > 26 && distancia <= 28){
       tone(ZumbadorPin, eH, 500); 
    delay(500+50);   
    }
    else {
      
      noTone(ZumbadorPin); // Silencio
      }
    
  Serial.print(distancia);
  Serial.println(" cm");
  delay(2000);  // dos segundos para volver a empezar.
}
