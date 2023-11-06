#define numeros_lidos 10

const int led_vermelho = 3;
const int led_amarelo = 2;
const int led_verde = 4;
const int trig = 10;
const int echo = A0;
float distancia = 0;
long tempo = 0;
int index = 0;

int leituras[numeros_lidos];

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

    leituras[index] = distancia;

    index = (index + 1) % numeros_lidos;

    float soma = 0.0;
    for(int i = 0; i < numeros_lidos; i++){
        soma += leituras[i];
    }

    soma = soma / numeros_lidos;


     //2.5: distancia marca copo 5e o sensor
    float distancia_atual = soma - 4;
    float copo_vazio;

    if(distancia_atual >= 10 && distancia_atual <= 11.22){
        delay(100);
        digitalWrite(led_verde,LOW);
        digitalWrite(led_amarelo,LOW);
        digitalWrite(led_vermelho,LOW);
        delay(50);
        digitalWrite(led_verde,HIGH);
        digitalWrite(led_amarelo,HIGH);
        digitalWrite(led_vermelho,HIGH);
        copo_vazio = distancia_atual;
    }
      //copo cheio
      if(distancia_atual >= 4 && distancia_atual <= 5){
        digitalWrite(led_verde,LOW);
        digitalWrite(led_amarelo,LOW);
        digitalWrite(led_vermelho,LOW);
        digitalWrite(led_vermelho,HIGH);
      }

      
      if(distancia_atual >= 3 && distancia_atual <= 3.5){
        digitalWrite(led_verde,LOW);
        digitalWrite(led_amarelo,LOW);
        digitalWrite(led_vermelho,LOW);
          digitalWrite(led_amarelo,HIGH);
      }
    

    delay(100);
    Serial.print("COPO VAZIO: ");
    Serial.println(copo_vazio);
    delay(100);
    Serial.print("DISTANCIA ATUALA: ");
    Serial.println(distancia_atual);


}
