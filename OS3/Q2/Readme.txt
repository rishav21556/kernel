In communication over fifo, two fifo's has been used for complete transmission. For sending ID's of the string, 10th index of each string is char form of integer
number. Fork system call has been used to invoke the receiver's process.

For communication over shared memory, fork system call has been invoked for reciver process. Only one shared memory segment has been used for complete communication.
Synchronization has been ensured by fork and wait in both the cases.
