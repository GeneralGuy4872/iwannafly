
clock_t prevframe = clock()
framecount = 0
bool ready = FALSE
bool nextframe = FALSE
bool pause = FALSE

frametimeloop()
  {
	clock_t diff = clock() - prevframe
	msec = diff * 1000
	if (msec > MSPF)
    {
    nextframe = true
    prevframe = clock()
		}
  else
    {}
  }
