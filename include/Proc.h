#pragma once

#include "Queue.h"
#include <cstdlib>

class TProc {
protected:

  double procRate;
  TQueue<size_t> jobs;
  size_t jobsDone;
  size_t overflowTimes;
  size_t noJobsTimes;

public:

	TProc(double _rate, size_t _maxJobs);
	double GetRate();
	size_t IsProcBusy();
	bool IsProcFull();
	size_t RunNewJob(size_t _jobId);
	size_t DoJob();
	size_t GetJobsDone();
	size_t GetOverflowTimes();
	size_t GetNoJobsTimes();

};