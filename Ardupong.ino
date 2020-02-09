//The Matrix
int pos[8][8]; 
int i, j; 

//The Player 1
int player1[7] = {1, 2, 3, 4, 5, 6, 7}; 
int player1_position; 
#define btn_p1_r 11
#define btn_p1_l 10

//The Player 2
int player2[7] = {1, 2, 3, 4, 5, 6, 7}; 
int player2_position; 
#define btn_p2_r 9
#define btn_p2_l 8

bool controll_up;

//Stand-by
#define led_standby 13

//BUTTONS
#define btn_start 12

//Sounds FX
#define buzzer 7

//Variables 
int rng;
int ball_move_i;
int ball_move_j;
int started;
int game_level; //milliseconds (decrease for faster)
bool ball_roll; 
bool game_over; 
int game_mode;

//Task Controll
#include <Metro.h>

boolean blink1State = false;
boolean blink2State = false;

Metro blink1Metro = Metro(1);
Metro blink2Metro = Metro(16);

//Leds FX
void Led_Start(){
  //led fx for start
  digitalWrite(led_standby, HIGH); 
}
void Led_GameOver(){
  //led fx for game over
}
//General FX
void Countdown(){
  tone(buzzer, 300, 800); 
  delay(1000); 
  tone(buzzer, 300, 800); 
  delay(1000); 
  tone(buzzer, 400, 1000); 
  delay(1000); 
}
//Game
//Start
void Start(){
  Led_Start(); 
  
  if(analogRead(btn_start) == HIGH){
    started = 1; 
  }else{
    Serial.println("Delay iniciado!!");
    delay(5000); 
    Idle(); 
  }
}
void Game_Over(){
  controll_up = false; 
  ball_move_i = 0; 
  ball_move_j = 0; 
  Led_GameOver(); 
  started = 0; 
}
//GAME MODE
void Idle(){
  Simulated_Playing();
}

//Simulated Gaming
void Simulated_Playing(){
  //WIP
}
//PVP Game
void PVP_Game(){
  if(started == 1 && game_over == false){

    ball_roll = true; 
    controll_up = true; 
    
    Countdown(); 
  }
}
//PVE Game
void PVE_Game(){
  //WIP
}
//ENGINE
void Ball_Roll(){
   Serial.println("Ball Roll iniciado!!");

   Serial.println("Posição incial verificada!!");

   Serial.println("Start Ball Move");
   Serial.println(ball_move_i); 

   while(!game_over){
     for(i; i >= 1 && i <= 8; i = i + ball_move_i){
      j = j + ball_move_j;
      
      Serial.println(i); 
      Serial.println(j); 
      
      delay(game_level); 
      
     }
     //Line Correction
     if(i <= 1){
      if(j == player1_position){
        i = 2; 
        ball_move_i = ball_move_i * (-1);
        ball_move_j = -1; 
      }
      else{
        game_over = true; 
      }
      if(j == (player1_position + 1)){
        i = 2; 
        ball_move_i = ball_move_i * (-1);
        ball_move_j = 1; 
      }
      else{
        game_over = true; 
      }
     }
     if(i >= 8){
      if(j == player2_position){
        i = 7; 
        ball_move_i = ball_move_i * (-1); 
        ball_move_j = 1; 
      }
      else{
        game_over = true; 
      }
      if(j == (player2_position + 1)){
        i = 7; 
        ball_move_i = ball_move_i * (-1); 
        ball_move_j = -1; 
      }
      else{
        game_over = true; 
      }
     }
   }
}
void Player_Controll(){
  while(controll_up){
    //PLAYER CONTROLLS
    if(digitalRead(btn_p1_r == HIGH)){
      player1_position++; 
      delay(50); 
    }
    if(digitalRead(btn_p1_l == HIGH)){
      player1_position--; 
      delay(50); 
    }
    player1[player1_position]; 
    
    if(digitalRead(btn_p2_r == HIGH)){
      player1_position++; 
      delay(50); 
    }
    if(digitalRead(btn_p2_l == HIGH)){
      player1_position--; 
      delay(50); 
    }
    player2[player2_position]; 
    Serial.println("Controll Actived!!!");
  }
  if(game_over == true){
      Game_Over(); 
    }
}
//SERVICES
void setup() {
  Serial.begin(9600); 
  Serial.println("Setup iniciado!!");

  pinMode(led_standby, OUTPUT); 
  pinMode(btn_start, INPUT); 

  started = 1; 

  i = 4;
  j = 4;

  ball_move_i = 1;
  ball_move_j = 0;

  game_over = false; 
  controll_up = false; 
  ball_roll = true; 

  game_level = 1000; 

  Serial.println("Setup concluído!!");
  
  //Player Position
  player1_position = 4; 
  player1[player1_position]; 
  player2_position = 4; 
  player2[player2_position]; 

  pinMode(btn_p1_r, INPUT); 
  pinMode(btn_p1_l, INPUT); 
  pinMode(btn_p2_r, INPUT); 
  pinMode(btn_p1_l, INPUT); 

  //Game Mode 1 - PVP - 2 PVE
  game_mode = 1; 
}

void loop() {

  //Start(); 

    if(blink1Metro.check()){
      blink1State = !blink1State;
      if(blink1State){
        
        //PLAYER CONTROLLS

        if(game_over == true){
          Game_Over(); 
        }
        
        if(digitalRead(btn_p1_r == HIGH)){
          player1_position++; 
          delay(50); 
        }
        if(digitalRead(btn_p1_l == HIGH)){
          player1_position--; 
          delay(50); 
        }
        player1[player1_position]; 
        
        if(digitalRead(btn_p2_r == HIGH)){
          player1_position++; 
          delay(50); 
        }
        if(digitalRead(btn_p2_l == HIGH)){
          player1_position--; 
          delay(50); 
        }
        player2[player2_position]; 
        
        Serial.println("Controll Actived!!!");
        
      }
    }
    if(blink2Metro.check()){
      blink2State = !blink2State;
      if(blink2State){

          i = i + ball_move_i;
          j = j + ball_move_j;
          
          Serial.println(ball_move_i); 
          Serial.println(ball_move_j); 

          int number = -1;
          Serial.println(number); 
         
         //Line Correction
         if(i <= 1){
          if(j == player1_position){
            i = 2; 
            ball_move_i = 1;
            ball_move_j = -1;
          }
          else{
            game_over = true; 
          }
          if(j == (player1_position + 1)){
            i = 2; 
            ball_move_i = 1;
            ball_move_j = 1; 
          }
          else{
            game_over = true; 
          }
         }
         if(i >= 8){
          if(j == player2_position){
            i = 7; 
            ball_move_i = -2;
            ball_move_j = 1; 
          }
          else{
            game_over = true; 
          }
          if(j == (player2_position + 1)){
            i = 7; 
            ball_move_i = -2;
            ball_move_j = -1;
          }
          else{
            game_over = true; 
          }
         }
         
      }
    }

}
