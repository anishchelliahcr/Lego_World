#include<fstream.h>
#include<string.h>
#include<process.h>
#include<iostream.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>
#include<time.h>
#include<ctype.h>
  int key=0,p=0;

struct save
{
int l,h,o,i,f,t,level;
};
void level1(int x,int o,int t,int f,char name[20]);

char cont(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode=1, errorcode;
   int d=-1,n=0,ch,f=0,o=0,x=0,maxx,maxy,midx, midy, i;

   /* initialize graphics, local variables*/
   initgraph(&gdriver, &gmode, "c:\\TurboC3\\BGI");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error
       occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with error code */
   }

   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   maxx = getmaxx() ;
   maxy = getmaxy() ;
   i=0;
   randomize();
   setbkcolor(4);
	setcolor(4);
// bar(midx-15,midy-40,midx+15,midy+40);
 setfillstyle(1,6);
 bar(0,0,maxx,maxy);
setfillstyle(8,8);
fillellipse(midx, midy, midx, midy);
 //setfillstyle(1,14);
//pieslice(midx-5, midy-22, 0, 360, 40);
//setcolor(1);
settextstyle(3,HORIZ_DIR,6);
setcolor(-1);
outtextxy(midx-280,midy-60,"WANNA CONTINUE??");
ch=getch();

closegraph();
return ch;
}

int bonus(char name[20],int x=0,int o=0,int t=0,int f=0)


{  clock_t start ,end,c1,c2,end2;
   struct time t1,t2;
    char namei[10] ;
   /* request auto detection */
   int gdriver = DETECT, gmode=1, errorcode;
   int l=12,d=-1,ch,ch0,maxx,maxy,midx, midy, i,score;
   start=clock();
   /* initialize graphics, rlocal variables*/
   initgraph(&gdriver, &gmode, "c:\\TurboC3\\BGI");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error
       occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with error code */
   }

   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   maxx = getmaxx() ;
   maxy = getmaxy() ;
   i=0;
   randomize();
    settextstyle(1,HORIZ_DIR,1) ;

    setcolor(4);
    outtextxy(midx-30,midy+300,"loading");
    int ran=1;
    while(++i<=570)
    {   if(i%100==0)
	x=-x;
	sound(x*((i%10)*(i%20)*(i%10)*(i%20))*50+5000*i);
	delay(30);
	cleardevice();
	setcolor(-1);
	outtextxy(midx-30,midy+30,"loading");
	setfillstyle(8,1);
	bar3d(50, midy-50, 50+i,midy, 10, 1);
	delay(5);

    i+=5;
    }
       cleardevice();
	nosound();
	int b;
	settextstyle(1,HORIZ_DIR,1) ;

	if(t==0)
	{
	bar3d(0, 0, maxx,maxy, 10, 1);
	setcolor(-1);
	outtextxy(midx-60,midy,"enter your name:");
	gets(namei);
	strcpy(name,namei);
	strcat(namei,".dat");}
	bar3d(0, 0, maxx,maxy, 10, 1);
	setcolor(-1);
	outtextxy(midx-30,midy-60,"1.start");
	setcolor(-1);
	outtextxy(midx-30,midy,"2.exit");
	outtextxy(midx-30,midy+60,"3.load");

	ch=getch();
    if(ch=='2')
    {
    exit(0);

    }
    else if(ch=='3')
    {
    cleardevice();
    ifstream v(name,ios::binary|ios::in);
   if(v)
    {
    save s;
    v.read((char*)&s,sizeof(s));
    if(s.level=='i')
    {
    cleardevice();
   setbkcolor(-1);
	setcolor(-1);
// bar(midx-15,midy-40,midx+15,midy+40);
 setfillstyle(8,7);
 bar3d(0,0,maxx,maxy,0,0);
  setcolor(-1);
 setfillstyle(9,7);
 bar3d(midx/2,midy/2,3*maxx/4,3*maxy/4,0,0);
settextstyle(7,HORIZ_DIR,4);
setcolor(14);
outtextxy(midx-70,midy-90,"LOAD");
outtextxy(midx-140,midy-10,"SUCCESSFUL");

delay(100);
getch();
    bonus(name,s.i,s.o,s.t,s.f);
    }
    else
    goto uns1;


    goto end;
    }
    else
    {
    uns1:

cleardevice();
   setbkcolor(-1);
	setcolor(-1);
 setfillstyle(8,7);
 bar3d(0,0,maxx,maxy,0,0);
  setcolor(-1);
 setfillstyle(9,7);
 bar3d(midx/2,midy/2,3*maxx/4,3*maxy/4,0,0);
settextstyle(7,HORIZ_DIR,3);
setcolor(14);
outtextxy(midx-90,midy-90,"LOAD");
outtextxy(midx-130,midy-10,"UNSUCCESSFUL");

delay(100);
getch();
    }
     v.close();
    settextstyle(1,HORIZ_DIR,1);
    }
	cleardevice();
gettime(&t1);
int randx[30],j[30];
char no[30][2];

for( b=0;b<30;b++)
{
j[b]=0;
no[b][1]='\0';
}
c1=clock();
c2=clock();
 settextstyle(1, HORIZ_DIR, 3);
start=clock();
for(i=0;;(ch=='a')?o-=5:(ch=='d')?o+=5:o)
{//midx, midy-20-i,midx+50,midy+30-i, 10, 1
//bar3d(midx+o, midy-20-i,midx+50+o,midy+30-i, 10, 1);
	begin:
	 settextstyle(1, HORIZ_DIR, 3);

	for(int g=0;g<10;g++)
	{
	if(j[g]>=maxy-11)
	j[g]=0;
	if(j[g]==0)
	{
	randx[g]=random(maxx);
	no[g][0]=random(10)+48;
	no[g][1]='\0';
	}
	}
	setcolor(-1);
	setfillstyle(9,16);
	bar3d(maxx,maxy,0,0,1,1);
	setfillstyle(9,15);
	bar3d(maxx,maxy,0,maxy-22,0,0);
	setfillstyle(8,1);
	bar3d(maxx,maxy-55,maxx-80,maxy-70,0,0);
	for(g=0;g<30;g++)
	{
	circle(randx[g],j[g],20);
	no[g][1]=0;
	setcolor(no[g][0]-49);
	outtextxy(randx[g]-6,j[g]-14,(char*)no[g]);
	}

	setcolor(-1);
	setfillstyle(1,-1);
	bar3d(15+o,maxy-80-i,23+o,maxy-100-i,0,0);
	setfillstyle(1,1);
	bar3d(12+o, maxy-10-i,22+o,maxy-40-i,0,0);
	bar3d(22+o,maxy-13-i,28+o,maxy-40-i,0,0);
	setfillstyle(9,4);
	bar3d(10+o, maxy-40-i, 30+o,maxy-80-i,0,0);
			     end=clock();
     char n[7];
     itoa(((end-start)/CLK_TCK+t),n,10);
     settextstyle(1,HORIZ_DIR,1);
     setcolor(-1);
     outtextxy(330,midy-80,"time youv'e survived for  :   ");
     outtextxy(600,midy-80,(char*)n);
      setcolor(14);
	delay(25);
//cont:
	if(kbhit())
	ch=tolower(getch());

//else if(ch=='s')
//i-=5;
else if(ch=='e')
{
delay(200);
ch=getch();
if(ch=='n')
{
ch=getch();
if(ch=='d')
break;
}}

else if(ch==27)
{
c1=clock();
setfillstyle(8,1);
setcolor(-1);
bar3d(0, 0, maxx,maxy, 10, 1);
   setcolor(-1);
	outtextxy(midx-30,midy-30,"1.continue");
	setcolor(-1);
	outtextxy(midx-30,midy+30,"2.new game");
	outtextxy(midx-30,midy+60,"3.exit");
	outtextxy(midx-30,midy+90,"4.save");

	ch=getch();
    if(ch=='1')
    ;
   else if(ch=='2')
   {
   start=clock();
   i=0;o=0;t=0;
   goto begin;
   }
   else if(ch=='3')
   goto end;

    else if(ch=='4')
    {
    remove(name);
    ofstream v(name,ios::binary|ios::out);
    if(v)
    {
    end=clock();
    save s;
    s.i=i;
    s.o=o;
    s.f=f;
    s.t=(end-start)/CLK_TCK;
    s.level='i';
    v.seekp(0,ios::beg);
    v.write((char*)&s,sizeof(s));
    v.close();
    cleardevice();
   setbkcolor(-1);
	setcolor(-1);
 setfillstyle(8,7);
 bar3d(0,0,maxx,maxy,0,0);
  setcolor(-1);
 setfillstyle(9,7);
 bar3d(midx/2,midy/2,3*maxx/4,3*maxy/4,0,0);
settextstyle(7,HORIZ_DIR,5);
setcolor(14);
outtextxy(midx-90,midy-90,"SAVE");
outtextxy(midx-130,midy-10,"SUCCESSFUL");

delay(100);
getch();

cleardevice();
   setbkcolor(-1);
	setcolor(-1);
// bar(midx-15,midy-40,midx+15,midy+40);
 setfillstyle(8,7);
 bar3d(0,0,maxx,maxy,0,0);
  setcolor(-1);
 setfillstyle(9,7);
 bar3d(midx/2,midy/2,3*maxx/4,3*maxy/4,0,0);
settextstyle(7,HORIZ_DIR,3);
setcolor(14);
outtextxy(midx-150,midy-60,"PLAY AGAIN WITH");
outtextxy(midx-150,midy-10,"THE SAME NAME TO");
outtextxy(midx-160,midy+40,"LOAD THE SAVED FILE");
delay(100);
getch();

    }
    else
    {
     setbkcolor(-1);
	setcolor(-1);
// bar(midx-15,midy-40,midx+15,midy+40);
 setfillstyle(8,7);
 bar3d(0,0,maxx,maxy,0,0);
  setcolor(-1);
 setfillstyle(9,7);
 bar3d(midx/2,midy/2,3*maxx/4,3*maxy/4,0,0);
settextstyle(7,HORIZ_DIR,5);
setcolor(14);
outtextxy(midx-80,midy-90,"SAVE");
outtextxy(midx-130,midy-10,"UNSUCCESSFUL");

delay(100);
getch();
    }
    } end2=clock();
    start+=end2-c1;
    settextstyle(1,HORIZ_DIR,1);}



//if(midx+50+o>=maxx||midx+o<=0||midy-20-i<=0||midy+30-i>=maxy)
//goto cont;
if(/*10-i<23&&23<30-i&&*/ maxy-400>=maxy-80-i)
f++;

if(10+o>maxx-40&&30+o<maxx&&maxy-40-i<maxy-400)
break;
end=clock();
int k=0;
for(g=0;g<30;g++)
if(!(randx[g]<0+o||randx[g]>40+o)&&j[g]<maxy-20&&j[g]>maxy-100&&(c2=clock(),(c2-c1)/CLK_TCK>=2))
{
c1=clock();
setcolor(1);
for(int d=0;d<400;d++)
{
circle(randx[g],j[g],d);
delay(1);
}
setcolor(-1);
outtextxy(midx-100,midy,"enter the element in the bubble");
ch=getch();
if(ch==no[g][0])
l+=2;
else
{
end=clock();
score=(((end-start)/CLK_TCK)*2)/3;
return score;
}
c2=clock();
start+=c2-c1;
}
cleardevice();
ch0=ch;

for(g=0;g<30;g++)
j[g]+=l;
}
end:
}


