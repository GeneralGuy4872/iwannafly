clock_t prevframe = 0;
bool ready = FALSE;
bool nextframe = FALSE;
bool paused = FALSE;
my_date_time date_and_time = {3,0,1,0,7,30};

frametimeloop ()
	{
	clock_t diff = clock() - prevframe;
	if (diff > uSEC_FRAME)
		{
		nextframe = true;
		prevframe = clock();
		tick_tock(date_and_time);
		}
	else
		{
		noop();
		}
	}
