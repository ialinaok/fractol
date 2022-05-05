#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define WIDTH 60
#define HEIGHT 20
#define X WIDTH/2
#define Y HEIGHT/2
#define XMAX WIDTH-X-1
#define XMIN -(WIDTH-X)
#define YMAX HEIGHT-Y
#define YMIN -(HEIGHT-Y)+1

char grid[HEIGHT][WIDTH];

int circle(int x, int y, int radius);
int plot(int x, int y);
void init_grid(void);
void show_grid(void);

int main()
{
    init_grid();
    circle(0,0,8);
    show_grid();

    return(0);
}

/* Plot a circle */
int circle(int x, int y, int radius)
{
    float xpos,ypos,radsqr,xsqr;

    for(xpos=x-radius;xpos<=x+radius;xpos+=0.1)
    {
        radsqr = pow(radius,2);
        xsqr = pow(xpos,2);
        ypos = sqrt(fabsf(radsqr - xsqr));
        plot(rintf(xpos),rintf(ypos));
        plot(rintf(xpos),rintf(-ypos));
    }

    return(1);
}

/* Set "pixel" at specific coordinates */
int plot(int x, int y)
{
    if( x > XMAX || x < XMIN || y > YMAX || y < YMIN )
        return(-1);

    grid[Y-y][X+x] = '*';
    return(1);
}

/* Initialize grid */
void init_grid(void)
{
    int x,y;

    for(y=0;y<HEIGHT;y++)
        for(x=0;x<WIDTH;x++)
            grid[y][x] = ' ';
    /* draw the axis */
    for(y=0;y<HEIGHT;y++)
        grid[y][X] = '|';
    for(x=0;x<WIDTH;x++)
        grid[Y][x] = '-';
    grid[Y][X] = '+';
}

/* display grid */
void show_grid(void)
{
    int x,y;

    for(y=0;y<HEIGHT;y++)
    {
        for(x=0;x<WIDTH;x++)
            putchar(grid[y][x]);
        putchar('\n');
    }
}