void level1intro(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode=1, errorcode;
   int d=-1,n=0,ch,f=0,o=0,x=0,maxx,maxy,midx, midy, i;

   /* initialize graphics, local variables*/
   initgraph(&gdriver, &gmode, "c:\\TurboC3\\BGI");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error
       occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with error code */
   }

   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   maxx = getmaxx() ;
   maxy = getmaxy() ;
   i=0;
   randomize();
   setbkcolor(4);
	setcolor(4);
// bar(midx-15,midy-40,midx+15,midy+40);
 setfillstyle(1,6);
 bar(0,0,maxx,maxy);
setfillstyle(8,8);
fillellipse(midx, midy, midx, midy);
 //setfillstyle(1,14);
//pieslice(midx-5, midy-22, 0, 360, 40);
//setcolor(1);
setcolor(-1);
settextstyle(7,HORIZ_DIR,9);

outtextxy(midx-200,midy-60,"LEVEL 1");

getch();
closegraph();
}
void level2intro(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode=1, errorcode;
   int d=-1,n=0,ch,f=0,o=0,x=0,maxx,maxy,midx, midy, i;

   /* initialize graphics, local variables*/
   initgraph(&gdriver, &gmode, "c:\\TurboC3\\BGI");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error
       occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with error code */
   }

   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   maxx = getmaxx() ;
   maxy = getmaxy() ;
   i=0;
   randomize();
   setbkcolor(4);
	setcolor(4);
// bar(midx-15,midy-40,midx+15,midy+40);
 setfillstyle(1,6);
 bar(0,0,maxx,maxy);
setfillstyle(8,8);
fillellipse(midx, midy, midx, midy);
 //setfillstyle(1,14);
//pieslice(midx-5, midy-22, 0, 360, 40);
//setcolor(1);
setcolor(-1);
settextstyle(7,HORIZ_DIR,9);
outtextxy(midx-200,midy-60,"LEVEL 2");
getch();
closegraph();
}



void leavel2(char name[20],int x=0,int o=0,int t=0,int f=0)

{

	level2intro();
   clock_t start ,end;
   struct time t1,t2;

   /* request auto detection */
   int gdriver = DETECT, gmode=1, errorcode;
   int d=-1,ch,ch0,maxx,maxy,midx, midy, i,score;
   start=clock();
   /* initialize graphics, rlocal variables*/
   initgraph(&gdriver, &gmode, "c:\\TurboC3\\BGI");
      //	char name[20];
   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error
       occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with error code */
   }

   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   maxx = getmaxx() ;
   maxy = getmaxy() ;
   i=0;
   randomize();
       settextstyle(1,HORIZ_DIR,1) ;

       if(t==0)
    {setcolor(4);

    outtextxy(midx-30,midy+300,"loading");
    while(++i<=570)
    {
	sound(i);
	delay(30);
	cleardevice();
	setcolor(-1);
	outtextxy(midx-30,midy+30,"loading");
	setfillstyle(8,4);
	bar3d(50, midy-50, 50+i,midy, 10, 1);
	delay(5);

    i+=5;
    }
	    cleardevice();

	nosound();
	settextstyle(1,HORIZ_DIR,1);

	bar3d(0, 0, maxx,maxy, 10, 1);
	setcolor(-1);
	outtextxy(midx-30,midy-60,"1.start");
	setcolor(-1);
	outtextxy(midx-30,midy,"2.exit");
	outtextxy(midx-30,midy+60,"3.load");

	ch=getch();
    if(ch=='2')
    {
    exit(0);

    }
    else if(ch=='3')
    {
    cleardevice();
     ifstream v(name,ios::binary|ios::in);
    save s;
    if(v)
    {
    v.read((char*)&s,sizeof(s));
    if(s.level==2)
    {

cleardevice();
   setbkcolor(-1);
	setcolor(-1);
// bar(midx-15,midy-40,midx+15,midy+40);
 setfillstyle(8,7);
 bar3d(0,0,maxx,maxy,0,0);
  setcolor(-1);
 setfillstyle(9,7);
 bar3d(midx/2,midy/2,3*maxx/4,3*maxy/4,0,0);
settextstyle(7,HORIZ_DIR,5);
setcolor(14);
outtextxy(midx-90,midy-90,"LOAD");
outtextxy(midx-130,midy-10,"SUCCESSFUL");

delay(100);
getch();

    leavel2(name,s.i,s.o,s.t,s.f);
    }
    else if(s.level==1)
    {
cleardevice();
   setbkcolor(-1);
	setcolor(-1);
// bar(midx-15,midy-40,midx+15,midy+40);
 setfillstyle(8,7);
 bar3d(0,0,maxx,maxy,0,0);
  setcolor(-1);
 setfillstyle(9,7);
 bar3d(midx/2,midy/2,3*maxx/4,3*maxy/4,0,0);
settextstyle(7,HORIZ_DIR,5);
setcolor(14);
outtextxy(midx-90,midy-90,"LOAD");
outtextxy(midx-130,midy-10,"SUCCESSFUL");

delay(100);
getch();

    level1(s.i,s.o,s.t,s.f,name);
    }
    else
    goto uns2;
    v.close();

    }
    else

    {
    uns2:
cleardevice();
   setbkcolor(-1);
	setcolor(-1);
 setfillstyle(8,7);
 bar3d(0,0,maxx,maxy,0,0);
  setcolor(-1);
 setfillstyle(9,7);
 bar3d(midx/2,midy/2,3*maxx/4,3*maxy/4,0,0);
settextstyle(7,HORIZ_DIR,3);
setcolor(14);
outtextxy(midx-90,midy-90,"LOAD");
outtextxy(midx-130,midy-10,"UNSUCCESSFUL");

delay(100);
getch();
    }
    }
     settextstyle(1,HORIZ_DIR,1);
     }
	cleardevice();
