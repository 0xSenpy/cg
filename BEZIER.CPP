#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void drawaxis()
{
	int maxx=getmaxx();
	int maxy=getmaxy();
	int maxx2=maxx/2;
	int maxy2=maxy/2;
	line(maxx2,0,maxx2,maxy);
	line(0,maxy2,maxx,maxy2);
}

void plotpixel(int x, int y)
{
	putpixel(x+getmaxx()/2, (getmaxy()/2)-y, RED);
}
void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	drawaxis();
	int x[4],y[4],px,py,i;
	cout<<"Enter four control points of bezier curve: ";
	for(i=0;i<4;i++)
		cin>>x[i]>>y[i];
	double t;
	for(t=0.0;t<=1.0;t+=0.001)
	{
		px=(1-t)*(1-t)*(1-t)*x[0]+3*t*(1-t)*(1-t)*x[1]+3*t*t*(1-t)*x[2]+t*t*t*x[3];
		py=(1-t)*(1-t)*(1-t)*y[0]+3*t*(1-t)*(1-t)*y[1]+3*t*t*(1-t)*y[2]+t*t*t*y[3];
		plotpixel(px,py);

	}
	getch();
	closegraph();
}