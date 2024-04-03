#include <graphics.h>
#include <conio.h>
#include<string.h>
#include<math.h>
#define scalediv 10
#define pixeldiv 20
#define len 4
#define xmax 625   // Last pixel distance from center in x-axis
#define ymax 325   // Last pixel distance from center in Y-axis

int xc = getmaxwidth() / 2, yc = getmaxheight() / 2;
static int x1,x2,x3,Y1,y2,y3;
int shape;
int a=x1, c=x2, e=x3, b= Y1, d=y2, f=y3;

int g_in(int x_coordinate, int y_coordinate)
{
    static char data[len];
    memset(data,0,sizeof(data));
    int i = 0;
    while ((data[i] = getch()) != '\r')
    {
        if(i>=len)
        {
            outtextxy(x_coordinate,y_coordinate+20,"Char Array Limit Reached");
        }
        if (( isdigit(data[i])||data[i]=='-'||data[i]=='+')&&i<len)
        {
            outtextxy(x_coordinate, y_coordinate, data);
            i++;
        }
        else if (data[i]== '\b'&&i>0)
        {
            i--;
            data[i]='\0';
            outtextxy(x_coordinate,y_coordinate+20,"                                          ");
            strcat(data,"    ");
            outtextxy(x_coordinate, y_coordinate, data);
        }
        else
        {
            while (kbhit())
            {
                getch();
            }
        }
    }
    if(i>=1)
    {
        int num=std::stoi(data);
        return num;
    }
    else
        g_in(xc,yc);
}

void user_interface(int x, int y)
{
    settextstyle(8,0,1);
    setcolor(2);
    outtextxy(5,5,"[1] TRANSLATION");
    outtextxy(getmaxwidth()/2-70,5,"[2] SCALING");
    outtextxy(getmaxwidth()-150,5,"[3] ROTATION ");
    line(0,25,getmaxwidth(),25);
    line(0,getmaxheight()-30,getmaxwidth(),getmaxheight()-30);
    outtextxy(getmaxwidth()/2-70,getmaxheight()-25,"[4] SET OBJECT");
    outtextxy(10,getmaxheight()-25,"[0] CLEAR");
    outtextxy(getmaxwidth()-150,getmaxheight()-25," (X) EXIT [5]");
}

void plot_points(int ax, int ay, int bx, int by, char a[], char b[])
{
    int x1=ax*pixeldiv, Y1=ay*pixeldiv, x2=bx*pixeldiv, y2=by*pixeldiv;
    line(xc+x1,yc-Y1,xc+x2,yc-y2);
    outtextxy(xc+x1,yc-Y1,a);
    outtextxy(xc+x2,yc-y2,b);
}

void translation( int winmain)
{
    int window=initwindow(300,300,"Translation");
    int Tx,Ty;
    outtextxy(10,10,"Enter the Translation factor: ");
    Tx=g_in(30,25);
    Ty=g_in(50,25);
    a=x1+Tx;
    b=Y1+Ty;
    c=x2+Tx;
    d=y2+Ty;
    e=x3+Tx;
    f=y3+Ty;
    closegraph(window);
    setcurrentwindow(winmain);
//    plot_points(x1+Tx,Y1+Ty,x2+Tx,y2+Ty,"Ta","Tb");
}

void scaling( int winmain)
{
    int window=initwindow(300,300,"SCALING");
    int Sx,Sy;
    outtextxy(10,10,"Enter the Scaling factor: ");
    Sx=g_in(30,25);
    Sy=g_in(50,25);
    a=x1*Sx;
    b=Y1*Sy;
    c=x2*Sx;
    d=y2*Sy;
    e=x3*Sx;
    f=y3*Sy;
    closegraph(window);
    setcurrentwindow(winmain);
//    plot_points(x1*Sx,Y1*Sy,x2*Sx,y2*Sy,"Sa","Sb");
}

void rotation( int winmain)
{
    int window=initwindow(300,300,"ROTATION");
    float angle;
    outtextxy(10,10,"Enter the angle of rotation: ");
    cleardevice();
    angle=g_in(25,25);
    angle = (angle * 3.14) / 180;
    int A, B, C, D,E,F;
    A = xc + x1 * cos(angle) - Y1 * sin(angle);
    B = yc + x1 * sin(angle) + Y1 * cos(angle);
    C = xc + x2 * cos(angle) - y2 * sin(angle);
    D = yc + x2 * sin(angle) + y2 * cos(angle);
    E = xc + x3 * cos(angle) - y3 * sin(angle);
    F = yc + x3 * sin(angle) + y3 * cos(angle);
//    line(xc + x1, yc + Y1, xc + x2, yc + y2);
    a = A - xc;
    b = B - yc;
    c = C - xc;
    d = D - yc;
    e = E - xc;
    f = F - yc;
    closegraph(window);
    setcurrentwindow(winmain);
}

void plot_transformation()
{
    if(shape==1)
    {
        plot_points(a,b,c,d,"A","B");
    }
    if(shape==2)
    {
        plot_points(a,b,c,d,"A","B");
        plot_points(a,b,e,f,"A","C");
        plot_points(c,d,e,f,"B","C");
    }
    if(shape==3)
    {
        plot_points(a,b,a,d,"A","C");
        plot_points(a,d,c,d,"C","D");
        plot_points(c,d,c,b,"D","B");
        plot_points(c,b,a,b,"B","A");
    }
}