gettime(&t1);
int randx[30],j[30];
for(int b=0;b<30;b++)
j[b]=0;
for(i=x;;(ch=='a')?o-=5:(ch=='d')?o+=5:o)
{//midx, midy-20-i,midx+50,midy+30-i, 10, 1
//bar3d(midx+o, midy-20-i,midx+50+o,midy+30-i, 10, 1);

	begin:
	for(int g=0;g<10;g++)
	{
	if(j[g]>=maxy-11)
	j[g]=0;
	if(j[g]==0)
	randx[g]=random(maxx);
	}
	setcolor(-1);
	setfillstyle(9,16);
	bar3d(maxx,maxy,0,0,1,1);
	setfillstyle(9,15);
	bar3d(maxx,maxy,0,maxy-22,0,0);
	setfillstyle(8,1);
	bar3d(maxx,maxy-55,maxx-80,maxy-70,0,0);
	for(g=0;g<10;g++)
	circle(randx[g],j[g],10);

	setfillstyle(1,-1);
	bar3d(15+o,maxy-80-i,23+o,maxy-100-i,0,0);
	setfillstyle(1,1);
	bar3d(12+o, maxy-10-i,22+o,maxy-40-i,0,0);
	bar3d(22+o,maxy-13-i,28+o,maxy-40-i,0,0);
	setfillstyle(9,4);
	bar3d(10+o, maxy-40-i, 30+o,maxy-80-i,0,0);
	char n[7];
		     end=clock();
     itoa(((end-start)/CLK_TCK)+t,n,10);
     setcolor(-1);
     outtextxy(330,midy-80,"time youv'e survived for  :   ");
     outtextxy(600,midy-80,(char*)n);
	//delay(10);

	delay(50);
//cont:
	if(kbhit())
	ch=tolower(getch());

//else if(ch=='s')
//i-=5;
else if(ch=='j'&&f!=0)
{
for(;;)

{

	setfillstyle(1,-1);
	bar3d(15+o,maxy-80-i,23+o,maxy-100-i,0,0);
	setfillstyle(1,1);
	bar3d(12+o, maxy-10-i,22+o,maxy-40-i,0,0);
	bar3d(22+o,maxy-13-i,28+o,maxy-40-i,0,0);
	setfillstyle(9,4);
	bar3d(10+o, maxy-40-i, 30+o,maxy-80-i,0,0);
	setfillstyle(9,15);
	bar3d(6+o,maxy-45-i,10+o,maxy-75-i,0,0);
	delay(1);
//cont:
	ch=getch();
  if(ch=='w')
  i+=1;
  else if(ch=='s')
  i-=1;
  else if(ch=='a')
  o-=1;
  else if(ch=='d')
  o+=1;


if(maxy-400>=maxy-80-i&&30-i>=maxx-200)
exit(0);
   if(((maxy-13-i>=maxy-130&&maxy-40-i<=maxy-100-i&&(30+o==midx-50||10+o==maxx-100))||(maxy-13-i>=maxy-200&&maxy-40-i<=maxy-185-i&&(30+o==midx-170||10+o==midx-80))||(maxy-13-i>=maxy-285&&maxy-40-i<=maxy-270-i&&(30+o==midx-300||10+o==maxx-500))||(maxy-13-i>=maxy-400&&maxy-40-i<=maxy-385-i&&(30+o==0||10+o==50))||(maxy-13-i>=maxy-400&&maxy-40-i<=maxy-385-i&&(30+o==maxx-200||10+o==maxx)))||((maxy-13-i==maxy-130-15&&10+o>=midx-50&&10+o<=maxx-100)||(maxy-13-i==maxy-185-15&&10+o>=midx-170&&10+o<=midx-80)||(maxy-13-i==maxy-270-15&&10+o<=midx-300&&10+o>=maxx-500)||(maxy-13-i==maxy-385-15&&10+o>=0&&10+o<=50)||(maxy-13-i==maxy-385-15&&10+o>=maxx-300&&10+o<=maxx)||(maxy-13-i==maxy-70-15&&10+o>=maxx-80&&10+o<=maxx)))//||
//((maxy-13-i>=maxy-130&&maxy-40-i<=maxy-100-i&&(30+o==midx-50||10+o==maxx-100))||(maxy-13-i>=maxy-200&&maxy-40-i<=maxy-185-i&&(30+o==midx-170||10+o==midx-80))||(maxy-13-i>=maxy-285&&maxy-40-i<=maxy-270-i&&(30+o==midx-300||10+o==maxx-500))||(maxy-13-i>=maxy-400&&maxy-40-i<=maxy-385-i&&(30+o==0||10+o==50))||(maxy-13-i>=maxy-400&&maxy-40-i<=maxy-385-i&&(30+o==maxx-200||10+o==maxx)))||((maxy-13-i==maxy-130&&10+o>=midx-50&&10+o<=maxx-100)||(maxy-13-i==maxy-185&&10+o>=midx-170&&10+o<=midx-80)||(maxy-13-i==maxy-270&&10+o<=midx-300&&10+o>=maxx-500)||(maxy-13-i==maxy-385&&10+o>=0&&10+o<=50)||(maxy-13-i==maxy-385&&10+o>=maxx-300&&10+o<=maxx)||(maxy-13-i==maxy-70&&10+o>=maxx-80&&10+o<=maxx)))
  {
   break;}

  }
}
else if(ch=='e')
{
delay(200);
ch=getch();
if(ch=='n')
{
ch=getch();
if(ch=='d')
break;
}}

else if(ch==27)
{
clock_t end1 ,end2;
end1=clock();

setfillstyle(8,4);
setcolor(-1);
bar3d(0, 0, maxx,maxy, 10, 1);
	setcolor(-1);
	outtextxy(midx-30,midy-30,"1.continue");
	setcolor(-1);
	outtextxy(midx-30,midy+30,"2.new game");
	outtextxy(midx-30,midy+60,"3.exit");
	outtextxy(midx-30,midy+90,"4.save");

	ch=getch();
    if(ch=='1')  ;
   //continue();
   else if(ch=='2')
   {
   i=0;o=0;t=0;
   start=clock();
   goto begin;
   }
   else if(ch=='3')
   goto end;

    else if(ch=='4')
    {
    remove(name);
    ofstream v(name,ios::binary|ios::out);
    end=clock();
    save s;
    if(v)
    {
    s.i=i;
    s.o=o;
    s.f=f;
    s.t=(end-start)/CLK_TCK;
    s.level=2;
    v.seekp(0,ios::beg);
    v.write((char*)&s,sizeof(s));
    cleardevice();
   setbkcolor(-1);
	setcolor(-1);
 setfillstyle(8,7);
 bar3d(0,0,maxx,maxy,0,0);
  setcolor(-1);
 setfillstyle(9,7);
 bar3d(midx/2,midy/2,3*maxx/4,3*maxy/4,0,0);
settextstyle(7,HORIZ_DIR,5);
setcolor(14);
outtextxy(midx-90,midy-90,"SAVE");
outtextxy(midx-130,midy-10,"SUCCESSFUL");

delay(100);
getch();

cleardevice();
   setbkcolor(-1);
	setcolor(-1);
// bar(midx-15,midy-40,midx+15,midy+40);
 setfillstyle(8,7);
 bar3d(0,0,maxx,maxy,0,0);
  setcolor(-1);
 setfillstyle(9,7);
 bar3d(midx/2,midy/2,3*maxx/4,3*maxy/4,0,0);
settextstyle(7,HORIZ_DIR,3);
setcolor(14);
outtextxy(midx-150,midy-60,"PLAY AGAIN WITH");
outtextxy(midx-150,midy-10,"THE SAME NAME TO");
outtextxy(midx-160,midy+40,"LOAD THE SAVED FILE");
delay(100);
getch();

    }
    else
    {
     setbkcolor(-1);
	setcolor(-1);
// bar(midx-15,midy-40,midx+15,midy+40);
 setfillstyle(8,7);
 bar3d(0,0,maxx,maxy,0,0);
  setcolor(-1);
 setfillstyle(9,7);
 bar3d(midx/2,midy/2,3*maxx/4,3*maxy/4,0,0);
settextstyle(7,HORIZ_DIR,4);
setcolor(14);
outtextxy(midx-80,midy-90,"SAVE");
outtextxy(midx-130,midy-10,"UNSUCCESSFUL");

delay(100);
getch();
    }
    v.close();
    } end2=clock();
    start+=end2-end1;
    settextstyle(1,HORIZ_DIR,1); }

//if(midx+50+o>=maxx||midx+o<=0||midy-20-i<=0||midy+30-i>=maxy)
//goto cont;
if(/*10-i<23&&23<30-i&&*/ maxy-400>=maxy-80-i)
f++;


if(10+o>maxx-40&&30+o<maxx&&maxy-40-i<maxy-400)
break;
end=clock();
int k=0;
for(g=0;g<10;g++)
if(!(randx[g]<10+o||randx[g]>30+o)&&j[g]<maxy-20&&j[g]>maxy-100)
{
for(int d=0;d<400;d++)
{
circle(randx[g],j[g],d);
delay(1);
}
while(ch==getch())
getch();
goto end;
}
cleardevice();
ch0=ch;

for(g=0;g<10;g++)
j[g]+=15;
}
end:
end=clock();

score=(((end-start)/CLK_TCK+t)*2)/3;
char s[4]={0};

int temp=score;
for(i=0;i<3;i++)
{
s[2-i]=score%10+48;
score/=10;
}
outtextxy(midx,midy,(char*)s);
i=0;
for(o=0;o<500;o++)
{

cleardevice();
setfillstyle(1,-1);
bar3d(15+o,maxy-80-i,23+o,maxy-100-i,0,0);
setfillstyle(1,1);
bar3d(12+o, maxy-10-i,22+o,maxy-40-i,0,0);
bar3d(22+o,maxy-13-i,28+o,maxy-40-i,0,0);
setfillstyle(9,4);
bar3d(10+o, maxy-40-i, 30+o,maxy-80-i,0,0);
outtextxy(midx,midy-30,"score");
outtextxy(midx,midy,(char*)s);
delay(5);
}

//level3();
closegraph();
skip:
}


void intro(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode=1, errorcode;
   int d=-1,n=0,ch,f=0,o=0,x=0,maxx,maxy,midx, midy, i;

   /* initialize graphics, local variables*/
   initgraph(&gdriver, &gmode, "c:\\TurboC3\\BGI");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error
       occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with error code */
   }

   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   maxx = getmaxx() ;
   maxy = getmaxy() ;
   i=0;
   randomize();

	setcolor(14);
// bar(midx-15,midy-40,midx+15,midy+40);
 setfillstyle(9,15);

 fillellipse(midx, midy, 20, 45);
 setfillstyle(1,14);
pieslice(midx-5, midy-22, 0, 360, 40);

settextstyle(7,HORIZ_DIR,6);
setcolor(-1);
outtextxy(midx-300,midy+50,"inovation productions");
outtextxy(midx-150,midy+120,"presents");
delay(900);
cleardevice();
   setbkcolor(-1);
	setcolor(-1);
// bar(midx-15,midy-40,midx+15,midy+40);
 setfillstyle(8,7);
 bar3d(0,0,maxx,maxy,0,0);
  setcolor(-1);
 setfillstyle(9,7);
 bar3d(midx/2,midy/2,3*maxx/4,3*maxy/4,0,0);
settextstyle(7,HORIZ_DIR,8);
setcolor(14);
outtextxy(midx-100,midy-90,"LEGO");
outtextxy(midx-130,midy-10,"WORLD");

delay(100);
getch();
closegraph();
}





void level1(int x,int o,int t,int f,char name[20])
{
 level1intro();
 int key=0,p=0;

clock_t start ,end;
   /* request auto detection */
   int gdriver = DETECT, gmode=1, errorcode;
   int d=-1,ch,ch0,maxx,maxy,midx, midy,score;
   start=clock();
   /* initialize graphics variables*/
   initgraph(&gdriver, &gmode, "c:\\TurboC3\\BGI");
     char n[5],no[1],namei[20];

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error
       occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with error code */
   }

   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   maxx = getmaxx() ;
   maxy = getmaxy() ;
   int i=0;
   randomize();
    setcolor(4);
    settextstyle(1,HORIZ_DIR,1) ;

    if(t==0)
    {setcolor(4);

    outtextxy(midx-30,midy+300,"loading");
    while(++i<=570)
    {
	sound(i);
	delay(30);
	cleardevice();
	setcolor(-1);
	outtextxy(midx-30,midy+30,"loading");
	setfillstyle(8,4);
	bar3d(50, midy-50, 50+i,midy, 10, 1);
	delay(5);

    i+=5;
    }
	    cleardevice();

	nosound();
	    if(t==0)
	    {	bar3d(0, 0, maxx,maxy, 10, 1);
	setcolor(-1);
	outtextxy(midx-60,midy,"enter your name:");
	gets(name);
	strcpy(namei,name);
	strcat(name,".dat"); }
	settextstyle(1,HORIZ_DIR,1);
	bar3d(0, 0, maxx,maxy, 10, 1);
	setcolor(-1);
	outtextxy(midx-30,midy-60,"1.start");
	setcolor(-1);
	outtextxy(midx-30,midy,"2.exit");
	outtextxy(midx-30,midy+60,"3.load");

	ch=getch();
    if(ch=='2')
    {  exit(0);

    }
    else if(ch=='3')
    {
    cleardevice();
     ifstream v(name,ios::binary|ios::in);
    save s;
    if(v)
    {
    v.read((char*)&s,sizeof(s));
    if(s.level==1)
    {
    cleardevice();
   setbkcolor(-1);
	setcolor(-1);
// bar(midx-15,midy-40,midx+15,midy+40);
 setfillstyle(8,7);
 bar3d(0,0,maxx,maxy,0,0);
  setcolor(-1);
 setfillstyle(9,7);
 bar3d(midx/2,midy/2,3*maxx/4,3*maxy/4,0,0);
settextstyle(7,HORIZ_DIR,3);
setcolor(14);
outtextxy(midx-90,midy-90,"LOAD");
outtextxy(midx-130,midy-10,"SUCCESSFUL");

delay(100);
getch();

    level1(s.i,s.o,s.t,s.f,name);
    }
    else if(s.level==2)
    {cleardevice();
   setbkcolor(-1);
	setcolor(-1);
// bar(midx-15,midy-40,midx+15,midy+40);
 setfillstyle(8,7);
 bar3d(0,0,maxx,maxy,0,0);
  setcolor(-1);
 setfillstyle(9,7);
 bar3d(midx/2,midy/2,3*maxx/4,3*maxy/4,0,0);
settextstyle(7,HORIZ_DIR,3);
setcolor(14);
outtextxy(midx-90,midy-90,"LOAD");
outtextxy(midx-130,midy-10,"SUCCESSFUL");

delay(100);
getch();

    leavel2(name,s.i,s.o,s.t,s.f);
    }
    else
    goto uns3;

    }
    else
    {
    uns3:

cleardevice();
   setbkcolor(-1);
	setcolor(-1);
 setfillstyle(8,7);
 bar3d(0,0,maxx,maxy,0,0);
  setcolor(-1);
 setfillstyle(9,7);
 bar3d(midx/2,midy/2,3*maxx/4,3*maxy/4,0,0);
settextstyle(7,HORIZ_DIR,3);
setcolor(14);
outtextxy(midx-90,midy-90,"LOAD");
outtextxy(midx-130,midy-10,"UNSUCCESSFUL");

delay(100);
getch();
    }
    v.close();
    settextstyle(1,HORIZ_DIR,1) ;
    }
     }
