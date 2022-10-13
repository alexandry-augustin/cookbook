#ifndef BASERUNNABLE_H
#define BASERUNNABLE_H

// NOTE: implement by classes having threading support (cf. BaseThread)

class BaseRunnable
{
public:
	virtual void run()=0;
};

#endif
