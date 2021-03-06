#include "includes/interfaces.h"

void DrawSideMenu() { //Haya Utami
  setcolor(WHITE);
  readimagefile("picture/pecimen.bmp",609,15,795,60);
  rectangle(606,15,795,594);
  rectangle(609,60,792,591);

  settextstyle(8, HORIZ_DIR,1);

  rectangle(624,75,780,105);
  outtextxy(645,84,"LEVEL");

  outtextxy(645, 126,"PLAYER NAME");
  rectangle(624,120,780,150);
  rectangle(624,120,780,210);

  outtextxy(675, 243,"SCORE");
  rectangle(624,240,780,270);
  rectangle(624,240,780,330);

  outtextxy(675, 366,"LIVES");
  rectangle(624,360,780,390);
  rectangle(624,360,780,495);

	outtextxy(636, 516,"BACK TO MENU");
	rectangle(624,510,780,540);

    settextstyle(2, HORIZ_DIR,4);
    outtextxy(675,555, "GOOD LUCK!");
}

void tampilan() //Auliya Aqma
{
    readimagefile("assets/images/background.bmp",0, 0 , 800, 600);
}

void tampilan2()//Auliya Aqma
{
    readimagefile("picture/pecimen.bmp",100, 10 , 700, 210);
    readimagefile("picture/pacman2.bmp",0, 200, 150, 580);
    readimagefile("picture/pacman2.bmp",650, 200, 800, 580);
}

void storymode()//Auliya Aqma
{
    playerControl player1;
    cleardevice();
    inputnama(&player1);
    chooseskin(&player1);
    InitGame(&player1);
    GameStart(&player1);
}

void chooseskin(playerControl * player){
    tampilan();
    settextstyle(8, HORIZ_DIR,4);
    outtextxy(297,300, "Choose Skin\n");
    readimagefile("assets/images/RedPacman/PacmanRightOpen.bmp",200,400,300,500);
    readimagefile("assets/images/GreenPacman/PacmanLeftOpen.bmp",500,400,600,500);
    while(1)
    {
        GetCursorPos(&cursorPosition);
        mX=cursorPosition.x;
        mY=cursorPosition.y;

       if (GetAsyncKeyState(VK_LBUTTON) && mX>=200 && mX<=300 && mY>=400 && mY<=500)
       {
           player->peciman.skin = 1;//GANTI DISINI DIT
           break;
       }
        else if (GetAsyncKeyState(VK_LBUTTON) && mX>=500 && mX<=600 && mY>=400&& mY<=500)
       {
            player->peciman.skin = 2;//GANTI DISINI DIT
            break;
       }
    }
}



void menuscore()//Auliya Aqma
{
    cleardevice();
    FILE *highscore;
    highscore = fopen("assets/files/highscore.dat","rb");
    dataStore scoreData;
    int y = 275;
    char score[7];
    int count=0;
    setcolor(15);
    tampilan2();
    outtextxy(275,250,"NAMA");
    outtextxy(525,250,"SCORE");
    fread(&scoreData, sizeof(scoreData), 1, highscore);
    while(!feof(highscore) && count<10){
      outtextxy(225, y, scoreData.name);
      sprintf(score, "%d", scoreData.score);
      outtextxy(500, y, score);
      y+=25;
      count++;
      fread(&scoreData, sizeof(scoreData), 1, highscore);
    }
    fclose(highscore);
    setcolor(4);
    readimagefile("picture/pacman1.bmp",335, 565, 360, 590);
    readimagefile("picture/pacman3.bmp",515, 565, 540, 590);
	outtextxy(370,570,"BACK TO MENU");
    while(1)
    {
        GetCursorPos(&cursorPosition);
        mX=cursorPosition.x;
        mY=cursorPosition.y;

       if (GetAsyncKeyState(VK_LBUTTON) && mX>=370 && mX<=470 && mY>=570)
       {
           menuutama();
            break;
       }
    }
}

