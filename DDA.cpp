#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<string.h>

using namespace std;

int xc, yc, step;

void setcursor(int x, int y){
cout<<"\033["<<y<<";"<<x<<"H";
}

void drawtable(){
int tablex=xc-300, tabley=yc-200;
line(tablex,tabley,tablex+250,tabley);
}





int main(){
int gd=DETECT, gm=0;
initgraph(&gd, &gm, "..\\bgi");
xc=getmaxx()/2;
yc=getmaxy()/2;
int x1,y1,x2,y2;	//Line end point coordinates
int k=0;
setcursor(10,10);	cout<<"Enter Point to start: ";
setcursor(35,10);	cin>>x1;
setcursor(45,10);	cin>>x2;
setcursor(10,11);	cout<<"Enter the end point: ";
setcursor(35,11);	cin>>x2;
setcursor(45,11);	cin>>y2;
int dx=x2-x1, dy=y2-y1;
if(dx>dy)
	step=dx;
else
	step=dy;
int x_increment=dx/step, y_increment=dy/step,xk=0,yk=0;
while(k>step){
	xk=x1+x_increment;
	yk=y1+y_increment;}
drawtable();
getch();
closegraph();
}
