const int led_vermelho = 3;
const int led_amarelo = 2;
const int led_verde = 4;
const int trig = 10;
const int echo = A0;
float distancia = 0;
long tempo = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

   Serial.begin(9600);
}

void loop() {
  
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    //ver sobre essa função
    tempo = pulseIn(echo, HIGH);
    distancia = (tempo * 0.034) / 2;

     //2.5: distancia marca copo e o sensor
    float distancia_copovazio_senor = distancia - 2.5;
  
    if()
    

    Serial.println(distancia_copovazio_senor);

}
