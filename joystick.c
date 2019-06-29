//see below
typedef struct js_event
	{
	unsigned int time;
	signed short value;
	unsigned char type;
	unsigned char number;
	} jsevent;
/* previous structure definition (and event type identifiers below)
 * are from a linux kernel documentation page;
 * I could not find the source file which it describes in my distro's
 * repo to #include it. sorce web address is:
 * https://www.kernel.org/doc/Documentation/input/joystick-api.txt
 * last section says use of code snippits is permitted
 */

jsloop ()
	{
	int joystick;
	joystick = (open ("/dev/input/js0",O_RDONLY | O_NONBLOCK));
	js_event event1;
	signed short values[8];
	while (1)
		{
		for(int n=0;n<SHRT_MAX;n++)
			{
			read(joystick,&event1,sizeof(event1));
			if (event1.type == 0x02)
				{
				values[event1.number] = event1.value;
				}
			}
	while (*JSAXISFLAG == 0)
		{
		sleep(0);
		}
	*JSAXISFLAG = -1;
	(*JSAXISBUFF)[0] = values[0];
	(*JSAXISBUFF)[1] = values[1];
	(*JSAXISBUFF)[2] = values[2];
	(*JSAXISBUFF)[3] = values[3];
	(*JSAXISBUFF)[4] = values[4];
	(*JSAXISBUFF)[5] = values[5];
	(*JSAXISBUFF)[6] = values[6];
	(*JSAXISBUFF)[7] = values[7];
	*JSAXISFLAG = 0;
	}
