#include <stdio.h>

int main()
{
   char C;
   int D;

   scanf("%c %d", &C, &D);

   if('a' <= C && C <= 'z')
   {
       C -= 32;
       if(D >= 0)
       {
            if(C-D < 'A')
            {
                C += 26; 
            }
            C = C-D;
            printf("%c\n", C); 
       }
       else
       {
           if(C-D > 'Z')
           {
               C -= 26;
           }
           C = C-D;
           printf("%c\n", C);
       }
       return 0;
   }
   if('A' <= C && C <= 'Z')
   {
       C += 32;
       if(D >= 0)
       {
            if(C-D < 'a')
            {
                C += 26; 
            }
            C = C-D;
            printf("%c\n", C); 
       }
       else
       {
           if(C-D > 'z')
           {
               C -= 26;
           }
           C = C-D;
           printf("%c\n", C);
       }
       return 0;
   }
}