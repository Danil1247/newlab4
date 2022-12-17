#pragma once

#include <cstdlib>

class TJobStream
{
public:
	TJobStream(double _intens);

	double GetJobIntens();

	size_t GetNewJob();

	size_t GetLastJobId();

protected:

	double jobIntens;

	size_t lastJobId;

};
