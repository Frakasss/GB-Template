void game_init(){
  game.gameStatus = GAMEMAKERS;
  game.globalTimer = 0;
  game.pause=0;
  game.menuOption=1;
  game.menuPauseOption=0;
}

void game_manageGlobalCounter(){
  switch ( game.gameStatus ){
     //#################################### 
     case GAMEMAKERS:
        if(game.globalTimer<30){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
          game.gameStatus = TITLESCREEN;
        }
        break;

     //####################################  
     case TITLESCREEN:
        if(game.globalTimer<30){
          game.globalTimer = game.globalTimer +1;
        }else{
          game.globalTimer = 0;
          game.gameStatus = MENU;
        }
        break;
     //####################################  
     case MENU:
        break;
        
     //####################################  
     case CONTROLS:
        break;
        
     //####################################  
     case CREDITS:
        break;
        

     //####################################  
     case MENUPAUSE:
        break;

                          
     default:
        game.gameStatus = GAMEMAKERS;
        break;
  }
}

