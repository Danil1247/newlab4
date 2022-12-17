#include "JobStream.h"
#include "gtest.h"

TEST(TJobStream, can_create_JobStream)
{
  ASSERT_NO_THROW(TJobStream test(0.8));
}

TEST(TJobStream, cant_create_JobStream_with_unsuitable_values)
{
  ASSERT_ANY_THROW(TJobStream test(1.8));
}

TEST(TJobStream, can_get_JobStream)
{
  TJobStream test(0.8);

  ASSERT_NO_THROW(test.GetJobIntens());
}

TEST(TJobStream, can_get_new_job)
{
  TJobStream test(0.8);

  ASSERT_NO_THROW(test.GetNewJob());
}

TEST(TJobStream, can_get_last_job)
{
  TJobStream test(0.8);

  ASSERT_NO_THROW(test.GetLastJobId());
}