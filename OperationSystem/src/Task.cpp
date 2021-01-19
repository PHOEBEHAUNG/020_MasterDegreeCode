#include "Global.h"

void ForkExample1()
{
  pid_t  pid;
  int    i;
  char   buf[BUF_SIZE];

  pid = fork();

  if (pid == 0)
  {
    pid = getpid(); /// child 裡面的pid
    for (i = 1; i <= MAX_COUNT; i++) {
      sprintf(buf, "This line is from pid %d, value = %d\n", pid, i);
      write(1, buf, strlen(buf));
    } 
  }
  else 
  {
    pid = getpid();
    for (i = 1; i <= MAX_COUNT; i++) {
      sprintf(buf, "This line is from parents pid %d, value = %d\n", pid, i);
      write(1, buf, strlen(buf));
    } 
  }
}

void ForkExample2()
{
  pid_t  pid;

  pid = fork(); 
  printf("[%d] hello, 1\n", pid); 
  pid = fork(); 
  printf("[%d] hello, 2\n", pid); 
  pid = fork();
  printf("[%d] hello, 3\n", pid); 
}

void ForkExample3()
{
  int i = 0;
  int n = 2;
  pid_t  pid;
  for (i = 0; i < n; i++)
  { 
    pid = fork(); 
    printf("[%d] hello\n", pid); 
  }
}

void ExeclpExample1()
{
  const char* file = "cat";
  const char* arg = "test.txt";
  execlp(file, file, arg, NULL);  //works
}

#define NUM_THREADS 5
void *PrintHello(void *threadId) 
{
  long* data = static_cast <long*> (threadId); 
  printf("Hello World! It's me, thread #%ld!\n", *data);
  pthread_exit(NULL);
}
void PThreadExample1()
{
  pthread_t threads[NUM_THREADS];
  
  for(long tid = 0; tid < NUM_THREADS; tid++)
  {
    pthread_create(&threads[tid], NULL, PrintHello, (void *)&tid);
  }
  pthread_exit(NULL);
}

/// sychronization 
/// process check
void *Thread1(void *threadId) 
{
  int i = 0;
  while (1) 
  {
    if(i > 1000)
    {
      printf("Thread1 End\n");
      break;
    }
    i++;
    printf("Thread1 %d\n", i);
    usleep(300000);
  }
  pthread_exit(NULL);
}

void *Thread2(void *threadId)
{
  int i = 0;
  while (1) 
  {
    if(i > 1000)
    {
      printf("Thread2 End\n");
      break;
    }
    i++;
    printf("Thread2 %d\n", i);
    usleep(600000);
  }
  pthread_exit(NULL);
}

void ThreadCheck()
{
  pthread_t threads[2];
  
  int tid1 = 0;
  pthread_create(&threads[0], NULL, Thread1, (void *)&tid1);

  int tid2 = 0;
  pthread_create(&threads[1], NULL, Thread2, (void *)&tid2);
}

/// Consumer & Producer Problem
/// https://blog.gtwang.org/programming/pthread-multithreading-programming-in-c-tutorial/
/// https://ithelp.ithome.com.tw/articles/10229559
#define BUFFER_SIZE 5
int dataProducer = 0;
int dataConsumer = 0;
int buffer[5];
int count = 0;
int in = 0;
int out = 0;

void *Producer(void *threadId) 
{
  while (1) 
  {
    while (count >= BUFFER_SIZE); 
    buffer[in] = dataProducer;
    printf("Producer %d [%d = %d]\n", count, in, dataProducer);
    in = (in + 1) % BUFFER_SIZE; 
    count++;
    dataProducer++;
    usleep(300000);
  }
  printf("Producer End\n");
  pthread_exit(NULL);
}

void *Consumer(void *threadId)
{
  while (1) 
  {
    printf("Consumer %d [%d]\n", count, out);
    while (count == 0);
    dataConsumer = buffer[out];
    printf("%d [%d = %d]\n", count - 1, out, dataConsumer);
    out = (out + 1) % BUFFER_SIZE; 
    count--;
    usleep(600000);
  }
  printf("Consumer End\n");
  pthread_exit(NULL);
}

void ConsumerProducer()
{
  pthread_t threads[2];
  
  int tid1 = 0;
  pthread_create(&threads[0], NULL, Producer, (void *)&tid1);

  int tid2 = 0;
  pthread_create(&threads[1], NULL, Consumer, (void *)&tid2);
  sleep(20);
}

/// Race Condition
/// Critical Section
/// Algorithm for Two Processes
int CriticalTwoProcessesVariable = 0;
int CriticalTwoProcessesTurn = 1;
// void *CriticalTwoProcesses1(void *threadId) 
// {
//   int i = 0;
//   while (1) 
//   {
//     if(i > 1000)
//     {
//       printf("Thread1 End\n");
//       break;
//     }

//     printf("Thread1 %d\n", CriticalTwoProcessesTurn);
//     /// critical section
//     while(CriticalTwoProcessesTurn != 1)
//     {
//       //printf("CriticalTwoProcesses1 %d\n", CriticalTwoProcessesTurn);
//     }

