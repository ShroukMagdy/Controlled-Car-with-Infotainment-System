#include "mainwindow.h"
#include <QApplication>
#include <stdio.h>
#include <stdlib.h>
#include "readfile.h"

char Encoder_u8Val(void){ // encoder value function implementation
  char Result;
    FILE *fpointer;
    char Sline[3];
    fpointer=fopen("/home/pi/SPI/speed.txt","r");
    // hoss.txt is the name of the file that u should read u can change it's name & it's path
    fgets(Sline,3,fpointer);
    Sline[0]-=48;
    Sline[1]-=48;
    Result =Sline[0]*10 + Sline[1];
    //printf("\n %d \n",Result);// printf for testing only
    fclose(fpointer);
    return Result;
}
