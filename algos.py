
table = []
sortedTable = []

def tInput():
    noP = int(input("Enter the number of process: "))
    print("Process Arrival Time  Burst Time")
    print("--------------------------------")
    for _ in range(noP):
        lis = input().split()
        print("-----------")
        table.append(lis)

    
def tOutput():
    print("Process |  Arrival Time |  Burst Time")
    print("---------------------------------------")
    for sl in table:
        for dt in sl:
            print("",dt,end="\t|\t")
        print("\n---------------------------------------")

    

def FCFS():
    timeline = 0
    for sl in table:
        timeline += sl[2]

tInput()
tOutput()


    
