# CPU-scheduling-algorithms
The CPU Scheduling is the process by which a process is executed by the using the resources of the CPU. The process also can wait due to the absence or unavailability of the resources. These processes make the complete use of Central Processing Unit.
CPU scheduling algorithms are used by operating systems to allocate CPU time to processes.<br>
 <br>
 <b>Some common CPU scheduling algorithms are:</b><br>
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
* <b>Banker's Algorithm </b>
It is a banker algorithm used to avoid deadlock and allocate resources safely to each process in the computer system. The 'S-State' examines all possible tests or activities before deciding whether the allocation should be allowed to each process. It also helps the operating system to successfully share the resources between all the processes. <br>
The banker's algorithm is named because it checks whether a person should be sanctioned a loan amount or not to help the bank system safely simulate allocation resources.
* <b>Wait-Die Algorithm</b>
The Wait-Die algorithm is a deadlock avoidance algorithm that uses timestamps to manage resource allocation. It ensures that a process requesting a resource will either wait or be granted access based on the timestamp comparison with the processes currently holding the resource. The algorithm prevents deadlock by allowing younger processes to wait for older processes but granting access to older processes immediately.
* <b>Wound-Wait Algorithm</b>
The Wound-Wait algorithm is another deadlock avoidance algorithm that uses timestamps to manage resource allocation. Similar to the Wait-Die algorithm, it ensures that a process requesting a resource will either wait or be granted access based on the timestamp comparison with the processes currently holding the resource. However, in the Wound-Wait algorithm, if a younger process is denied access to a resource, it "wounds" (preempts) the older process holding the resource, allowing the younger process to proceed.<br>
<br>Here's an explanation of the Wound-Wait algorithm:<br>
1. Each process is assigned a unique timestamp, representing its age or order of arrival.<br>

2. When a process requests a resource, the algorithm compares the timestamps of the requesting process and the process holding the resource.

3. If the requesting process has a lower timestamp (younger), it indicates that it arrived later than the process holding the resource. In this case:
   - The requesting process "wounds" (preempts) the older process by forcefully taking the resource.
   - The older process is put into a waiting state.

4. If the requesting process has a higher timestamp (older), it indicates that it arrived earlier than the process holding the resource. In this case:
   - The requesting process is allowed to proceed, as it is older and has higher priority.
   - The process can access the requested resource.

5. When a process releases a resource, the algorithm checks if any wounded process is waiting for that resource. If found, the wounded process is granted access to the resource.

# Graph traversal algorithms
## Breadth-First Search (BFS)
Algorithm of Breadth-First Search:
Step 1: Consider the graph you want to navigate.<br>
Step 2: Select any vertex in your graph (say v1), from which you want to traverse the graph.<br>
Step 3: Utilize the following two data structures for traversing the graph.<br>
Visited array(size of the graph)<br>
Queue data structure<br>
Step 4: Add the starting vertex to the visited array, and afterward, you add v1’s adjacent vertices to the queue data structure.<br>
Step 5: Now using the FIFO concept, remove the first element from the queue, put it into the visited array, and then add the adjacent vertices of the removed element to the queue.<br>
Step 6: Repeat step 5 until the queue is not empty and no vertex is left to be visited.<br>

## Depth-first search (DFS)
DFS algorithm in the data structure. It is a recursive algorithm to search all the vertices of a tree data structure or a graph. The depth-first search (DFS) algorithm starts with the initial node of graph G and goes deeper until we find the goal node or the node with no children.

Because of the recursive nature, stack data structure can be used to implement the DFS algorithm. The process of implementing the DFS is similar to the BFS algorithm.

The step by step process to implement the DFS traversal is given as follows -

Step 1: First, create a stack with the total number of vertices in the graph.<br>
Step 2: Now, choose any vertex as the starting point of traversal, and push that vertex into the stack.<br>
Step 3: After that, push a non-visited vertex (adjacent to the vertex on the top of the stack) to the top of the stack.<br>
Step 4: Now, repeat steps 3 and 4 until no vertices are left to visit from the vertex on the stack's top.<br>
Step 5: If no vertex is left, go back and pop a vertex from the stack.<br>
Step 6: Repeat steps 2, 3, and 4 until the stack is empty.<br>

## Dijkstra's Algorithm
Dijkstra's Algorithm:

## Reference
https://www.geeksforgeeks.org/ <br>
https://javatpoint.com/ <br>
