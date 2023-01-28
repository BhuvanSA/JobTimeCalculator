#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int id;
  int at;
  int bt;
  int et;
  int tt;
  int wt;
  int ic;
} process;

typedef struct {
  int id;
  int ic;
} readyQueue;

// Pro is a pointer to the memory being allocated at input
process *pro;
readyQueue *rq;

// noProcess ,totaltime, totatturnaroundtime, totalwaittime
int noP, totaltime, totaltt = 0, totalwt = 0;

void input(void);
void sort(void);
void output(void);
void freer(void);
void fcfs(void);
void npsjf(void);

int main(void) {
  input();
  // sort();
  fcfs();
  output();
  // npsjf();
  // output();
  freer();
}

void npsjf(void) {
  // Checking if there is a process in JobPool
  totaltime = 0;
  while (1) {
    // Choosing a job from job pool if the at <= totaltime and ic == 0
    for (int i = 0; i < noP; i++) {
      if (pro[i].at <= totaltime && pro[i].ic == 0) {
        rq[i].id = pro[i].id;
      }
    }
  }
}

// Calculating times for fcfs algorithm
// void fcfs(void) {
//   totaltime = 0;
//   for (int i = 0; i < noP; i++) {
//     int copybt = pro[i].bt;
//     while (copybt > 0) {
//       if (pro[i].at <= totaltime) {
//         copybt--;
//       }
//       totaltime++;
//     }
//     pro[i].et = totaltime;
//     pro[i].tt = pro[i].et - pro[i].at;
//     pro[i].wt = pro[i].tt - pro[i].bt;
//     totaltt += pro[i].tt;
//     totalwt += pro[i].wt;
//   }
// }
void fcfs(void) {
  int j = 0;
  int k = 0;
  totaltime = 0;
  int t = 500;
  while (t--) {
    // searching for process which have arrived and adding it into the ready
    // queue
    j = 0;
    for (int i = 0; i < noP; i++) {
      if (pro[i].at <= totaltime && pro[i].ic == 0) {
        rq[j].id = pro[i].id;
        j++;
        pro[i].ic++;
      }
    }
    // If there is no process in the readyQueue then increase the currenttime
    if (j == 0) {
      totaltime++;
      continue;
    }
    // Else if there were projects in the readyQueue then execute them
    for (int i = 0; i < j; i++) {
      int var = rq[i].id;
      totaltime += pro[var].bt;
      pro[var].et = totaltime;
      pro[var].tt = pro[var].et - pro[var].at;
      pro[var].wt = pro[var].tt - pro[var].bt;
      totaltt += pro[var].tt;
      totalwt += pro[var].wt;
      pro[var].ic++;
    }
  }
}

// Frees all the malloced memory spaces
void freer(void) {
  free(pro);
  free(rq);
}

// Output the results
void output(void) {
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
    printf("|%11i |%13i |%11i |%12i |%16i |%10i |\n", pro[i].id, pro[i].at,
           pro[i].bt, pro[i].et, pro[i].tt, pro[i].wt);
  }
  printf("------------------------------------------------------------------"
         "--------"
         "------------\n");
  printf("\nTotal Time Taken : %i\n", totaltime);
  printf("Average Turnaround Time : %.2f\n", (float)totaltt / noP);
  printf("Average Wait Time : %.2f\n", (float)totalwt / noP);
}

// Input the processes from user
void input(void) {
  printf("Enter no of processes : ");
  scanf("%d", &noP);
  pro = malloc(noP * sizeof(process));
  rq = malloc(noP * sizeof(readyQueue));
  printf("Arrival Time | Burst Time\n");
  for (int i = 0; i < noP; i++) {
    printf("----------------------------------------\n");
    scanf("%i %i", &pro[i].at, &pro[i].bt);
    // Assigning id as the location of it as entered
    pro[i].id = i;
    pro[i].ic = 0;
  }
  printf("\n\n");
}

void readyQueueInit() {}
