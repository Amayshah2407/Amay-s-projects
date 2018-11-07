//
//  main.c
//  prime numbers using self made functions
//
//  Created by Amay shah  on 03/07/18.
//  Copyright © 2018 Amay shah . All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int x,y;
    printf("enter a number");
    scanf("%d",&x);
    
    if (x<=1)
    {
        printf("not a prime number");
    }
    else
    {
    for (y=2;y<x;y++)
    {
        if (x%y==0)
        {
            printf("not a prime number");
        }
        else
        {
            printf("it is a prime number\n");
        }
        
    }}
    
    return 0;
}
