#include "Proc.h"
#include "gtest.h"

TEST(TProc, can_create_Proc)
{
  ASSERT_NO_THROW(TProc test(0.8, 1));
}

TEST(TProc, cant_create_Proc_with_unsuitable_values)
{
  ASSERT_ANY_THROW(TProc test(1.8, 1));
}

TEST(TProc, can_get_rate)
{
  TProc test(0.8, 1);

  ASSERT_NO_THROW(test.GetRate());
}

TEST(TProc, can_get_IsProcBusy)
{
  TProc test(0.8, 1);

  ASSERT_NO_THROW(test.IsProcBusy());
}

TEST(TProc, can_get_IsProcFull)
{
  TProc test(0.8, 1);

  ASSERT_NO_THROW(test.IsProcFull());
}

TEST(TProc, can_get_new_job)
{
  TProc test(0.8, 1);

  ASSERT_NO_THROW(test.RunNewJob(1));
}

TEST(TProc, can_do_job)
{
  TProc test(0.8, 1);

  ASSERT_NO_THROW(test.DoJob());
}

TEST(TProc, can_get_jobsDone)
{
  TProc test(0.8, 1);

  ASSERT_NO_THROW(test.GetJobsDone());
}

TEST(TProc, can_get_overflowTime)
{
  TProc test(0.8, 1);

  ASSERT_NO_THROW(test.GetOverflowTimes());
}

TEST(TProc, can_get_noJobsTime)
{
  TProc test(0.8, 1);

  ASSERT_NO_THROW(test.GetNoJobsTimes());
}