#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef signed short mesurements[16];
enum mesure_index {mes_skull,mes_neck,mes_shld,mes_back,mes_humr,mes_femr,
  mes_pelv,mes_cxyx,mes_tail,mes_wing,mes_q,mes_dig,mes_fan_len,mes_fan_rad,
  mes_fan_ang};

mesurements geomet;
float tmp;
FILE * newfile;
char filepath[512];

#define nextline scanf("%*[^\n]s");
#define S_RATIO 2.414213562373095048802

noop () {}

main()
	{
	puts("file to write: ");
	scanf("%s",filepath);
	nextline
	newfile = fopen(filepath,"wx");
	if (newfile != NULL)
		{
		for (unsigned char n=0;n<15;n++)
			{
			switch (n)
				{
				case 0 :
					{
					printf("head circumfrence\n(cm) ");
					scanf("%f",&tmp);
					geomet[mes_skull] = (signed short)((tmp / (200 * M_PI)) * 64);
					break;
					}
				case 1 :
					{
					printf("length of spine (cervical)\n(cm) ");
					scanf("%f",&tmp);
					geomet[mes_neck] = (signed short)((tmp / 100) * 64);
					break;
					}
				case 2 :
					{
					printf("shoulder width\n(cm) ");
					scanf("%f",&tmp);
					geomet[mes_shld] = (signed short)((tmp / 200) * 64);
					break;
					}
				case 3 :
					{
					printf("length of spine (thorassic, lumbar)\n(cm) ");
					scanf("%f",&tmp);
					geomet[mes_back] = (signed short)((tmp / 100) * 64);
					break;
					}
				case 4 :
					{
					printf("humoral length\n(cm) ");
					scanf("%f",&tmp);
					geomet[mes_humr] = (signed short)((tmp / 100) * 64);
					break;
					}
				case 5 :
					{
					printf("femoral length\n(cm) ");
					scanf("%f",&tmp);
					geomet[mes_femr] = (signed short)((tmp / 100) * 64);
					break;
					}
				case 6 :
					{
					printf("pelvis width\n(cm) ");
					scanf("%f",&tmp);
					geomet[mes_pelv] = (signed short)((tmp / 200) * 64);
					break;
					}
				case 7 :
					{
					printf("coxxyx length\n(cm) ");
					scanf("%f",&tmp);
					geomet[mes_cxyx] = (signed short)((tmp / 100) * 64);
					break;
					}
				case 8 :
					{
					printf("tail (spinal) length\n(cm) ");
					scanf("%f",&tmp);
					geomet[mes_tail] = (signed short)((tmp / 100) * 64);
					break;
					}
				case 9 :
					{
					printf("wingspan (literally)\n(m) ");
					scanf("%f",&tmp);
					geomet[mes_wing] = (signed short)((tmp / ((4 * S_RATIO) + 2)) * 64);
					break;
					}
				case 10 :
					{
					printf("\"Q\" angle\n(deg) ");
					scanf("%f",&tmp);
					geomet[mes_q] = (signed short)(tmp * 64);
					break;
					}
				case 11 :
					{
					printf("digitigrade angle\n(deg) ");
					scanf("%f",&tmp);
					geomet[mes_dig] = (signed short)(tmp * 64);
					break;
					}
				case 12 :
					{
					printf("tail (fan) length\n(cm) ");
					scanf("%f",&tmp);
					geomet[mes_fan_len] = (signed short)((tmp / 100) * 64);
					break;
					}
				case 13 :
					{
					printf("tail (fan) width\n(cm) ");
					scanf("%f",&tmp);
					geomet[mes_fan_rad] = (signed short)((tmp / 100) * 64);
					break;
					}
				case 14 :
					{
					printf("tail (fan) spread\n(rad) pi / ");
					scanf("%f",&tmp);
					geomet[mes_fan_ang] = (signed short)(tmp * 64);
					break;
					}
				default :
					{
					fprintf(stderr,"/!\\ An ERROR has occured.");
					break;
					}
				}
			}
		for (unsigned char n=0;n<16;n++)
			{
			switch (n)
				{
				case mes_skull :
					{
					fprintf(newfile,"%d\n",geomet[mes_skull]);
					break;
					}
				case mes_neck :
					{
					fprintf(newfile,"%d\n",geomet[mes_neck]);
					break;
					}
				case mes_shld :
					{
					fprintf(newfile,"%d\n",geomet[mes_shld]);
					break;
					}
				case mes_back :
					{
					fprintf(newfile,"%d\n",geomet[mes_back]);
					break;
					}
				case mes_humr :
					{
					fprintf(newfile,"%d\n",geomet[mes_humr]);
					break;
					}
				case mes_femr :
					{
					fprintf(newfile,"%d\n",geomet[mes_femr]);
					break;
					}
				case mes_pelv :
					{
					fprintf(newfile,"%d\n",geomet[mes_pelv]);
					break;
					}
				case mes_cxyx :
					{
					fprintf(newfile,"%d\n",geomet[mes_cxyx]);
					break;
					}
				case mes_tail :
					{
					fprintf(newfile,"%d\n",geomet[mes_tail]);
					break;
					}
				case mes_wing :
					{
					fprintf(newfile,"%d\n",geomet[mes_wing]);
					break;
					}
				case mes_q :
					{
					fprintf(newfile,"%d\n",geomet[mes_q]);
					break;
					}
				case mes_dig :
					{
					fprintf(newfile,"%d\n",geomet[mes_dig]);
					break;
					}
				case mes_fan_len :
					{
					fprintf(newfile,"%d\n",geomet[mes_fan_len]);
					break;
					}
				case mes_fan_rad :
					{
					fprintf(newfile,"%d\n",geomet[mes_fan_rad]);
					break;
					}
				case mes_fan_ang :
					{
					fprintf(newfile,"%d\n",geomet[mes_fan_ang]);
					break;
					}
				default :
					{
					break;
					}
				}
			}
		}
	else
		{
		fprintf(stderr,"/!\\ Could not create file \"%s\"\n",filepath);
		}
	}
