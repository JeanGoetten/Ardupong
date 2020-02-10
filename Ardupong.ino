//The Matrix
int ball[8][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, 
                 {1, 1, 1, 1, 1, 1, 1, 1}, 
                 {1, 1, 1, 1, 1, 1, 1, 1}, 
                 {1, 1, 1, 1, 1, 1, 1, 1}, 
                 {1, 1, 1, 1, 1, 1, 1, 1}, 
                 {1, 1, 1, 1, 1, 1, 1, 1}, 
                 {1, 1, 1, 1, 1, 1, 1, 1}, 
                 {1, 1, 1, 1, 1, 1, 1, 1}};

int ball_shadow[8][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, 
                         {1, 1, 1, 1, 1, 1, 1, 1}, 
                         {1, 1, 1, 1, 1, 1, 1, 1}, 
                         {1, 1, 1, 1, 1, 1, 1, 1}, 
                         {1, 1, 1, 1, 1, 1, 1, 1}, 
                         {1, 1, 1, 1, 1, 1, 1, 1}, 
                         {1, 1, 1, 1, 1, 1, 1, 1}, 
                         {1, 1, 1, 1, 1, 1, 1, 1}};
int i, j; 
int i_shadow, j_shadow; 

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

//Stand-by
#define led_standby 13

//BUTTONS
#define btn_start 12

//Sounds FX
#define buzzer 7

//Variables 
int rng;
int i_controll;
int j_controll;
int started;
int game_level; //milliseconds (decrease for faster)
bool ball_roll; 
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
  while(!started){
    i_controll = 0; 
    j_controll = 0; 
    Led_GameOver(); 
  }
}
//GAME MODE
void Idle(){
  Simulated_Playing();
}

//Simulated Gaming
void Simulated_Playing(){
  //WIP
}
//PVE Game
void PVE_Game(){
  //WIP
}

//SERVICES
void setup() {
  Serial.begin(9600); 
  Serial.println("Setup iniciado!!");

  pinMode(led_standby, OUTPUT); 
  pinMode(btn_start, INPUT); 

  int z = 0;
  int w = 0; 


  i = 3;
  j = 3;

  i_controll = 1;
  j_controll = 0;

  game_level = 1000; 

  Serial.println("Setup concluído!!");
  
  //Player Position
  player1_position = 3; 
  player1[player1_position]; 
  player2_position = 3; 
  player2[player2_position]; 

  pinMode(btn_p1_r, INPUT); 
  pinMode(btn_p1_l, INPUT); 
  pinMode(btn_p2_r, INPUT); 
  pinMode(btn_p1_l, INPUT); 

}
void loop() {
        
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
          player2_position++; 
          delay(50); 
        }
        if(digitalRead(btn_p2_l == HIGH)){
          player2_position--; 
          delay(50); 
        }
        player2[player2_position]; 
        
        //GAME ENGINE   
           i = i + i_controll;
           j = j + j_controll;
            
           ball[i][j] = 0; 

           i_shadow = i - 1; 
           j_shadow = j - 1;
            
           ball_shadow[i_shadow][j_shadow] = 1; 

            //Line Correction
               if(i == 0){
                switch(player1_position){
                  case 3:
                    i_controll = 1;
                    j_controll = -1;
                    break;
                  case 4:
                    i_controll = 1;
                    j_controll = 1;
                    break;
                  default:
                    Game_Over();
                    Serial.println("Gameover 1"); 
                    break;
                }
               }
               if(i == 7){
                switch(player2_position){
                  case 3:
                    i_controll = -1;
                    j_controll = 1;
                    break;
                  case 4:
                    i_controll = -1;
                    j_controll = -1;
                    break;
                  default:
                    Game_Over();
                    Serial.println("Gameover 2"); 
                    break;
                }
               }
               //Colunm correction
               if(j == 0){
                j_controll = 1;
               }
               if(j == 7){
                j_controll = -1;
               }
      
}