void set_object(int winMain)
{
    int window=initwindow(300,300,"SET OBJECT");
loop:
    outtextxy(10,10,"[1] Line");
    outtextxy(10,30,"[2] Triangle");
    outtextxy(10,50,"[3] Rectangle");
    outtextxy(10,70,"[4] Leave It !!");
    char a=getch();
    cleardevice();
    int choice= a-'0';
    switch (choice)
    {
    case 1:
    {
//        int x1,x2,Y1,y2;
        outtextxy(10,10,"Enter two points (x1,Y1) and (x2,y2)");
        x1=g_in(20,30);
        Y1=g_in (50,30);
        x2=g_in(20,50);
        y2=g_in(50,50);
        shape=1;
        closegraph(window);
        setcurrentwindow(winMain);
        plot_points(x1,Y1,x2,y2,"A","B");
        break;
    }

    case 2:
    {
//        int x1,x2,Y1,y2,x3,y3;
        outtextxy(10,10,"Enter two diagonal points (x1,Y1) and (x2,y2) and (x3,y3)");
        x1=g_in(20,30);
        Y1=g_in (50,30);
        x2=g_in(20,50);
        y2=g_in(50,50);
        x3=g_in(20,70);
        y3=g_in(50,70);
        shape=2;
        closegraph(window);
        setcurrentwindow(winMain);
        plot_points(x1,Y1,x2,y2,"A","B");
        plot_points(x1,Y1,x3,y3,"A","C");
        plot_points(x2,y2,x3,y3,"B","C");
        break;
    }

    case 3:
    {
//        int x1,x2,Y1,y2;
        outtextxy(10,10,"Enter two diagonal points (x1,Y1) and (x2,y2)");
        x1=g_in(20,30);
        Y1=g_in (50,30);
        x2=g_in(20,50);
        y2=g_in(50,50);
        shape=3;
        closegraph(window);
        setcurrentwindow(winMain);
        plot_points(x1,Y1,x1,y2,"A","C");
        plot_points(x1,y2,x2,y2,"C","D");
        plot_points(x2,y2,x2,Y1,"D","B");
        plot_points(x2,Y1,x1,Y1,"B","A");
        break;
    }

    case 4:
    {
        closegraph(window);
        setcurrentwindow(winMain);
        break;
    }
    default:
    {
        goto loop;
    }
    }
}

int main()
{
    int main_window = initwindow(getmaxwidth(), getmaxheight(), "2D TRANSFORMATIONS");
//    int x1,x2,Y1,y2;
//    plot_points(x1,Y1,x2,y2,"A","B");   //reference line to observe transformation    user_interface(xc,yc);
TOP:
    user_interface(xc,yc);
    int p_xpoint=xc+pixeldiv, n_xpoint=xc-pixeldiv;  //X-axis: y constant
    int p_ypoint=yc-pixeldiv, n_ypoint=yc+pixeldiv;  //y-axis: x constant

    for(int i=0; (p_ypoint<=ymax+yc)&&(p_xpoint<=xmax+xc); i++)
    {
        int color = RGB(40,40,40);
        setcolor(color);
        setlinestyle(DOTTED_LINE,0,0);
        if(n_ypoint<=ymax+yc)
        {
            line(xc-xmax,p_ypoint,xc+xmax,p_ypoint);    //Dotted line in positive Y axis parallel to x axis
            line(xc-xmax,n_ypoint,xc+xmax,n_ypoint);    //Dotted line in negative Y axis parallel to x axis
            p_ypoint-=pixeldiv;
            n_ypoint+=pixeldiv;
        }
        if(p_xpoint<=xmax+xc)
        {
            line(p_xpoint,yc-ymax,p_xpoint,yc+ymax);    //Dotted line in positive X axis parallel to Y axis
            line(n_xpoint,yc-ymax,n_xpoint,yc+ymax);    //Dotted line in negative X axis parallel to Y axis
            p_xpoint+=pixeldiv;
            n_xpoint-=pixeldiv;
        }
    }
    int color = RGB(150, 150, 150);
    setcolor(color);
    setlinestyle(0,0,2);
    line(xc,yc-ymax,xc,yc+ymax);    //axis line
    line(xc-xmax,yc,xc+xmax,yc);    //axis line
loop:
    //Choice and switch case for transformations
    char a=getch();
    int choice= a-'0';
    switch(choice)
    {
    case 1:
    {
        setcolor(RED);
        translation(main_window);
        plot_transformation();
        goto loop;
    }
    case 2:
    {
        setcolor(BLUE);
        scaling(main_window);
        plot_transformation();
        goto loop;
    }
    case 3:
    {
        setcolor(YELLOW);
        rotation(main_window);
        plot_transformation();
        goto loop;
    }
    case 4:
    {
        set_object(main_window);
        goto loop;
    }
    case 5:
    {
        exit(0);
    }
    case 0:
    {
        x1=0,x2=0,x3=0,Y1=0,y2=0,y3=0,shape=0;
        cleardevice();
        goto TOP;
    }
    default:
    {
        goto loop;
    }
    }
}