void howtoplay()//Auliya Aqma
{
        int a=10,b=35,c=25;
    cleardevice();
    setcolor(15);
    readimagefile("picture/pacman1.bmp",200, 5, 225, 30);
    readimagefile("picture/pacman3.bmp",575, 5, 600, 30);
    settextstyle(8,HORIZ_DIR,3);
    outtextxy(320,5, "How To Play");
    settextstyle(8,HORIZ_DIR,1);
    outtextxy(a,b,"> Game ini dapat dimainkan oleh 1 Orang  ");
    outtextxy(a,b+(1*c),"> Peci-men dikontrol menggunakan keyboard. ");
    outtextxy(a,b+(2*c),"> Player menggerakan 1 Peci-men. ");
    outtextxy(a,b+(3*c),"> Kontrol Player :   ");
    outtextxy(a+50,b+(4*c),"o Arrow atas untuk menggerakan ke atas ");
    outtextxy(a+50,b+(5*c),"o Arrow bawah untuk menggerakan ke bawah  ");
    outtextxy(a+50,b+(6*c),"o Arrow kanan untuk menggerakan ke kanan  ");
    outtextxy(a+50,b+(7*c),"o Arrow kiri untuk menggerakan ke kiri ");
    outtextxy(a,b+(8*c),"> Peci-Men tidak dapat menembus pembatas/dinding labirin  ");
    outtextxy(a,b+(9*c),"> Pada sisi kanan dan kiri ada pintu khusus yang membuat Peci-Men");
    outtextxy(a,b+(10*c),"  berpindah tempat / teleport dari satu sisi ke sisi lainnya.  ");
    outtextxy(a,b+(11*c),"> Player diberikan 5 Nyawa. Terdapat bonus / sesajen untuk");
    outtextxy(a,b+(12*c),"  menambah skor dan lives (nyawa) dari karakter Pac-Man yang dimainkan.  ");
    outtextxy(a,b+(13*c),"> Peci-Men dapat memakan musuh dengan memakan 'Power Up', sehingga");
    outtextxy(a,b+(14*c),"  musuh berubah warna dan mencoba menghindari Peci-Men.  ");
    outtextxy(a,b+(15*c),"> Kondisi menang ditentukan saat semua ‘Pac-Dot’ termakan oleh ");
    outtextxy(a,b+(16*c),"  karakter Peci-Men dan Player dapat menyelesaikan seluruh level ");
    outtextxy(a,b+(17*c),"(7 level).");
    outtextxy(a,b+(17*c),"> Player akan dinyatakan kalah / Game Over jika Peci-Men terkena musuh");
    outtextxy(a,b+(18*c),"  dan nyawa habis.");
    outtextxy(a,b+(19*c),"> Terdapat portal (masuk dan keluar) yang secara random muncul.  ");

	readimagefile("picture/pacman1.bmp",335, 565, 360, 590);
	readimagefile("picture/pacman3.bmp",515, 565, 540, 590);
	setcolor(4);
	outtextxy(370,570,"BACK TO MENU");
	while(1)
    {
        GetCursorPos(&cursorPosition);
        mX=cursorPosition.x;
        mY=cursorPosition.y;

       if (GetAsyncKeyState(VK_LBUTTON) && mX>=370 && mX<=470 && mY>=570)
       {
           menuutama();
            break;
       }
    }
}

