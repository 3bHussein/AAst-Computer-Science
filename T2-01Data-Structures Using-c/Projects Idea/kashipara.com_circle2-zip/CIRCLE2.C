#include<graphics.h>
#include<conio.h>
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
while(!kbhit())
{
setcolor(rand()%16);
setlinestyle(1,0,3);
circle(rand()%600,rand()%600,rand()%16);
delay(300);
}
getch();
closegraph();
}