/***************************************************
//Web: http://www.buydisplay.com
EastRising Technology Co.,LTD
Examples for ER-TFTM1.14-1
Display is Hardward SPI 4-Wire SPI Interface 
Tested and worked with: 
Works with Raspberry pi
****************************************************/

#include <bcm2835.h>
#include <stdio.h>
#include <time.h>
#include "st7789.h"

char value[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int main(int argc, char **argv)
{
    time_t now;
    struct tm *timenow;
 

    if(!bcm2835_init())
    {
        return -1;
    }


  
    st7789_begin();
  st7789_clear_screen(0) ;

    st7789_mono_bitmap(3, 57, mono_bmp, 128, 128, GREEN);
    st7789_display();
    bcm2835_delay(2000);


   st7789_bitmap16(0, 0, pic1, 135, 240);
   st7789_display();
    bcm2835_delay(2000);

  st7789_bitmap16(0, 0, pic2, 135, 240);
   st7789_display();
    bcm2835_delay(2000);

  st7789_bitmap16(0, 0, pic3, 135, 240);
   st7789_display();
    bcm2835_delay(2000);

  st7789_bitmap16(0, 0, pic4, 135, 240);
   st7789_display();
    bcm2835_delay(2000);

  st7789_bitmap16(0, 0, pic5, 135, 240);
   st7789_display();
    bcm2835_delay(2000);

  st7789_bitmap16(0, 0, pic6, 135, 240);
   st7789_display();
    bcm2835_delay(2000);


    st7789_clear();
    printf("TFT example. Press Ctrl + C to exit.\n");

    uint16_t i=100;
    while(1)
    {
        time(&now);
        timenow = localtime(&now);   

     
     	st7789_string(30, 10, "EastRising", 16, 1, CYAN);  
   	     
       st7789_string(15, 88, "hour", 16, 0, RED); 
       st7789_char3216(64, 80, ':' , WHITE);

        st7789_char3216(90, 80, value[timenow->tm_hour / 10],RED);
        st7789_char3216(120, 80, value[timenow->tm_hour % 10],RED);
  
        st7789_char3216(0, 120, value[timenow->tm_min / 10], GREEN);
        st7789_char3216(30, 120, value[timenow->tm_min % 10], GREEN);
        st7789_char3216(64, 120, ':' , WHITE);
        st7789_char3216(90, 120, value[timenow->tm_sec / 10],  BLUE);
        st7789_char3216(120, 120, value[timenow->tm_sec % 10],  BLUE);

        st7789_string(12, 200, "buydisplay.com", 16, 1, i); 
	i+=1000; if(i>=65536)i=1000;
    
        st7789_display();
      
    }
    bcm2835_spi_end();
    bcm2835_close();
    return 0;
}

