// test_burst_time.c
#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
  int ret;
  
  printf(1, "Setting burst time to 10...\n");
  ret = set_burst_time(10);
  if(ret < 0)
    printf(1, "set_burst_time failed\n");
  else
    printf(1, "set_burst_time succeeded\n");

  printf(1, "Getting burst time...\n");
  ret = get_burst_time();
  if(ret < 0)
    printf(1, "get_burst_time failed\n");
  else
    printf(1, "Burst time: %d\n", ret);

  exit();
}