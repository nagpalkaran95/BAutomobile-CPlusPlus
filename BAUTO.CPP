#include<conio.h>
#include<fstream.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<graphics.h>

#define RECORDS 1
#define INSTALL 2
#define WORKER_DETAILS 3
#define ABOUT 4
#define EXIT 5

#define ADD_RECORD 6
#define SEARCH_RECORD 7
#define DELETE_RECORD 8
#define MODIFY_RECORD 9
#define MAIN_MENU 10

#define GET 11
#define ADD 12
#define DEL 13

int charge=0;
int zz=0;
int nfwrk=0,empslt=20;
int install;

void heading(int c1,int c2)
{
int b,t;

int gdriver=DETECT,gmode,errorcode;
initgraph(&gdriver,&gmode,"");

setcolor(4);
setlinestyle(7,0,6);

/*********TOP LINE*********/
line(5,20,5,35);
line(55,20,55,35);
line(105,20,105,35);
line(155,20,155,35);
line(210,20,210,35);
line(260,20,260,35);
line(310,20,310,35);
line(360,20,360,35);
line(410,20,410,35);
line(460,20,460,35);
line(510,20,510,35);
line(560,20,560,35);
line(610,20,610,35);

/**********BOTTOM LINE************/

line(5,85,5,100);
line(55,85,55,100);
line(105,85,105,100);
line(155,85,155,100);
line(210,85,210,100);
line(260,85,260,100);
line(310,85,310,100);
line(360,85,360,100);
line(410,85,410,100);
line(460,85,460,100);
line(510,85,510,100);
line(560,85,560,100);
line(610,85,610,100);

/***HORIZONTAL LINES***/

setcolor(4);
line(3,20,640,20);
line(3,35,640,35);

line(3,85,640,85);
line(3,100,640,100);

/**********FILLING THE COLORS IN THE TOP ********/

setfillstyle(1,c1);
floodfill(10,25,4);
floodfill(110,25,4);
floodfill(215,25,4);
floodfill(315,25,4);
floodfill(415,25,4);
floodfill(515,25,4);
floodfill(616,25,4);

floodfill(10,90,4);
floodfill(110,90,4);
floodfill(215,90,4);
floodfill(315,90,4);
floodfill(415,90,4);
floodfill(515,90,4);
floodfill(616,90,4);

/*********FILLING THE COLORS IN THE BOTTOM*********/
setfillstyle(1,c2);
floodfill(60,25,4);
floodfill(160,25,4);
floodfill(265,25,4);
floodfill(365,25,4);
floodfill(465,25,4);
floodfill(565,25,4);

   floodfill(60,90,4);
   floodfill(160,90,4);
   floodfill(265,90,4);
   floodfill(365,90,4);
   floodfill(465,90,4);
   floodfill(565,90,4);

   setbkcolor(0);
   setcolor(10);
   settextstyle(1,0,4);
   outtextxy(174,30,"BCOOL AUTOMOBILES");
   setcolor(12);
   settextstyle(3,0,1);
   outtextxy(200,60,"A Complete Automobile Center");
   setcolor(15);        //setting copyright text color
   circle(432,471.5,5);
   settextstyle(2,0,4);
   outtextxy(430,465,"C");
   settextstyle(2,0,4);
   outtextxy(440,465," 2013 Bcool. All Rights Reserved.");
 }/* Fn ENDS*/

void mainmenu()
  {
	setcolor(4);
	setlinestyle(7,0,10);

	//horizontal lines
	line(215,180,429,180);
	line(215,182,429,182);
	line(215,184,429,184);
	line(215,210,429,210);
	line(215,212,429,212);
	line(215,214,429,214);
	line(215,244,429,244);
	line(215,274,429,274);
	line(215,304,429,304);
	line(215,334,429,334);
	line(215,364,429,364);
	line(215,366,429,366);
	line(215,368,429,368);

	//vertical lines
	line(215,180,215,368);
	line(217,180,217,368);
	line(219,180,219,368);
	line(425,180,425,368);
	line(427,180,427,368);
	line(429,180,429,368);
  }

class service
{
   char owname[16],owadd[16],owph[11],model[16];
   int yom;
   int ts,charge;

