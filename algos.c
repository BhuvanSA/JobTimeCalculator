#include <stdio.h>

int noP;

typedef struct {
  int id;
  int at;
  int bt;
  int et;
  int tt;
  int wt;
} process;

int main(void) {
  printf("Enter no of processes\n");
  scanf("%i", &noP);
  process processes[noP];
  printf("Process ID | Arrival Time | Burst Time\n");

  for (int i = 0; i < noP; i++) {
    printf("----------------------------------------\n");
    scanf("%i %i %i", &processes[i].id, &processes[i].at, &processes[i].bt);
  }
  printf("\n\n");

  for (int i = 0; i < noP - 1; i++) {
    for (int j = 0; j < noP - 1 - i; j++) {
      if (processes[j].at > processes[j + 1].at) {
        int tempid = processes[j].id;
        int tempat = processes[j].at;
        int tempbt = processes[j].bt;
        processes[j].id = processes[j + 1].id;
        processes[j].at = processes[j + 1].at;
        processes[j].bt = processes[j + 1].bt;
        processes[j + 1].id = tempid;
        processes[j + 1].at = tempat;
        processes[j + 1].bt = tempbt;
      }
    }
  }

  int ct;
  int totaltt = 0;
  int totalwt = 0;
  for (int i = 0; i < noP; i++) {
    int copybt = processes[i].bt;
    while (copybt > 0) {
      if (processes[i].at <= ct) {
        copybt--;
      }
      ct++;
    }
    processes[i].et = ct;
    processes[i].tt = processes[i].et - processes[i].at;
    processes[i].wt = processes[i].tt - processes[i].bt;
    totaltt = processes[i].tt;
    totalwt = processes[i].wt;
  }

  printf("------------------------------------------------------------------"
         "--------"
         "------------\n");
  printf("| Process ID | Arrival Time | Burst Time | End Time    | Turnaround "
         "Time "
         "| Wait Time |\n");
  for (int i = 0; i < noP; i++) {
    printf("------------------------------------------------------------------"
           "--------"
           "------------\n");
    printf("|%11i |%13i |%11i |%12i |%16i |%10i |\n", processes[i].id,
           processes[i].at, processes[i].bt, processes[i].et, processes[i].tt,
           processes[i].wt);
  }
  printf("------------------------------------------------------------------"
         "--------"
         "------------\n");
  printf("\nTotal Execution Time : %i\n", ct);
  printf("Average Turnaround Time : %i\n", totaltt / noP);
  printf("Average Wait Time : %i\n", totalwt / noP);

  return 0;
}
