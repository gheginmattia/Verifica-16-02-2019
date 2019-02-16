int led_giallo=6;
int led_bianco=8;
int led_verde=10;
int led_rosso=12;
int aspetta=0; 
int serial_begin=9600;
int i=0;
int giri=0;
int minimo=0;
int massimo=0;
void rg (void);
void bv (void);
void ripeti (void);
void setup() {
  pinMode(led_giallo, OUTPUT);
  pinMode(led_bianco, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_rosso, OUTPUT);
  Serial.begin(serial_begin);
  Serial.println("Inserisci quanti giri fare prima di fermarsi");
  while(Serial.available()==0){}
  giri=Serial.readString().toInt();
  Serial.println(giri);
  Serial.println("Inserisci il minimo valore del random");
  while(Serial.available()==0){}
  minimo=Serial.readString().toInt();
  Serial.println(minimo);
  Serial.println("Inserisci il massimo valore del random");
  while(Serial.available()==0){}
  massimo=Serial.readString().toInt();
  Serial.println(massimo);
  aspetta = random(minimo,massimo);
  Serial.println(aspetta);
  } 
  void rg (void){
    digitalWrite(led_rosso,HIGH);
    digitalWrite(led_giallo,HIGH);
    delay(aspetta);
    digitalWrite(led_rosso,LOW);
    digitalWrite(led_giallo,LOW);
  }
  void bv (void) {
    digitalWrite(led_bianco,HIGH);
    digitalWrite(led_verde,HIGH);
    delay(aspetta);
    digitalWrite(led_bianco,LOW);
    digitalWrite(led_verde,LOW);
  }
 void ripeti(void){
    rg();
  bv();
 }

void loop() {
while(i<giri){
  ripeti();
  i++;
}
}