      public:
	void getinfo()
	  {
	     settextstyle(11,0,1);
	     setcolor(14);
	     gotoxy(21,11);
	     outtextxy(45,165,"Owner's Name : ");
	     gets(owname);
	     gotoxy(21,12);
	     outtextxy(45,180,"Address      : ");
	     gets(owadd);
	     gotoxy(21,13);
	     outtextxy(45,195,"Contact No.  : ");
	     gets(owph);
	     gotoxy(21,14);
	     outtextxy(45,212,"Car Model    : ");
	     gets(owph);
	     gotoxy(28,15);
	     outtextxy(45,228,"Year Of Manufacture : ");
	     cin>>yom;
	     gotoxy(61,17);
	     setcolor(12);
	     outtextxy(45,245,"Type of Service ");
	     outtextxy(75,260,"(1) MOT / (2) Interim Service / (3) Full Service : ");
	     cin>>ts;
	  }

	 void dispinfo()
	  {
	     setcolor(14);
	     gotoxy(21,11);
	     settextstyle(11,0,1);
	     outtextxy(45,165,"Owner's Name : ");
	     puts(owname);
	     gotoxy(21,12);
	     outtextxy(45,180,"Address      : ");
	     puts(owadd);
	     gotoxy(21,13);
	     outtextxy(45,195,"Contact No.  : ");
	     puts(owph);
	     gotoxy(21,14);
	     outtextxy(45,210,"Car Model    : ");
	     puts(owph);
	     gotoxy(28,15);
	     outtextxy(45,228,"Year Of Manufacture : ");
	     cout<<yom;
	  }
	char* retname()
	  {
	     return owname;
	  }
};

class main_menu_fns
{
    service v;
      public:
	int menu();
	int rec_menu();

	void add_rec()
	{
	   cleardevice();
	   heading(4,14);
	   fstream fl("service.dat",ios::app);
	   service s;
	   s.getinfo();
	   fl.write((char*)&s,sizeof(s));
	   fl.close();
	   setcolor(2);
	   settextstyle(2,0,4);
	   outtextxy(540,440,"1 Record Added.");
	   getch();
	   cleardevice();
	   closegraph();
	}

	void search_rec()
	{
	   heading(4,14);
	   fstream fl("service.dat",ios::in,ios::binary);
	   service s;
	   char rn[16];
	   settextstyle(11,0,1);
	   outtextxy(32,148,"Enter Owner's Name to search record : ");
	   gotoxy(43,10);
	   gets(rn);
	   char search='n';

	   while(!fl.eof())
	     {
	       fl.read((char*)&s,sizeof(s));
	       if(fl.eof())
		   break;
	       if(strcmp(s.retname(),rn)==0)
		{
		 search='y';
		}
	     }
	       if(search=='y')
		{
		 cleardevice();
		 closegraph();
		 heading(4,14);
		 s.dispinfo();
		 setcolor(2);
		 settextstyle(2,0,4);
		 outtextxy(542,440,"Record Found.");
		 getch();
		}
	       if(search=='n')
		{
		  cleardevice();
		  closegraph();
		  heading(4,14);
		  setcolor(4);
		  settextstyle(2,0,4);
		  outtextxy(535,440,"No Record Found.");
		  getch();
		}
	   fl.close();
	   cleardevice();
	   closegraph();
	}

	void modify_rec()
	{
	   clrscr();
	   heading(4,14);
	   fstream fl("service.dat",ios::in|ios::out,ios::binary);
	   service s;
	   long pos;
	   char oname[16];
	   settextstyle(11,0,1);
	   outtextxy(32,148,"Enter Owner's Name to modify record : ");
	   gotoxy(43,10);
	   gets(oname);
	   char fd='n';
	   while(!fl.eof())
	     {
	       pos=fl.tellg();
	       fl.read((char*)&s,sizeof(s));
	       if(fl.eof())
		   break;
	       if(strcmp(s.retname(),oname)==0)
		{
		 fd='y';
		}
	     }
	       if(fd=='y')
		{
		 cleardevice();
		 closegraph();
		 heading(4,14);
		 fl.seekp(pos,ios::beg);
		 s.getinfo();
		 fl.write((char*)&s,sizeof(s));
		 setcolor(2);
		 settextstyle(2,0,4);
		 outtextxy(526,440,"  Record Modified.");
		 getch();
		}

	       if(fd=='n')
		{
		  cleardevice();
		  closegraph();
		  heading(4,14);
		  setcolor(4);
		  settextstyle(2,0,4);
		  outtextxy(535,440,"No Record Found.");
		  getch();
		}
	   fl.close();
	   cleardevice();
	   closegraph();
	}

