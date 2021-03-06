#ifndef COLOR_H
#define COLOR_H

#include <iostream>
using namespace std;

//16色位图：
//黑色　　0     00 00 00   00
//深红　　1     00 00 80   00
//深绿　　2     00 80 00   00
//深黄　　3     00 80 80   00
//深蓝　　4     80 00 00   00
//深紫　　5     80 00 80   00
//深青　　6     80 80 00   00
//深灰　　7     80 80 80   00
//浅灰    8     C0 C0 C0   00
//红色　　9     00 00 FF   00
//绿色　　A　　 00 FF 00   00
//黄色　　B　　 00 FF FF   00
//蓝色　　C　　 FF 00 00   00
//紫色　　D　　 FF 00 FF   00
//青色　　E　　 FF FF 00   00
//白色　　F　　 FF FF FF   00

#define COLOR_BLACK (0x00000000)
#define COLOR_HALF_RED (0x00008000)
#define COLOR_HALF_GREEN (0x00800000)
#define COLOR_HALF_YELLOW (0x00808000)
#define COLOR_HALF_BLUE (0x80000000)
#define COLOR_HALF_VIOLET (0x80008000)
#define COLOR_HALF_CYAN (0x80800000)
#define COLOR_DARK_GREY (0x80808000)
#define COLOR_LIGHT_GREY (0xc0c0c000)
#define COLOR_RED (0x0000ff00)
#define COLOR_GREEN (0x00ff0000)
#define COLOR_YELLOW (0x00ffff00)
#define COLOR_BLUE (0xff000000)
#define COLOR_VIOLET (0xff00ff00)
#define COLOR_CYAN (0xffff0000)
#define COLOR_WHITE (0xffffff00)

#define Bi (3) 
#define Gi (2)
#define Ri (1)
#define Ai (0)

union color_u
{
	unsigned char uc[4];
	unsigned long ulg;
};

class colorpad_1
{
public:
	colorpad_1();
	~colorpad_1();
	union color_u getcolor(unsigned char num);
	union color_u filter(unsigned char b1,unsigned char g1,unsigned char r1);
	union color_u filter(union color_u u1);
	int getnum(unsigned char b1,unsigned char g1,unsigned char r1);
	int getnum(union color_u u1);
	int printlist();
	union color_u ColorList[2];	
};

class colorpad_4
{
public:
	colorpad_4();
	~colorpad_4();
	union color_u getcolor(unsigned char num);
	union color_u filter(unsigned char b1,unsigned char g1,unsigned char r1);
	union color_u filter(union color_u u1);
	int getnum(unsigned char b1,unsigned char g1,unsigned char r1);
	int getnum(union color_u u1);
	int printlist();
	union color_u ColorList[16];	
};

class colorpad_8
{
public:
	colorpad_8();
	~colorpad_8();
	union color_u getcolor(unsigned char num);
	virtual union color_u filter(unsigned char b1,unsigned char g1,unsigned char r1);
	virtual union color_u filter(union color_u u1);
	int getnum(unsigned char b1,unsigned char g1,unsigned char r1);
	int getnum(union color_u u1);
	int printlist();
	bool testBLend();
	union color_u ColorList[256];	
};

class colorpad_8G:public colorpad_8
{
public:
	colorpad_8G();
	~colorpad_8G();
	union color_u filter(unsigned char b1,unsigned char g1,unsigned char r1);
	union color_u filter(union color_u u1);
};

#endif
