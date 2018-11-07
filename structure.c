//
//  main.c
//  structure
//
//  Created by Amay shah  on 30/06/18.
//  Copyright © 2018 Amay shah . All rights reserved.
//

#include <stdio.h>
struct student
{
int r;
char nm[10];
float m1,m2,avg;
};
int main(int argc, const char * argv[]) {
    struct student s1,s2,s3;
    printf("enter roll no:");
    scanf("%d",&s1.r);
    
    printf("enter name:");
    scanf("%s",&s1.nm);
    
    printf("enter marks of 2 subjects");
    scanf("%f%f",&s1.m1,&s1.m2);
    
    s1.avg=(s1.m1+s1.m2)/2;
    printf("avg is %f",s1.avg);
    
    printf("enter roll no:");
    scanf("%d",&s2.r);
    
    printf("enter name:");
    scanf("%s",&s2.nm);
    
    printf("enter marks of 2 subjects");
    scanf("%f%f\n",&s2.m1,&s2.m2);
    
    s1.avg=(s2.m1+s2.m2)/2;
    printf("avg is %f",s2.avg);
    
    printf("enter roll no:");
    scanf("%d",&s3.r);
    
    printf("enter name:");
    scanf("%s",&s3.nm);
    
    printf("enter marks of 2 subjects");
    scanf("%f%f",&s3.m1,&s3.m2);
    
    s1.avg=(s3.m1+s3.m2)/2;
    printf("avg is %f",s3.avg);


    return 0;
}