	void del_rec()
	{
	   clrscr();
	   heading(4,14);
	   ifstream fl1("service.dat",ios::binary);
	   ofstream fl2("temp.dat",ios::binary);
	   char dl[16];
	   settextstyle(11,0,1);
	   outtextxy(32,148,"Enter Owner's Name to delete record : ");
	   gotoxy(43,10);
	   gets(dl);
	   service s;
	   char f='n';
	   while(!fl1.eof())
	     {
	       fl1.read((char*)&s,sizeof(s));
		if(fl1.eof())
		  break;
		if(strcmp(s.retname(),dl)!=0)
		  {
		     f='y';
		  }
		if(strcmp(s.retname(),dl)!=0)
		  {
		   fl2.write((char*)&s,sizeof(s));
		  }
	     }
	   fl1.close();
	   fl2.close();
	   remove("service.dat");
	   rename("temp.dat","service.dat");
	   if(f=='y')
	      {
		cleardevice();
		closegraph();
		heading(4,14);
		setcolor(2);
		settextstyle(2,0,4);
		outtextxy(530,440,"1 Record deleted.");
		getch();
	      }
	   if(f=='n')
	      {
		cleardevice();
		closegraph();
		heading(4,14);
		setcolor(4);
		settextstyle(2,0,4);
		outtextxy(535,440,"No Record Found.");
		getch();
	      }
	    cleardevice();
	    closegraph();
	 }
};

int main_menu_fns::menu()
  {
	cleardevice();
	heading(4,14);
	mainmenu();
	settextstyle(1,0,1);
	setcolor(12);
	outtextxy(296,185,"MENU");
	settextstyle(2,0,5);
	setcolor(11);
	outtextxy(260,221,"1. RECORDS");
	outtextxy(260,251,"2. INSTALL PARTS");
	outtextxy(260,281,"3. WORKER DETAILS");
	outtextxy(260,311,"4. ABOUT");
	outtextxy(260,341,"5. EXIT");
	setcolor(10);
	outtextxy(85,400,"Press UP/DOWN arrow key for scrolling & ENTER key for selection ");

	int rect_co_ord[5][4]={
			220,215,424,243,
			220,245,424,273,
			220,275,424,303,
			220,305,424,333,
			220,335,424,363
			};
	setcolor(15);
	int i=0;
     rectangle(rect_co_ord[i][0],rect_co_ord[i][1],rect_co_ord[i][2],rect_co_ord[i][3]);
	char c;
    while(1)
     {
      c=getch();
      if(c==80)
	{
	   int x=getmaxx();
	   int y=getmaxy();
	    setviewport(rect_co_ord[i][0],rect_co_ord[i][1],rect_co_ord[i][2],rect_co_ord[i][3],1);
	   clearviewport();
	   setviewport(0,0,x,y,1);
	   setcolor(11);
	  if(i==0)
		outtextxy(260,221,"1. RECORDS");
	  else if(i==1)
		outtextxy(260,251,"2. INSTALL PARTS");
	  else if(i==2)
		outtextxy(260,281,"3. WORKER DETAILS");
	  else if(i==3)
		outtextxy(260,311,"4. ABOUT");
	  else if(i==4)
		outtextxy(260,341,"5. EXIT");
	  setcolor(15);
	  if(i==4)
	      i=-1;
	   rectangle(rect_co_ord[i+1][0],rect_co_ord[i+1][1],rect_co_ord[i+1][2],rect_co_ord[i+1][3]);
	   i++;
	}
       else if(c==72)
	{
	   int x=getmaxx();
	   int y=getmaxy();
	    setviewport(rect_co_ord[i][0],rect_co_ord[i][1],rect_co_ord[i][2],rect_co_ord[i][3],1);
	   clearviewport();
	   setviewport(0,0,x,y,1);
	   setcolor(11);
	  if(i==0)
		outtextxy(260,221,"1. RECORDS");
	  else if(i==1)
		outtextxy(260,251,"2. INSTALL PARTS");
	  else if(i==2)
		outtextxy(260,281,"3. WORKER DETAILS");
	  else if(i==3)
		outtextxy(260,311,"4. ABOUT");
	  else if(i==4)
		outtextxy(260,341,"5. EXIT");
	  i--;
	  if(i<0)
	      i=4;
	   setcolor(15);
	   rectangle(rect_co_ord[i][0],rect_co_ord[i][1],rect_co_ord[i][2],rect_co_ord[i][3]);
	}

	/*** if enter key is pressed for 'Records' option ***/
	   else if(c==13 && i==0)
	    {
	    return RECORDS;
	    }
	   /*** if enter key is pressed for 'install parts' option ***/
	   else if(c==13 && i==1)
	    {
	    return INSTALL;
	    }
	   /*** if enter key is pressed for 'work info' option ***/
	   else if(c==13 && i==2)
	    {
	    return WORKER_DETAILS;
	    }
	   /*** if enter key is pressed for 'About' option ***/
	   else if(c==13 && i==3)
	    {
	    return ABOUT;
	    }
	   /*** if enter key is pressed for 'Exit' option ***/
	   else if(c==13 && i==4)
	    {
	    return EXIT;
	    }
       }
}

