/* Código para controle dos motores da luneta
   com switch de três posições como controle
   de velocidade
*/

#include <AccelStepper.h>

#define Azul 2
#define Rosa 3
#define Amarelo 4
#define Laranja 5
#define Button1 6
#define Button2 7
#define velBaixa 9
#define velAlta 10

int but1 = 0, but2 = 0;
int vel = 0, vel2 = 0;

AccelStepper motor1(8, Azul, Amarelo, Rosa, Laranja);   // Inicialização do primeiro motor

void setup() {
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(velBaixa, INPUT);
  pinMode(velAlta, INPUT);
  motor1.setMaxSpeed(1000.0);
}

void loop() {

  // Switch:
  
  if (digitalRead(velBaixa) == HIGH) {   // Velocidade Mínima
    vel = 50.0;
  } 
  if (digitalRead(velAlta) == HIGH) {   // Velocidade máxima
    vel = 900.0;
  }
  if (digitalRead(velBaixa) == LOW && digitalRead(velAlta) == LOW) {   // Velocidade média
    vel = 300.0;
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
