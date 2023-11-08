const int led_vermelho = 3;
const int led_amarelo = 2;
const int led_verde = 4;
const int trig = 10;
const int echo = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

}