int main_menu_fns::rec_menu()
  {
	heading(4,14);
	mainmenu();
	settextstyle(1,0,1);
	setcolor(12);
	outtextxy(285,185,"RECORDS");
	settextstyle(2,0,5);
	setcolor(11);
	outtextxy(260,221,"1. ADD RECORD");
	outtextxy(260,251,"2. SEARCH RECORD");
	outtextxy(260,281,"3. DELETE RECORD");
	outtextxy(260,311,"4. MODIFY RECORD");
	outtextxy(260,341,"5. BACK");
	setcolor(10);
	outtextxy(85,400,"Press UP/DOWN arrow key for scrolling & ENTER key for selection ");

	int rect_co_ord[5][4]={
			220,215,424,243,
			220,245,424,273,
			220,275,424,303,
			220,305,424,333,
			220,335,424,363
			};
	setcolor(15);
	int i=0;
     rectangle(rect_co_ord[i][0],rect_co_ord[i][1],rect_co_ord[i][2],rect_co_ord[i][3]);
	char c;
      while(1)
       {
	c=getch();
	if(c==80)
	 {
	   int x=getmaxx();
	   int y=getmaxy();
	    setviewport(rect_co_ord[i][0],rect_co_ord[i][1],rect_co_ord[i][2],rect_co_ord[i][3],1);
	   clearviewport();
	   setviewport(0,0,x,y,1);
	   setcolor(11);
	  if(i==0)
		outtextxy(260,221,"1. ADD RECORD");
	  else if(i==1)
		outtextxy(260,251,"2. SEARCH RECORD");
	  else if(i==2)
		outtextxy(260,281,"3. DELETE RECORD");
	  else if(i==3)
		outtextxy(260,311,"4. MODIFY RECORD");
	  else if(i==4)
		outtextxy(260,341,"5. BACK");
	  setcolor(15);
	  if(i==4)
	      i=-1;
	   rectangle(rect_co_ord[i+1][0],rect_co_ord[i+1][1],rect_co_ord[i+1][2],rect_co_ord[i+1][3]);
	   i++;
	   }
	   else if(c==72)
	   {
	   int x=getmaxx();
	   int y=getmaxy();
	   setviewport(rect_co_ord[i][0],rect_co_ord[i][1],rect_co_ord[i][2],rect_co_ord[i][3],1);
	   clearviewport();
	   setviewport(0,0,x,y,1);
	   setcolor(11);
	  if(i==0)
		outtextxy(260,221,"1. ADD RECORD");
	  else if(i==1)
		outtextxy(260,251,"2. SEARCH RECORD");
	  else if(i==2)
		outtextxy(260,281,"3. DELETE RECORD");
	  else if(i==3)
		outtextxy(260,311,"4. MODIFY RECORD");
	  else if(i==4)
		outtextxy(260,341,"5. BACK");
	  i--;
	  if(i<0)
	      i=4;
	   setcolor(15);
	   rectangle(rect_co_ord[i][0],rect_co_ord[i][1],rect_co_ord[i][2],rect_co_ord[i][3]);
	}

	/*** if enter key is pressed for 'add record' option ***/
	   else if(c==13 && i==0)
	    {
	    return ADD_RECORD;
	    }
	   /*** if enter key is pressed for 'search record' option ***/
	   else if(c==13 && i==1)
	    {
	    return SEARCH_RECORD;
	    }
	   /*** if enter key is pressed for 'delete record' option ***/
	   else if(c==13 && i==2)
	    {
	    return DELETE_RECORD;
	    }
	   /*** if enter key is pressed for 'modify record' option ***/
	   else if(c==13 && i==3)
	    {
	    return MODIFY_RECORD;
	    }
	   /*** if enter key is pressed for 'Back' option ***/
	   else if(c==13 && i==4)
	    {
	    return MAIN_MENU;
	    }
       }
}

