#include <stdio.h>
#include <math.h>

const int width = 800;
const int height = 600;

short int p[800][600];
short int debug = 0;

void fill(short int rgb);
void rect_filled(short int rgb, int x1, int y1, int x2, int y2);
void rect_outline(short int rgb, int x1, int y1, int x2, int y2, int thick);
void rect(short int rgb, int x1, int y1, int x2, int y2);
void circle(short int rgb, int x, int y, int r);
void circle_outline(short int rgb, int x, int y, int r, int thick);
int inside(int x, int y);
void out();
short int rgbint(short int r, short int g, short int b);

int main()
{
	fill(rgbint(180, 0, 0));
	/* Filled rectangle */
	rect_filled(rgbint(30, 50, 70), 50, 50, 100, 100);
	/* Rectangle w/ variable border width */
	rect_outline(rgbint(0, 180, 0), 125, 50, 250, 200, 5);
	/* Rectangle w/ 1px border width */
	rect(rgbint(220, 255, 50), 50, 250, 100, 350);
	/* Circle, 1px */
	circle(rgbint(0, 150, 0), 400, 300, 200);
	/* Circle w/ variable border widht */
	circle_outline(rgbint(0, 250, 100), 400, 300, 100, 5);

	/* Objects are out of border */
	circle(rgbint(100, 200, 100), width + 10, height + 10, 200);
	circle(rgbint(100, 200, 100), -10, height + 10, 200);
	circle(rgbint(100, 200, 100), width + 10, -10, 200);
	circle(rgbint(100, 200, 100), -10, -10, 200);

	rect_outline(rgbint(100, 200, 100), -50, -50, 50, 50, 2);	
	rect_outline(rgbint(100, 200, 100), -50, height-50, 50, height+50, 2);	
	rect_outline(rgbint(100, 200, 100), width-50, -50, width+50, 50, 2);	
	rect_outline(rgbint(100, 200, 100), width-50, height-50, width+50, height+50, 2);	

	if (!debug) out();	
	return 0;
}

void out()
{
	printf("P3\n");
	printf("800 600\n");
	printf("255\n");
	int w, h;
	for(h = 0; h < height; h++) {
		for(w = 0; w < width; w++) {
			printf("%d %d %d\n", p[w][h] & 255, p[w][h]>>8 & 255, p[w][h]>>16 & 255);
		}
	}
}

void fill(short int rgb)
{
	int w, h;
	for(w = 0; w < width; w++) {
		for(h = 0; h < height; h++) {
			p[w][h] = rgb;
		}
	}
}

void circle(short int rgb, int x, int y, int r)
{
	int xr, yr;
	float i;
	for(i = 0; i < 360 * 2; i += 0.1) {
		xr = x + r * cos(i);
		yr = y + r * sin(i);
		if (!inside(xr, yr)) continue;
		if (debug) printf("%d x %d\n", xr, yr);
		p[xr][yr] = rgb;
	}
}

void circle_outline(short int rgb, int x, int y, int r, int thick)
{
        int i;
        for(i = thick; i > 0; i--) {
                circle(rgb, x, y, r--);
        }
}

void rect_filled(short int rgb, int x1, int y1, int x2, int y2)
{
	int w, h;
	if(debug) printf("Drawing rect from %d/%d to %d/%d\n", x1, y1, x2, y2);
	for(h = y1; h < y2; h++) {
		for(w = x1; w < x2; w++) {
			if (!inside(w, h)) continue;
			p[w][h] = rgb;
		}
	}
}

void rect(short int rgb, int x1, int y1, int x2, int y2)
{
	int w, h;
	if(debug) printf("Drawing rect from %d/%d to %d/%d\n", x1, y1, x2, y2);
	/* Hor lines */
	for(h = y1; h < y2; h++) {
		if (inside(x1, h)) p[x1][h] = rgb;
		if (inside(x2, h)) p[x2][h] = rgb;
	}
	/* Ver lines */
	for(w = x1; w < x2; w++) {
		if(inside(w, y1)) p[w][y1] = rgb;
		if(inside(w, y2)) p[w][y2] = rgb;
	}

}

void rect_outline(short int rgb, int x1, int y1, int x2, int y2, int thick)
{
	int i;
	for(i = thick; i > 0; i--) {
		rect(rgb, x1++, y1++, x2--, y2--);
	}
}

int inside(int x, int y)
{
	return x > 0 && x < width && y > 0 && y < height;
}

/*
short int t = (100 | 200<<8 | 240<<16);
printf("%d\n", t & 255 );
printf("%d\n", t>>8 & 255 );
printf("%d\n", t>>16 & 255 );
*/
short int rgbint(short int r, short int g, short int b)
{
	return r | g<<8 | b<<16;
}
