/* UFO 2D Platformer*/
/*C Graphic app created Jan 2018*/


/*C Graphic app created Jan 2018 - updated Jul 2018*/
/* Author Dusanexe 81/14R */


#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include <dos.h>
#include <stdlib.h>
#include <windows.h>

#include "main.h"

/*start main program*/
int main()
{


    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

	initwindow(screenWidth, screenHeight, "", -3, -3);
	//int gd = DETECT,gm;
	//initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	laser.la=0; //laserloop

	planet.x = getmaxx()/4 , planet.y = getmaxy()/3, planet.radius; //parameters for planet circle
	planet.px= 150, planet.py = 150;                                //parameters for planet ellipse

	npcman.v=0; npcman.h=0; //Npcmanloop parameters

	bird.bi=0; 	//bird parameter

	dog.d=120; 	//NPC dog parameter

	kid.k=100;     //NPC kid parameter

	player.rectPosX = 0;
	player.rectPosY = 0;
	player.speed = SPEED; //player parameters
    	player.ldisp = 0;

	int page=0;
    	int start=0;
    	int bary=0;
    	int del=10;
	
	while(1){
	while(start==0)
	{

		setactivepage(page);
		setvisualpage(1-page);

        	controlMenu(&player.getKey1, &start, &bary, &del);

        	

       		setcolor(GREEN);

		cleardevice();
        	//restart variables

        	npcman.v=0; npcman.h=0; //Npcmanloop parameters
        	bird.bi=0; 	//bird parameter
        	dog.d=120; 	//NPC dog parameter
        	kid.k=100;     //NPC kid parameter
        	player.rectPosX = 0;
        	player.rectPosY = 0;

        	setcolor(BLUE);
        	setfillstyle(SLASH_FILL, 7);
        	bar3d (100,205,200,505,30,30);
        	bar3d (80,150,390,205,30,20);
        	bar3d (300,205,390,405,30,20);
        	bar3d (200,405,390,505,30,20);



        setfillstyle(INTERLEAVE_FILL,LIGHTCYAN);
        setcolor(LIGHTGRAY);
        bar3d(400,140+bary,560,180+bary,10,10);
        setcolor(YELLOW);
        char myStr[128];
        char myStr1[128];
        char myStr2[128];
        char myStr3[128];
        char myStr4[128];
        sprintf(myStr, "NEW GAME");
        sprintf(myStr1, "QUIT");

        sprintf(myStr2, "GAME SPEED:%d",del);

        sprintf(myStr3, "'WSAD' or 'AROWS' FOR MOVING");
        sprintf(myStr4, "'SPACE' FOR JUMPING");


        outtextxy(421,150, myStr);
        outtextxy(421,270, myStr1);
        setcolor(RED);
        outtextxy(421,190, myStr2);
        setcolor(GREEN);
        outtextxy(440,460, myStr3);
        outtextxy(440,480, myStr4);
		page=1-page;
		delay(del);

	 }//end while loop0

	/* while loop*/
	while(player.rectPosY<=629)
	{

		setactivepage(page);
		setvisualpage(1-page);

        //colusion
        player.rectPosY += GRAVITY;

        


        //box collision
        if(player.rectPosX>33&&player.rectPosX<63&& player.rectPosY>=78&&player.rectPosY<=80)
        {
            player.rectPosY-=GRAVITY;
            player.grounded=true;
        }
        //house collision
        if(player.rectPosX>113&&player.rectPosX<173&& player.rectPosY>=50&& player.rectPosY<=54)
        {
            player.rectPosY-=GRAVITY;
            player.grounded=true;

        }
        //building collision
        if(player.rectPosX>490&&player.rectPosX<660&& player.rectPosY<= -105 && player.rectPosY>=-122)
        {
            player.rectPosY-=GRAVITY;
            player.grounded=true;
        }
        //leader1 collision
        if(player.rectPosX>480&&player.rectPosX<496&& player.rectPosY<GROUND&&player.rectPosY>-120)
        {
            player.rectPosY-=GRAVITY;
            if(player.rectPosY<-120)
            {player.rectPosY=(-120);}
        }
        //leader2 collision
        if(player.rectPosX>=1084&&player.rectPosX<=1096 && player.rectPosY>=GROUND-4&&player.rectPosY<=400)
        {
            player.rectPosY-=GRAVITY;
        }

        if(player.rectPosX<970&&player.rectPosX>950)
        {
            player.rectPosX=970;
        }

        if(player.rectPosY>=GROUND&&player.rectPosY<GROUND+30&&player.rectPosX<=1086)
        {
            player.rectPosY=GROUND;
            player.grounded=true;
        }


        if(player.rectPosX>=875&&player.rectPosX<=880)
        {
            player.rectPosX=870;
        }

        if(player.rectPosX<=-25&&player.rectPosX>=-30)
        {
            player.rectPosX=-20;
        }
        //bomb collision
        if(player.rectPosX>=350&&player.rectPosX<=380&& laser.la>250)
        {

            player.rectPosY-=40;
        }

        if(player.rectPosY <= -170&& player.rectPosX>=350&& player.rectPosX<=380)
        {
            player.rectPosX=1000;
        }



		cleardevice();
		DrawStars(&stars.s,&stars.sx,&stars.sy);
		DrawRoadLine();
		ControlPlayer( &player.rectPosX, &player.rectPosY, &player.getkey, &player.speed, &player.grounded, &laser.la, &player.ldisp, &start);
		//TextOnTop( &x);
		DrawPlanet( &planet.px, &planet.py);
        DrawShip();

		if(bird.bi<=350)
        {bird.bi++;}


        //gravity
		DrawBird(&bird.bi);

		//NpcMan Loop
        if(npcman.v<=50){
		npcman.v++;npcman.h++;}
		if(npcman.h<=50){
		npcman.v++;}
		if(npcman.v==75){
		npcman.h=0;npcman.v++;}
		if(npcman.v>=385)
		{npcman.v=385;npcman.h++;}
		if(npcman.h>=320)
		{npcman.h=420;}

		DogLoop( &npcman.v, &dog.d);
		NpcKidLoop( &dog.d, &kid.k);
		LaserLoop(&laser.la);

		DrawLadders();
		DrawLadders1();
		DrawBuilding1();
		DrawNpcMan( &npcman.v, &npcman.h, &npcman.ldispa);
		DrawNpcDog( &dog.d);
		DrawNpcKid( &kid.k);
		DrawLaser(&laser.la);
		DrawBarierBox();
		DrawPlayer( &player.rectPosX, &player.rectPosY, &player.ldisp);
        //NpcLoop(&v, &h);
        DrawBuilding2();
		page=1-page;
		delay(del);

	 }//end while loop

	 while(player.rectPosY<=633)
	{

		setactivepage(page);
		setvisualpage(1-page);
        if(player.rectPosY>618)
        {
            player.rectPosY= -250;
        }
        //colusion
        player.rectPosY += GRAVITY;


		cleardevice();
		DrawStars1(&stars.s,&stars.sx,&stars.sy);

		ControlPlayer( &player.rectPosX, &player.rectPosY, &player.getkey, &player.speed, &player.grounded, &laser.la, &player.ldisp, &start);

		DrawPlayer( &player.rectPosX, &player.rectPosY, &player.ldisp);


		page=1-page;
		delay(del);

	 }//end while loop2
	}
	getch();
	closegraph();
	return 0;
}
 //end main program



