#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

char* prehrnutie_minci(unsigned int *a,unsigned int *b,unsigned int len)
{
    int i;

    for(i=0;i<len;i++)
    {
        if (a[i]%2!=0)
        {
            if (i-1 < 0 || i+1 > len-1)
            {
                if((a[i]-1)/2!=0)
                {
                    return "PM_SIZE";
                    break;
                }
                else
                {
                    b[i]=b[i]+1;
                }
            }
            else
            {
                b[i-1]=b[i]+(a[i]-1)/2;
                b[i+1]=b[i]+(a[i]-1)/2;
                b[i]=b[i]+1;                
            }
        }
        else
        {
            if (i-1 < 0 || i+1 > len-1)
            {
                if((a[i])/2!=0)
                {
                    return "PM_SIZE";
                    break;
                }
            }
            else
            {
                b[i]=b[i]+a[i]/2;
                b[i]=b[i]+a[i]/2;               
            }
        }
    }

    bool same = true;
    for (i=0;i<len;i++)
    {
        if(a[i] != b[i])
        {
            same = false;
            break;
        }
    }

    if (same)
    {
        return "PM_STAB";
    }
    else
    {
        return "PM_OK";
    }
}

void main()
{
    unsigned int Pole[4]={0,4,3,0};
    unsigned int newPole[4]={0,0,0,0};

    unsigned int *a=Pole;
    unsigned int *b=newPole;

    printf("%s\n",prehrnutie_minci(a,b,4));
}