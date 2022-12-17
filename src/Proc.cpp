#include "Proc.h"

TProc::TProc(double _rate, size_t _maxJobs) : jobs(_maxJobs)
{
  if ((_rate >= 0.0) && (_rate <= 1.0))
  {
    procRate = _rate;

    jobsDone = 0;

    overflowTimes = 0;

    noJobsTimes = 0;
  }
  else
    throw "Proc rate must be between 0.0 and 1.0";
}

double TProc::GetRate()
{
  return procRate;
}

size_t TProc::IsProcBusy()
{
  if (jobs.IsEmpty())
    return 0;
  else
    return jobs.Top();
}

bool TProc::IsProcFull()
{
  return jobs.IsFull();
}

size_t TProc::RunNewJob(size_t _jobId)
{
  if (_jobId > 0)
  {
    if (IsProcFull())
    {
      overflowTimes++;

      return 0;
    }
    else
    {
      jobs.Push(_jobId);

      return _jobId;
    }
  }
  else
    return ~0;
}

size_t TProc::DoJob()
{
  if (!IsProcBusy())
  {
    noJobsTimes++;

    return 0;
  }
  else if ((((static_cast<double>(std::rand())) / (static_cast<double>(RAND_MAX))) <= procRate) && IsProcBusy())
  {
    size_t lastJob = jobs.TopPop();

    jobsDone++;

    return lastJob;
  }
  else
    return jobs.Top();
}

size_t TProc::GetJobsDone()
{
  return jobsDone;
}

size_t TProc::GetOverflowTimes()
{
  return overflowTimes;
}

size_t TProc::GetNoJobsTimes()
{
  return noJobsTimes;
}