class welcome
{
     char uname[16];
     char pass[16];
     char che[16];
     int i,x,y;
	public:
	  char user[5];
	  char pword[8];
	  void login()
		{
		 settextstyle(3,0,1);
		 setcolor(12);
		 outtextxy(205,175,"Please Login To Continue");
		 gotoxy(30,15);
		 cout<<"USER NAME : ";
		 gets(uname);
		 cout<<"\n";
		 gotoxy(30,16);
		 cout<<"PASSWORD  : ";
		 x=327;
		 y=237;
		 setcolor(7);
		 for(int i=0;i<16;i++)
		  {
			che[i]=getch();
			    if(che[i]==13)
			       break;
			outtextxy(x,y,"*");
			x+=10;
		  }
		  che[i]='\0';
		 if(strcmp(uname,"admin")==0 && strcmp(che,"password")==0)
		   {
		       settextstyle(3,0,1);
		       setcolor(2);
		       outtextxy(115,290,"Password Accepted. Press any key to continue...");
		       getch();
		       return;
		   }
		else
		   {
		       settextstyle(3,0,1);
		       setcolor(4);
		       outtextxy(90,290,"Access Denied. Please enter again or press ESC to exit");
		       int ch=getch();
		       if(ch==27)
		       exit(0);
		       clrscr();
		       heading(4,14);
		       login();
		   }
		}
};


void insmenu()
  {
	setcolor(7);
	setlinestyle(7,0,10);

	//horizontal lines
	line(30,176,616,176);
	line(30,178,616,178);
	line(30,180,616,180);

	line(30,210,616,210);
	line(30,212,616,212);
	line(30,214,616,214);

	line(30,244,616,244);
	line(30,246,616,246);
	line(30,248,616,248);

	line(30,278,616,278);
	line(30,280,616,280);
	line(30,282,616,282);

	line(30,312,616,312);
	line(30,314,616,314);
	line(30,316,616,316);

	line(30,346,616,346);
	line(30,348,616,348);
	line(30,350,616,350);

	line(30,380,616,380);
	line(30,382,616,382);
	line(30,384,616,384);

	//vertical lines
	line(30,176,30,384);
	line(32,176,32,384);
	line(34,176,34,384);

	line(224,176,224,384);
	line(226,176,226,384);
	line(228,176,228,384);

	line(418,176,418,384);
	line(420,176,420,384);
	line(422,176,422,384);

	line(612,176,612,384);
	line(614,176,614,384);
	line(616,176,616,384);
  }

void billcount()
      {
	 switch(install)
	  {
	     case 1 : charge=1000;
		      break;
	     case 2 : charge=1000;
		      break;
	     case 3 : charge=800;
		      break;
	     case 4 : charge=800;
		      break;
	     case 5 : charge=500;
		      break;
	     case 6 : charge=400;
		      break;
	     case 7 : charge=100;
		      break;
	     case 8 : charge=100;
		      break;
	     case 9 : charge=100;
		      break;
	     case 10 : charge=200;
		      break;
	     case 11 : charge=2000;
		      break;
	     case 12 : charge=4000;
		      break;
	     case 13 : charge=150;
		      break;
	     case 14 : charge=100;
		      break;
	     case 15 : charge=50;
		      break;
	     case 16 : charge=2000;
		      break;
	     case 17 : charge=200;
		      break;
	     case 18 : charge=3000;
		      break;
	  }
      }