i=x;
start=clock();
for(i;;)
{//midx, midy-20-i,midx+50,midy+30-i, 10, 1
//bar3d(midx+o, midy-20-i,midx+50+o,midy+30-i, 10, 1);
	begin:


	setcolor(-1);
	setfillstyle(9,16);
	bar3d(maxx,maxy,0,0,1,1);
	setfillstyle(9,15);
	bar3d(maxx,maxy,0,maxy-22,0,0);
	setfillstyle(8,1);
	bar3d(maxx,maxy-55,maxx-80,maxy-70,0,0);

	setcolor(4);
	setfillstyle(7,4);
	bar3d(midx-50, maxy-130, maxx-100,maxy-145,1,6);
	bar3d(midx-170, maxy-200, midx-80,maxy-185,1,6);
	bar3d(midx-300, maxy-270, maxx-500,maxy-285,1,6);
	bar3d(0, maxy-400, 50,maxy-385,1,6);
	bar3d(maxx, maxy-400, maxx-200,maxy-385,1,6);
	setcolor(-1);
	setfillstyle(9,2);
	bar3d(maxx-40, maxy-400,maxx,maxy-440,1,6);

	setcolor(14);
	setfillstyle(1,14);
	if((maxx-13-i==maxy-400&&10+o>=0&&10+o<=50)||f!=0)
	 {
      f++;
      goto key;
      }
	circle(23, maxy-430, 20);
	pieslice(23, maxy-430, 0, 360, 20);
	setcolor(4);
	outtextxy(10,maxy-448,"key");
	key:
	setfillstyle(1,-1);

	setfillstyle(1,-1);
	bar3d(15+o,maxy-80-i,23+o,maxy-100-i,0,0);
	setfillstyle(1,1);
	bar3d(12+o, maxy-10-i,22+o,maxy-40-i,0,0);
	bar3d(22+o,maxy-13-i,28+o,maxy-40-i,0,0);
	setfillstyle(9,4);
	bar3d(10+o, maxy-40-i, 30+o,maxy-80-i,0,0);
	//delay(50);
//cont:

	     end=clock();
     itoa(90-((end-start)/CLK_TCK)-t,n,10);
     setcolor(-1);
     outtextxy(410,midy-80,"time left  :   ");
     outtextxy(600,midy-80,(char*)n);
	delay(50);
	if(kbhit())
	ch=getch();

  if(ch=='w'&&ch!=ch0)
	{
	 delay(300);
	 if(kbhit())
	 ch=getch();
	 else
	 ch='w';
for(;i<=120+x;i+=1)
{
  if((maxy-100-i==maxy-130&&10+o>=midx-50&&10+o<=maxx-100)||(maxy-100-i==maxy-185&&10+o>=midx-170&&10+o<=midx-80)||(maxy-100-i==maxy-270&&10+o<=midx-300&&10+o>=maxx-500)||(maxy-100-i==maxy-385&&10+o>=0&&10+o<=50)||(maxy-100-i==maxy-385&&10+o>=maxx-300&&10+o<=maxx)||(maxy-100-i==maxy-70&&10+o>=maxx-80&&10+o<=maxx))
  goto down;
    if((maxy-13-i>=maxy-130&&maxy-40-i<=maxy-100-i&&(30+o==midx-50||10+o==maxx-100))||(maxy-13-i>=maxy-200&&maxy-40-i<=maxy-185-i&&(30+o==midx-170||10+o==midx-80))||(maxy-13-i>=maxy-285&&maxy-40-i<=maxy-270-i&&(30+o==midx-300||10+o==maxx-500))||(maxy-13-i>=maxy-400&&maxy-40-i<=maxy-385-i&&(30+o==0||10+o==50))||(maxy-13-i>=maxy-400&&maxy-40-i<=maxy-385-i&&(30+o==maxx-200||10+o==maxx)))
  goto down;
if((maxy-13-i==maxy-145&&10+o>=midx-50&&10+o<=maxx-100)||(maxy-13-i==maxy-200&&10+o>=midx-170&&10+o<=midx-80)||(maxy-13-i==maxy-285&&10+o>=midx-300&&10+o<=maxx-500)||(maxy-13-i==maxy-400&&10+o>=0&&10+o<=50)||(maxy-13-i==maxy-400&&10+o>=maxx-300&&10+o<=maxx)||(maxy-13-i==maxy-70&&10+o>=maxx-80&&10+o<=maxx))
  {i+=1;
   goto skip;}
setcolor(-1);
	 setfillstyle(9,16);
	 bar3d(maxx,maxy,0,0,1,1);
	 setfillstyle(9,15);
	 bar3d(maxx,maxy,0,maxy-22,0,0);
	 setfillstyle(8,1);
	 bar3d(maxx,maxy-55,maxx-80,maxy-70,0,0);

	 setcolor(4);
	 setfillstyle(7,4);
	 bar3d(midx-50, maxy-130, maxx-100,maxy-145,1,6);
	 bar3d(midx-170, maxy-200, midx-80,maxy-185,1,6);
	 bar3d(midx-300, maxy-270, maxx-500,maxy-285,1,6);
	 bar3d(0, maxy-400, 50,maxy-385,1,6);
	 bar3d(maxx, maxy-400, maxx-200,maxy-385,1,6);
	 setcolor(-1);
	 setfillstyle(9,2);
	 bar3d(maxx-40, maxy-400,maxx,maxy-440,1,6);

	 setcolor(14);
	 setfillstyle(1,14);
	 if((maxx-13-i-1==maxy-400&&10+o>=0&&10+o<=50)||f!=0)
    {
    f++;
    goto ke;}

	 circle(23, maxy-430, 20);
	 pieslice(23, maxy-430, 0, 360, 20);
	 setcolor(4);
	 outtextxy(10,maxy-448,"key");
	 ke:
	 setfillstyle(1,-1);

   setfillstyle(1,-1);
   bar3d(15+o,maxy-80-i,23+o,maxy-100-i,0,0);
   setfillstyle(1,1);
   bar3d(12+o, maxy-10-i,22+o,maxy-40-i,0,0);
   bar3d(22+o,maxy-13-i,28+o,maxy-40-i,0,0);
   setfillstyle(9,4);
   bar3d(10+o, maxy-40-i, 30+o,maxy-80-i,0,0);

	     end=clock();
     itoa(90-((end-start)/CLK_TCK)-t,n,10);
     setcolor(-1);
     outtextxy(410,midy-80,"time left  :   ");
     outtextxy(600,midy-80,(char*)n);
	delay(10);

 if(ch=='a')
   o-=1;
//else if(ch=='s')
//i-=5;
else if(ch=='d')
   o+=1;

//if(midx+50+o>=maxx||midx+o<=0||midy-20-i<=0||midy+30-i>=maxy)
//goto cont;

cleardevice();
}
for(;i>=0;i-=1)
{
if((maxy-13-i==maxy-145&&10+o>=midx-50&&10+o<=maxx-100)||(maxy-13-i==maxy-200&&10+o>=midx-170&&10+o<=midx-80)||(maxy-13-i==maxy-285&&10+o>=midx-300&&10+o<=maxx-500)||(maxy-13-i==maxy-400&&10+o>=0&&10+o<=50)||(maxy-13-i==maxy-400&&10+o>=maxx-300&&10+o<=maxx)||(maxy-13-i==maxy-70&&10+o>=maxx-80&&10+o<=maxx))
  {i+=1;
   goto skip;}

setcolor(-1);
   setfillstyle(9,16);
   bar3d(maxx,maxy,0,0,1,1);
   setfillstyle(9,15);
   bar3d(maxx,maxy,0,maxy-22,0,0);
      setfillstyle(8,1);
   bar3d(maxx,maxy-55,maxx-80,maxy-70,0,0);

setcolor(4);
   setfillstyle(7,4);
	bar3d(midx-50, maxy-130, maxx-100,maxy-145,1,6);
	bar3d(midx-170, maxy-200, midx-80,maxy-185,1,6);
	bar3d(midx-300, maxy-270, maxx-500,maxy-285,1,6);
	bar3d(0, maxy-400, 50,maxy-385,1,6);
	bar3d(maxx, maxy-400, maxx-200,maxy-385,1,6);
	setcolor(-1);
	setfillstyle(9,2);
	bar3d(maxx-40, maxy-400,maxx,maxy-440,1,6);

	setcolor(14);
	setfillstyle(1,14);
	if((maxx-13-i-1==maxy-400&&10+o>=0&&10+o<=50)||f!=0)
     {f++;goto k;}

	circle(23, maxy-430, 20);
   pieslice(23, maxy-430, 0, 360, 20);
   setcolor(4);
	outtextxy(10,maxy-448,"key");
    k:
   setfillstyle(1,-1);

setfillstyle(1,-1);
   bar3d(15+o,maxy-80-i,23+o,maxy-100-i,0,0);
   setfillstyle(1,1);
   bar3d(12+o, maxy-10-i,22+o,maxy-40-i,0,0);
   bar3d(22+o,maxy-13-i,28+o,maxy-40-i,0,0);
   setfillstyle(9,4);
   bar3d(10+o, maxy-40-i, 30+o,maxy-80-i,0,0);

	     end=clock();
     itoa(90-((end-start)/CLK_TCK)-t,n,10);
     setcolor(-1);
     outtextxy(410,midy-80,"time left  :   ");
     outtextxy(600,midy-80,(char*)n);
	delay(5);
 if(ch=='a')
o-=1;
//else if(ch=='s')
//i-=5;
else if(ch=='d')
o+=1;
//if(midx+50+o>=maxx||midx+o<=0||midy-20-i<=0||midy+30-i>=maxy)
//goto cont;
delay(10);
cleardevice();
}
skip:
x=i;
}

			  else if(ch=='a')
{o-=10;
  if(!((maxy-13-i==maxy-145&&10+o>=midx-50&&10+o<=maxx-100)||(maxy-13-i==maxy-200&&10+o>=midx-170&&10+o<=midx-80)||(maxy-13-i==maxy-285&&10+o>=midx-300&&10+o<=maxx-500)||(maxy-13-i==maxy-400&&10+o>=0&&10+o<=50)||(maxy-13-i==maxy-400&&10+o>=maxx-300&&10+o<=maxx)||(maxy-13-i==maxy-70&&10+o>=maxx-80&&10+o<=maxx)) )
  for(;i>=0;i-=1)
{
    if((maxy-13-i>=maxy-130&&maxy-40-i<=maxy-100-i&&(30+o==midx-50||10+o==maxx-100))||(maxy-13-i>=maxy-200&&maxy-40-i<=maxy-185-i&&(30+o==midx-170||10+o==midx-80))||(maxy-13-i>=maxy-285&&maxy-40-i<=maxy-270-i&&(30+o==midx-300||10+o==maxx-500))||(maxy-13-i>=maxy-400&&maxy-40-i<=maxy-385-i&&(30+o==0||10+o==50))||(maxy-13-i>=maxy-400&&maxy-40-i<=maxy-385-i&&(30+o==maxx-200||10+o==maxx)))
  goto down;
if((maxy-13-i==maxy-145&&10+o>=midx-50&&10+o<=maxx-100)||(maxy-13-i==maxy-200&&10+o>=midx-170&&10+o<=midx-80)||(maxy-13-i==maxy-285&&10+o>=midx-300&&10+o<=maxx-500)||(maxy-13-i==maxy-400&&10+o>=0&&10+o<=50)||(maxy-13-i==maxy-400&&10+o>=maxx-300&&10+o<=maxx)||(maxy-13-i==maxy-70&&10+o>=maxx-80&&10+o<=maxx))
  {i+=1;
   goto kip;}

setcolor(-1);
   setfillstyle(9,16);
   bar3d(maxx,maxy,0,0,1,1);
   setfillstyle(9,15);
   bar3d(maxx,maxy,0,maxy-22,0,0);
      setfillstyle(8,1);
   bar3d(maxx,maxy-55,maxx-80,maxy-70,0,0);

setcolor(4);
   setfillstyle(7,4);
	bar3d(midx-50, maxy-130, maxx-100,maxy-145,1,6);
	bar3d(midx-170, maxy-200, midx-80,maxy-185,1,6);
	bar3d(midx-300, maxy-270, maxx-500,maxy-285,1,6);
	bar3d(0, maxy-400, 50,maxy-385,1,6);
	bar3d(maxx, maxy-400, maxx-200,maxy-385,1,6);
	setcolor(-1);
	setfillstyle(9,2);
	bar3d(maxx-40, maxy-400,maxx,maxy-440,1,6);

	setcolor(14);
	setfillstyle(1,14);
	circle(23, maxy-430, 20);
   pieslice(23, maxy-430, 0, 360, 20);
   setcolor(4);
	outtextxy(10,maxy-448,"key");

   setfillstyle(1,-1);

setfillstyle(1,-1);
   bar3d(15+o,maxy-80-i,23+o,maxy-100-i,0,0);
   setfillstyle(1,1);
   bar3d(12+o, maxy-10-i,22+o,maxy-40-i,0,0);
   bar3d(22+o,maxy-13-i,28+o,maxy-40-i,0,0);
   setfillstyle(9,4);
   bar3d(10+o, maxy-40-i, 30+o,maxy-80-i,0,0);

	     end=clock();
     itoa(90-((end-start)/CLK_TCK)-t,n,10);
     setcolor(-1);
     outtextxy(410,midy-80,"time left  :   ");
     outtextxy(600,midy-80,(char*)n);
	delay(5);
if(ch=='a')
o-=1;
//else if(ch=='s')
//i-=5;
else if(ch=='d')
o+=1;

//if(midx+50+o>=maxx||midx+o<=0||midy-20-i<=0||midy+30-i>=maxy)
//goto cont;
delay(10);
cleardevice();
}
kip:
x=i;
}
//else if(ch=='s')
//i-=5;
else if(ch=='j'&&f!=0)
{
ch='v';
o+=1;
for(;;)

{
setcolor(-1);
	setfillstyle(9,16);
	bar3d(maxx,maxy,0,0,1,1);
	setfillstyle(9,15);
	bar3d(maxx,maxy,0,maxy-22,0,0);
	setfillstyle(8,1);
	bar3d(maxx,maxy-55,maxx-80,maxy-70,0,0);

	setcolor(4);
	setfillstyle(7,4);
	bar3d(midx-50, maxy-130, maxx-100,maxy-145,1,6);
	bar3d(midx-170, maxy-200, midx-80,maxy-185,1,6);
	bar3d(midx-300, maxy-270, maxx-500,maxy-285,1,6);
	bar3d(0, maxy-400, 50,maxy-385,1,6);
	bar3d(maxx, maxy-400, maxx-200,maxy-385,1,6);
	setcolor(-1);
	setfillstyle(9,2);
	bar3d(maxx-40, maxy-400,maxx,maxy-440,1,6);

	setcolor(14);
	setfillstyle(1,14);
	if((maxx-13-i==maxy-400&&10+o>=0&&10+o<=50)||f!=0)
	 {
      f++;
      goto e;
      }
	circle(23, maxy-430, 20);
	pieslice(23, maxy-430, 0, 360, 20);
	setcolor(4);
	outtextxy(10,maxy-448,"key");
	e:
	setfillstyle(1,-1);

	setfillstyle(1,-1);
	bar3d(15+o,maxy-80-i,23+o,maxy-100-i,0,0);
	setfillstyle(1,1);
	bar3d(12+o, maxy-10-i,22+o,maxy-40-i,0,0);
	bar3d(22+o,maxy-13-i,28+o,maxy-40-i,0,0);
	setfillstyle(9,4);
	bar3d(10+o, maxy-40-i, 30+o,maxy-80-i,0,0);
	setfillstyle(9,15);
	bar3d(6+o,maxy-45-i,10+o,maxy-75-i,0,0);

	     end=clock();
     itoa(90-((end-start)/CLK_TCK)-t,n,10);
     setcolor(-1);
     outtextxy(410,midy-80,"time left  :   ");
     outtextxy(600,midy-80,(char*)n);
	delay(5);
//cont:
	if(kbhit())
	ch=getch();
  if(ch=='w')
  i+=1;
  else if(ch=='s')
  i-=1;
  else if(ch=='a')
  o-=1;
  else if(ch=='d')
  o+=1;
  else if(ch=='j')
  {

  goto down;

  }

if(maxy-400>=maxy-80-i&&30-i>=maxx-200)
exit(0);
   if(((maxy-13-i>=maxy-130&&maxy-40-i<=maxy-100-i&&(30+o==midx-50||10+o==maxx-100))||(maxy-13-i>=maxy-200&&maxy-40-i<=maxy-185-i&&(30+o==midx-170||10+o==midx-80))||(maxy-13-i>=maxy-285&&maxy-40-i<=maxy-270-i&&(30+o==midx-300||10+o==maxx-500))||(maxy-13-i>=maxy-400&&maxy-40-i<=maxy-385-i&&(30+o==0||10+o==50))||(maxy-13-i>=maxy-400&&maxy-40-i<=maxy-385-i&&(30+o==maxx-200||10+o==maxx)))||((maxy-13-i==maxy-130-15&&10+o>=midx-50&&10+o<=maxx-100)||(maxy-13-i==maxy-185-15&&10+o>=midx-170&&10+o<=midx-80)||(maxy-13-i==maxy-270-15&&10+o<=midx-300&&10+o>=maxx-500)||(maxy-13-i==maxy-385-15&&10+o>=0&&10+o<=50)||(maxy-13-i==maxy-385-15&&10+o>=maxx-300&&10+o<=maxx)||(maxy-13-i==maxy-70-15&&10+o>=maxx-80&&10+o<=maxx)))//||
//((maxy-13-i>=maxy-130&&maxy-40-i<=maxy-100-i&&(30+o==midx-50||10+o==maxx-100))||(maxy-13-i>=maxy-200&&maxy-40-i<=maxy-185-i&&(30+o==midx-170||10+o==midx-80))||(maxy-13-i>=maxy-285&&maxy-40-i<=maxy-270-i&&(30+o==midx-300||10+o==maxx-500))||(maxy-13-i>=maxy-400&&maxy-40-i<=maxy-385-i&&(30+o==0||10+o==50))||(maxy-13-i>=maxy-400&&maxy-40-i<=maxy-385-i&&(30+o==maxx-200||10+o==maxx)))||((maxy-13-i==maxy-130&&10+o>=midx-50&&10+o<=maxx-100)||(maxy-13-i==maxy-185&&10+o>=midx-170&&10+o<=midx-80)||(maxy-13-i==maxy-270&&10+o<=midx-300&&10+o>=maxx-500)||(maxy-13-i==maxy-385&&10+o>=0&&10+o<=50)||(maxy-13-i==maxy-385&&10+o>=maxx-300&&10+o<=maxx)||(maxy-13-i==maxy-70&&10+o>=maxx-80&&10+o<=maxx)))
  {
  // if(o!=m)
   break;}

  }
//m=o;
}
else if(ch=='k')
{
delay(200);
ch=getch();
if(ch=='e')
{
ch=getch();
if(ch=='y')
{
key++;
f++;}
}}
else if(ch=='e')
{
delay(200);
ch=getch();
if(ch=='n')
{
ch=getch();
if(ch=='d')
break;
}}
else if(ch=='d')
{o+=10;
 if(!((maxy-13-i==maxy-145&&10+o>=midx-50&&10+o<=maxx-100)||(maxy-13-i==maxy-200&&10+o>=midx-170&&10+o<=midx-80)||(maxy-13-i==maxy-285&&10+o>=midx-300&&10+o<=maxx-500)||(maxy-13-i==maxy-400&&10+o>=0&&10+o<=50)||(maxy-13-i==maxy-400&&10+o>=maxx-300&&10+o<=maxx)||(maxy-13-i==maxy-70&&10+o>=maxx-80&&10+o<=maxx)) )
  for(;i>=0;i-=1)
{
if((maxy-13-i==maxy-145&&10+o>=midx-50&&10+o<=maxx-100)||(maxy-13-i==maxy-200&&10+o>=midx-170&&10+o<=midx-80)||(maxy-13-i==maxy-285&&10+o>=midx-300&&10+o<=maxx-500)||(maxy-13-i==maxy-400&&10+o>=0&&10+o<=50)||(maxy-13-i==maxy-400&&10+o>=maxx-300&&10+o<=maxx)||(maxy-13-i==maxy-70&&10+o>=maxx-80&&10+o<=maxx))
  {i+=1;
   goto ip;}

setcolor(-1);
   setfillstyle(9,16);
   bar3d(maxx,maxy,0,0,1,1);
   setfillstyle(9,15);
   bar3d(maxx,maxy,0,maxy-22,0,0);
      setfillstyle(8,1);
   bar3d(maxx,maxy-55,maxx-80,maxy-70,0,0);

setcolor(4);
   setfillstyle(7,4);
	bar3d(midx-50, maxy-130, maxx-100,maxy-145,1,6);
	bar3d(midx-170, maxy-200, midx-80,maxy-185,1,6);
	bar3d(midx-300, maxy-270, maxx-500,maxy-285,1,6);
	bar3d(0, maxy-400, 50,maxy-385,1,6);
	bar3d(maxx, maxy-400, maxx-200,maxy-385,1,6);
	setcolor(-1);
	setfillstyle(9,2);
	bar3d(maxx-40, maxy-400,maxx,maxy-440,1,6);

	setcolor(14);
	setfillstyle(1,14);
	circle(23, maxy-430, 20);
   pieslice(23, maxy-430, 0, 360, 20);
   setcolor(4);
	outtextxy(10,maxy-448,"key");

   setfillstyle(1,-1);

setfillstyle(1,-1);
   bar3d(15+o,maxy-80-i,23+o,maxy-100-i,0,0);
   setfillstyle(1,1);
   bar3d(12+o, maxy-10-i,22+o,maxy-40-i,0,0);
   bar3d(22+o,maxy-13-i,28+o,maxy-40-i,0,0);
   setfillstyle(9,4);
   bar3d(10+o, maxy-40-i, 30+o,maxy-80-i,0,0);

	     end=clock();
     itoa(90-((end-start)/CLK_TCK)-t,n,10);
     setcolor(-1);
     outtextxy(410,midy-80,"time left  :   ");
     outtextxy(600,midy-80,(char*)n);
	delay(5); if(ch=='a')
o-=1;
//else if(ch=='s')
//i-=5;
else if(ch=='d')
o+=1;
//if(midx+50+o>=maxx||midx+o<=0||midy-20-i<=0||midy+30-i>=maxy)
//goto cont;
delay(10);
cleardevice();
}
ip:

x=i;
}

else if(ch==27)
{
clock_t end1 ,end2;
end1=clock();
setfillstyle(8,4);
setcolor(-1);
bar3d(0, 0, maxx,maxy, 10, 1);
	setcolor(-1);
	outtextxy(midx-30,midy-30,"1.continue");
	setcolor(-1);
	outtextxy(midx-30,midy+30,"2.new game");
	outtextxy(midx-30,midy+60,"3.exit");
	outtextxy(midx-30,midy+90,"4.save");

	ch=getch();
    if(ch=='1')  ;
   //continue();
   else if(ch=='2')
   {
   i=0;o=0;t=0;
   start=clock();
   goto begin;
   }
   else if(ch=='3')
   exit(0);

    else if(ch=='4')
    {
    remove(name);
    ofstream v(name,ios::binary|ios::out);
    end=clock();
    save s;
    if(v)
    {
    s.i=i;
    s.o=o;
    s.f=f;
    s.t=(end-start)/CLK_TCK;
    s.level=1;
    v.seekp(0,ios::beg);
    v.write((char*)&s,sizeof(s));
    cleardevice();
   setbkcolor(-1);
	setcolor(-1);
 setfillstyle(8,7);
 bar3d(0,0,maxx,maxy,0,0);
  setcolor(-1);
 setfillstyle(9,7);
 bar3d(midx/2,midy/2,3*maxx/4,3*maxy/4,0,0);
settextstyle(7,HORIZ_DIR,5);
setcolor(14);
outtextxy(midx-90,midy-90,"SAVE");
outtextxy(midx-130,midy-10,"SUCCESSFUL");

delay(100);
getch();

cleardevice();
   setbkcolor(-1);
	setcolor(-1);
// bar(midx-15,midy-40,midx+15,midy+40);
 setfillstyle(8,7);
 bar3d(0,0,maxx,maxy,0,0);
  setcolor(-1);
 setfillstyle(9,7);
 bar3d(midx/2,midy/2,3*maxx/4,3*maxy/4,0,0);
settextstyle(7,HORIZ_DIR,3);
setcolor(14);
outtextxy(midx-150,midy-60,"PLAY AGAIN WITH");
outtextxy(midx-150,midy-10,"THE SAME NAME TO");
outtextxy(midx-160,midy+40,"LOAD THE SAVED FILE");
delay(100);
getch();

    }
    else
    {
     setbkcolor(-1);
	setcolor(-1);
// bar(midx-15,midy-40,midx+15,midy+40);
 setfillstyle(8,7);
 bar3d(0,0,maxx,maxy,0,0);
  setcolor(-1);
 setfillstyle(9,7);
 bar3d(midx/2,midy/2,3*maxx/4,3*maxy/4,0,0);
settextstyle(7,HORIZ_DIR,5);
setcolor(14);
outtextxy(midx-80,midy-90,"SAVE");
outtextxy(midx-130,midy-10,"UNSUCCESSFUL");

delay(100);
getch();
    }
    v.close();
    settextstyle(1,HORIZ_DIR,1);
    }
   end2=clock();
   start+=end2-end1;
   }
if(d==1)
{
down:

for(;i>=0;i-=1)
{
if((maxy-40-i==maxy-145&&10+o>=midx-50&&10+o<=maxx-100)||(maxy-40-i==maxy-200&&10+o>=midx-170&&10+o<=midx-80)||(maxy-40-i==maxy-285&&10+o>=midx-300&&10+o<=maxx-500)||(maxy-40-i==maxy-400&&10+o>=0&&10+o<=50)||(maxy-13-i==maxy-400&&10+o>=maxx-300&&10+o<=maxx)||(maxy-40-i==maxy-70&&10+o>=maxx-80&&10+o<=maxx))
  {i+=1;
   goto skip;}

setcolor(-1);
   setfillstyle(9,16);
   bar3d(maxx,maxy,0,0,1,1);
   setfillstyle(9,15);
   bar3d(maxx,maxy,0,maxy-22,0,0);
      setfillstyle(8,1);
   bar3d(maxx,maxy-55,maxx-80,maxy-70,0,0);

setcolor(4);
   setfillstyle(7,4);
	bar3d(midx-50, maxy-130, maxx-100,maxy-145,1,6);
	bar3d(midx-170, maxy-200, midx-80,maxy-185,1,6);
	bar3d(midx-300, maxy-270, maxx-500,maxy-285,1,6);
	bar3d(0, maxy-400, 50,maxy-385,1,6);
	bar3d(maxx, maxy-400, maxx-200,maxy-385,1,6);
	setcolor(-1);
	setfillstyle(9,2);
	bar3d(maxx-40, maxy-400,maxx,maxy-440,1,6);

	setcolor(14);
	setfillstyle(1,14);
	if((maxx-13-i-1==maxy-400&&10+o>=0&&10+o<=50)||f!=0)
     {f++;goto kd;}
     if(f)
     goto kd;
	circle(23, maxy-430, 20);
   pieslice(23, maxy-430, 0, 360, 20);
   setcolor(4);
	outtextxy(10,maxy-448,"key");
    kd:

   setfillstyle(1,-1);

setfillstyle(1,-1);
   bar3d(15+o,maxy-80-i,23+o,maxy-100-i,0,0);
   setfillstyle(1,1);
   bar3d(12+o, maxy-10-i,22+o,maxy-40-i,0,0);
   bar3d(22+o,maxy-13-i,28+o,maxy-40-i,0,0);
   setfillstyle(9,4);
   bar3d(10+o, maxy-40-i, 30+o,maxy-80-i,0,0);

	     end=clock();
     itoa(90-((end-start)/CLK_TCK)-t,n,10);
     setcolor(-1);
     outtextxy(410,midy-80,"time left  :   ");
     outtextxy(600,midy-80,(char*)n);
	delay(5);}
x=i;
}

//if(midx+50+o>=maxx||midx+o<=0||midy-20-i<=0||midy+30-i>=maxy)
//goto cont;
if(/*10-i<23&&23<30-i&&*/ maxy-400>=maxy-80-i)
f++;
if(10+o>maxx-40&&30+o<maxx&&maxy-40-i<maxy-400)
break;
end=clock();
ch=0;
if((end-start)/CLK_TCK+t>90) //closes progrm after 1min30 s
{
i=0;
for(o=0;o<500;o++)
{

cleardevice();
setfillstyle(1,-1);
bar3d(15+o,maxy-80-i,23+o,maxy-100-i,0,0);
setfillstyle(1,1);
bar3d(12+o, maxy-10-i,22+o,maxy-40-i,0,0);
bar3d(22+o,maxy-13-i,28+o,maxy-40-i,0,0);
setfillstyle(9,4);
bar3d(10+o, maxy-40-i, 30+o,maxy-80-i,0,0);
settextstyle(7,HORIZ_DIR,6);
outtextxy(30,midy,"time out! . 'try again'");
delay(10);
}
getch();

exit(0);

}

cleardevice();
ch0=ch;

}
end=clock();

