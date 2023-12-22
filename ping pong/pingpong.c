#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//loading masuk
void load(){

    // LOADING
  system("color F9 ");
  printf("\n\n\n\n\n\t\t\t\t\t\t  AYO PINGPONG BERSAMA KAMI...\n");
  printf("\n\t\t\t\t    ");
  for (int loading = 0; loading <= 50; loading++) {
    printf("%c", 219);
    Sleep(80);
    if (loading == 50) {
      printf("\n\n\t\t\t\t\t\t\t\t          Sabar ya pak,janlup di enter!");
      getch();
    }
  }system("cls");

  return(0);
}

void menu();
void gameRules();
void satu_player();
void dua_player();
void panah();
void loading();
void thanks();

int main()
{
    system("COLOR F1");
    ulangimenu:
    load();
    menu();
    goto ulangimenu;

    return 0;
}
void menu()
{
    system("cls");
	gotoxy(30,5);  printf("===========================================================");
    gotoxy(30,6);  printf("|                                                         |");
    gotoxy(30,7);  printf("|                      PING PONG GAME                     |");
    gotoxy(30,8);  printf("|                                                         |");
    gotoxy(30,9);  printf("===========================================================");

    int position = 1;
    int keyPressed = 0;
    int maxoption = 4;

    while(keyPressed != 13){
    gotoxy(32,12);arrowhere(1,position); printf("\t 1. Game Rules");
    gotoxy(32,13);arrowhere(2,position); printf("\t 2. Play 1 Player");
    gotoxy(32,14);arrowhere(3,position); printf("\t 3. Play 2 Player");
    gotoxy(32,15);arrowhere(4,position); printf("\t 4. Exit");
    gotoxy(30,17);  printf("===========================================================");
    keyPressed = getch();
        if(keyPressed == 80 && position !=4){
            position++;
        }else if(keyPressed == 72 && position !=1){
            position--;
        }else{
            position = position;
        }
        if(keyPressed == 13 && position == 1){
        loading();
        gameRules();
        getch();
        menu();
    	}
        else if(keyPressed == 13 && position == 2){
        loading();
        satu_player();
        getch();
        menu();
    	}else if(keyPressed == 13 && position == 3){
    	loading();
        dua_player();
        getch();
        menu();
    	}else if(keyPressed == 13 && position == 4){
        system("cls");
        thanks();
        exit(0);
    	}
	}
}
void arrowhere (int realposition,int arrowposition){
    if(realposition == arrowposition){
        printf("==>");
    }else{
        printf("   ");
    }
}

