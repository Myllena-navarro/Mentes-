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
             BOX_UPRIGHT); 
      screenGotoxy(GANHAR_TROFEU_X, GANHAR_TROFEU_Y + 1);
      printf("%c%c%c", BOX_VLINE, ' ', BOX_VLINE); 
      screenGotoxy(GANHAR_TROFEU_X, GANHAR_TROFEU_Y + 2);
      printf("%c%c%c", BOX_VLINE, ' ', BOX_VLINE); 
      screenGotoxy(GANHAR_TROFEU_X + 2, GANHAR_TROFEU_Y + 3);
      printf("%c", BOX_HLINE); 
}

void screenCaveira() {
      screenGotoxy(PERDER_CAVEIRA_X,
                   PERDER_CAVEIRA_Y); 
      printf("%c%c%c", BOX_UPLEFT, BOX_HLINE,
             BOX_UPRIGHT); 
      screenGotoxy(PERDER_CAVEIRA_X, PERDER_CAVEIRA_Y + 1);
      printf("%c%c%c", BOX_VLINE, ' ', BOX_VLINE); 
      screenGotoxy(PERDER_CAVEIRA_X + 2, PERDER_CAVEIRA_Y + 2);
      printf("%c", BOX_CROSS); 
}


void screenGotoxy(int x, int y) {
  
}

void screenBoxDisable() {

}

void screenUpdate(int erros) {
    screenForca(erros); 
}
