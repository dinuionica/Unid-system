// Copyright 2021 Dinu Ion Irinel
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "functions.h"
#include "menu.h"
#include "quiz_game.h"


 // this function is gonna show the menu of the game
void menu() {
  printf("-------------------------  WORLD CAPITALS QUIZ GAME ---------------------------- \n\n");
  printf("---START A NEW GAME   -> 1 ----------------------------------------------------- \n\n");
  printf("---SHOW YOUR BEST SCORE -> 2 --------------------------------------------------- \n\n");
  printf("---HELP OPTIONS -> 3 --------------------------------------------------- \n\n");
  printf("---EXIT -> 4 ------------------------------------------------------------------- \n\n");
  printf("---PLEASE ENTER A OPTION : ");
}

// this function is gonna start the game itself
void game() {
  int score = 0;
  system("clear");
  printf("-------------------------  WORLD CAPITALS QUIZ GAME ---------------------------- \n\n");
  printf(" NOW YOU WILL RECEIVE SOME QUESTIONS AND YOU MUST TO  ANSWER OF EATCH WITH 1,2,3,4 THAT IS TRUE \n\n");
  printf(" WHAT IS THE CAPITAL OF ROMANIA ? \n 1.CONSTNATA\n 2.IASI\n 3.BUCURESTI\n 4.CLUJ  \n\n");
  int answer;
  printf(" THE CORRECT ANSWER IS : ");
  scanf("%d", & answer);
  if (answer == 3)
    score++;
  system("clear");

  //this are instructions for a answer of a questions
  printf(" SCORE : %d\n\n", score);
  printf(" WHAT IS THE CAPITAL OF RUSIA ? \n 1.TALLIN\n 2.MOSCOW\n 3.DUBLIN\n 4.MADRID  \n\n");
  printf(" THE CORRECT ANSWER IS : ");
  scanf("%d", & answer);
  if (answer == 2)
    score++;
  system("clear");


  printf(" SCORE : %d\n\n", score);
  printf(" WHAT IS THE CAPITAL OF BULGARIA ? \n 1.SOFIA\n 2.PARIS\n 3.DUBLIN\n 4.COPENHAGA  \n\n");
  printf(" THE CORRECT ANSWER IS : ");
  scanf("%d", & answer);
  if (answer == 1)
    score++;
  system("clear");


  printf(" SCORE : %d\n\n", score);
  printf(" WHAT IS THE CAPITAL OF SPAIN ? \n 1.TIRANA\n 2.CHISINAU\n 3.MADRID\n 4.PARIS  \n\n");
  printf(" THE CORRECT ANSWER IS : ");
  scanf("%d", & answer);
  if (answer == 3)
    score++;
  system("clear");


  printf(" SCORE : %d\n\n", score);
  printf(" WHAT IS THE CAPITAL OF FRANCE ? \n 1.DUBLIN\n 2.BRATISLAVA\n 3.LONDRA\n 4.PARIS  \n\n");
  printf(" THE CORRECT ANSWER IS : ");
  scanf("%d", & answer);
  if (answer == 4)
    score++;
  system("clear");

 
  printf(" SCORE : %d\n\n", score);
  printf(" WHAT IS THE CAPITAL OF DANEMARK ? \n 1.COPENHAGA\n 2.BRATISLAVA\n 3.NICOSIA\n 4.BERLIN  \n\n");
  printf(" THE CORRECT ANSWER IS : ");
  scanf("%d", & answer);
  if (answer == 1)
    score++;
  system("clear");

 
  printf(" SCORE : %d\n\n", score);
  printf(" WHAT IS THE CAPITAL OF ITALY ? \n 1.ROMA\n 2.BERLIN\n 3.SARAJEVO\n 4.DUBLIN  \n\n");
  printf(" THE CORRECT ANSWER IS : ");
  scanf("%d", & answer);
  if (answer == 1)
    score++;
  system("clear");


  printf(" SCORE : %d\n\n", score);
  printf(" WHAT IS THE CAPITAL OF GERMANY ? \n 1.PARIS\n 2.BERLIN\n 3.BRATISLAVA\n 4.BUCURESTI  \n\n");
  printf(" THE CORRECT ANSWER IS : ");
  scanf("%d", & answer);
  if (answer == 2)
    score++;
  system("clear");


  printf(" SCORE : %d\n\n", score);
  printf(" WHAT IS THE CAPITAL OF PORTUGAL  ? \n 1.PARIS\n 2.BERLIN\n 3.LISABONA\n 4.VIENA  \n\n");
  printf(" THE CORRECT ANSWER IS : ");
  scanf("%d", & answer);
  if (answer == 2)
    score++;
  system("clear");

  
  printf(" SCORE : %d\n\n", score);
  printf(" WHAT IS THE CAPITAL OF AUSTRIA  ? \n 1.PARIS\n 2.VIENA \n 3.LUJBLIANA\n 4.ROMA  \n\n");
  printf(" THE CORRECT ANSWER IS : ");
  scanf("%d", & answer);
  if (answer == 2)
    score++;
  system("clear");


  printf(" SCORE : %d\n\n", score);
  printf(" WHAT IS THE CAPITAL OF CIPRU  ? \n 1.PARIS\n 2.VIENA \n 3.NICOSIA \n 4.COPENHAGA  \n\n");
  printf(" THE CORRECT ANSWER IS : ");
  scanf("%d", & answer);
  if (answer == 3)
    score++;
  system("clear");


  printf(" SCORE : %d\n\n", score);
  printf(" WHAT IS THE CAPITAL OF ENGLAND  ? \n 1.PARIS\n 2.ROMA \n 3.TALLIN \n 4.LONDRA  \n\n");
  printf(" THE CORRECT ANSWER IS : ");
  scanf("%d", & answer);
  if (answer == 4)
    score++;
  system("clear");


  printf(" SCORE : %d\n\n", score);
  printf(" WHAT IS THE CAPITAL OF IRLEND  ? \n 1.PARIS\n 2.ROMA \n 3.DUBLIN \n 4.BUCURESTI  \n\n");
  printf(" THE CORRECT ANSWER IS : ");
  scanf("%d", & answer);
  if (answer == 3)
    score++;
  system("clear");

  printf(" CONGRATULATIONS, YOU ANSWERED CORRECTLY OF  %d", score);
  printf(" QUESTIONS ! \n\n");
  printf(" YOU ARE SO GOOD ...");
  printf(" IF YOU WANT TRY AGAIN ----> PRESS 1 ");
  int option = 0;
  scanf("%d", & option);
  if (option == 1) {
    system("clear");
    quiz_game();
  }
  // now we are gonna save the best score of the player
  int max = 0;
  FILE * file = fopen("score.txt", "r");
  if (file == NULL) {
    fprintf(stderr,"Error of malloc!\n");
  }
  fscanf(file, "%d", & max);
  fclose(file);
  if (score > max) {
    file = fopen("score.txt", "w");
    fprintf(file, "%d", score);
    fclose(file);
  }
}

