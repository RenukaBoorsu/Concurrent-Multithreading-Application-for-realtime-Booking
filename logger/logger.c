//logger.c
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "logger.h"
FILE *fp ;
static int SESSION_TRACKER; //Keeps track of session

char* print_time()
{
    int size = 0;
    time_t t;
    char *buf;
    
    t=time(NULL); /* get current calendar time */
    
    char *timestr = asctime( localtime(&t) );
    timestr[strlen(timestr) - 1] = 0;  //Getting rid of \n
    
    size = strlen(timestr)+ 1 + 2; //Additional +2 for square braces
    buf = (char*)malloc(size);
    
    memset(buf, 0x0, size);
    snprintf(buf,size,"[%s]", timestr);
   
    return buf;
}
void log_print(char* filename, char* func, int line, char *fmt,...)
{
    va_list         list;
    char            *p, *r;
    int             e;

    if(SESSION_TRACKER > 0)
      fp = fopen ("log.txt","a+");
    else
      fp = fopen ("log.txt","w");
    
    fprintf(fp,"%s ",print_time());
    printf(fp,"%s ",print_time());
    fprintf(fp,"[%s][%s][line: %d] ",filename,func,line);
    printf("[%s][%s][line: %d] ",filename,func,line);
    va_start( list, fmt );

    for ( p = fmt ; *p ; ++p )
    {
        if ( *p != '%' )//If simple string
        {
            fputc( *p,fp );
            fputc( *p,stdout );
        }
        else
        {
            switch ( *++p )
            {
                /* string */
            case 's':
            {
                r = va_arg( list, char * );

                fprintf(fp,"%s", r);
                fprintf(stdout,"%s", r);
                continue;
            }

            /* integer */
            case 'd':
            {
                e = va_arg( list, int );

                fprintf(fp,"%d", e);
                fprintf(stdout,"%d", e);
                continue;
            }

            default:
                fputc( *p, fp );
                fputc( *p, stdout );
            }
        }
    }
    va_end( list );
    fputc( '\n', fp );
    fputc( '\n', stdout );
    SESSION_TRACKER++;
    fclose(fp);
}
