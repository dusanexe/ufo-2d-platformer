/*C Graphic app created by zombieexecutioner 2018*/
/* UFO 2D Platformer */


#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include <dos.h>
#include <stdlib.h>


#define KeyUp		72
#define	KeyDown		80
#define KeyLeft		75
#define	KeyRight	77
#define	KeyEsc		27
#define KeySpace    32

void ControlPlayer(int *rectPosX,int *rectPosY,int *getkey,int *speed);
void TextOnTop(int *x);
void DrawSun(int *x,int *y);
void DrawStars(int *s, int *sx, int *sy);
void DrawBomb(int *bomb);
void BombLoop(int *bomb);
void DrawBird(int *bi);
void DogLoop(int *v,int *d);
void NpcKidLoop(int *d,int *kid);
void DrawNpcKid(int *kid);
void DrawLadders();
void DrawBuilding();
void DrawNpcMan(int *v,int *h);
void DrawNpcDog(int *d);
void DrawRoadLine();
void DrawBarierBox();
void DrawPlayer(int *rectPosX,int *rectPosY);
void DrawShip();


/*start main program*/
main()
{
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	initwindow(800, 600, "", -3, -3);
	//int gd = DETECT,gm;
	//initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	int bomb=0; //boombloop
	int x = getmaxx()/4 , y = getmaxy()/3, radius; //paraeters for planet circle
	int s, sx, sy; //stars parameters
	int v=0 ,h=0; 	//Npcmanloop parameters
	int bi=0; 	//bird parameter
	int d=120; 	//NPC dog parameter
	int kid=100;     //NPC kid parameter
	int rectPosX = 100, rectPosY = 100, getkey, speed = 10; //player parameters
	int w;

       //	int r=50;
	int page=0;
	/*infinity while loop*/
	while(1)
	{

		setactivepage(page);
		setvisualpage(1-page);


		cleardevice();
		DrawStars(&s,&sx,&sy);
		DrawRoadLine();
		ControlPlayer( &rectPosX, &rectPosY, &getkey, &speed);
		TextOnTop( &x);
		DrawSun( &x, &y);
        DrawShip();

		if(bi<=350)
        {bi++;}

		DrawBird(&bi);

		//NpcMan Loop
 		if(v<=50){
		v++;h++;}
		if(h<=50){
		v++;}
		if(v==75){
		h=0;v++;}
		if(v>=385)
		{v=385;h++;}
		if(h>=320)
		{h=420;}

		DogLoop( &v, &d);
		NpcKidLoop( &d, &kid);
		BombLoop(&bomb);

		DrawLadders();
		DrawBuilding();
		DrawNpcMan( &v, &h);
		DrawNpcDog( &d);
		DrawNpcKid( &kid);
		DrawBomb(&bomb);
		DrawBarierBox();
		DrawPlayer( &rectPosX, &rectPosY);

		page=1-page;
		delay(70);

	 }//end while loop

	getch();
	closegraph();
	return 0;
}
 //end main program



/*player control loop*/
void ControlPlayer(int *rectPosX,int *rectPosY,int *getkey,int *speed)
{
	if(kbhit())//check if a key is pressed
		{
		*getkey=getch();
		}//end check key
	switch(*getkey)
		{
		case KeyLeft : if(*rectPosY==100&&*rectPosX>=0||*rectPosY==(-120)&&*rectPosX>490){*rectPosX -= *speed;}
		break;
		case KeyRight : if(*rectPosY==100&&*rectPosX<=730||*rectPosY==(-120)&&*rectPosX<=650){*rectPosX += *speed;}
		break;
		case KeyUp : if(*rectPosX>=485&&*rectPosX<=490&&*rectPosY>=(-110)){*rectPosY -= *speed;}
		break;
		case KeyDown : if(*rectPosX>=485&&*rectPosX<=490&&*rectPosY<=(90)){*rectPosY += *speed;}
		break;
		case KeyEsc : exit(0);
		}//end switch


 }


/*BombLoop*/
void BombLoop(int *bomb)
{
	if(*bomb<=300)
	{*bomb+=5;}
	if(*bomb>=300)
	{*bomb-=300;}
 }


/*npcdog loop*/
void DogLoop(int *v,int *d)
{
	if(*v>=385)
	{*d+=5;}
	if(*d>=380)
    {*d=385;}
 }


/*npckid loop*/
void NpcKidLoop(int *d,int *kid)
{
	if(*d>=235)
	{*kid+=5;}
	if(*kid==125)
	{*kid+=2;}
	if(*kid>=487)
	{*kid=489;}
 }


/*Draw Text on top*/
void TextOnTop(int *x)
{
	setcolor(GREEN);
	outtextxy(*x-100, 420, "Created Using Graphics in C by zombieexecutioner (2018).");
	outtextxy(*x-100, 440, "To move player use arrow keys, Press ESC to Quit..!");
 }


/*Draw Sun*/
void DrawSun(int *x,int *y)
{
	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	circle(*x, *y, 55);
	floodfill(*x, *y, RED);
	setcolor(YELLOW);
	ellipse(*x, *y, 122, 418, 100, 20);
 }


/*Draw Bird*/
void DrawBird(int *bi)
{
	setcolor(YELLOW);
	outtextxy(300-(*bi),150,",o-/\\'~");

 }


/*Draw Ship*/
void DrawShip()
{
    setcolor(CYAN);
    setfillstyle(LTSLASH_FILL,DARKGRAY);
    fillellipse(400,50,100,30);
    setcolor(BLUE);
    setfillstyle(SOLID_FILL,DARKGRAY);
    fillellipse(400,70,50,10);
}

