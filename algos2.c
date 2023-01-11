#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int id;
  int at;
  int bt;
  int et;
  int tt;
  int wt;
} process;

process *pro;
int noP, totaltime, totaltt, totalwt;

void input(void);
void sort(void);
void output(void);
void freer(void);
void fcfs(void);
void sjf(void);

int main(void) {
  input();
  sort();
  fcfs();
  output();
  freer();
}

// void sjf(void) {
//   totaltime = 0;
//   // Loop from here
//   while (totaltime <) {
//     int shortt = 999999;
//     int shorti = -1;
//     for (int i = 0; i < noP; i++) {
//       if (totaltime >= pro[i].at) {
//         if (pro[i].bt < shortt) {
//           shortt = pro[i].bt;
//           shorti = i;
//         }
//       }
//     }
//     if (shorti != -1) {
//       totaltime += shortt;
//       pro[shorti].et = totaltime;
//       pro[shorti].tt = pro[shorti].et - pro[shorti].at;
//       pro[shorti].wt = pro[shorti].tt - pro[shorti].bt;
//       totaltt += pro[shorti].tt;
//       totalwt += pro[shorti].wt;
//     } else {
//       totaltime++;
//     }
//   }
// }
//
// Calculaing times for fcfs algorithm
void fcfs(void) {
  totaltime = 0;
  for (int i = 0; i < noP; i++) {
    int copybt = pro[i].bt;
    while (copybt > 0) {
      if (pro[i].at <= totaltime) {
        copybt--;
      }
      totaltime++;
    }
    pro[i].et = totaltime;
    pro[i].tt = pro[i].et - pro[i].at;
    pro[i].wt = pro[i].tt - pro[i].bt;
    totaltt += pro[i].tt;
    totalwt += pro[i].wt;
  }
}

// Frees all the malloced memory spaces
void freer(void) { free(pro); }

// Sorting list according to arrival time using bubble sort
void sort(void) {
  for (int i = 0; i < noP - 1; i++) {
    for (int j = 0; j < noP - 1 - i; j++) {
      if (pro[j].at > pro[j + 1].at) {
        process temp = pro[j];
        pro[j] = pro[j + 1];
        pro[j + 1] = temp;
      }
    }
  }
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
  printf("\nTotal Execution Time : %i\n", totaltime);
  printf("Average Turnaround Time : %i\n", totaltt / noP);
  printf("Average Wait Time : %i\n", totalwt / noP);
}

// Input the processes from user
void input(void) {
  printf("Enter no of processes");
  scanf("%d", &noP);
  pro = malloc(noP * sizeof(process));
  printf("Process ID | Arrival Time | Burst Time\n");
  for (int i = 0; i < noP; i++) {
    printf("----------------------------------------\n");
    scanf("%i %i %i", &pro[i].id, &pro[i].at, &pro[i].bt);
  }
  printf("\n\n");
}
