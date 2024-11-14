#include "keyboard.h"
#include <termios.h>
#include <unistd.h>

int keyhit(void) {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt); 
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); 
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);  
    if (ch != EOF) {
        ungetc(ch, stdin);  
        return 1; 
    }
    return 0; 
}

char get_input(void) {
    char ch = getchar(); 
    return ch;
}


Screen.c
#include "screen.h"

void screenDrawBorders() {
  char hbc = BOX_HLINE;
  char vbc = BOX_VLINE;

  screenBoxEnable(); 

  screenGotoxy(MINX, MINY);
  printf("%c", BOX_UPLEFT);

  for (int i = MINX + 1; i < MAXX; i++) {
    screenGotoxy(i, MINY);
    printf("%c", hbc);
  }

  screenGotoxy(MAXX, MINY);
  printf("%c", BOX_UPRIGHT);

  for (int i = MINY + 1; i < MAXY; i++) {
    screenGotoxy(MINX, i);
    printf("%c", vbc);
    screenGotoxy(MAXX, i);
    printf("%c", vbc);
  }

  screenGotoxy(MINX, MAXY);
  printf("%c", BOX_DWNLEFT);
  for (int i = MINX + 1; i < MAXX; i++) {
    screenGotoxy(i, MAXY);
    printf("%c", hbc);
  }

  screenGotoxy(MAXX, MAXY);
  printf("%c", BOX_DWNRIGHT);

  screenBoxDisable();  
}

void screenInit(int drawBorders) {
  screenClear();
  if (drawBorders) 
    screenDrawBorders();
}

void screenDestroy() {

}

void screenSetColor(screenColor fg, screenColor bg) {
  char atr[] = "[0;";

  if (fg > LIGHTGRAY) {
    atr[1] = '1';
    fg -= 8;
  }

  printf("%s%s%d;%dm", ESC, atr, fg + 30, bg + 40);
}

void screenForca(int erros) {
      screenGotoxy(FORCA_X, FORCA_Y); 
      printf("%c%c%c", BOX_UPLEFT, BOX_HLINE, BOX_UPRIGHT);
      screenGotoxy(FORCA_X, FORCA_Y + 1);
      printf("%c%c%c", BOX_VLINE, ' ', BOX_VLINE); 
      screenGotoxy(FORCA_X, FORCA_Y + 2);
      printf("%c%c%c", BOX_VLINE, ' ', BOX_VLINE); 
      screenGotoxy(FORCA_X + 2, FORCA_Y + 2);      
      printf("%c", BOX_HLINE);                   
}

void screenTrofeu() {
      screenGotoxy(GANHAR_TROFEU_X,
                   GANHAR_TROFEU_Y); 
      printf("%c%c%c", BOX_UPLEFT, BOX_HLINE,
             BOX_UPRIG
