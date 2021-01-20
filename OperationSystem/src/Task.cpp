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
/// https://ithelp.ithome.com.tw/articles/10206310
/// https://sls.weco.net/node/21326

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
/// Bakery Algorithm (n processes) /// 排隊拿門票

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
#define LOCKED 1
int TestAndSet(int* lockPtr) 
{
    int oldValue;     
    // Start of atomic segment
    // The following statements should be interpreted as pseudocode for
    // illustrative purposes only.
    // Traditional compilation of this code will not guarantee atomicity, the
    // use of shared memory (i.e. not-cached values), protection from compiler
    // optimization, or other required properties.
    oldValue = *lockPtr;
    *lockPtr = LOCKED;
    // End of atomic segment

    return oldValue;
}

void* TestAndSetChild(void *threadId) 
{
  int lock = 1;
  for(int i = 0;i < 3;++i) 
  {
    lock = i % 2;
    while(TestAndSet(&lock));

    int tmp = counter;
    sleep(1);
    counter = tmp + 1;
    lock = 0;
    printf("Counter = %d\n", counter);
  }
  pthread_exit(NULL);
}

void TestAndSetCheck()
{
  pthread_t t1, t2;
  pthread_mutex_init (&mutex1, NULL);
  pthread_create(&t1, NULL, TestAndSetChild, NULL);
  pthread_create(&t2, NULL, TestAndSetChild, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
}

/// swap

/// semaphores
/// 必需要保證沒有兩個process可以同時執行wait ()和signal()，也就是說要把wait ()和signal()也放入critical section。
/// POSIX, JAVA

/// n-Process Critical Section Problem  
/// Non-busy waiting Implementation
/// Semaphore with Critical Section

/// classic problem
/// Bounded-Buffer Problem
/**
 * 有n個buffers，且每個都可以放一個item。
 * Semaphore mutex的初始值設為1。
 * Semaphore full的初始值設為0。
 * Semaphore empty的初始值設為n。
 * 在producer與consumer的process架構中，因為producer是wait(empty)、wait(mutex)，
 * 然後signal(mutes)、signal(full)，與consumer的wait(full)、wait(mutex)跟signal(mutex)、signal(empty)並不一樣，
 * 而且在wait()方面需要取得lock或spinlock才可以進入CS操作，這就是容易產生問題的所在。
 * 
 */ 
/// Readers-Writers Problem
/**
 * 
 * 多個process可以同時共享data：
 * Readers：只能read the data，並不能執行任何更新。
 * Writers：可以read也可以write。
 * Problem：只允許多個reader在同一時間進行read。
 * 只有單一writer可以在一個時間內存取共享的data。
 * 共享data：
 * Data set
 * Semaphore rw_mutex的初始值為1。
 * Semaphore mutex的初始值為1。
 * Semaphore read_count的初始值為0。
 */
/// First Reader-Writer Algorithm
/**
 * First variation：除非有witer去使用共享object，否則不能有reader在一直等待。
 * Second variation：只要writer準備就緒，就會執行寫作ASAP。
 * 以上兩種都有可能會產生「Starvation」的情況，導致更多的變化出現。
 * 由kernel提供reader-writer locks，才能使某些系統得以解決problem。
 */
/// Dining-Philosophers Problem
/// Deadlock的發生 
/**
 * 只允許在一個圓桌上有4個人而已。
 * 要檢查左右是否都已經available，可以的話便能eating。
 * 使用asymmetric方法解決：也就是說，坐在奇位數位置的人先拿取左邊再拿取右邊的筷子；坐在雙數位置的人先拿取右邊再拿取左邊的筷子，方能解決問題。
 */
/// monitor 
/**
 * 提供方便且有效率的機制給process synchronization使用。
有些系統不支持。
一次只能有一個process可以在monitor內執行。
不能解決所有的synchronization問題，但這已經是較為複雜的方法。
 */
/// Bounded-Buffer Problem
/// Readers-Writers Problem
/// First Reader-Writer Algorithm
/// Dining-Philosophers Problem
/**
 * 每個philosopher i invoke兩個operations pickup()以及putdown()在sequence中。
 * 因為一次一個進入，所以並不會產生dealock，但因為動作慢所以可能會產生starvation的情況。
 */
