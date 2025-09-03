#include "types.h"
#include "user.h"

int
main(void)
{
  printf(1, "Number of active processes: %d\n", getNumProc());
  printf(1, "Maximum PID: %d\n", getMaxPid());
  exit();
}