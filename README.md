# CPU-scheduling-algorithms
The CPU Scheduling is the process by which a process is executed by the using the resources of the CPU. The process also can wait due to the absence or unavailability of the resources. These processes make the complete use of Central Processing Unit.CPU scheduling algorithms are used by operating systems to allocate CPU time to processes.<br>
<br> <b>Some common CPU scheduling algorithms are:</b><br>
* First-Come, First-Served (FCFS)<br>
* Shortest Job First (SJF)<br>
* Priority Scheduling<br>
* Round Robin (RR)<br>
* Multilevel Queue Scheduling<br>
## First-Come, First-Served (FCFS)
First Come First Serve CPU Scheduling Algorithm, the CPU allots the resources to the process in a certain order. The order is serial way. The CPU is allotted to the process in which it has occurred.<br>
-First Serve CPU Scheduling Algorithm follows First In First Out in Ready Queue.
## Shortest Job First (SJF)
Shortest Job is heavily dependent on the Burst Times. Every CPU Scheduling Algorithm is basically dependent on the Arrival Times. Here, in this Shortest Job First CPU Scheduling Algorithm, the CPU allots its resources to the process which is in ready queue and the process which has least Burst Time.
## Priority Scheduling 
In Priority scheduling, there is a priority number assigned to each process. In some systems, the lower the number, the higher the priority. While, in the others, the higher the number, the higher will be the priority. The Process with the higher priority among the available processes is given the CPU.
## Round Robin (RR)
A round-robin is a CPU scheduling algorithm that shares equal portions of resources in circular orders to each process and handles all processes without prioritization. In the round-robin, each process gets a fixed time interval of the slice to utilize the resources or execute its task called time quantum or time slice. Some of the round-robin processes are pre-empted if it executed in a given time slot, while the rest of the processes go back to the ready queue and wait to run in a circular order with the scheduled time slot until they complete their task. It removes the starvation for each process to achieve CPU scheduling by proper partitioning of the CPU.
## Multilevel Queue Scheduling
Each algorithm supports a different process, but in a general system, some processes require scheduling using a priority algorithm. While some processes want to stay in the system (interactive processes), others are background processes whose execution can be delayed.<br>
In a Multilevel Queue Scheduling system, processes are assigned to one of the several queues, based on the priority or other criteria, and each queue is assigned a different priority. The processes in each queue are scheduled using a different scheduling algorithm that is appropriate for the characteristics of the processes in that queue.

# Deadlock Avoidance algothms
In deadlock avoidance, the request for any resource will be granted if the resulting state of the system doesn't cause deadlock in the system.The state of the system will continuously be checked for safe and unsafe states.

In order to avoid deadlocks, the process must tell OS, the maximum number of resources a process can request to complete its execution.
<br>
* Banker's Algorithm:


## Reference
https://www.geeksforgeeks.org/ <br>
https://javatpoint.com/ <br>
