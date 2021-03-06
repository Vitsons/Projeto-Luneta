/* Código para controle dos motores da luneta
   com potenciômetro para controle de velocidade
*/

#include <AccelStepper.h>   // Biblioteca para controle do motor de passo

#define Azul 2
#define Rosa 3
#define Amarelo 4
#define Laranja 5
#define Button1 6
#define Button2 7
#define LED1 8
#define LED2 9
#define LED3 10
#define LED4 11
#define LED5 12

int but1 = 0, but2 = 0;
int vel = 0, vel2 = 0;
int pot = 0;

AccelStepper motor1(8, Azul, Amarelo, Rosa, Laranja);   // Inicialização do primeiro motor

void setup() {
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  motor1.setMaxSpeed(1000.0);   // Velocidade máxima definida
}

void loop() {
  
  // Controle de velocidade:
   
  pot = analogRead(A5);
  vel = pot/1.13; // vel máxima = 905
  if (vel < 40){
    vel = 40;     // vel mínima = 40
  }

  // LEDs:
  /* Cada LED acende a cada dois números do potenciômetro*/

  digitalWrite(LED1, HIGH);   // LED1 sempre aceso
  
  if (vel>=170){
    digitalWrite(LED2, HIGH);
  }else{
    digitalWrite(LED2, LOW);
  }
  if (vel>=380){
    digitalWrite(LED3, HIGH);
  }else{
    digitalWrite(LED3, LOW);
  }
  if (vel>=600){
    digitalWrite(LED4, HIGH);
  }else{
    digitalWrite(LED4, LOW);
  }
  if (vel>=815){
    digitalWrite(LED5, HIGH);
  }else{
    digitalWrite(LED5, LOW);
  }

  // Botões direcionais:
  
  but1 = digitalRead(Button1);
  but2 = digitalRead(Button2);
  if (but1 == HIGH){
    motor1.setSpeed(vel);
    motor1.runSpeed();
  }
  vel2 = -vel;    // Inverter direção
  if (but2 == HIGH){
    motor1.setSpeed(vel2);
    motor1.runSpeed();
  }
}