/*player control loop*/
void ControlPlayer(int *rectPosX,int *rectPosY,int *getkey,int *speed, bool *grounded, int *laser, int *ldisp, int *start)
{
	if(kbhit())//check if a key is pressed
		{
		*getkey=getch();
		//end check key
	switch(*getkey)
		{
		case KeyLeft :
        case KeyA    : {*rectPosX -= *speed;
                        *ldisp=(*ldisp+2)%7;

            break;}
		case KeyRight :
        case KeyD     : {*rectPosX += *speed;
                        *ldisp=(*ldisp+2)%7;


            break;}

		case KeyDown :
        case KeyS    : {*rectPosY += *speed;
                        *ldisp=(*ldisp+2)%7;
                        if(*rectPosX<=1020&&*rectPosX>=1010)
                            {
                                *rectPosX=575;
                                *rectPosY=GROUND-*speed;
                            }
            break;}
        case KeyUp :
        case KeyW  : {*rectPosY -= *speed;
                        *ldisp=(*ldisp+2)%7;
                        if(*rectPosX>=565&&*rectPosX<=585&&*rectPosY==GROUND-*speed)
                            {
                                *rectPosX=1000;
                            }
            break;}
		case KeySpace :

                if(*grounded==true)
                {*rectPosY -= JUMPPOWER;
                *grounded=false;
                break;}
            break;
		case KeyEsc : {player.rectPosY=650; *start=0;
		break;}
		}
		//end switch
		}



 }
 void controlMenu(int *getkey1, int *start, int *bary, int *del)
 {
 if(kbhit())//check if a key is pressed
		{
		*getkey1=getch();
		//end check key
	switch(*getkey1)
		{
		case KeyEnter : if(*bary==0)
                        {*start=1;
                        break;}
                        if(*bary==120)
                        {exit(0);
                        break;
                        }
		break;
		case KeyEsc : exit(0);
		break;
		case KeyUp  : if(*bary>0){
                        *bary-=40;
                        break;}
		break;
		case KeyDown: if(*bary<120)
                        {*bary+=40;
                        break;}
        break;
        case KeyRight: if(*bary==40 && *del<=30)
                        {
                            *del+=5;
                            break;
                        }
        case KeyLeft:  if(*bary==40&& *del>=5)
                        {
                            *del-=5;
                            break;
                        }
		    }
		}
 }
