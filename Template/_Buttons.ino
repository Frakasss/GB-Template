void button_check(int typeCheck){
  switch(typeCheck){
     //####################################
     //########### Skip Logo ##############
     //####################################
     case GAMEMAKERS:
      if(gb.buttons.pressed(BUTTON_A)){
        game.globalTimer = 0;
        game.gameStatus=TITLESCREEN;
      }
     break;    
    
     //####################################
     //########### Skip title #############
     //####################################
     case TITLESCREEN:      
      if(gb.buttons.pressed(BUTTON_A)){
        game.globalTimer = 0;
        game.gameStatus=MENU;
      }
     break;   

     //####################################
     //########### Controls P1 ############
     //####################################
     case CONTROLS:      
      if(gb.buttons.pressed(BUTTON_A)){
        game.gameStatus=MENU;
      }
     break; 

     //####################################
     //########### Credits ################
     //####################################
     case CREDITS:      
      if(gb.buttons.pressed(BUTTON_A)){
        game.gameStatus=MENU;
      }
     break;
     
     //#######################################
     //############# Menu ####################
     //#######################################
     case MENU:      
      if(gb.buttons.pressed(BUTTON_A)){
        switch(game.menuOption){
          case 0:
          break;

          case 1:
            game.gameStatus=GAME;
          break;

          case 2:
            game.gameStatus=CONTROLS;
          break;

          case 3:
            game.gameStatus=CREDITS;
          break;
        }
      }

      if(gb.buttons.pressed(BUTTON_UP)){    
        game.menuOption = game.menuOption - 1;
        if(game.menuOption<=0){game.menuOption=3;}
      }

      if(gb.buttons.pressed(BUTTON_DOWN)){    
        game.menuOption = game.menuOption + 1;
        if(game.menuOption>=4){game.menuOption=1;}
      }


     //##################################
     case MENUPAUSE:
      if(gb.buttons.pressed(BUTTON_A)){
        if(game.menuPauseOption==0){
          game.gameStatus = game.pause;
        }else{
          game.globalTimer=0;
          game_init();
          gb.pickRandomSeed();
          game.gameStatus = TITLESCREEN;
        }
      }else{
        if(gb.buttons.pressed(BUTTON_UP)){    
          game.menuPauseOption = game.menuPauseOption - 1;
          if(game.menuPauseOption<0){game.menuPauseOption=1;}
        }
  
        if(gb.buttons.pressed(BUTTON_DOWN)){    
          game.menuPauseOption = game.menuPauseOption + 1;
          if(game.menuPauseOption>1){game.menuPauseOption=0;}
        } 
      }

      
     break; 
  }
}
