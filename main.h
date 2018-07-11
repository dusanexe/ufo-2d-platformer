/*this file is for declarations of main program ufo-2d-platformer*/
/* created Jul 2018*/
/* Author Dusanexe 81/14R */


#define KeyUp		72
#define	KeyDown		80
#define KeyLeft		75
#define	KeyRight	77
#define KeyW        119
#define KeyS        115
#define KeyA        97
#define KeyD        100
#define	KeyEsc		27
#define KeySpace    32
#define KeyEnter    13
#define GRAVITY     (3)
#define SPEED       (4)
#define JUMPPOWER   (70)
#define GROUND      (99)


typedef struct
{
    int la;
}Laser;

typedef struct
{
    int x;
    int y;
    int radius;
    int px;
    int py;
}Planet;

typedef struct
{
    int s;
    int sx;
    int sy;
}Stars;

typedef struct
{
    int v;
    int h;
    int ldispa;
}Npcman;

typedef struct
{
    int bi;
}Bird;

typedef struct
{
    int d;
}Dog;

typedef struct
{
    int k;
}Kid;

typedef struct
{
    int rectPosX;
    int rectPosY;
    int getkey;
    int getKey1;
    int speed;
    bool grounded;
    int ldisp;
}Player;


void ControlPlayer(int *,int *,int *,int *,bool *, int*, int*, int*);
void controlMenu(int *, int *, int*, int*);
void TextOnTop(int *);
void DrawPlanet(int *,int *);
void DrawStars(int *, int *, int *);
void DrawStars1(int *, int *, int *);
void DrawLaser(int *);
void LaserLoop(int *);
void DrawBird(int *);
void DogLoop(int *,int *);
void NpcKidLoop(int *,int *);
void DrawNpcKid(int *);
void DrawLadders();
void DrawLadders1();
void DrawBuilding1();
void DrawBuilding2();
void DrawNpcMan(int *,int *, int *);
void DrawNpcDog(int *);
void DrawRoadLine();
void DrawBarierBox();
void DrawPlayer(int *,int *, int *);
void DrawShip();
void NpcLoop(int *,int *);


	Laser laser;

	Planet planet;

	Stars stars; //stars parameters

	Npcman npcman;

	Bird bird;

	Dog dog;

	Kid kid;

	Player player;