void aboutus() //Haya Utami
{
    cleardevice();
    setcolor(15);
    outtextxy(45,30, "  AAA    BBBBBBB   OOOOO  UUUU UUUU TTTTTTT   UUUU UUUU SSSSSSS");
    outtextxy(45,47, " AA AA    BB   BB OO   OO  UU   UU    TTT      UU   UU  SS   SS");
    outtextxy(45,64, "AA   AA   BB   BB OO   OO  UU   UU    TTT      UU   UU  SS");
    outtextxy(45,81, "AAAAAAA   BBBBBB  OO   OO  UU   UU    TTT      UU   UU  SSSSSSS");
    outtextxy(45,98, "AA   AA   BB   BB OO   OO  UU   UU    TTT      UU   UU       SS");
    outtextxy(45,115,"AA   AA   BB   BB OO   OO  UU   UU    TTT      UU   UU  SS   SS");
    outtextxy(35,130,"AAAA AAAA BBBBBBB   OOOOO   UUUUUUU    TTT      UUUUUUU  SSSSSSS ");
    rectangle(20,164,755,270);
    rectangle(20,270,755,490);
    outtextxy(350,185,"<Leader>");
    outtextxy(280,220,"Nama : Pega Kurniawan");
    outtextxy(280,240,"NIM  : 161511060");
    outtextxy(25,300,"Nama : Auliya Aqma Dinilah");
    outtextxy(25,320,"NIM  : 161511006");
    outtextxy(25,380,"Nama : Haya Utami Lutfi");
    outtextxy(25,400,"NIM  : 161511011");
    outtextxy(400,300,"Nama : Achmad Fadhitya Muharram");
    outtextxy(400,320,"NIM  : 161511034");
    outtextxy(400,380,"Nama : Fahmi Rosdiansyah Mahdani");
    outtextxy(400,400,"NIM  : 161511044");
    outtextxy(280,440,"Nama : Muhamad Hisyam Anshory");
    outtextxy(280,460,"NIM  : 161511052");
    setcolor(15);
    settextstyle(8,HORIZ_DIR,1);
    outtextxy(200,550,"Kelompok 9 - D3 Teknik Informatika");
    outtextxy(250,570,"POLITEKNIK NEGERI BANDUNG");
    readimagefile("picture/pacman1.bmp",315, 500, 340, 525);
    readimagefile("picture/pacman3.bmp",495, 500, 520, 525);
    setcolor(4);
    outtextxy(350,505, "BACK TO MENU");
    while(1)
    {
        GetCursorPos(&cursorPosition);
        mX=cursorPosition.x;
        mY=cursorPosition.y;

       if (GetAsyncKeyState(VK_LBUTTON) && mX>=370 && mX<=470 && mY>=505 && mY<=550)
       {
           menuutama();
            break;
       }
    }
}

void menuutama()//Auliya Aqma
{
    cleardevice();
    tampilan();
    setcolor(15);
    rectangle(350,280,505,340);
    settextstyle(9,HORIZ_DIR,2);
    outtextxy(385,300, "MENU");
    settextstyle(8,HORIZ_DIR,1);
    setcolor(9);
    outtextxy(400,355, "PLAY");
    outtextxy(395,380, "SCORE");
    outtextxy(370,405, "HOW TO PLAY");
    outtextxy(385,430, "ABOUT US");
    setcolor(4);
    outtextxy(400,458, "EXIT");
    while(1)
    {
        GetCursorPos(&cursorPosition);
        mX=cursorPosition.x;
        mY=cursorPosition.y;

       if (GetAsyncKeyState(VK_LBUTTON) && mX>=400 && mX<=470 && mY>=380 && mY<=404)
       {
           storymode();
            break;
       }
        else if (GetAsyncKeyState(VK_LBUTTON) && mX>=400 && mX<=470 && mY>=405&& mY<=429)
       {
           menuscore();
            break;
       }
        else if (GetAsyncKeyState(VK_LBUTTON) && mX>=400 && mX<=470 && mY>=430&& mY<=454)
       {
           howtoplay();
            break;
       }
        else if (GetAsyncKeyState(VK_LBUTTON) && mX>=400 && mX<=470 && mY>=455&& mY<=479)
       {
           aboutus();
            break;
       }
       else if (GetAsyncKeyState(VK_LBUTTON) && mX>=400 && mX<=470 && mY>=485 && mY<=509)
       {
           exit(1);
       }
    }
}

