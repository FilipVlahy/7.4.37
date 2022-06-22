#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define PM_SIZE 1
#define PM_OK 0
#define PM_STAB 2

char prehrnutie_minci(unsigned int *a,unsigned int *b,unsigned int len)
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
                    return PM_SIZE;
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
                    return PM_SIZE;
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
        return PM_STAB;
    }
    else
    {
        return PM_OK;
    }
}

void print_array(unsigned int *a, unsigned int len)
{
    unsigned int i;

    for(i=0; i<len; i++)
        printf(" %d ",a[i]);
    printf("\n");
}

void main()
{
    unsigned int Pole[4]={0,2,0,0};
    unsigned int newPole[4]={0,0,0,0};

    unsigned int *a=Pole;
    unsigned int *b=newPole;

    printf("%d\n",prehrnutie_minci(a,b,4));

    print_array(a,4);
    print_array(b,4);
}
