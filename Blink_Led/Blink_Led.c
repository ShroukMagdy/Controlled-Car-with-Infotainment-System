#include <wiringPi.h>
#include <stdio.h>

/* GPIO4 as per wiringPi, GPIO23 as per BCM, pin no.4 */
int led_no=4;

int main(){
printf("\nhiiiiiii");
//initialize wiringpi setup
wiringPiSetup();
pinMode(led_no,OUTPUT);

while(1){
digitalWrite(led_no,HIGH);
delay(1000);
digitalWrite(led_no,LOW);
delay(1000);
}

//printf("ls");
return 0;
}
