#include"stdio.h"
#include<time.h>
#include"walk.h"
#include"color.h"

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
int song(int i)
{
    int note[160]={1,2,2,2,3,4,4,4,5,6,5,
                        6,7,8,3,4,4,3,4,4,3,
                        9,10,11,10,12,10,4,13,3,4,
                        4,3,4,4,3,4,10,11,10,12,
                        14,15,16,17,2,14,3,4,4,3,
                        4,4,3,4,10,11,10,12,10,4,
                        13,18,13,19,20,19,13,18,21,18,
                        13,22,13,18,21,23,21,18,24,18,
                        21,25,23,26,27,6,28,23,25,29,
                        30,25,23,10,25,10,37,30,6,30,
                        25,4,31,4,2,6,32,6,30,13,
                        33,13,34,32,28,35,28,18,24,36,
                        30,25,23,10,25,10,37,30,6,30,
                        25,4,30,4,2,6,32,6,38,13,
                        18,13,3,4,6,6,6,6,39,39,
                        39,40,39,40,39,41,42,43,44};
    switch(note[i]){
        case 1 :Beep(480,200);break;
        case 2 :Beep(1568,200);break;
        case 3 :Beep(739.99,200);break;
        case 4 :Beep(783.99,200);break;
        case 5 :Beep(369.99,200);break;
        case 6 :Beep(392,200);break;
        case 7 :Beep(392,400);break;
        case 8 :Beep(196,400);break;
        case 9 :Beep(196,400);break;
        case 10 :Beep(880,200);break;
        case 11 :Beep(830.61,200);break;
        case 12 :Beep(987.77,400);break;
        case 13 :Beep(698.46,200);break;
        case 14 :Sleep(200);break;
        case 15 :Beep(1108,10);break;
        case 16 :Beep(1174.7,200);break;
        case 17 :Beep(1480,10);break;
        case 18 :Beep(659.25,200);break;
        case 19 :Beep(784,200);break;
        case 20 :Beep(880,400);break;
        case 21 :Beep(587.33,200);break;
        case 22 :Beep(784,400);break;
        case 23 :Beep(523.25,200);break;
        case 24 :Beep(698.46,400);break;
        case 25 :Beep(493.88,200);break;
        case 26 :Sleep(400);break;
        case 27 :Beep(349.23,400);break;
        case 28 :Beep(329.63,200);break;
        case 29 :Beep(466.16,200);break;
        case 30 :Beep(440,200);break;
        case 31 :Beep(440, 200);break;
        case 32 :Beep(349.23,200);break;
        case 33 :Beep(415.2,200);break;
        case 34 :Beep(1396.92,200);break;
        case 35 :Beep(311.13,200);break;
        case 36 :Beep(783.99,400);break;
        case 37 :Beep(1760,200);break;
        case 38 :Beep(440,00);break;
        case 39 :Beep(196,200);break;
        case 40 :Beep(185,200);break;
        case 41 :Beep(207.65,200);break;
        case 42 :Beep(220,200);break;
        case 43 :Beep(233.08,200);break;
        case 44 :Beep(246.94,200);break;
    }

}
main()
{
        char font[12][60]={"           _____                             "
                     ,"          /     \\  _____   ________  ____   "
                     ,"         /  \\ /  \\ \\__  \\  \\___   /_/ __ \\  "
                     ,"        /    Y    \\ / __ \\_ /    / \\  ___/  "
                     ,"        \\____|__  /(____  //_____ \\ \\___  >  "
                     ,"                \\/      \\/       \\/     \\/   "
                     ,"     ___________          __                  "
                     ,"     \\_   _____/_____   _/  |_   ____  _______ "
                     ,"      |    __)_ \\__  \\  \\   __\\_/ __ \\ \\_  __ \\"
                     ,"      |        \\ / __ \\_ |  |  \\  ___/  |  | \\/"
                     ,"     /_______  /(____  / |__|   \\___  > |__|   "
                     ,"             \\/      \\/             \\/          "};
    char direct,pank[]="press any key";
    int p=0,i,j,x=15,y=14,enter=0,directn,s=0;
    int score=0;
    int n,m;
    //p=2;
    while(p<6){
        switch(p){
        case 0: for(i=0;i<12;i++){
                        textcolor(5,0);printf("%s",font[i]);resetcolor();
                        printf("\n");
                }
                {for(i=0;i<13;i++){
                    if(i==0)printf("\n%20c",' ');
                    delay(30);
                    printf("%c",pank[i]);
                }
                for(s=0;s<160;s++){
                    if(kbhit()){getch();break;}
                    song(s);
                    if(s==159)s=0;
                }

                }break;


        case 1: for(i=0;i<12;i++){
                        textcolor(5,0);printf("%s",font[i]);resetcolor();
                        printf("\n");
                }
                {printf("\n%35s\n","Choose your dificult");
                printf("%22s\n","easy");
                printf("%24s\n","normal");
                printf("%22s\n","hard");
                while(enter!=1){
                  hidecursor();
                  resetcolor();
                  walk(x,y);
                  printf(">>");
                  if(kbhit()){
                    direct=getch();
                    if(direct==72&&y>=15){y--;walk(x,y+1);textcolor(0,0);printf(">>");}
                    if(direct==80&&y<=15){y++;walk(x,y-1);textcolor(0,0);printf(">>");}
                    if(direct==13)enter++;
                  }
                    song(s);
                    s++;
                    if(s==159)s=0;

                }}break;

        case 2:{ if(y==14){n=20;m=10;}
                 if(y==15){n=30;m=14;}
                 if(y==16){n=50;m=16;}
                 { ///load
                     for(i=0;i<2;i++){
                walk(n,n);

                printf("Loadding ");
                for(j=0;j<4;j++){
                    delay(500);printf(". ");
                    }
                system("cls");
                 }
                 }///end load

                 int show[100*2+1][100*2+1];
                map(n,m,show);

                rand_item(show,n,m,0);resetcolor();

                rand_item(show,n,m,1);resetcolor();

                int *mons_pos,unit=2,*p;
                mons_pos=(int*)malloc(sizeof(int)*2*unit);
                p=mons_pos;
                rand_mons(show,n,m,unit,mons_pos);resetcolor();

                for(i=0;i<unit;i++,p+=2){
                    walk(70,10+i);
                    printf("%d  %d\n",*p,*(p+1));
                }

                run(show,n,m,&score,mons_pos);
                free(mons_pos);

                //getch();
                 }
                 break;
        case 3: {for(i=0;i<2;i++){
                //walk(n,n);
                printf("Loadding ");
                for(j=0;j<4;j++){
                    //delay(500);printf(". ");
                    }
                system("cls");
                 }
                    //walk(n,n);//printf("CONGRATULATIONS FOR \"NOOP LEVEL\"");//delay(5000);
                //score page

                char name[20];

                n=10; //
                walk(n,n);
                printf("You got %d score\n",score);
                printf("enter your name : ");
                gets(name);
                savescore(name,score);
                system("cls");


                printf("+----------Top 10's score-----------+\n");
                readscore();
                printf("+-----------------------------------+\n");
                getch();

                  }break;

        };
        system("cls");
        p++;
    }
}
void savescore(char name[],int score){
    FILE *fp;
    fp = fopen("score.txt","a");
    fprintf(fp, "%s %d\n",name,score);
    fclose(fp);
}

