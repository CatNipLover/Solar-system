#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <math.h>
#include <stdio.h>
 
//Funkcaj obliczająca ruch planety
void planetRuch(int xrad, int yrad,
                  int midx, int midy,
                  int x[70], int y[70])
{
    int i, j = 0;
 
    //Ruch po orbicie
    for (i = 360; i > 0; i = i - 6) {
        x[j] = midx - (xrad * cos((i * 3.14) / 180));
        y[j++] = midy - (yrad * sin((i * 3.14) / 180));
    }
 
    return;
}
 
int main()
{
    //Wczytuje biblioteke i tworzy scene na której rysuje planety
    int gdriver = gmode, err;
    int i = 0, midx, midy;
    int xrad[9], yrad[9], x[9][70], y[9][70];
    int pos[9], planet[9], tmp;
 
    
    initgraph(&gdriver, &gmode, "");
    err = graphresult();
 
    if (err ! = grOk) {
 
        printf("Graphics Error: %s",
               grapherrormsg(err));
        return 0;
    }
 
    midx = getmaxx() - 220;
    midy = getmaxy() - 150;
 
    //Obliczanie promienia planet
    Planeta[0] = 8;
    for (i = 1; i < 9; i++) {
        planeta[i] = planeta[i - 1] + 1;
    }
 
    //Ustawianie odległości orbit
    for (i = 0; i < 9; i++) {
        pos[i] = i * 6;
    }
 
    Xrad[0] = 70, yrad[0] = 40;
    for (i = 1; i < 9; i++) {
        xrad[i] = xrad[i - 1] + 38;
        yrad[i] = yrad[i - 1] + 20;
    }
 

    for (i = 0; i < 9; i++) {
        planetRuch(xrad[i], yrad[i],
                     midx, midy, x[i],
                     y[i]);
    }
 
    while (!kbhit()) {
 
        //Rysowanie orbit
        Setcolor(WHITE);
        for (i = 0; i < 9; i++) {
            setcolor(CYAN);
            ellipse(midx, midy, 0, 360,
                    xrad[i], yrad[i]);
        }
 
        //Słońce
        outtextxy(midx, midy, "   Slonce");
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        circle(midx, midy, 30);
        floodfill(midx, midy, YELLOW);
 
        //Merkury
        Setcolor(CYAN);
 
        Setfillstyle(SOLID_FILL, CYAN);
        Outtextxy(x[0][pos[0]],
                  y[0][pos[0]],
                  " Merkury");
 
        Pieslice(x[0][pos[0]],
                 y[0][pos[0]],
                 0, 360, planeta[0]);
 
        //Venus
        Setcolor(GREEN);
        Setfillstyle(SOLID_FILL, GREEN);
        Outtextxy(x[1][pos[1]],
                  y[1][pos[1]],
                  " VENUS");
        Pieslice(x[1][pos[1]],
                 y[1][pos[1]],
                 0, 360, planeta[1]);
 
        //Ziemia
        Setcolor(BLUE);
        Setfillstyle(SOLID_FILL, BLUE);
        Outtextxy(x[2][pos[2]],
                  y[2][pos[2]],
                  " Ziemia");
        Pieslice(x[2][pos[2]],
                 y[2][pos[2]],
                 0, 360, planeta[2]);
 
        //Mars
        Setcolor(RED);
        Setfillstyle(SOLID_FILL, RED);
        Outtextxy(x[3][pos[3]],
                  y[3][pos[3]],
                  " MARS");
        Pieslice(x[3][pos[3]],
                 y[3][pos[3]],
                 0, 360, planeta[3]);
 
        //Jowisz
        setcolor(BROWN);
        setfillstyle(SOLID_FILL, BROWN);
        outtextxy(x[4][pos[4]],
                  y[4][pos[4]],
                  " Jowisz");
        pieslice(x[4][pos[4]],
                 y[4][pos[4]],
                 0, 360, planeta[4]);
 
        //Satrun
        Setcolor(LIGHTGRAY);
        Setfillstyle(SOLID_FILL, LIGHTGRAY);
        Outtextxy(x[5][pos[5]],
                  y[5][pos[5]],
                  "  Saturn");
        Pieslice(x[5][pos[5]],
                 y[5][pos[5]],
                 0, 360, planet[5]);
 
        //Uran
        Setcolor(LIGHTGREEN);
        Setfillstyle(SOLID_FILL, LIGHTGREEN);
                Outtextxy (x [6] [pos [6]],
                           y [6] [pos [6]],
                           "  Uran");
                pieslice (x [6] [pos [6]],
                          y [6] [pos [6]],
                          0, 360, planet [6]);
 
        //Neptun
        Setcolor (LIGHTBLUE);
        Setfillstyle (SOLID_FILL, LIGHTBLUE);
        Outtextxy (x [7] [pos [7]],
                   y [7] [pos [7]],
                   "  Neptun");
        Pieslice (x [7] [pos [7]],
                  y [7] [pos [7]],
                  0, 360, planet [7]);
 
        //Pluto
        Setcolor (LIGHTRED);
        Setfillstyle (SOLID_FILL, LIGHTRED);
        Outtextxy (x [8] [pos [8]],
                   y [8] [pos [8]],
                   "  Pluto");
        Pieslice (x [8] [pos [8]],
                  y [8] [pos [8]],
                  0, 360, planet [8]);
 
        //Symuluje jeden pełny ovrut po orbicie
        for (i = 0; i < 9; i++) {
            if (pos[i] <= 0) {
                pos[i] = 59;
            }
            else {
                pos[i] = pos[i] - 1;
            }
        }
                            
        //Spowalnia program o 100 milisekund 
        Delay (100);
                            
        Cleardevice ();
    }
 
    closegraph();
 
    return 0;
}