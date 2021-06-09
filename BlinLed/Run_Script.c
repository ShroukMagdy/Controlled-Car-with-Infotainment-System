#include <stdio.h>
#include <stdlib.h>

#define SHELLSCRIPT "\
#! /bin/bash \n\
cd /sys/class/gpio \n\
echo 23 > export \n\
cd gpio23 \n\
sleep 1 \n\
echo out > direction \n\
echo 1 > value \n\
"

int main(){
puts("execute the script");
//puts(SHELLSCRIPT);
puts("starting now");
system(SHELLSCRIPT);

return 0;
}