void readscore(){
    FILE *fp;
    char read[30],name[50][30],score[50][10],keep[30];
    int i,j,c=0;
    fp =fopen("score.txt","r");
    fscanf(fp, "%s", read);
    while(strcmp(read,score[c-1])!=0){
        strcpy(name[c],read);
        fscanf(fp, "%s", read);
        strcpy(score[c],read);
        fscanf(fp, "%s", read);
        c++;
    }

    for(i=0;i<c;i++){
        for(j=i+1;j<c;j++){
            if (cmp(score[i],score[j])<0){
                strcpy(keep,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],keep);
                strcpy(keep,score[i]);
                strcpy(score[i],score[j]);
                strcpy(score[j],keep);
            }
        }
    }

    for (i = 0; i < 10; ++i)
    {
        printf("|%36c\n",'|');
        switch(i){
            case 0: printf("|%6s %-15s  %8s   |\n","1st",name[i],score[i]);break;
            case 1: printf("|%6s %-15s  %8s   |\n","2nd",name[i],score[i]);break;
            case 2: printf("|%6s %-15s  %8s   |\n","3rd",name[i],score[i]);break;
            default: printf("|%4d%s %-15s  %8s   |\n",i+1,"th",name[i],score[i]);
        }
    }
    fclose(fp);
}