void install_parts()
{
   clrscr();
   heading(4,14);
   insmenu();

	settextstyle(2,0,5);
	setcolor(6);

	outtextxy(50,188,"1. FRONT BUMPERS");
	outtextxy(50,221,"2. REAR BUMPERS");
	outtextxy(50,255,"3. SIDE SKIRTS");
	outtextxy(50,289,"4. SPOILERS");
	outtextxy(50,323,"5. HOODS");
	outtextxy(50,357,"6. ROOF SCOOPS");
	outtextxy(244,188,"7. HEADLIGHTS");
	outtextxy(244,221,"8. TAILLIGHTS");
	outtextxy(244,255,"9. SIDE MIRRORS");
	outtextxy(236,289,"10. EXHAUST TIPS");
	outtextxy(236,323,"11. RIMS");
	outtextxy(236,357,"12. CARBON FIBERS");
	outtextxy(438,188,"13. NEON LIGHTS");
	outtextxy(438,221,"14. WINDOW TINT");
	outtextxy(438,255,"15. VINYLS");
	outtextxy(438,289,"16. AUDIO SYSTEM");
	outtextxy(438,323,"17. BASE PAINT");
	outtextxy(438,357,"18. HYDRAULICS");

	setcolor(10);
	outtextxy(100,400,"Press ESC key to finish installing item and know your bill ");

	setcolor(13);
	outtextxy(50,127,"What you want to install ? : ");
	outtextxy(265,132,"__");
	gotoxy(34,9);
	cin>>install;
	billcount();
	int x=getmaxx();
	int y=getmaxy();
	setviewport(160,230,476,296,1);
	clearviewport();
	setviewport(0,0,x,y,1);
	setcolor(9);
	x=getmaxx();
	y=getmaxy();
	setviewport(190,310,446,340,1);
	clearviewport();
	setviewport(0,0,x,y,1);
	rectangle(160,230,476,296);
	rectangle(163,233,473,293);
	rectangle(190,310,446,340);
	rectangle(193,313,443,337);
	setcolor(13);
	outtextxy(170,255,"You just installed parts worth $ ");
	gotoxy(53,17);
	cout<<charge;
	setcolor(11);
	outtextxy(215,317,"Press any key to continue... ");
   getch();
}

void work()
  {
	setcolor(7);
	setlinestyle(7,0,10);

	//horizontal lines
	line(30,278,616,278);
	line(30,280,616,280);
	line(30,282,616,282);

	line(30,312,616,312);
	line(30,314,616,314);
	line(30,316,616,316);

	//vertical lines
	line(30,278,30,316);
	line(32,278,32,316);
	line(34,278,34,316);

	line(224,278,224,316);
	line(226,278,226,316);
	line(228,278,228,316);

	line(418,278,418,316);
	line(420,278,420,316);
	line(422,278,422,316);

	line(612,278,612,316);
	line(614,278,614,316);
	line(616,278,616,316);
  }

class worker
{
   char wname[16],wadd[16],wph[11];
   int age,sal;

      public:
	void getinfo()
	  {
	     settextstyle(11,0,1);
	     setcolor(14);
	     gotoxy(22,11);
	     outtextxy(45,165,"Worker's Name : ");
	     gets(wname);
	     gotoxy(21,12);
	     outtextxy(45,180,"Address      : ");
	     gets(wadd);
	     gotoxy(21,13);
	     outtextxy(45,195,"Contact No.  : ");
	     gets(wph);
	     gotoxy(15,14);
	     outtextxy(45,212,"Age    : ");
	     cin>>age;
	     gotoxy(15,15);
	     outtextxy(45,228,"Salary : ");
	     cin>>sal;
	  }

	 void dispinfo()
	  {
	     setcolor(14);
	     gotoxy(22,11);
	     settextstyle(11,0,1);
	     outtextxy(45,165,"Worker's Name : ");
	     puts(wname);
	     gotoxy(21,12);
	     outtextxy(45,180,"Address      : ");
	     puts(wadd);
	     gotoxy(21,13);
	     outtextxy(45,195,"Contact No.  : ");
	     puts(wph);
	     gotoxy(15,14);
	     outtextxy(45,210,"AGE    : ");
	     cout<<age;
	     gotoxy(15,15);
	     outtextxy(45,228,"Salary : ");
	     cout<<sal;
	  }
	char* retname()
	  {
	     return wname;
	  }
};

void nfwr()
	  {
	    fstream fl("work.dat",ios::app);
	    worker w;
	    fl.seekg(0,ios::end);
	    nfwrk=fl.tellg()/sizeof(w);
	    fl.close();
	  }

class workerfns
{
   public:

	void addwork()
	  {
	    clrscr();
	    heading(4,14);
	    fstream fl("work.dat",ios::app);
	    worker w;
	    w.getinfo();
	    fl.write((char*)&w,sizeof(w));
	    setcolor(2);
	    settextstyle(2,0,4);
	    outtextxy(540,440,"1 Record Added.");
	    fl.close();
	    cleardevice();
	    closegraph();
	  }

