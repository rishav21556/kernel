In non required synchronization part (A), only two philosphers can eat at a time, those philosphers must not be sitting next to each other. So, in order to 
resolve deadlock, the algorithm is designed is such a way that if philosopher 1 is eating then 3 will eat along with him.

In required synchronization part(A), semaphores are used to denote each fork such that if the value of a semaphore is zero then sem_wait() function will block itself.
If the value of a semaphore is 0, the sem_post() will increase the value of semaphore.

In non required synchronizaton part(B), as only two philosophers can eat at a time and only two souce balls are available. Logic of (a) part(A) is extended, such that 
one of the two philosophers will get souce ball 1 and other will get souce ball 2.

In required synchronization part (B), sem_trywait() has been used inplace of sem_wait(). It does not block the systemcall and returns -1 or set errno to EAGAIN. 
