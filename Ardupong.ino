//The Matrix
int ball_i [] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int ball_j [] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

int i, j; 

//The Player 1
int player1;  
int player1_position; 
#define btn_p1_r 8
#define btn_p1_l 9

//The Player 2
int player2; 
int player2_position; 
#define btn_p2_r 10
#define btn_p2_l 11

//Variables 
int i_controll;
int j_controll;
int started;
int game_level; //milliseconds (decrease for faster)

//Shift Register
#define lath_i 2 //ST_CP
#define cloc_i 3//SH_CP
#define data_i 4 //DS

#define lath_j 5
#define cloc_j 6
#define data_j 7

#define start 12
#define buzzer 13

void Game_Over(){
  while(!started){
    i_controll = 0; 
    j_controll = 0;  
  }
}
void setup() {
  Serial.begin(9600); 
  Serial.println("Setup iniciado!!");

  pinMode(lath_i, OUTPUT);
  pinMode(cloc_i, OUTPUT); 
  pinMode(data_i, OUTPUT);

  pinMode(lath_j, OUTPUT);
  pinMode(cloc_j, OUTPUT); 
  pinMode(data_j, OUTPUT);

  pinMode(start, INPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(btn_p1_r, INPUT);
  pinMode(btn_p1_l, INPUT);
  pinMode(btn_p2_r, INPUT);
  pinMode(btn_p2_l, INPUT);

  i = 4;
  j = 4;

  i_controll = 1;
  j_controll = 0;

  //Player Position
  player1_position = 4;
  player2_position = 4;

  Serial.println("Setup concluído!!");

}
void loop(){
  //PLAYER CONTROLLS
        if(digitalRead(btn_p1_r == HIGH)){
          player1_position++; 
          delay(50); 
        }
        if(digitalRead(btn_p1_l == HIGH)){
          player1_position--; 
          delay(50); 
        }
        player1 = player1_position; 
        
        if(digitalRead(btn_p2_r == HIGH)){
          player2_position++; 
          delay(50); 
        }
        if(digitalRead(btn_p2_l == HIGH)){
          player2_position--; 
          delay(50); 
        }
        player2 = player2_position; 
        delay(1000);

        //GAME ENGINE
        //Table Clean
        for(int k = 1; k < 9; k++){
         ball_i[k] = 0; 
         for(int w = 1; w < 9; w++){
           ball_j[w] = 0; 
         }
        }
 
        //Mark ball position
        i = i + i_controll;
        j = j + j_controll; 
        
        ball_i[i] = 1;
        ball_j[j] = 1; 
        
        //Register line
        digitalWrite(lath_i, LOW); 
        for(int data_reg_i = 0; data_reg_i < 7; data_reg_i++){
          digitalWrite(cloc_i, HIGH);
         digitalWrite(data_i, ball_i[data_reg_i]);
         Serial.print(ball_i[data_reg_i]);
         digitalWrite(cloc_i, LOW);  
          
        }
        digitalWrite(lath_i, HIGH); 
        Serial.println("");
           
        //Register column
          digitalWrite(lath_j, LOW); 
          for(int data_reg_j = 0; data_reg_j < 7; data_reg_j++){
            digitalWrite(cloc_j, HIGH);
            digitalWrite(data_j, ball_j[data_reg_j]);
            digitalWrite(cloc_j, LOW);  
          }
          digitalWrite(lath_j, HIGH);
        
        //Line Correction
        if(i == 1){
          if(player1 == j){
            i_controll = 1;
            Serial.println("Ponged!!"); 
            j_controll = 1;
          }
          if(player1 == j + 1){
            i_controll = -1;
            j_controll = -1;
          }
          else{
            Serial.println("Gameover 1"); 
            Game_Over();
          }
        }
        if(i == 8){
          if(player2 == j){
            i_controll = -1;
            Serial.println("Ponged!!"); 
            j_controll = 1;
          }
          if(player2 == j + 1){
            i_controll = -1;
            j_controll = -1;
          }
          else{
            Serial.println("Gameover 2"); 
            Game_Over();
          }
        }
        //Colunm correction
        if(j == 1){
          j_controll = 1;
        }
        if(j == 8){
          j_controll = -1;
        }
}