void gameRules()
{
    system("cls");
    printf("\n\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("\t\t\t\t|                      Game Rules                         |");
    printf("\n\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

    printf("\n\t\t\t\t\t\tRules Player 1 :");
    printf("\n\n\t\t\t\t\t\tPress -> A : Left Movement");
    printf("\n\n\t\t\t\t\t\tPress -> W : Up Movement");
    printf("\n\n\t\t\t\t\t\tPress -> S : Down Movement");
    printf("\n\n\t\t\t\t\t\tPress -> D : Right Movement\n");

    printf("\n\n\t\t\t\t\t\tRules Player 2 :");
    printf("\n\n\t\t\t\t\t\tPress -> J : Left Movement");
    printf("\n\n\t\t\t\t\t\tPress -> I : Up Movement");
    printf("\n\n\t\t\t\t\t\tPress -> K : Down Movement");
    printf("\n\n\t\t\t\t\t\tPress -> L : Right Movement\n");
}

void satu_player()
{
    system("cls");
    // deklarasi papan2
    int i2, j2;
    int xp2 = 5;
    int yp2 = 14;
    int pjgp2 = 2;
    int gerakpapan = 1;

    // deklarasi papan
    int i1, j1;
    int xp = 80;
    int yp = 14;
    int pjgp = 2;

    int gamemulai = 1;
    int skor1 = 0;
    int skor2 = 0;
    int x;
    int y;
    int dx, dy;
    int i, j;
    x = 7;
    y = 14;
    dx = 0;
    dy = 0;
    int game = 0;

    char key = 0;
ulang:
    while (gamemulai)
    {
        if (kbhit())
        {
            key = getch();
            if (key == 'w')
            {
                if (yp2 > 2)
                {
                    yp2 -= 1;
                    if (game == 0 && x == xp2 + 2)
                    {
                        y -= 1;
                    }
                }
            }

            else if (key == 27)
            {
                menu();
            }

            else if (key == 'a')
            {
                if (xp2 >= 2)
                {
                    xp2 -= 1;
                    if (game == 0 && x == xp2 + 3)
                    {
                        x -= 1;
                    }
                }
            }

            else if (key == 's')
            {
                if (yp2 + pjgp2 <= 29)
                {
                    yp2 += 1;
                    if (game == 0 && x == xp2 + 2)
                    {
                        y += 1;
                    }
                }
            }
            if (key == 'd')
            {
                if (xp2 <= 45)
                {
                    xp2 += 1;
                    if (game == 0 && x == xp2 + 1)
                    {
                        x += 1;
                    }
                }
            }

            else if (key == ' ')
            {
                game = 1;
                if (x == xp2 + 2)
                {
                    dx = 1;
                    dy = -1;
                }
            }
            else if (x == xp + 1)
            {
                game = 1;
                dx = -1;
                dy = 1;
            }
        }
        // clear / hapus
        system("cls");

        // gerak

        if ((y <= 1) || (y >= 30))
            dy = -dy;
        x += dx;
        y += dy;

        // gerak papan bot
        if ((yp <= 2) || (yp >= 32))
            gerakpapan = -gerakpapan;
        yp += gerakpapan;

        // cek kanan
        if (y >= yp && y <= yp + pjgp && x == xp - 1)
        {
            dx = -dx;
        }
        else if (x >= 100)
        {
            skor2 = skor2 + 1;
            system("cls");
            xp2 = 5;
            yp2 = 14;
            x = xp - 2;
            y = yp + 1;
            dx = -1;
            dy = 1;
            game = 1;
        }
        // cek krii
        if (y >= yp2 && y <= yp2 + pjgp2 && x == xp2 + 1)
        {
            dx = -dx;
        }
        else if (x <= 1)
        {
            skor1 = skor1 + 1;
            system("cls");
            xp2 = 5;
            yp2 = 14;
            x = xp2 + 2;
            y = yp2 + 1;
            dx = 0;
            dy = 0;
            game = 0;
            goto ulang;
        }

        // cetak poin
        int poin1 = 32, poin2 = 32, poin3 = 32, poin4 = 32, poin5 = 32, poin6 = 32, poin7 = 32, poin8 = 32, poin9 = 32, poin10 = 32, poin11 = 32, poin12 = 32, poin13 = 32, poin14 = 32, poin15 = 32, poin16 = 32, poin17 = 32, poin18 = 32, poin19 = 32, poin20 = 32, poin21 = 32, poin22 = 32, poin23 = 32, poin24 = 32;
        int poin1a = 32, poin2a = 32, poin3a = 32, poin4a = 32, poin5a = 32, poin6a = 32, poin7a = 32, poin8a = 32, poin9a = 32, poin10a = 32, poin11a = 32, poin12a = 32, poin13a = 32, poin14a = 32, poin15a = 32, poin16a = 32, poin17a = 32, poin18a = 32, poin19a = 32, poin20a = 32, poin21a = 32, poin22a = 32, poin23a = 32, poin24a = 32;
        int poinb = 32, poinc = 32, poind = 32, poine = 32, poinf = 32, poing = 32, poinh = 32;
        int poin1b = 32, poin1c = 32, poin1d = 32, poin1e = 32, poin1f = 32, poin1g = 32, poin1h = 32;
        int poin2b = 32, poin2c = 32, poin2d = 32, poin2e = 32, poin2f = 32, poin2g = 32, poin2h = 32;
        int poin3b = 32, poin3c = 32, poin3d = 32, poin3e = 32, poin3f = 32, poin3g = 32, poin3h = 32;
        int poin4b = 32, poin4c = 32, poin4d = 32, poin4e = 32, poin4f = 32, poin4g = 32, poin4h = 32;
        int poin5b = 32, poin5c = 32, poin5d = 32, poin5e = 32, poin5f = 32, poin5g = 32, poin5h = 32;

        // 220 garis bawah
        // 221 garis kiri
        // 32 spasi
        // 222 garis kanan
        // 223 grais atas
        if (skor1 == 0)
        {
            poin1 = 220;
            poin2 = 220;
            poin3 = 220;
            poin4 = 220;
            poin5 = 221;
            poin8 = 222;
            poin9 = 221;
            poin12 = 222;
            poin13 = 221;
            poin16 = 222;
            poin17 = 221;
            poin20 = 222;
            poin21 = 223;
            poin22 = 223;
            poin23 = 223;
            poin24 = 223;
        }
        else if (skor1 == 1)
        {
            poin1 = 219;
            poin2 = 219;
            poin6 = 219;
            poin10 = 219;
            poin14 = 219;
            poin18 = 219;
            poin22 = 219;
            poin21 = 219;
            poin23 = 219;
        }
        else if (skor1 == 2)
        {
            poin1 = 219;
            poin2 = 219;
            poin3 = 219;
            poin4 = 219;
            poin8 = 219;
            poin12 = 219;
            poin11 = 219;
            poin10 = 219;
            poin9 = 219;
            poin13 = 219;
            poin17 = 219;
            poin21 = 219;
            poin22 = 219;
            poin23 = 219;
            poin24 = 219;
        }
        else if (skor1 == 3)
        {
            poin1 = 223;
            poin2 = 223;
            poin3 = 223;
            poin4 = 219;
            poin8 = 219;
            poin9 = 223;
            poin10 = 223;
            poin11 = 223;
            poin12 = 219;
            poin16 = 219;
            poin20 = 219;
            poin24 = 219;
            poin22 = 220;
            poin23 = 220;
            poin21 = 220;
            gamemulai = 0;
        }

        gotoxy(75, 3);
        printf("%c%c%c%c%c%c%c%c%c%c%c\n", poin1, poin2, poin3, poin4, poin3b, poin3c, poin3d, poin3e, poin3f, poin3g, poin3h);
        gotoxy(75, 4);
        printf("%c%c%c%c%c%c%c%c%c%c%c\n", poin5, poin6, poin7, poin8, poin4b, poin4c, poin4d, poin4e, poin4f, poin4g, poin4h);
        gotoxy(75, 5);
        printf("%c%c%c%c%c%c%c%c%c%c%c\n", poin9, poin10, poin11, poin12, poin5b, poin5c, poin5d, poin5e, poin5f, poin5g, poin5h);
        gotoxy(75, 6);
        printf("%c%c%c%c\n", poin13, poin14, poin15, poin16);
        gotoxy(75, 7);
        printf("%c%c%c%c\n", poin17, poin18, poin19, poin20);
        gotoxy(75, 8);
        printf("%c%c%c%c\n", poin21, poin22, poin23, poin24);

        // skor player 2
        if (skor2 == 0)
        {
            poin1a = 220;
            poin2a = 220;
            poin3a = 220;
            poin4a = 220;
            poin5a = 221;
            poin8a = 222;
            poin9a = 221;
            poin12a = 222;
            poin13a = 221;
            poin16a = 222;
            poin17a = 221;
            poin20a = 222;
            poin21a = 223;
            poin22a = 223;
            poin23a = 223;
            poin24a = 223;
        }
        else if (skor2 == 1)
        {
            poin1a = 219;
            poin2a = 219;
            poin6a = 219;
            poin10a = 219;
            poin14a = 219;
            poin18a = 219;
            poin22a = 219;
            poin21a = 219;
            poin23a = 219;
        }
        else if (skor2 == 2)
        {
            poin1a = 219;
            poin2a = 219;
            poin3a = 219;
            poin4a = 219;
            poin8a = 219;
            poin12a = 219;
            poin11a = 219;
            poin10a = 219;
            poin9a = 219;
            poin13a = 219;
            poin17a = 219;
            poin21a = 219;
            poin22a = 219;
            poin23a = 219;
            poin24a = 219;
        }
        else if (skor2 == 3)
        {
            poin1a = 223;
            poin2a = 223;
            poin3a = 223;
            poin4a = 219;
            poin8a = 219;
            poin9a = 223;
            poin10a = 223;
            poin11a = 223;
            poin12a = 219;
            poin16a = 219;
            poin20a = 219;
            poin24a = 219;
            poin22a = 220;
            poin23a = 220;
            poin21a = 220;
            gamemulai = 0;
        }

        gotoxy(20, 3);
        printf("%c%c%c%c%c%c%c%c%c%c%c\n", poin1a, poin2a, poin3a, poin4a, poinb, poinc, poind, poine, poinf, poing, poinh);
        gotoxy(20, 4);
        printf("%c%c%c%c%c%c%c%c%c%c%c\n", poin5a, poin6a, poin7a, poin8a, poin1b, poin1c, poin1d, poin1e, poin1f, poin1g, poin1h);
        gotoxy(20, 5);
        printf("%c%c%c%c%c%c%c%c%c%c%c\n", poin9a, poin10a, poin11a, poin12a, poin2b, poin2c, poin2d, poin2e, poin2f, poin2g, poin2h);
        gotoxy(20, 6);
        printf("%c%c%c%c\n", poin13a, poin14a, poin15a, poin16a);
        gotoxy(20, 7);
        printf("%c%c%c%c\n", poin17a, poin18a, poin19a, poin20a);
        gotoxy(20, 8);
        printf("%c%c%c%c\n", poin21a, poin22a, poin23a, poin24a);

        // cetak
        gotoxy(x, y);
        printf("%c", 254);

        // batas atas
        int atas;
        gotoxy(0, 0);
        for (atas = 0; atas <= 101; atas++)
        {

            printf("%c", 219);
        }

        // batas kanan
        int kanan;
        for (kanan = 1; kanan <= 31; kanan++)
        {
            gotoxy(101, kanan);
            printf("%c", 219);
        }

        // batas krii
        int kiri;
        for (kiri = 0; kiri <= 31; kiri++)
        {
            gotoxy(0, kiri);
            printf("%c", 219);
        }

        if (skor1 == 10 || skor2 == 10)
        {
            gamemulai = 0;
        }

        // batas bawah
        int bawah;
        gotoxy(0, 31);
        for (bawah = 0; bawah <= 101; bawah++)
        {
            printf("%c", 219);
        }

        int baris;
        for (baris = 0; baris <= 29; baris++)
        {
            for (baris = 0; baris <= 29; baris++)
            {
                gotoxy(50, 1 + baris);
                printf("|");
            }
            printf("\n");
        }

        // papan2
        for (i2 = 0; i2 < pjgp2; i2++)
        {
            for (j2 = 0; j2 < 2; j2++)
            {
                gotoxy(xp2, yp2 + i2);
                printf("%c", 219);
                gotoxy(xp2 - 1, yp2 + i2);
                printf("%c", 222);
            }
            printf("\n");
        }

        // cetak papan
        for (i1 = 0; i1 < pjgp; i1++)
        {
            for (j1 = 0; j1 < 2; j1++)
            {
                gotoxy(xp, yp + i1);
                printf("%c", 219);
                gotoxy(xp + 1, yp + i1);
                printf("%c", 221);
            }

            printf("\n");
        }
        // tunda
        for (i = 1; i <= 5000; i++)
            for (j = 1; j <= 10000; j++)
                ;
    } // end while
    getch();
}

void dua_player()
{

    // deklarasi papan2
    int i2, j2;
    int xp2 = 5;
    int yp2 = 14;
    int pjgp2 = 2;

    // deklarasi papan
    int i1, j1;
    int xp = 80;
    int yp = 14;
    int pjgp = 2;

    int skor1 = 0;
    int skor2 = 0;
    int x;
    int y;
    int dx, dy;
    int i, j;
    x = 78;
    y = 14;
    dx = 0;
    dy = 0;
    int game = 0;
    int gamemulai = 1;

    char key = 0;
ulang:
    while (gamemulai)
    {
        if (kbhit())
        {
            key = getch();
            if (key == 'i')
            {
                if (yp > 2)
                {
                    yp -= 1;
                    if (game == 0 && x == xp - 2)
                    {
                        y -= 1;
                    }
                }
            }

            else if (key == 27)
            {
                menu();
            }

            else if (key == 'j')
            {
                if (xp >= 55)
                {
                    xp -= 1;
                    if (game == 0 && x == xp - 1)
                    {
                        x -= 1;
                    }
                }
            }

            else if (key == 'k')
            {
                if (yp + pjgp <= 29)
                {
                    yp += 1;
                    if (game == 0 && x == xp - 2)
                    {
                        y += 1;
                    }
                }
            }
            if (key == 'l')
            {
                if (xp <= 98)
                {
                    xp += 1;
                    if (game == 0 && x == xp - 3)
                    {
                        x += 1;
                    }
                }
            }
            if (key == 'w')
            {
                if (yp2 >= 3)
                {
                    yp2 -= 1;
                    if (game == 0 && x == xp2 + 2)
                    {
                        y -= 1;
                    }
                }
            }
            if (key == 'a')
            {
                if (xp2 >= 3)
                {
                    xp2 -= 1;
                    if (game == 0 && x == xp2 + 3)
                    {
                        x -= 1;
                    }
                }
            }
            else if (key == 's')
            {
                if (yp2 + pjgp2 <= 29)
                {
                    yp2 += 1;
                    if (game == 0 && x == xp2 + 2)
                    {
                        y += 1;
                    }
                }
            }
            if (key == 'd')
            {
                if (xp2 <= 45)
                {
                    xp2 += 1;
                    if (game == 0 && x == xp2 + 1)
                    {
                        x += 1;
                    }
                }
            }
            else if (key == ' ' && game == 0)
            {
                game = 1;
                if (x == xp2 + 2)
                {
                    dx = 1;
                    dy = -1;
                }
                else
                {
                    dx = -1;
                    dy = 1;
                }
            }
            else if (x == xp2 + 2 && key == ' ' && game == 0)
            {
                game = 1;
                dx = 1;
                dy = -1;
            }
        }
        // clear / hapus
        system("cls");

        // gerak

        if ((y <= 1) || (y >= 30))
            dy = -dy;
        x += dx;
        y += dy;

        // cek kanan
        if (y >= yp && y <= yp + pjgp && x == xp - 1)
        {
            dx = -dx;
        }
        else if (x >= 100)
        {
            skor2 = skor2 + 1;
            system("cls");
            xp2 = 5;
            yp2 = 14;
            xp = 80;
            yp = 14;
            x = xp - 2;
            y = yp + 1;
            dx = 0;
            dy = 0;
            game = 0;
            goto ulang;
        }
        // cek krii
        if (y >= yp2 && y <= yp2 + pjgp2 && x == xp2 + 1)
        {
            dx = -dx;
        }
        else if (x <= 1)
        {
            skor1 = skor1 + 1;
            system("cls");
            xp2 = 5;
            yp2 = 14;
            xp = 80;
            yp = 14;
            x = xp2 + 2;
            y = yp2 + 1;
            dx = 0;
            dy = 0;
            game = 0;
            goto ulang;
        }

        // cetak poin
        int poin1 = 32, poin2 = 32, poin3 = 32, poin4 = 32, poin5 = 32, poin6 = 32, poin7 = 32, poin8 = 32, poin9 = 32, poin10 = 32, poin11 = 32, poin12 = 32, poin13 = 32, poin14 = 32, poin15 = 32, poin16 = 32, poin17 = 32, poin18 = 32, poin19 = 32, poin20 = 32, poin21 = 32, poin22 = 32, poin23 = 32, poin24 = 32;
        int poin1a = 32, poin2a = 32, poin3a = 32, poin4a = 32, poin5a = 32, poin6a = 32, poin7a = 32, poin8a = 32, poin9a = 32, poin10a = 32, poin11a = 32, poin12a = 32, poin13a = 32, poin14a = 32, poin15a = 32, poin16a = 32, poin17a = 32, poin18a = 32, poin19a = 32, poin20a = 32, poin21a = 32, poin22a = 32, poin23a = 32, poin24a = 32;
        int poinb = 32, poinc = 32, poind = 32, poine = 32, poinf = 32, poing = 32, poinh = 32;
        int poin1b = 32, poin1c = 32, poin1d = 32, poin1e = 32, poin1f = 32, poin1g = 32, poin1h = 32;
        int poin2b = 32, poin2c = 32, poin2d = 32, poin2e = 32, poin2f = 32, poin2g = 32, poin2h = 32;
        int poin3b = 32, poin3c = 32, poin3d = 32, poin3e = 32, poin3f = 32, poin3g = 32, poin3h = 32;
        int poin4b = 32, poin4c = 32, poin4d = 32, poin4e = 32, poin4f = 32, poin4g = 32, poin4h = 32;
        int poin5b = 32, poin5c = 32, poin5d = 32, poin5e = 32, poin5f = 32, poin5g = 32, poin5h = 32;

        // 220 garis bawah
        // 221 garis kiri
        // 32 spasi
        // 222 garis kanan
        // 223 grais atas
        if (skor1 == 0)
        {
            poin1 = 220;
            poin2 = 220;
            poin3 = 220;
            poin4 = 220;
            poin5 = 221;
            poin8 = 222;
            poin9 = 221;
            poin12 = 222;
            poin13 = 221;
            poin16 = 222;
            poin17 = 221;
            poin20 = 222;
            poin21 = 223;
            poin22 = 223;
            poin23 = 223;
            poin24 = 223;
        }
        else if (skor1 == 1)
        {
            poin1 = 219;
            poin2 = 219;
            poin6 = 219;
            poin10 = 219;
            poin14 = 219;
            poin18 = 219;
            poin22 = 219;
            poin21 = 219;
            poin23 = 219;
        }
        else if (skor1 == 2)
        {
            poin1 = 219;
            poin2 = 219;
            poin3 = 219;
            poin4 = 219;
            poin8 = 219;
            poin12 = 219;
            poin11 = 219;
            poin10 = 219;
            poin9 = 219;
            poin13 = 219;
            poin17 = 219;
            poin21 = 219;
            poin22 = 219;
            poin23 = 219;
            poin24 = 219;
        }
        else if (skor1 == 3)
        {
            poin1 = 223;
            poin2 = 223;
            poin3 = 223;
            poin4 = 219;
            poin8 = 219;
            poin9 = 223;
            poin10 = 223;
            poin11 = 223;
            poin12 = 219;
            poin16 = 219;
            poin20 = 219;
            poin24 = 219;
            poin22 = 220;
            poin23 = 220;
            poin21 = 220;
            gamemulai = 0;
        }

        gotoxy(75, 3);
        printf("%c%c%c%c%c%c%c%c%c%c%c\n", poin1, poin2, poin3, poin4, poin3b, poin3c, poin3d, poin3e, poin3f, poin3g, poin3h);
        gotoxy(75, 4);
        printf("%c%c%c%c%c%c%c%c%c%c%c\n", poin5, poin6, poin7, poin8, poin4b, poin4c, poin4d, poin4e, poin4f, poin4g, poin4h);
        gotoxy(75, 5);
        printf("%c%c%c%c%c%c%c%c%c%c%c\n", poin9, poin10, poin11, poin12, poin5b, poin5c, poin5d, poin5e, poin5f, poin5g, poin5h);
        gotoxy(75, 6);
        printf("%c%c%c%c\n", poin13, poin14, poin15, poin16);
        gotoxy(75, 7);
        printf("%c%c%c%c\n", poin17, poin18, poin19, poin20);
        gotoxy(75, 8);
        printf("%c%c%c%c\n", poin21, poin22, poin23, poin24);

        // skor player 2
        if (skor2 == 0)
        {
            poin1a = 220;
            poin2a = 220;
            poin3a = 220;
            poin4a = 220;
            poin5a = 221;
            poin8a = 222;
            poin9a = 221;
            poin12a = 222;
            poin13a = 221;
            poin16a = 222;
            poin17a = 221;
            poin20a = 222;
            poin21a = 223;
            poin22a = 223;
            poin23a = 223;
            poin24a = 223;
        }
        else if (skor2 == 1)
        {
            poin1a = 219;
            poin2a = 219;
            poin6a = 219;
            poin10a = 219;
            poin14a = 219;
            poin18a = 219;
            poin22a = 219;
            poin21a = 219;
            poin23a = 219;
        }
        else if (skor2 == 2)
        {
            poin1a = 219;
            poin2a = 219;
            poin3a = 219;
            poin4a = 219;
            poin8a = 219;
            poin12a = 219;
            poin11a = 219;
            poin10a = 219;
            poin9a = 219;
            poin13a = 219;
            poin17a = 219;
            poin21a = 219;
            poin22a = 219;
            poin23a = 219;
            poin24a = 219;
        }
        else if (skor2 == 3)
        {
            poin1a = 223;
            poin2a = 223;
            poin3a = 223;
            poin4a = 219;
            poin8a = 219;
            poin9a = 223;
            poin10a = 223;
            poin11a = 223;
            poin12a = 219;
            poin16a = 219;
            poin20a = 219;
            poin24a = 219;
            poin22a = 220;
            poin23a = 220;
            poin21a = 220;
            gamemulai = 0;
        }

        gotoxy(20, 3);
        printf("%c%c%c%c%c%c%c%c%c%c%c\n", poin1a, poin2a, poin3a, poin4a, poinb, poinc, poind, poine, poinf, poing, poinh);
        gotoxy(20, 4);
        printf("%c%c%c%c%c%c%c%c%c%c%c\n", poin5a, poin6a, poin7a, poin8a, poin1b, poin1c, poin1d, poin1e, poin1f, poin1g, poin1h);
        gotoxy(20, 5);
        printf("%c%c%c%c%c%c%c%c%c%c%c\n", poin9a, poin10a, poin11a, poin12a, poin2b, poin2c, poin2d, poin2e, poin2f, poin2g, poin2h);
        gotoxy(20, 6);
        printf("%c%c%c%c\n", poin13a, poin14a, poin15a, poin16a);
        gotoxy(20, 7);
        printf("%c%c%c%c\n", poin17a, poin18a, poin19a, poin20a);
        gotoxy(20, 8);
        printf("%c%c%c%c\n", poin21a, poin22a, poin23a, poin24a);

        // cetak
        gotoxy(x, y);
        printf("%c", 254);

        // batas atas
        int atas;
        gotoxy(0, 0);
        for (atas = 0; atas <= 101; atas++)
        {

            printf("%c", 219);
        }

        // batas kanan
        int kanan;
        for (kanan = 1; kanan <= 31; kanan++)
        {
            gotoxy(101, kanan);
            printf("%c", 219);
        }

        // batas krii
        int kiri;
        for (kiri = 0; kiri <= 31; kiri++)
        {
            gotoxy(0, kiri);
            printf("%c", 219);
        }

        // batas bawah
        int bawah;
        gotoxy(0, 31);
        for (bawah = 0; bawah <= 101; bawah++)
        {
            printf("%c", 219);
        }

        int baris;
        for (baris = 0; baris <= 29; baris++)
        {
            for (baris = 0; baris <= 29; baris++)
            {
                gotoxy(50, 1 + baris);
                printf("|");
            }
            printf("\n");
        }

        // papan2
        for (i2 = 0; i2 < pjgp2; i2++)
        {
            for (j2 = 0; j2 < 2; j2++)
            {
                gotoxy(xp2, yp2 + i2);
                printf("%c", 219);
                gotoxy(xp2 - 1, yp2 + i2);
                printf("%c", 222);
            }
            printf("\n");
        }

        // cetak papan
        for (i1 = 0; i1 < pjgp; i1++)
        {
            for (j1 = 0; j1 < 2; j1++)
            {
                gotoxy(xp, yp + i1);
                printf("%c", 219);
                gotoxy(xp + 1, yp + i1);
                printf("%c", 221);
            }

            printf("\n");
        }
        // tunda
        for (i = 1; i <= 5000; i++)
            for (j = 1; j <= 10000; j++)
                ;
    } // end while
    getch();
}
void thanks()
{
    //program animasi
    int a, invoiceFound = 0;
    double b;
    char salam[] = "\n\n\n\n\t\t\t\t\t TERIMAKASIH UNTUK SATU SEMESTER INI PAK HENDRY   ";
    int k, l;
    printf("\n\n\n");
    for (a = 0; salam[a] != NULL; a++)
    {
        printf("%c", salam[a]);
        for (b = 0; b <= 9999999; b++)
        {
        }
    }
}
void loading(){
    system("cls");
    gotoxy(53,13);
    printf("LOADING ");
    for (int i=0; i<=2; i++){
        printf(". ");
        Sleep(500);
    }
}