score=(45)/((end-start)/CLK_TCK)*100;
char s[4]={0};
if(key!=0)
score/=2;
if(ch=='3')
score=0;
int temp=score;
for(i=0;i<3;i++)
{
s[2-i]=score%10+48;
score/=10;
}
outtextxy(midx,midy,(char*)s);
i=0;
for(o=0;o<500;o++)
{

cleardevice();
setfillstyle(1,-1);
bar3d(15+o,maxy-80-i,23+o,maxy-100-i,0,0);
setfillstyle(1,1);
bar3d(12+o, maxy-10-i,22+o,maxy-40-i,0,0);
bar3d(22+o,maxy-13-i,28+o,maxy-40-i,0,0);
setfillstyle(9,4);
bar3d(10+o, maxy-40-i, 30+o,maxy-80-i,0,0);
outtextxy(midx,midy-30,"score");
outtextxy(midx,midy,(char*)s);
delay(5);
}
while(ch==getch())
getch();
strcat(namei,"2.dat");
leavel2(name);

end:

closegraph();

}
class savegame
{
 public:
 int k,y[4],randx[4],o,score;
 char name[100];// add name also to be saved.....have not coded the program for saving name
 char time[200];
 char pass[9];
 savegame()
 {k=0;}
};
class actualpoints
{public:
char n[100];
int rank;
int score;
actualpoints()
{score=0;
rank=0;
strcpy(n,"     ");}
};
class points
{public:
char n[100];
int score;
points()
{score=0;
strcpy(n,"     ");}
};
void mycar(int y,int p)
{
 setfillstyle(1,5);
 bar(p,y-60,p+45,y-10);
 setfillstyle(1,-1);
 bar(p+3,y-58,p+42,y-43);
 setfillstyle(1,4);
 setcolor(14);
 setfillstyle(1,14);
 pieslice(p+6,y-60,0,360,4);
 pieslice(p+39,y-60,0,360,4);
 line(p+6,y-67,p+6,y-70);
 line(p+5,y-67,p+3,y-70);
 line(p+7,y-67,p+9,y-70);
 line(p+39,y-67,p+39,y-70);
 line(p+38,y-67,p+36,y-70);
 line(p+40,y-67,p+42,y-70);
}
int racing(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy, i;

   /* initialize graphics and local
      variables */
   initgraph(&gdriver, &gmode, "c://turboc3//bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error
       occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error
		  code */
   }
   begin:
   char str1[100],str2[100];
   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   int maxx = getmaxx();
   int maxy = getmaxy();
   cleardevice();
   settextstyle(2,0,7);
   setcolor(-1);
   outtextxy(midx-100,midy-140,"Rule Breaker"); //main menu
   line(midx-100,midy-120,midx+40,midy-120);
   outtextxy(midx-100,midy-80,"1.New Game");
   outtextxy(midx-100,midy-40,"2.Load Game");
   outtextxy(midx-100,midy,"3.Instructions");
   outtextxy(midx-100,midy+40,"4.High Scores");
   outtextxy(midx-100,midy+80,"5.Exit");
   int choice;
   int back;
   int conti;
   int again;
   choice=getch();
  if(choice==49)
  {ofstream fout("points.dat",ios::binary|ios::app|ios::out);
   ofstream fout1("actualpoints.dat",ios::binary|ios::out);
   ofstream f1("save.dat",ios::binary|ios::app);
   points s;
   points p[100];
   actualpoints q[100];
   char password[9];
   cleardevice();
    outtextxy(midx-175,midy-23,"Please enter your name:");
    gotoxy(53,15);                                             //accepting player name
    gets(s.n);
    settextstyle(6,0,1);
    outtextxy(midx-180,midy-11,"Please enter your password:");
    gotoxy(48,16);
    for(int aaaa=0;aaaa<8;aaaa++)
    {
     password[aaaa]=getch();
     cout<<'*';
    }
    password[aaaa]='\0';
   cleardevice();
   for(int hor=0;hor<maxx;hor+=50)         //loading graphics
   {
    delay(300);
    settextstyle(3,0,3);
    outtextxy(midx-30,midy-30,"Loading......");
    setfillstyle(1,-1);
    bar(hor,midy,hor+50,midy+8);
   }
   setbkcolor(8);
   setfillstyle(1,9);
   bar(maxx-65,0,maxx,maxy);
   int y[4];
   int randx[4];
   int o=0;
   int k=0;
   int ch;
   mycar(maxy,o);
    for(int g=0;g<4;g++)
     y[g]=0;
   for (;;k++)
   {
    int l=0;
    for(int w=150;w<maxx-50;w+=150)   //lane splitter
    {
     setfillstyle(1,-1);
     bar(w,0,w+5,maxy);
    }
    for(int z=75;z<maxx-50;z+=150)    //lines in the middle of the road
     for(int vis=10;vis<maxy;vis+=30)
     {
      setfillstyle(1,-1);
      bar(z,vis,z+5,vis+20);
     }
    setbkcolor(8);
    setfillstyle(1,9);
    bar(maxx-65,0,maxx,maxy);
    for(int g=0;g<4;g++)                        //assigning co-ordinates to other cars
     if(y[g]>=maxy-15)
      y[g]=0;
    for(g=0;g<4;g++)                        //assigning co-ordinates to other cars
     if(y[g]==0)
      randx[g]=((random(4)*(maxx-20))/4)+10;//adjustment done to make other cars go in the lanes correctly
    for(g=0;g<4;g++)                        //displaying the other cars
    {
     setfillstyle(1,2);
     bar(randx[g],y[g],randx[g]+45,y[g]+50);
     setfillstyle(1,-1);
     bar(randx[g]+3,y[g]+33,randx[g]+42,y[g]+48);
     setcolor(14);
     setfillstyle(1,14);
     pieslice(randx[g]+6,y[g]+50,0,360,4);
     pieslice(randx[g]+39,y[g]+50,0,360,4);
     line(randx[g]+6,y[g]+57,randx[g]+6,y[g]+60);
     line(randx[g]+5,y[g]+57,randx[g]+3,y[g]+60);
     line(randx[g]+7,y[g]+57,randx[g]+9,y[g]+60);
     line(randx[g]+39,y[g]+57,randx[g]+39,y[g]+60);
     line(randx[g]+38,y[g]+57,randx[g]+36,y[g]+60);
     line(randx[g]+40,y[g]+57,randx[g]+42,y[g]+60);
    }
    for(g=0;g<4;g++)                    //separation of cars in odd and even lanes
    {if(g==0||g==2)
      y[g]+=20;
     else if(g==1||g==3)
      y[g]+=40;}
    if(kbhit())                         //checking whether any key is typed...
    {
     ch=getch();
     if(ch==100)                        //moving right
     {o+=maxx/4;
      delay(10);
      mycar(maxy,o);
      if(o>maxx-65)
       break;                           //if my car drowns...breaks out of the loop
     }
     else if(ch==97)                    //moving left
     {o-=maxx/4;
      delay(10);
      mycar(maxy,o);}
     else if(ch==27)                    //pause menu
     {finishsave:
      settextstyle(2,0,6);
      outtextxy(midx-100,midy-80,"1.Continue");
      outtextxy(midx-100,midy,"2.Save");
      outtextxy(midx-100,midy+80,"3.Exit");
      conti=getch();
      if(conti==49)                    //continue the game
       goto cont;
      else if(conti==51)               //exit
       goto begin;
      else if(conti==50)               //save game
      {
       time_t t;
       t = time(NULL);
       savegame save;
       save.k=k;
       for(int cou=0;cou<4;cou++)
	save.y[cou]=y[cou];
       for(cou=0;cou<4;cou++)
	save.randx[cou]=randx[cou];
       save.o=o;
       save.score=s.score;
       strcpy(save.pass,password);
       strcpy(save.name,s.n);
       strcpy(save.time,ctime(&t));
       f1.write((char*)&save,sizeof(save));
       f1.close();
       goto finishsave;
      }
     }
    }//block closing of if kbhit
    else
    {mycar(maxy,o);}
    cont:
    for(g=0;g<4;g++)                  //checking for cars colliding
     if((randx[g]+45>=o&&randx[g]+45<=o+45)||(randx[g]>=o&&randx[g]<=o+45))
      {if(y[g]+40>=maxy-60)
       l++;}
    if(l==1)                           //if collided...breaks out of the loop
     break;
    s.score+=10;
    delay(400-k);
    cleardevice();
   }                                  //main loop closes
   fout.write((char*)&s,sizeof(s));
   int h=0;
   fout.close();
   ifstream fin("points.dat",ios::binary|ios::in);
   while(fin.read((char*)&p[h],sizeof(p[h])))
     {h++;}
   for(int b=0;b<=h-1;b++)
    for(int e=0;e<=h-1-b;e++)
     if(p[e].score<p[e+1].score)
      {
       points u=p[e];
       p[e]=p[e+1];
       p[e+1]=u;}
   for(b=0;b<h;b++)
   {
    strcpy(q[b].n,p[b].n);
    q[b].score=p[b].score;
    q[b].rank=b+1;
   }
   for(b=0;b<h;b++)
     fout1.write((char*)&q[b],sizeof(q[b]));
   char str[10];
   cleardevice();
   setbkcolor(0);
   settextstyle(2,0,4);
   outtextxy(midx-40,midy-50,"Game over");
   outtextxy(midx-125,midy-20,"Try to drive in the proper lane next time");
   outtextxy(midx-125,midy,"Your score is");
   outtextxy(midx-125,midy+20,itoa(s.score,str,10));
   outtextxy(midx-125,midy+50,"Press 1 to play again");
   outtextxy(midx-125,midy+70,"Press 2 to quit the game");
   again=getch();
   if(again==49)
    goto begin;
   else if(again==50)
    exit(EXIT_SUCCESS);
   fin.close();
   fout1.close();
  }
  else if(choice==50)
  {
   cleardevice();
   ifstream f2("save.dat",ios::binary);
   settextstyle(6,0,1);
   if(!f2)
   {
    outtextxy(midx-110,midy,"No saved file exists");
    int ore;
    ore=getch();
    if(ore==27)
     goto begin;
   }
   else
   {
    cleardevice();
    ofstream fout("points.dat",ios::binary|ios::app);
    ofstream fout1("actualpoints.dat",ios::binary);
    points s;
    points p[100];
    actualpoints q[100];
    savegame load[5];
    int he=0;
    char str3[10];
    int hud;
    char passwo[9];
    do
    {
    settextstyle(3,0,3);
    gotoxy(30,10);
    cout<<"Saved Files";     // menu for saved file
    line(midx-88,midy-77,midx+5,midy-77);
    gotoxy(10,12);
    cout<<"Select your choice and then press enter";
    gotoxy(7,13);
    cout<<"(Please take care to choose the proper choice)";
      settextstyle(6,0,1);
      while(f2.read((char*)&load[he],sizeof(load[he]))&&he<=4)
      {
       gotoxy(29,15+he);
       cout<<he+1;
       gotoxy(31,15+he);
       puts(load[he].name);
      // if(he==4)
       //outtextxy(midx-130,midy+25*he,itoa(he+1,str3,10));
       //outtextxy(midx-105,midy+25*he,load[he].name);
       //outtextxy(midx-145,midy+150,"Press 0 and then enter to go back....");
       he++;
      }
       cout<<"\t\tPress 0 and then enter to go back...";
    cin>>hud;
    if(hud==0)
     {
      f2.close();
      fout.close();
      fout1.close();
      goto begin;}
    }while(hud>he);
    cleardevice();
    settextstyle(6,0,1);
    gotoxy(20,15);
    cout<<"Please enter your password: "<<endl;
    gotoxy(19,16);
    cout<<"(Please take care to enter the right password) ";
 //   outtextxy(midx-180,midy-11,"Please enter your password:");
 //   outtextxy(midx-195,midy+10,"(Please take care to enter the right password)");
    gotoxy(48,15);
    for(int aaaa=0;aaaa<8;aaaa++)
    {
     passwo[aaaa]=getch();
     cout<<'*';
    }
    passwo[aaaa]='\0';
    if(strcmp(passwo,load[hud-1].pass)==0)
     goto goda;
    else
     exit(EXIT_SUCCESS);
    goda:
    int y[4];
    int randx[4];
    int o;
    int k;
   cleardevice();
   for(int hor=0;hor<maxx;hor+=50)         //loading graphics
   {
    delay(300);
    settextstyle(3,0,3);
    outtextxy(midx-30,midy-30,"Loading......");
    setfillstyle(1,-1);
    bar(hor,midy,hor+50,midy+8);
   }
   setbkcolor(8);
   setfillstyle(1,9);
   bar(maxx-65,0,maxx,maxy);
   int ch;
   mycar(maxy,o);
    strcpy(s.n,load[hud-1].name);
    for(int g=0;g<4;g++)
     y[g]=load[hud-1].y[g];
     k=load[hud-1].k;
     o=load[hud-1].o;
     s.score=load[hud-1].score;
    f2.close();
    fstream f1("save.dat",ios::binary|ios::in|ios::out);
   for (;;k++)
   {
    int l=0;
    for(int w=150;w<maxx-50;w+=150)   //lane splitter
    {
     setfillstyle(1,-1);
     bar(w,0,w+5,maxy);
    }
    for(int z=75;z<maxx-50;z+=150)    //lines in the middle of the road
     for(int vis=10;vis<maxy;vis+=30)
     {
      setfillstyle(1,-1);
      bar(z,vis,z+5,vis+20);
     }
    setbkcolor(8);
    setfillstyle(1,9);
    bar(maxx-65,0,maxx,maxy);
    for(int g=0;g<4;g++)                        //assigning co-ordinates to other cars
     if(y[g]>=maxy-15)
      y[g]=0;
    for(g=0;g<4;g++)                        //assigning co-ordinates to other cars
     if(y[g]==0)
      randx[g]=((random(4)*(maxx-20))/4)+10;//adjustment done to make other cars go in the lanes correctly
    if(k==0)
     for(int g=0;g<4;g++)
      randx[g]=load[hud-1].randx[g];

    for(g=0;g<4;g++)                        //displaying the other cars
    {
     setfillstyle(1,2);
     bar(randx[g],y[g],randx[g]+45,y[g]+50);
     setfillstyle(1,-1);
     bar(randx[g]+3,y[g]+33,randx[g]+42,y[g]+48);
     setcolor(14);
     setfillstyle(1,14);
     pieslice(randx[g]+6,y[g]+50,0,360,4);
     pieslice(randx[g]+39,y[g]+50,0,360,4);
     line(randx[g]+6,y[g]+57,randx[g]+6,y[g]+60);
     line(randx[g]+5,y[g]+57,randx[g]+3,y[g]+60);
     line(randx[g]+7,y[g]+57,randx[g]+9,y[g]+60);
     line(randx[g]+39,y[g]+57,randx[g]+39,y[g]+60);
     line(randx[g]+38,y[g]+57,randx[g]+36,y[g]+60);
     line(randx[g]+40,y[g]+57,randx[g]+42,y[g]+60);
    }
    for(g=0;g<4;g++)                    //separation of cars in odd and even lanes
    {if(g==0||g==2)
      y[g]+=20;
     else if(g==1||g==3)
      y[g]+=40;}
    if(kbhit())                         //checking whether any key is typed...
    {
     ch=getch();
     if(ch==100)                        //moving right
     {o+=maxx/4;
      delay(10);
      mycar(maxy,o);
      if(o>maxx-65)
       break;                           //if my car drowns...breaks out of the loop
     }
     else if(ch==97)                    //moving left
     {o-=maxx/4;
      delay(10);
      mycar(maxy,o);}
     else if(ch==27)                    //pause menu
     {finishresave:
      settextstyle(2,0,6);
      outtextxy(midx-100,midy-80,"1.Continue");
      outtextxy(midx-100,midy,"2.Save");
      outtextxy(midx-100,midy+80,"3.Exit");
      conti=getch();
      if(conti==49)                    //continue the game
       goto conts;
      else if(conti==51)               //exit
       goto begin;
      else if(conti==50)               //save game again--overwrite
      {
       time_t t;
       t = time(NULL);
       load[hud-1].k=k;
       for(int cou=0;cou<4;cou++)
	load[hud-1].y[cou]=y[cou];
       for(cou=0;cou<4;cou++)
	load[hud-1].randx[cou]=randx[cou];
       load[hud-1].o=o;
       load[hud-1].score=s.score;
       strcpy(load[hud-1].name,s.n);
       strcpy(load[hud-1].time,ctime(&t));
       f1.seekp((hud-1)*sizeof(s),ios::beg);
       f1.write((char*)&load[hud-1],sizeof(load[hud-1]));
       f1.close();
       goto finishresave;
      }
     }
    }//block closing of if kbhit
    else
    {mycar(maxy,o);}
    conts:
    for(g=0;g<4;g++)                  //checking for cars colliding
     if((randx[g]+45>=o&&randx[g]+45<=o+45)||(randx[g]>=o&&randx[g]<=o+45))
      {if(y[g]+40>=maxy-60)
       l++;}
    if(l==1)                           //if collided...breaks out of the loop
     break;
    s.score+=10;
    delay(400-k);
    cleardevice();
   }                                  //main loop closes
   fout.write((char*)&s,sizeof(s));
   int h=0;
   fout.close();
   ifstream fin("points.dat",ios::binary|ios::in);
   while(fin.read((char*)&p[h],sizeof(p[h])))
     {h++;}
   for(int b=0;b<=h-1;b++)
    for(int e=0;e<=h-1-b;e++)
     if(p[e].score<p[e+1].score)
      {
       points u=p[e];
       p[e]=p[e+1];
       p[e+1]=u;}
   for(b=0;b<h;b++)
   {
    strcpy(q[b].n,p[b].n);
    q[b].score=p[b].score;
    q[b].rank=b+1;
   }
   for(b=0;b<h;b++)
     fout1.write((char*)&q[b],sizeof(q[b]));
   char str[10];
   cleardevice();
   setbkcolor(0);
   settextstyle(2,0,4);
   outtextxy(midx-40,midy-50,"Game over");
   outtextxy(midx-125,midy-20,"Try to drive in the proper lane next time");
   outtextxy(midx-125,midy,"Your score is");
   outtextxy(midx-125,midy+20,itoa(s.score,str,10));
   outtextxy(midx-125,midy+50,"Press 1 to play again");
   outtextxy(midx-125,midy+70,"Press 2 to quit the game");
   again=getch();
   if(again==49)
    goto begin;
   else if(again==50)
    exit(EXIT_SUCCESS);
   fin.close();
   fout1.close();
  // f1.close();
  }
 }
  else if(choice==51)
  {cleardevice();
   settextstyle(2,0,6);
   outtextxy(midx-300,midy-100,"The game Rule Breaker is a simple game designed using C++ ");
   outtextxy(midx-300,midy-80,"language.The aim of the game is to avoid clashing with the ");
   outtextxy(midx-300,midy-60,"cars which come in the opposite direction.The car can be ");
   outtextxy(midx-300,midy-40,"navigated by using A to move left and D to move right.");
   outtextxy(midx-300,midy-20,"That's all the rules are, folks.........");
   settextstyle(3,0,3);
   outtextxy(midx-300,midy+20,"ENJOY    THE    GAME!!!");
   outtextxy(midx-300,midy+45,"Press esc to go back");
   back=getch();
   if(back==27)
    goto begin;
  }
  else if(choice==53)
   {exit(EXIT_SUCCESS);}
  else if(choice==52)
   {char str1[10];
    char str2[10];
    cleardevice();
    setcolor(-1);
    settextstyle(3,0,3);
    outtextxy(midx-60,midy-100,"High Scores");
    settextstyle(3,0,3);
    outtextxy(midx-110,midy-35,"Rank");
    outtextxy(midx-35,midy-35,"Name");
    outtextxy(midx+65,midy-35,"Score");
    settextstyle(6,0,1);
    int j=0;
    ifstream fin1("actualpoints.dat",ios::binary|ios::in);
    actualpoints q[100];
     while(fin1.read((char*)&q[j],sizeof(q[j]))&&j<=4)
      {
       outtextxy(midx-100,midy+25*j,itoa(q[j].rank,str1,10));
       outtextxy(midx-25,midy+25*j,q[j].n);
       outtextxy(midx+75,midy+25*j,itoa(q[j].score,str2,10));
       j++;
      }
     back=getch();
     if(back==27)
      goto begin;
     fin1.close();
   }
   getch();

  // f2.close();
   /* clean up */
   closegraph();

   return 0;
}