void inputnama(playerControl *player) //Haya Utami
{
    int idx;
    char c;
    char inputbuf[MAX_INPUT_LEN];
    int input_pos;
    int the_end;

    for(idx=0;idx<MAX_INPUT_LEN;idx++)
    inputbuf[idx]=0;
    input_pos = 0;
    the_end=0;
        do
        {
            cleardevice();
            setcolor(15);
            readimagefile("picture/pecimen.bmp",100,10,700,160);
            rectangle(100,250,700,400);
            settextstyle(3, HORIZ_DIR,4);
            outtextxy(280,260,"Player Name:");
            outtextxy (280, 300, inputbuf);
            c = getch();
            switch (c)
            {
                case 8: /* backspace */
                        if (input_pos)
                        {
                            input_pos--;
                            inputbuf[input_pos] = 0;
                        }
                        break;
                case 13: /* return */
                        the_end = 1;
                        break;
                default:
                if (input_pos < MAX_INPUT_LEN-1 && c >= 'A' && c <= 'z')
                {
                    inputbuf[input_pos] = c;
                    input_pos++;
                    inputbuf[input_pos] = 0;
                }
            }
        }while (!the_end);
    strcpy(player->name, inputbuf);
    cleardevice();
}

void drawNumber(int num, int posX, int posY, int posisi){ //Fahmi Rosdiansyah
  posX+=posisi*GRIDSIZE/2;
  switch(num){
    case 0: readimagefile("assets/images/0.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
    case 1: readimagefile("assets/images/1.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
    case 2: readimagefile("assets/images/2.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
    case 3: readimagefile("assets/images/3.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
    case 4: readimagefile("assets/images/4.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
    case 5: readimagefile("assets/images/5.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
    case 6: readimagefile("assets/images/6.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
    case 7: readimagefile("assets/images/7.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
    case 8: readimagefile("assets/images/8.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
    case 9: readimagefile("assets/images/9.bmp",posX, posY, posX + GRIDSIZE/2, posY + GRIDSIZE/2); break;
  }
}

void printScore(int score, int posX, int posY){//Fahmi Rosdiansyah
  int posisi;
  for(posisi=5;posisi>=0;posisi--){
    drawNumber(score%10,posX,posY,posisi);
    score/=10;
  }
}

void printLives(int lives, int posX, int posY){//Fahmi Rosdiansyah
  int i, x=posX;
  for(i=0;i<lives;i++){
    readimagefile("assets/images/RedPacman/PacmanRightOpen.bmp", x, posY, x+GRIDSIZE, posY+GRIDSIZE);
    x+=GRIDSIZE;
    if((i+1)%5==0){
      posY+=GRIDSIZE;
      x=posX;
    }
  }
}

void DrawStory(int level) {
    switch(level){
        case 1 :
          readimagefile("assets/images/noir.bmp",0,0,800,600);
          readimagefile("assets/images/story1.bmp",20,100,755,400);
          break;
        case 2 :
          readimagefile("assets/images/noir.bmp",0,0,800,600);
          readimagefile("assets/images/story2.bmp",20,100,755,400);
          break;
        case 3 :
          readimagefile("assets/images/noir.bmp",0,0,800,600);
          readimagefile("assets/images/story3.bmp",20,100,755,400);
          break;
        case 4 :
          readimagefile("assets/images/noir.bmp",0,0,800,600);
          readimagefile("assets/images/story4.bmp",20,100,755,400);
          break;
        case 5 :
          readimagefile("assets/images/noir.bmp",0,0,800,600);
          readimagefile("assets/images/story5.bmp",20,100,755,400);
          break;
        case 6 :
           readimagefile("assets/images/noir.bmp",0,0,800,600);
          readimagefile("assets/images/story6.bmp",20,100,755,400);
          break;
        case 7 :
          readimagefile("assets/images/noir.bmp",0,0,800,600);
          readimagefile("assets/images/story7.bmp",20,100,755,400);
          break;
        }
        delay(5000);
}
