#ifndef BMP8G_H
#define BMP8G_H

#include "bmpinfo.h"
#include "color.h"
#include "bmp32.h"

class bmp8G : public bmpinfo,public colorpad_8G
{
public:
    bmp8G();
    bmp8G(unsigned long w,unsigned long h);
    bmp8G(const bmp8G& pmb);
    bmp8G& operator=(const bmp8G& pmb);
    bmp8G& operator=(const class bmp32& pmb);
    ~bmp8G();
    int readfromfile(const char* filename);
    int write2file(const char* filename);
public:
    unsigned char* dataptr;
};


#endif // BMP8_H