//void NpcLoop(int *v,int *h)
//{


//}
/*LaserLoop*/
void LaserLoop(int *la)
{
	if(*la<=300)
	{*la+=5;}
	if(*la>=300)
	{*la-=300;}
 }


/*npcdog loop*/
void DogLoop(int *v,int *d)
{
	if(*v>=385)
	{*d+=3;}
	if(*d>=380)
    {*d=385;}
 }


/*npckid loop*/
void NpcKidLoop(int *d,int *kid)
{
	if(*d>=235)
	{*kid+=3;}
	if(*kid==125)
	{*kid+=2;}
	if(*kid>=487)
	{*kid=489;}
 }





/*Draw Planet*/
void DrawPlanet(int *px,int *py)
{
	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	circle(*px, *py, 55);
	floodfill(*px, *py, RED);
	setcolor(YELLOW);
	ellipse(*px, *py, 122, 418, 100, 20);
 }


/*Draw Bird*/
void DrawBird(int *bi)
{
	setcolor(YELLOW);
	char myStr[128];
	//sprintf(myStr, "|v= %d h=%d|   Use Arrow keys to move and 'Space' key to Jump",*v,*h);
	sprintf(myStr, ",o-/\\'~");
	outtextxy(300-(*bi),150, myStr);

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

/*Draw buildings*/
void DrawBuilding1()
{
	setfillstyle(HATCH_FILL, 7);
	bar3d (535,190,680,399,30,20);
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

void DrawBuilding2()
{
    setfillstyle(SLASH_FILL, 7);
	bar3d (900,90,990,405,30,20);
	setfillstyle(HATCH_FILL, WHITE);
	bar (928,130,958,160);
	bar (928,188,958,218);
	//bar (620,230,650,260);
	//bar (620,290,650,320);
	//setfillstyle(LINE_FILL, BLUE);
	//bar3d (980,350,995,400,20,20);
	//setcolor(LIGHTGRAY);
	//line (535,190,680,190);
	ellipse(1050,400, 0, 360, 10,5);
}

/*draw ladder1*/
void DrawLadders1()
{
	setcolor(DARKGRAY);
	line (1118,700,1118,375);
	line (1132,700,1132,375);

	line (1118,681,1132,680);
	line (1118,660,1132,660);
	line (1118,641,1132,640);
	line (1118,621,1132,620);
	line (1118,600,1132,600);
	line (1118,579,1132,580);
	line (1118,560,1132,561);
	line (1118,540,1132,540);
	line (1118,519,1132,520);
	line (1118,500,1132,501);
	line (1118,481,1132,480);
	line (1118,461,1132,460);
	line (1118,441,1132,440);
	line (1118,420,1132,421);
	line (1118,401,1132,400);
	line (1118,386,1132,385);
 }

/*draw stars*/
void DrawStars(int *s,int *sx,int *sy)
{
		for(*s=0; *s<=800; *s++)
		{*sx=rand()%getmaxx();
		*sy=rand()%285;
		putpixel(*sx,*sy,WHITE);}
 }

 void DrawStars1(int *s,int *sx,int *sy)
{
		for(*s=0; *s<=800; *s++)
		{*sx=rand()%getmaxx();
		*sy=rand()%getmaxy();
		putpixel(*sx,*sy,WHITE);}
 }

/*draw npcman*/
void DrawNpcMan(int *v,int *h, int *ldispa)
{
    *ldispa=(*ldispa+1)%7;
	//setcolor(DARKGRAY);
	//char myStr[128];
	//sprintf(myStr, "|v= %d h=%d|   Use Arrow keys to move and 'Space' key to Jump",*v,*h);
	//sprintf(myStr, "Press Escape to exit, created by Dusan 2018");
	//outtextxy(5,550, myStr);
	char myStr1[128];
	setcolor(YELLOW);
	sprintf(myStr1, "Created by Dusan 81/14R 2018");
	outtextxy(1050,50, myStr1);

	char myStr0[128];
	sprintf(myStr0, "Press Esc to quit");
	outtextxy(50,20, myStr0);

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
	bar (21+*v, 388-*h, 29+*v, 385-*h);
	bar (22+*v+*ldispa, 400-*h, 24+*v+*ldispa, 386-*h);
	bar (26+*v-*ldispa, 400-*h, 28+*v-*ldispa, 386-*h);
	/*npcman hands*/
	setcolor(BLUE);
	line (16+*v-*ldispa, 385-*h, 20+*v, 370-*h);
	line (33+*v+*ldispa, 385-*h, 29+*v, 370-*h);

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
{
    setcolor(BROWN);
	setfillstyle(LTBKSLASH_FILL,BROWN);
	bar3d (73, 400, 90, 378, 5, 10);
	setfillstyle(CLOSE_DOT_FILL,RED);
	bar3d (150,400, 200, 350,10, 10);
	setfillstyle(LINE_FILL,LIGHTGRAY);
	bar (155,360, 170, 375);
	setfillstyle(LTBKSLASH_FILL,BROWN);
	pieslice(178,310,225,320,50);
 }

/*Draw Laser*/
void DrawLaser(int *la)
{
	setfillstyle(WIDE_DOT_FILL,CYAN);
	bar(400,70+*la,420,120+*la);
	}

/*Draw player creation*/
void DrawPlayer(int *rectPosX,int *rectPosY, int *ldisp)
{
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, YELLOW);
	circle(*rectPosX+35,*rectPosY+264, 6);

	floodfill(*rectPosX+35,*rectPosY+265, YELLOW);

	//outtextxy(*rectPosX+28,*rectPosY+259,"..");
	//outtextxy(*rectPosX+32,*rectPosY+260,"_");
	//torso
	setfillstyle(SOLID_FILL,RED);
	bar (*rectPosX+30, *rectPosY+283, *rectPosX+40,*rectPosY+270);
	//arms
	setcolor(LIGHTRED);
	line(*rectPosX+40+*ldisp, *rectPosY+283, *rectPosX+39, *rectPosY+270);
    line(*rectPosX+29-*ldisp, *rectPosY+283, *rectPosX+30, *rectPosY+270);

    setcolor(RED);
    line(*rectPosX+41+*ldisp, *rectPosY+283, *rectPosX+40, *rectPosY+270);
    line(*rectPosX+28-*ldisp, *rectPosY+283, *rectPosX+29, *rectPosY+270);
	//legs
	setfillstyle(SOLID_FILL,LIGHTBLUE);
	bar (*rectPosX+31, *rectPosY+288, *rectPosX+39, *rectPosY+283);
	setcolor(LIGHTBLUE);
	line(*rectPosX+38-*ldisp, *rectPosY+300, *rectPosX+37, *rectPosY+284);
	line(*rectPosX+39-*ldisp, *rectPosY+300, *rectPosX+38, *rectPosY+284);
    line(*rectPosX+31+*ldisp, *rectPosY+300, *rectPosX+32, *rectPosY+284);
    line(*rectPosX+30+*ldisp, *rectPosY+300, *rectPosX+31, *rectPosY+284);
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar (*rectPosX+29,*rectPosY+262,*rectPosX+41,*rectPosY+258);
	setcolor(LIGHTGRAY);
	line (*rectPosX+25,*rectPosY+262,*rectPosX+44,*rectPosY+262);
 }






