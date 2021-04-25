//
//  main.c
//  Laddu
//
//  Created by Vishal Jha on 29/10/20.
//

#include <stdio.h>
#include <string.h>
int main()
{
    int t,i,bug,rank,a,month=0;
     int laddu=0;
    char s[100],origin[100];
    scanf("%d",&t);
    while(t--)
    {
        month=0;
        laddu=0;
        scanf("%d %s",&a,&origin);
        while(a--)
        {
            scanf("%s",&s);
            if(strcmp(s,"CONTEST_WON")==0)
            {
                scanf("%d",&rank);
                if(rank<20)
                    laddu+=300+(20-rank);
                else
                    laddu+=300;
            }
            if(strcmp(s,"TOP_CONTRIBUTOR")==0)
                laddu+=300;
            if(strcmp(s,"BUG_FOUND")==0)
            {
                scanf("%d",&bug);
                laddu+=bug;
            }
            if(strcmp(s,"CONTEST_HOSTED")==0)
                laddu+=50;
        }
        if(strcmp(origin,"INDIAN")==0)
        {
            month = laddu/200;
        }
        if(strcmp(origin,"NON_INDIAN")==0)
        {
            month = laddu/400;
        }
        printf("%d\n",month);
    }
}
