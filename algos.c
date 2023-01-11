#include <stdio.h>
#include <stdlib.h>

int noP;

typedef struct {
  int id;
  int at;
  int bt;
  int et;
  int tt;
  int wt;
} process;

process *p;

int main(void) {
  // Taking the table as input
  p = (process *)malloc(20 * sizeof(process));
  printf("Enter no of processes\n");
  scanf("%i", &noP);
  process processes[noP];
  printf("Process ID | Arrival Time | Burst Time\n");

  for (int i = 0; i < noP; i++) {
    printf("----------------------------------------\n");
    scanf("%i %i %i", &processes[i].id, &processes[i].at, &processes[i].bt);
  }
  printf("\n\n");

  // Sorting list according to arrival time using bubble sort
  for (int i = 0; i < noP - 1; i++) {
    for (int j = 0; j < noP - 1 - i; j++) {
      if (processes[j].at > processes[j + 1].at) {
        process temp = processes[j];
        processes[j] = processes[j + 1];
        processes[j + 1] = temp;
      }
    }
  }

  // A algorithm which simulates FCFS and stores totaltt Turnaround time and
  // other stuff
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

  // Printing the output in pretty formatted layout
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
