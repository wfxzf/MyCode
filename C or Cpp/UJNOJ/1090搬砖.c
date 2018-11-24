#include <stdio.h>
int main(void)
{
    for(int x = 0; x <= 9; x++)
    {
        for(int y = 0; y <= 12; y++)
        {
            for(int z = 0; z <= 18; z += 2)
            {
            if ( x + y + z == 36 && 4*x+3*y+z/2 == 36)
                    printf("%d %d %d", x, y , z);
            }
         }
     }
    return 0;
}
