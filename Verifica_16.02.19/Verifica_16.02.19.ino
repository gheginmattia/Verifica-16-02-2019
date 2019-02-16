int led_giallo=6;
int led_bianco=8;
int led_verde=10;
int led_rosso=12;
int rosso_giallo=0;
int bianco_verde=0;  
int serial_begin=9600;
void rg (void);
void bv (void);
void setup() {
  pinMode(led_giallo, OUTPUT);
  pinMode(led_bianco, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_rosso, OUTPUT);
  Serial.begin(serial_begin);
  Serial.println("Inserisci la durata di rosso e giallo in millisecondi");
  while(Serial.available()==0){}
  rosso_giallo=Serial.readString().toInt();
  Serial.println(rosso_giallo);
  Serial.println("Inserisci la durata di bianco e verde in millisecondi");
  while(Serial.available()==0){}
  bianco_verde=Serial.readString().toInt();
  Serial.println(bianco_verde);
  } 
  void rg (void){
    digitalWrite(led_rosso,HIGH);
    digitalWrite(led_giallo,HIGH);
    delay(rosso_giallo);
    digitalWrite(led_rosso,LOW);
    digitalWrite(led_giallo,LOW);
  }
  void bv (void) {
    digitalWrite(led_bianco,HIGH);
    digitalWrite(led_verde,HIGH);
    delay(bianco_verde);
    digitalWrite(led_bianco,LOW);
    digitalWrite(led_verde,LOW);
  }

void loop() {
  rg();
  bv();
}