int cmp(char sc1[],char sc2[]){
    int i;
    char *p1=sc1,*p2=sc2;
    if (strlen(sc1)>strlen(sc2)){
        return 1;
    }else if (strlen(sc1)<strlen(sc2)){
        return -1;
    }else if (strlen(sc1)==strlen(sc2)){
        for (i = 0; i < strlen(sc1); ++i,p1++,p2++)
        {
            if (*p1>*p2){
                return 1;
            }
            if (*p1<*p2){
                return -1;
            }
        }
    }
}


void map(int x,int y,int show[100*2+1][100*2+1])
{
    //walk(55,5);
    //printf("%d %d\n",x,y);

    //int show[100*2+1][100*2+1];
	int map[100][100][3]={0},way[4],hway;
	int i,j,r=0,c=0,e,ra,k,l,rax,ray,w=0,sr=1,sc=1;
	//map for show
	for(i=0;i<=y*2;i+=2){
		for(j=0;j<=x*2;j++){
			show[i][j]=1;
		}
	}
//*-------------L ---------------------
for(i=0;i<=y*2;i+=2){
		for(j=0;j<=x*2;j++){
			walk(j,i);textcolor(15,15);printf("#",show[i][j]);
		}
		printf("\n");
	}
resetcolor();
//*--------------------------------------

	for(i=0;i<=y*2;i++){
		for(j=0;j<=x*2;j+=2){
			show[i][j]=1;
		}
	}
//*-------------L ---------------------
walk(0,0);
for(i=0;i<=y*2;i++){
		for(j=0;j<=x*2;j+=2){
			walk(j,i);textcolor(15,15);printf("#",show[i][j]);
		}
		printf("\n");
	}
resetcolor();

//*--------------------------------------


	time_t t;
    srand((unsigned) time(&t));
    map[r][c][1]=1;
    map[r][c][2]=1;
    while(w<x*y+1){

    	for(i=0;i<4;i++)way[i]=0;
    	if(map[r-1][c][1]==0&&r>0)way[0]=1;//check top way
    	if(map[r][c-1][1]==0&&c>0)way[1]=1;//check left way
    	if(map[r][c+1][1]==0&&c<x-1)way[2]=1;//check right way
   		if(map[r+1][c][1]==0&&r<y-1)way[3]=1;//check down way
   		hway=0;
   		for(i=0;i<4;i++)if(way[i]==1)hway++;
   		//printf("Move %d: p %d %d hway %d ",w+1,r,c,hway);
   		if(hway!=0)ra=rand()%(hway);
   		//printf("rand %d have ", ra);
   		if(hway!=0){
   			for(i=0;ra>=0;){
   		   			if(way[i]==1){
   		   				ra--;
   		   				i++;
   		   			}else if(way[i]==0)i++;
   		   		}
   		   		ra=i-1;
   		   		//printf(" move %d \n", ra);

   		   		switch(ra){
   		   			case 0:{
   		   				map[r][c][0]=85;
   		   				map[r][c][1]=1;
   		   				show[r*2][c*2+1]=0;
//*-------------L ---------------------
			delay(10);walk(c*2+1,r*2);printf(" ",show[i][j]);
//*--------------------------------------
   		   				r--;
   		   				map[r][c][1]=1;
   		   				break;
   		   			}
   		   			case 1:{
   		   				map[r][c][0]=76;
   		   				map[r][c][1]=1;
   		   				show[r*2+1][c*2]=0;
//*-------------L ---------------------
			delay(10);walk(c*2,r*2+1);printf(" ",show[i][j]);
//*--------------------------------------
   		   				c--;
   		   				map[r][c][1]=1;
   		   				break;
   		   			}
   		   			case 2:{
   		   				map[r][c][0]=82;
   		   				map[r][c][1]=1;
   		   				show[r*2+1][c*2+2]=0;
//*-------------L ---------------------
			delay(10);walk(c*2+2,r*2+1);printf(" ",show[i][j]);
//*--------------------------------------
   		   				c++;
   		   				map[r][c][1]=1;
   		   				break;
   		   			}
   		   			case 3:{
   		   				map[r][c][0]=68;
   		   				map[r][c][1]=1;
   		   				show[r*2+2][c*2+1]=0;
//*-------------L ---------------------
			delay(10);walk(c*2+1,r*2+2);printf(" ",show[i][j]);
//*--------------------------------------
   		   				r++;
   		   				map[r][c][1]=1;
   		   				break;
   		   			}
   		   		}
   		}else{
   			//break;
   			w++;
   			map[r][c][2]=1;
   			for(i=0;i<x;i++){
   				for(j=0;j<x;j++){
   				if(map[i][j][1]==1&&map[i][j][2]==0){
   					r=i;
   					c=j;
   					break;
   					break;
   				}
   				}
   			}
   			//printf(" address %d %d\n",r,c);

   		}



	}
	e=0;
	while(e==0){
	ra=rand()%(y*2-1);
    if(show[(y*2-1)-ra][(x*2+1)-2]!=1){show[(y*2-1)-(ra)][(x*2+1)-1]=7;e++;}
    }
    //------------------ end map-----------------
	walk(0,0);
	for(i=0;i<=y*2;i++){
   		for(j=0;j<=x*2;j++){
   			if (show[i][j]==1)textcolor(15,15);
   			if (show[i][j]==0)textcolor(0,0);
   			if (show[i][j]==7)textcolor(5,5);
   			printf("%d",show[i][j]);
   		}
   		printf("\n");
   	}
   	resetcolor();



}//------------- end gen ----------


