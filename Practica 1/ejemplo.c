#include <stdio.h>
#include <allegro.h>
#include <stdlib.h>
#define ancho 700
#define alto 550
int main(int argc, char *argv[])
{
    allegro_init();
    install_keyboard();
    text_mode(-1);
            int i,j;
            srand (time(NULL));
			printf(" Se abrira la Grafica");
                        int values[10];
                        for (j = 0; j < 10; j++)
                        {
                            values[j] = rand() % (50-2+1)+2;
                        }
                        int max = 410;
                    set_color_depth(32);
                    set_gfx_mode(GFX_AUTODETECT_WINDOWED, ancho, alto, 0, 0);
                    hline(screen,40,405,590,makecol(100,0,255));
                        for (i = 0; i <10 ; i++)
                        {
                                if(i == 9){
                                    line(screen,50*(i+1), max-(values[i]*5), 50*(i+1), max - (values[i]*5),makecol(100,0,255));
                                }
                                else{
                                line(screen,50*(i+1), max-(values[i]*5), 50*(i+2), max - (values[i+1]*5),makecol(100,0,255));
                                textprintf(screen,font,50*(i+1),410,makecol(255,255,255),"%d",i+1);
                                textprintf(screen,font,43*(i+1),max - (values[i]*5)-5,makecol(255,255,255),"%d",values[i]);
                                }
                        }
                        getch();
		 return 0;
}
END_OF_MAIN();

