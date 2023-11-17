#define numeros_lidos 10

const int led_vermelho = 3;
const int led_amarelo = 2;
const int led_verde = 4;
const int trig = 10;
const int echo = A0;
const int copo = 9;
float distancia = 0;
long tempo = 0;
int index = 0;


int leituras[numeros_lidos];

int pisca(int led_ver, int led_ama, int led_verd){
    delay(150);
    digitalWrite(led_ver, HIGH);
    digitalWrite(led_ama, LOW);
    digitalWrite(led_verd, LOW);
    delay(150);
    digitalWrite(led_ver, LOW);
    digitalWrite(led_ama, HIGH);
    digitalWrite(led_verd, LOW);
    delay(150);
    digitalWrite(led_ver, LOW);
    digitalWrite(led_ama, LOW);
    digitalWrite(led_verd, HIGH);
}

void apaga_led(int verde = 4, int vermelho = 3, int amarelo = 2){
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, LOW);
  digitalWrite(amarelo, LOW);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT_PULLUP);

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


     //distancia marca copo e o sensor = 4
    float distancia_atual = soma - 4;
    float copo_vazio;

    //piscar para quando tiver vazio ou sem o copo
    if(distancia_atual >= 8.05 && distancia_atual <= 10){
        pisca(led_vermelho,led_amarelo,led_verde);
    }

    //copo comecou a encher --> Acende apenas o verde
    if(distancia_atual <= 8){
      digitalWrite(led_amarelo, LOW);
      digitalWrite(led_vermelho, LOW);
      digitalWrite(led_verde, HIGH);
    }

    //zero até metade --> Acende o verde e o amarelo
    if(distancia_atual <= 3){
      digitalWrite(led_verde, HIGH);
      digitalWrite(led_amarelo, HIGH);
      digitalWrite(led_vermelho, LOW);
    }

    //copo cheio - topo 1 --> Acende o verde, amarelo e vermelho
    if(distancia_atual <= 1){
      digitalWrite(led_verde, LOW);
      digitalWrite(led_amarelo, LOW);
      digitalWrite(led_vermelho,HIGH);
    }
  

    
    delay(100);
    Serial.print("DISTANCIA ATUAL: ");
    Serial.println(distancia_atual);
  
}
