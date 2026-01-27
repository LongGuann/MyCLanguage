#include <stdio.h>

union un
{ int i;
char c[2];
};
int main( )
{ union un x;
x.c[0]=10;
x.c[1]=1;
printf("\n%d",x.i);
return 0;
}