	void getwork()
	  {
	    clrscr();
	    heading(4,14);
	    ifstream fl("work.dat",ios::binary);
	    worker w;
	    char rn[16];
	    settextstyle(11,0,1);
	    outtextxy(32,148,"Enter Worker's Name to search record : ");
	    gotoxy(43,10);
	    gets(rn);
	    char found='n';
	    while(!fl.eof())
	      {
		fl.read((char*)&w,sizeof(w));
		if(fl.eof())
		  break;
		if(strcmp(w.retname(),rn)==0)
		   {
			found='y';
		   }
	      }
	    if(found=='y')
	     {
		cleardevice();
		closegraph();
		heading(4,14);
		w.dispinfo();
		setcolor(2);
		settextstyle(2,0,4);
		outtextxy(542,440,"  Record Found.");
		getch();
	     }

	    else
	      {
		cleardevice();
		closegraph();
		heading(4,14);
		setcolor(4);
		settextstyle(2,0,4);
		outtextxy(535,440,"No Record Found.");
		getch();
	      }
	    fl.close();
	    cleardevice();
	    closegraph();
	  }

       void delwork()
	  {
	   clrscr();
	   heading(4,14);
	   ifstream fl1("work.dat",ios::binary);
	   ofstream fl2("temp.dat",ios::binary);
	   char dl[16];
	   settextstyle(11,0,1);
	   outtextxy(32,148,"Enter Worker's Name to delete record : ");
	   gotoxy(43,10);
	   gets(dl);
	   worker w;
	   char fnd='n';
	   while(!fl1.eof())
	     {
	       fl1.read((char*)&w,sizeof(w));
		if(fl1.eof())
		  break;
		if(strcmp(w.retname(),dl)==0)
		  {
		     fnd='y';
		  }
		if(strcmp(w.retname(),dl)!=0)
		  {
		   fl2.write((char*)&w,sizeof(w));
		  }
	     }
	   fl1.close();
	   fl2.close();
	   remove("work.dat");
	   rename("temp.dat","work.dat");
	   if(fnd=='y')
	      {
		cleardevice();
		closegraph();
		heading(4,14);
		setcolor(2);
		settextstyle(2,0,4);
		outtextxy(530,440,"1 Record deleted.");
		getch();
	      }
	    else
	      {
		cleardevice();
		closegraph();
		heading(4,14);
		setcolor(4);
		settextstyle(2,0,4);
		outtextxy(535,440,"No Record Found.");
		getch();
	      }
	    cleardevice();
	    closegraph();
	 }
};