typedef struct
{
int pos;
int score;
int type;  //0= วางของที่ช่องเดิน 1=วางของที่กำแพง
int unit;
int color;
} item;

void rand_item(int show[100*2+1][100*2+1],int n,int m,int f_num){
item it[20];
switch(f_num){
//=== more case or edit ===================
case 0 :
    it[f_num].pos   =  2;
    //it[f_num].score =  500;
    it[f_num].type  =  0;
    it[f_num].unit  =  10;
    it[f_num].color =  10;
    break;

case 1 :
    it[f_num].pos   =  3;
    //it[f_num].score =  300;
    it[f_num].type  =  1;
    it[f_num].unit  =  5;
    it[f_num].color =  12;
    break;
}
//==========================================

    int i,j,e,k,rax,ray;
    int horizal=0,vertical=0;

switch(it[f_num].type){
    case 0 :

            for(i=0;i<it[f_num].unit;i++){
                do{
                    rax=rand()%(2*n);
                    ray=rand()%(2*m);
                    e=0;
                        if(show[ray][rax]==0){
                            for(j=ray-3;j<ray+3;j++){
                            for(k=rax-3;k<rax+3;k++){
                                if(show[j][k]==it[f_num].pos)e=1;
                                if(j==1&&k==1)e=1;
                            }
                            }
                //printf(" %d  %d  ",e,show[rax][ray]);
                        }

                    }while(e!=0||show[ray][rax]!=0);
        //printf("%d  %d",e,show[rax][ray]);
        //printf("    %d  %d\n",rax,ray);
                    show[ray][rax]=it[f_num].pos;
//--------------------L -----------------------
                    delay(50);walk(rax,ray);textcolor(it[f_num].color,0);printf("%c",15);
//---------------------------------------------
                }break;

    default :
    //random hamburger

            for(i=0;i<it[f_num].unit;i++){
                do{
                    rax=rand()%(2*(n-1))+1;
                    ray=rand()%(2*(m-1))+1;
                    e=0;horizal=0;vertical=0;
                    if(show[ray][rax]==1){
                        for(j=ray-3;j<ray+3;j++){
                        for(k=rax-3;k<rax+3;k++){
                        if(show[j][k]==it[f_num].pos)e=1;
                        }
                        }
                        if(show[ray-1][rax]==0)horizal++;
                        if(show[ray+1][rax]==0)horizal++;
                        if(show[ray][rax-1]==0)vertical++;
                        if(show[ray][rax+1]==0)vertical++;
                //printf("before e=%d  show[%d][%d]=%d  horizal=%d  vertical=%d\n",e,rax,ray,show[rax][ray],horizal,vertical);
                    }
                    }while((e!=0)||!(((show[ray][rax]==1)&&(vertical==2)||(horizal==2))&&(horizal+vertical!=3)));

        //printf("after e=%d  show[%d][%d]=%d  horizal=%d  vertical=%d\n\n",e,rax,ray,show[rax][ray],horizal,vertical);
                show[ray][rax]=it[f_num].pos;
//--------------------L -----------------------
                    delay(50);walk(rax,ray);textcolor(it[f_num].color,0);printf("%c",5);
//---------------------------------------------
            }
}//end gen
}///---------------end item------------

