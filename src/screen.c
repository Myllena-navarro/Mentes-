#include "screen.h"

void screenDrawBorders() 
{
    char hbc = BOX_HLINE;
    char vbc = BOX_VLINE;
    
    screenClear();
    screenBoxEnable();
    
    screenGotoxy(MINX, MINY);
    printf("%c", BOX_UPLEFT);

    for (int i=MINX+1; i<MAXX; i++)
    {
        screenGotoxy(i, MINY);
        printf("%c", hbc);
    }
    screenGotoxy(MAXX, MINY);
    printf("%c", BOX_UPRIGHT);

    for (int i=MINY+1; i<MAXY; i++)
    {
        screenGotoxy(MINX, i);
        printf("%c", vbc);
        screenGotoxy(MAXX, i);
        printf("%c", vbc);
    }

    screenGotoxy(MINX, MAXY);
    printf("%c", BOX_DWNLEFT);
    for (int i=MINX+1; i<MAXX; i++)
    {
        screenGotoxy(i, MAXY);
        printf("%c", hbc);
    }
    screenGotoxy(MAXX, MAXY);
    printf("%c", BOX_DWNRIGHT);

    screenBoxDisable();
    
}

void screenInit(int drawBorders)
{
    screenClear();
    if (drawBorders) screenDrawBorders();
    screenHomeCursor();
    screenHideCursor();
}

void screenDestroy()
{
    printf("%s[0;39;49m", ESC); 
    screenSetNormal();
    screenClear();
    screenHomeCursor();
    screenShowCursor();
}

void screenGotoxy(int x, int y)
{
    x = ( x<0 ? 0 : x>=MAXX ? MAXX-1 : x);
    y = ( y<0 ? 0 : y>MAXY ? MAXY : y);
    
    printf("%s[f%s[%dB%s[%dC", ESC, ESC, y, ESC, x);
}

void screenSetColor( screenColor fg, screenColor bg)
{
    char atr[] = "[0;";

    if ( fg > LIGHTGRAY )
    {
        atr[1] = '1';
		fg -= 8;
    }

    printf("%s%s%d;%dm", ESC, atr, fg+30, bg+40);
}

void screenShowTime(int time) {
    char timeMessage[20];
    sprintf(timeMessage, "Tempo restante: %d segundos", time);

    int msgLen = strlen(timeMessage);

    int msgX = (MAXX - msgLen) / 2;
    int msgY = MAXY - 2;
    screenGotoxy(centerX, centerY);

    printf("%s", timeMessage);
}


void screenWelcome() {
    char welcomeMessage[] = "Bem-vindo ao jogo da Forca!!";
    int msgLen = strlen(welcomeMessage);
    
    int msgX = (MAXX - msgLen) / 2;
    int msgY = MAXY / 2;
    
    screenGotoxy(msgX, msgY);
    printf("%s", welcomeMessage);
}

void screenDrawHangman(int errors) {
    char hangman[] = 
        "  ________\n"
        "  |      |\n"
        "  |      %c%c%c\n"
        "  |      %c%c%c\n"
        "  |      %c\n"
        "  |      %c%c\n"
        "  |          \n"
        " _|___       \n";

    printf(hangman, 
           (errors >= 1 ? '(' : ' '), 
           (errors >= 1 ? '_' : ' '), 
           (errors >= 1 ? ')' : ' '),
           (errors >= 3 ? '\\' : ' '), 
           (errors >= 2 ? '|' : ' '), 
           (errors >= 3 ? '/' : ' '), 
           (errors >= 2 ? '|' : ' '), 
           (errors >= 4 ? '/' : ' '), 
           (errors > 4 ? '\\' : ' '));
}

void screenDrawTrophy() {
    char trophyMessage[] = "Parabéns, você acertou a palavra!";
    char trophy[] = 
        "     ___________   \n"
        "    '._==_==_=_.'  \n"
        "    .-\\:      /-. \n"
        "   | (|:.     |) | \n"
        "    '-|:.     |-'  \n"  
        "      \\::.    /   \n"
        "       '::. .'     \n"
        "         ) (       \n"  
        "       _.' '._     \n"
        "       '-----'     \n\n"; 

    printf("%s\n", trophyMessage);
    printf("%s", trophy);
}

void screenDrawGameOver() {
    char gameOverMessage[] = "Você perdeu! A palavra era: ";
    char hangman[] = 
        "   _______________         \n"
        "  /               \\       \n"
        " /                  \\     \n"
        "//                   \\    \n"
        " |   ----     ----   | /   \n"
        " |   ----     ----   |/    \n"
        " |    ---     ---    |     \n"
        " |                   |     \n"
        " \\__     ---     __/      \n"
        "   |\\    ---     /|       \n"
        "   | |           | |       \n"
        "   | X X X X X X X |       \n"   
        "   |  X X X X X X  |       \n"
        "   \\_            _/       \n"
        "     \\_         _/        \n"
        "       \\_______/          \n";

    printf("%s%s\n", gameOverMessage);

    printf("%s", hangman);
}
