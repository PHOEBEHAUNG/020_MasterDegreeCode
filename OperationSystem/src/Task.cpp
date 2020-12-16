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
  execlp(file,file,arg,NULL);  //works
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