/*draw ladder*/
void DrawLadders()
{
	setcolor(WHITE);
	line (518,400,518,170);
	line (532,400,532,170);

	line (518,380,532,380);
	line (518,360,532,360);
	line (518,340,532,340);
	line (518,320,532,320);
	line (518,300,532,300);
	line (518,280,532,280);
	line (518,260,532,260);
	line (518,240,532,240);
	line (518,220,532,220);
	line (518,200,532,200);
	line (518,180,532,180);
 }

/*Draw building*/
void DrawBuilding()
{
	setfillstyle(HATCH_FILL, 7);
	bar3d (535,190,680,400,30,20);
	setfillstyle(SLASH_FILL, WHITE);
	bar (560,230,590,260);
	bar (560,290,590,320);
	bar (620,230,650,260);
	bar (620,290,650,320);
	setfillstyle(LINE_FILL, BLUE);
	bar (600,350,625,400);
	setcolor(LIGHTGRAY);
	line (535,190,680,190);
 }

/*draw stars*/
void DrawStars(int *s,int *sx,int *sy)
{
		for(*s=0; *s<=800; *s++)
		{*sx=rand()%getmaxx();
		*sy=rand()%285;
		putpixel(*sx,*sy,WHITE);}
 }

/*draw npcman*/
void DrawNpcMan(int *v,int *h)
{
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, YELLOW);
	circle(25+*v, 365-*h, 5);
	floodfill(25+*v, 365-*h, YELLOW);
	setcolor(BLACK);
	//outtextxy(19+*v,359-*h,"..");
	//outtextxy(22+*v,361-*h,"_");
	setfillstyle(SOLID_FILL,BLUE);
	bar (20+*v, 385-*h, 29+*v, 370-*h);
	/*npcman legs*/
	setfillstyle(SOLID_FILL, BROWN);
	bar (22+*v, 400-*h, 24+*v, 386-*h);
	bar (26+*v, 400-*h, 28+*v, 386-*h);
	/*npcman hands*/
	setcolor(BLUE);
	line (16+*v, 385-*h, 20+*v, 370-*h);
	line (33+*v, 385-*h, 29+*v, 370-*h);

 }

/*Draw npcdog cration*/
void DrawNpcDog(int *d)
{
	setcolor(BROWN);
	bar (314+*d,390,330+*d,394);
	line(310+*d,387,314+*d,390);
	bar (334+*d,390,326+*d,387);
	line (315+*d,390,316+*d,400);
	line (318+*d,390,320+*d,400);
	line (327+*d,390,325+*d,400);
	line (328+*d,390,328+*d,400);

 }
/*draw npc kid*/
void DrawNpcKid(int *kid)
{
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, YELLOW);
	circle(650-*kid,370,4);
	floodfill(650-*kid,370,YELLOW);
	setcolor(BLACK);
	//outtextxy(643-*kid,364,"..");
	setfillstyle(SOLID_FILL,CYAN);
	bar(647-*kid,375,653-*kid,388);
	/*npckid legs*/
	setfillstyle(SOLID_FILL, BROWN);
	bar (647-*kid, 400, 649-*kid, 388);
	bar (651-*kid, 400, 653-*kid, 388);
	/*npckid hands*/
	setcolor(CYAN);
	line (647-*kid, 375, 643-*kid, 388);
	line (653-*kid, 375, 657-*kid, 388);
 }

/*draw road*/
void DrawRoadLine()
{
	setcolor(GREEN);
	line (0, 390, getmaxx(), 380);
	setcolor(DARKGRAY);
	line (0, 345, 534, 350);
	line (711, 350, getmaxx(), 350);
	arc(450,390,30,130,100);
	arc(345,429,50,118,120);
	arc(175,490,50,130,200);
	arc(0,380,40,140,100);
	arc(766,429,50,118,120);

 }



/*Draw barierbox*/
void DrawBarierBox()
{       setcolor(BROWN);
	setfillstyle(LTBKSLASH_FILL,BROWN);
	bar3d (73, 400, 90, 378, 5, 10);
	setfillstyle(CLOSE_DOT_FILL,RED);
	bar3d (150,400, 200, 350,10, 10);
	setfillstyle(LINE_FILL,LIGHTGRAY);
	bar (155,360, 170, 375);
	setfillstyle(LTBKSLASH_FILL,BROWN);
	pieslice(178,310,225,320,50);
 }

/*Draw Bomb*/
void DrawBomb(int *bomb)
{
	setfillstyle(WIDE_DOT_FILL,CYAN);
	bar(400,70+*bomb,420,120+*bomb);
	}

/*Draw player creation*/
void DrawPlayer(int *rectPosX,int *rectPosY)
{
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, YELLOW);
	circle(*rectPosX+35,*rectPosY+264, 6);

	floodfill(*rectPosX+35,*rectPosY+265, YELLOW);
	setcolor(BLACK);
	//outtextxy(*rectPosX+28,*rectPosY+259,"..");
	//outtextxy(*rectPosX+32,*rectPosY+260,"_");
	setfillstyle(SOLID_FILL,RED);
	bar (*rectPosX+30, *rectPosY+283, *rectPosX+40,*rectPosY+270);
	setfillstyle(SOLID_FILL,LIGHTBLUE);
	bar (*rectPosX+31, *rectPosY+300, *rectPosX+39, *rectPosY+284);
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar (*rectPosX+29,*rectPosY+262,*rectPosX+41,*rectPosY+258);
	setcolor(LIGHTGRAY);
	line (*rectPosX+25,*rectPosY+262,*rectPosX+44,*rectPosY+262);
 }



