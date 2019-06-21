struct js_event
	{
	unsigned int time;
	signed short value;
	unsigned char type;
	unsigned char number;
	}; //grumble grumble incomplete repos grumble

mainloop()
	{
	volatile int joystick;
	joystick = (open ("/dev/input/js0",O_RDONLY | O_NONBLOCK));
	struct js_event event1;
  signed short values[8]
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
    while (JSAXISFLAG < 0)
      {
      sleep(0)
      }
    JSAXISFLAG = 1
    JSAXISBUFF[0] = values[0]
    JSAXISBUFF[1] = values[1]
    JSAXISBUFF[2] = values[2]
    JSAXISBUFF[3] = values[3]
    JSAXISBUFF[4] = values[4]
    JSAXISBUFF[5] = values[5]
    JSAXISBUFF[6] = values[6]
    JSAXISBUFF[7] = values[7]
    JSAXISFLAG = 0
		}
	}
