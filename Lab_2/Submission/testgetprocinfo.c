
#include "types.h"
#include "stat.h"
#include "user.h"
#include "processInfo.h"


int
main(int argc, char *argv[])
{
  int pid;
  struct processInfo info;


  if(argc != 2){
    printf(2, "Usage: testgetprocinfo <pid>\n");
    exit();
  }


  pid = atoi(argv[1]);
 
  if(getProcInfo(pid, &info) < 0){
    printf(2, "getProcInfo failed for pid %d\n", pid);
    exit();
  }


  printf(1, "Process Info for PID %d:\n", pid);
  printf(1, "Parent PID: %d\n", info.ppid);
  printf(1, "Process Size: %d bytes\n", info.psize);
  printf(1, "Number of Context Switches: %d\n", info.numberContextSwitches);


  exit();
}