int start(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy, i;

   /* initialize graphics and local
      variables */
   initgraph(&gdriver, &gmode, "c://turboc3//bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error
       occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error
		  code */
   }

   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   int ch;
      setbkcolor(-1);
	setcolor(14);
// bar(midx-15,midy-40,midx+15,midy+40);
 setfillstyle(8,-1);
 bar3d(0,0,midx*2,midy*2,0,0);
  setcolor(14);
 setfillstyle(1,0);
 bar3d(midx-65,midy-90,midx+70,midy+105,0,0);

   setcolor(14);
   outtextxy(midx-35,midy-70,"LEGO WORLD");
   outtextxy(midx-45,midy-5,"1.ADVENTURER");
   outtextxy(midx-45,midy+35,"2.RULEBREAKER");
   outtextxy(midx-45,midy+75,"3.MEMORY");
   rectangle(midx-55,midy-20,midx+60,midy+15);
   rectangle(midx-55,midy+20,midx+60,midy+55);
   rectangle(midx-55,midy+60,midx+60,midy+95);
   ch=getch();
   if (ch==49)
   {level1(0,0,0,0,"");
    }
   else if(ch==50)
   {racing();
   }
   else if(ch==51)
   {bonus("");
   }
      getch();

   /* clean up */
   closegraph();
   return 0;
}

void main()
{
intro();
do
{
start();
}while(cont()!='n'&&cont()!='N');
closegraph();
}
