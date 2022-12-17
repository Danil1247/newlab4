#include "JobStream.h"

TJobStream::TJobStream(double _intens)
{
	if ((_intens >= 0.0) && (_intens <= 1.0))
	{
		jobIntens = _intens;

		lastJobId = 1;
	}
	else
		throw "Job Intens must be between 0.0 and 1.0";
}

double TJobStream::GetJobIntens()
{
  return jobIntens;
}

size_t TJobStream::GetNewJob()
{
	if (((static_cast<double>(std::rand())) / (static_cast<double>(RAND_MAX))) <= jobIntens)
	{
		lastJobId++;
		return lastJobId - 1;
	}
	else
		return 0;
}

size_t TJobStream::GetLastJobId()
{
  return lastJobId;
}
