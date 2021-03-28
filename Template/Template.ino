#include <Gamebuino-Meta.h>
#define GAMEMAKERS 0
#define TITLESCREEN 1
#define MENU 2
#define GAME 3


#define CONTROLS 97
#define CREDITS 98
#define MENUPAUSE 99

#define SCREENHEIGHT 64
#define SCREENWIDTH 80



//###########################
//##### INFO Global #########
//###########################
typedef struct{
  int gameStatus; 
  int globalTimer;
  int pause;
  int menuOption;
  int menuPauseOption;
}GameInfo;
GameInfo game;




typedef struct {
  int8_t weapon;
  int8_t bonus;
  int8_t playerDamage;
  int8_t music;
}SoundInfo;
SoundInfo sounds;


int strategies[5][10];



//###########################
//##### Game Setup ##########
//###########################
void setup(){
  gb.begin();
  game_init();
  gb.pickRandomSeed();
  loop();
}


//###########################
//##### Game Loop ###########
//###########################
void loop(){
  while(1){
    if(gb.update()){
      game_manageGlobalCounter();
      
      switch ( game.gameStatus )
      {
         //####################################
         case GAMEMAKERS:
            outputScreen_gamemakers();
            button_check(GAMEMAKERS);
            break;

         //#################################### 
         case TITLESCREEN:
            outputScreen_clear();
            outputScreen_title();
            button_check(TITLESCREEN);
            break;


         //#################################### 
         case CONTROLS:
            outputScreen_clear();
            outputScreen_controls();
            button_check(CONTROLS);
            break;

         //#################################### 
         case CREDITS:
            outputScreen_clear();
            outputScreen_credits();
            button_check(CREDITS);
            break;

         //####################################  
         case MENU:
            outputScreen_clear();
            outputScreen_menu();
            button_check(MENU);
            break;
                       
         //####################################  
         case MENUPAUSE:
            outputScreen_clear();
            outputScreen_menu();
            button_check(MENUPAUSE);
            break;

         //####################################                     
         default:
            game.gameStatus = GAMEMAKERS;
            break;
      }
    }  
  }
}