void rand_mons(int show[100*2+1][100*2+1],int n,int m,int unit,int*pos){
    int i,j,k,rax,ray,e;
    for(i=0;i<unit;i++){
                do{
                    rax=rand()%(2*n);
                    ray=rand()%(2*m);
                    e=0;
                        if(show[ray][rax]==0){
                            for(j=ray-3;j<ray+3;j++){
                            for(k=rax-3;k<rax+3;k++){
                                if(show[j][k]==5)e=1;
                                if(j==1&&k==1)e=1;
                            }
                            }
                        }

                    }while(e!=0||show[ray][rax]!=0);
                    *pos=ray;
                    *(pos+1)=rax;
                    pos+=2;
                    show[ray][rax]=5;//it[f_num].pos;
//--------------------L -----------------------
                    delay(50);walk(rax,ray);textcolor(9,0);printf("%c",002);
    }
}
void run(int show[100*2+1][100*2+1],int n,int m,int *score,int*mon_pos){
    item it[20];
    int i,j,end,s=0;
    int d,my,mx,*p,e=0,count=0;

    //show[(n*2-1)][(n*2+1)-1]=7;
	//ra=rand()%9 +7;

   	//walk((n*2+1)-1,(n*2+1)-2);textcolor(5,6);printf(" ");
   	//มุมล่าง (n*2+1)-2,(n*2+1)-2

    int x=1,y=1;
                char control;
                for(end=0;end==0;){
                        walk(x,y);
                        //	• O
                        printf("%c",2);
                            if(kbhit()){
                                control = getch();
                                if(control==75&&show[y][x-1]!=1){x--;walk(x+1,y);printf(" ");}
                                if(control==77&&show[y][x+1]!=1){x++;walk(x-1,y);printf(" ");}
                                if(control==80&&show[y+1][x]!=1){y++;walk(x,y-1);printf(" ");}
                                if(control==72&&show[y-1][x]!=1){y--;walk(x,y+1);printf(" ");}
                                if(show[y][x]==7){system("cls");end++;}
                                if(show[y][x]==2){show[y][x]=0;
                                                  *score+=500;
                                                  walk(50,5);textcolor(12,0);printf("SCORE   %d   ",*score);
                                                  resetcolor();}
                                if(show[y][x]==3){show[y][x]=0;
                                                  *score-=300;
                                                  walk(50,5);textcolor(12,0);printf("SCORE   %d   ",*score);
                                                  resetcolor();}
                            }
                            //monster movement

                            p=mon_pos;
                            if(count==5000){
                            for(i=0;i<2;i++,p+=2){
                                //delay(100);
                                my=*p;
                                mx=*(p+1);
                                walk(mx,my);
                                textcolor(9,0);printf("%c",002);resetcolor();
                                e=0;
                                do{
                                    d=rand()%4;

                                    if(d==0&&show[my][mx-1]==0){mx--;walk(mx+1,my);printf(" ");}
                                    if(d==1&&show[my][mx+1]==0){mx++;walk(mx-1,my);printf(" ");}
                                    if(d==2&&show[my+1][mx]==0){my++;walk(mx,my-1);printf(" ");}
                                    if(d==3&&show[my-1][mx]==0){my--;walk(mx,my+1);printf(" ");}
                                    *p=my;
                                    *(p+1)=mx;
                                }while(e==1);
                            }
                            count=0;
                            }
                            count++;


                }
}
///-----------end run-----------
//add new line