int work_info()
 {
   clrscr();
   heading(4,14);
   work();
   settextstyle(8,0,1);
   setcolor(11);
   outtextxy(190,150,"No. of workers : ");
   gotoxy(45,11);
   nfwr();
   cout<<nfwrk;
   outtextxy(190,180,"Empty slots : ");
   gotoxy(42,13);
   cout<<empslt-nfwrk;
   settextstyle(2,0,5);
   setcolor(5);
   outtextxy(62,289,"Get Worker Details ");
   outtextxy(258,289,"Add Worker Details ");
   outtextxy(442,289,"Delete Worker Details ");
   setcolor(9);
   outtextxy(160,340,"Press ESC key to go back to the MAIN MENU ");
   setcolor(10);
   outtextxy(75,380,"Press LEFT/RIGHT arrow key for scrolling & ENTER key for selection ");

   int rect_co_ord[4][4]={
			36,284,222,310,
			230,284,416,310,
			424,284,610,310,
			};
	setcolor(15);
	int i=0;
	rectangle(rect_co_ord[i][0],rect_co_ord[i][1],rect_co_ord[i][2],rect_co_ord[i][3]);
	char c;
    while(1)
     {
      c=getch();
      if(c==77)
	{
	  int x=getmaxx();
	  int y=getmaxy();
	  setviewport(rect_co_ord[i][0],rect_co_ord[i][1],rect_co_ord[i][2],rect_co_ord[i][3],1);
	  clearviewport();
	  setviewport(0,0,x,y,1);
	  settextstyle(2,0,5);
	  setcolor(5);
	  if(i==0)
	    {
		 outtextxy(62,289,"Get Worker Details ");
	    }
	  else if(i==1)
	    {
		 outtextxy(258,289,"Add Worker Details ");
	    }
	  else if(i==2)
	    {
		 outtextxy(442,289,"Delete Worker Details ");
	    }
	  setcolor(15);
	  if(i==2)
	      i=-1;
	   rectangle(rect_co_ord[i+1][0],rect_co_ord[i+1][1],rect_co_ord[i+1][2],rect_co_ord[i+1][3]);
	   i++;
	}
       else if(c==75)
	{
	   int x=getmaxx();
	   int y=getmaxy();
	   setviewport(rect_co_ord[i][0],rect_co_ord[i][1],rect_co_ord[i][2],rect_co_ord[i][3],1);
	   clearviewport();
	   setviewport(0,0,x,y,1);
	   settextstyle(2,0,5);
	   setcolor(5);
	   if(i==0)
	    {
		 outtextxy(62,289,"Get Worker Details ");
	    }
	  else if(i==1)
	    {
		 outtextxy(258,289,"Add Worker Details ");
	    }
	  else if(i==2)
	    {
		 outtextxy(442,289,"Delete Worker Details ");
	    }
	  i--;
	  if(i<0)
	      i=2;
	   setcolor(15);
	   rectangle(rect_co_ord[i][0],rect_co_ord[i][1],rect_co_ord[i][2],rect_co_ord[i][3]);
	}

	/*** if enter key is pressed for 'get worker det' option ***/
	   else if(c==13 && i==0)
	    {
	    return GET;
	    }
	   /*** if enter key is pressed for 'add worker det' option ***/
	   else if(c==13 && i==1)
	    {
	    return ADD;
	    }
	   /*** if enter key is pressed for 'delete worker det' option ***/
	   else if(c==13 && i==2)
	    {
	    return DEL;
	    }
	   else if(c==27)
	    {
	      return MAIN_MENU;
	    }
       }
   getch();
 }

void about()
 {
   clrscr();
   heading(4,14);
   settextstyle(1,0,1);
   setcolor(11);
   outtextxy(30,120,"This programe facilitates all the processes for Automobile ");
   outtextxy(30,145,"Service Center. Adding ,Modifying ,Deleting & Searching of ");
   outtextxy(30,170,"records can be done through this program.Moreover it deals ");
   outtextxy(30,195,"with installation of some extra parts. However, all the options ");
   outtextxy(30,220,"given are in working condition with negligible errors. This ");
   outtextxy(30,245,"programe has been designed in a very user friendly manner ");
   outtextxy(30,270,"supported by attractive graphics.The logic used is very simple ");
   outtextxy(30,295,"and easy to understand. Enjoy It !!");
   settextstyle(1,0,3);
   setcolor(10);
   outtextxy(150,350,"DESIGNED BY :");
   setcolor(9);
   outtextxy(330,350,"KARAN NAGPAL");
   settextstyle(11,0,4);
   setcolor(13);
   outtextxy(210,410,"Press Any Key To Continue!!..");
   getch();
 } /* Fn ENDS */

void main()
{
   clrscr();
   heading(4,14);
   int m_ret;
   int r_ret;
   int w_ret;
   welcome w1;
   w1.login();
   main_menu_fns m;
   workerfns w;
   do
    {
      m_ret=m.menu();
      switch(m_ret)
      {
	 case RECORDS:
	      do
	      {
		  r_ret=m.rec_menu();
		  switch(r_ret)
		  {
		     case ADD_RECORD:
			     m.add_rec();
			     break;
		     case SEARCH_RECORD:
			     m.search_rec();
			     getch();
			     break;
		     case DELETE_RECORD:
			     m.del_rec();
			     getch();
			     break;
		     case MODIFY_RECORD:
			     m.modify_rec();
			     getch();
			     break;
		  }
	      }while(r_ret!=MAIN_MENU);
	      break;
	 case INSTALL:
		  install_parts();
		  break;
	 case WORKER_DETAILS:
	     do
	      {
		  w_ret=work_info();
		  switch(w_ret)
		  {
		     case ADD:
			     w.addwork();
			     break;
		     case GET:
			     w.getwork();
			     getch();
			     break;
		     case DEL:
			     w.delwork();
			     getch();
			     break;
		  }
	      }while(w_ret!=MAIN_MENU);
	      break;

	 case ABOUT:
	       about();
	       break;
      }
    }while(m_ret!=EXIT);
}

//***END OF PROJECT***//