// this function is gonna show the best_score of the player
void best_score() {
  system("clear");
  int score = 0;
  FILE * file = fopen("score.txt", "r");
  if (file == NULL) {
    fprintf(stderr,"Error of malloc!\n");
  }
  fscanf(file, "%d", & score);
  fclose(file);
  printf("---------------CONGRATULATIONS, YOU ARE ONE OF THE BEST PLAYER !----------\n\n");
  printf("--------------- YOUR BEST SCORE IS :%d", score);

}

// this function is gonna show the help instruction and  version of the game
void help() {
  system("clear");
  printf("\n\n");
  printf(" THIS IS A SIMPLE QUIZ GAME CREATED BY DINU ION-IRINEL \n\n");
  printf(" IT'S VERY EASY TO PLAY,JUST START THE GAME AND CHOOSE THE CORRECT ANSWER \n\n");
  printf(" ALSO YOU HAVE THE POSIBILLITY TO SEE YOUR BEST SCORE  \n\n");
  printf(" WORLD CAPITALS QUIZ GAME ---- VERSION 1.0.1");
  system("clear");
  quiz_game();
}


void quiz_game(){
  menu();
  // this is the switch option witch is gonna offer to player the posibility to enter a option
  int option = 0;
  scanf("%d", & option);
  switch (option) {
  case 1:
    game();
    break;
  case 2:
    best_score();
    break;
  case 3:
    help();
    break;
  case 4:
    break;
  default:
    printf(" YOUR OPTION IS WRONG...");
    break;
  }

}