//     sleep(1);
//     CriticalTwoProcessesVariable = CriticalTwoProcessesVariable + 7;
//     printf("CriticalTwoProcesses1 CriticalTwoProcessesVariable %d\n", CriticalTwoProcessesVariable);
//     CriticalTwoProcessesTurn = 2;
//     /// end

//     i++;
//     printf("Thread1 %d\n", CriticalTwoProcessesTurn);
//   }
//   pthread_exit(NULL);
// }

// void *CriticalTwoProcesses2(void *threadId)
// {
//   int i = 0;
//   while (1) 
//   {
//     if(i > 1000)
//     {
//       printf("Thread2 End\n");
//       break;
//     }
//     printf("Thread2 %d\n", CriticalTwoProcessesTurn);

//     /// critical section
//     while(CriticalTwoProcessesTurn != 2)
//     {
//       //printf("CriticalTwoProcesses2 %d\n", CriticalTwoProcessesTurn);
//     }
//     sleep(1);
//     CriticalTwoProcessesVariable = CriticalTwoProcessesVariable + 3;
//     printf("CriticalTwoProcesses2 CriticalTwoProcessesVariable %d\n", CriticalTwoProcessesVariable);
//     CriticalTwoProcessesTurn = 1;
//     /// end

//     i++;
//     printf("Thread2 %d\n", CriticalTwoProcessesTurn);
//   }
//   pthread_exit(NULL);
// }

/// Peterson's solution
/// P0想執行了，但是一定要等到P1執行完才能執行(好比說「小明想過馬路但一定要給讓車先過」)。
bool flag[2]; 
void *CriticalTwoProcesses1(void *threadId) 
{
  int i = 0;
  int j = 0;
  while (1) 
  {
    if(i >= 1000)
    {
      printf("Thread1 End\n");
      break;
    }
    i++;
    j = 0;
    printf("Thread1 %d\n", CriticalTwoProcessesTurn);
    flag[0] = true;
    CriticalTwoProcessesTurn = 2;
    while(flag[1] && CriticalTwoProcessesTurn == 2)
    {
      if(j > 1000)
      {
        break;
      }
      j++;
      //printf("CriticalTwoProcesses1 %d\n", CriticalTwoProcessesTurn);
    }
    /// critical section
    CriticalTwoProcessesVariable = CriticalTwoProcessesVariable + 7;
    printf("CriticalTwoProcesses1 CriticalTwoProcessesVariable %d\n", CriticalTwoProcessesVariable);
    flag[0] = false;
    /// end
  }
  pthread_exit(NULL);
}

void *CriticalTwoProcesses2(void *threadId)
{
  int i = 0;
  int j = 0;
  while (1) 
  {
    if(i >= 1000)
    {
      printf("Thread2 End\n");
      break;
    }
    i++;
    j = 0;
    printf("Thread2 %d\n", CriticalTwoProcessesTurn);

    flag[1] = true;
    CriticalTwoProcessesTurn = 1;

    while(flag[0] && CriticalTwoProcessesTurn == 1)
    {
      if(j > 1000)
      {
        break;
      }
      j++;
      //printf("CriticalTwoProcesses2 %d %d\n", flag[0], CriticalTwoProcessesTurn);
    }
    
    /// critical section
    CriticalTwoProcessesVariable = CriticalTwoProcessesVariable + 3;
    printf("CriticalTwoProcesses2 CriticalTwoProcessesVariable %d\n", CriticalTwoProcessesVariable);
    flag[1] = false;
    /// end
  }
  pthread_exit(NULL);
}

void CriticalTwoProcessesCheck()
{
  pthread_t threads[2];
  pthread_create(&threads[0], NULL, CriticalTwoProcesses1, NULL);
  pthread_create(&threads[1], NULL, CriticalTwoProcesses2, NULL);

  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);
}

/// Peterson’s Solution for Two Processes
/// Bakery Algorithm (n processes)

/// implement 
/// Pthread Lock/Mutex Routines   (Condition Variables (CV))
int counter = 0;
// 加入 Mutex
pthread_mutex_t mutex1;
// 子執行緒函數
void* child(void *threadId) 
{
  for(int i = 0;i < 3;++i) 
  {
    pthread_mutex_lock(&mutex1); // 上鎖
    int tmp = counter;
    sleep(1);
    counter = tmp + 1;
    pthread_mutex_unlock(&mutex1); // 解鎖
    printf("Counter = %d\n", counter);
  }
  pthread_exit(NULL);
}

void PthreadMutexProcessesCheck() 
{
  pthread_t t1, t2;
  pthread_mutex_init (&mutex1, NULL);
  pthread_create(&t1, NULL, child, NULL);
  pthread_create(&t2, NULL, child, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
}

/// ThreadPool Implementation

/// Atomic
/// TestAndSet
/// swap 

/// semaphores
/// POSIX, JAVA

/// n-Process Critical Section Problem  
/// Non-busy waiting Implementation
/// Semaphore with Critical Section

/// classic problem
/// Bounded-Buffer Problem
/// Readers-Writers Problem
/// First Reader-Writer Algorithm
/// Dining-Philosophers Problem

/// monitor 
/// Bounded-Buffer Problem
/// Readers-Writers Problem
/// First Reader-Writer Algorithm
/// Dining-Philosophers Problem
