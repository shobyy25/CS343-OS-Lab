
#ifndef PROCESSINFO_H
#define PROCESSINFO_H


struct processInfo {
  int ppid;  // Parent Process ID
  int psize;  // Process Size in Bytes
  int numberContextSwitches;  // Number of Context Switches
};
 
#endif // PROCESSINFO_H


