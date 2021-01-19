#ifndef __TYPEDEF_H__
#define __TYPEDEF_H__

#define   MAX_COUNT  10
#define   BUF_SIZE   100

typedef struct
{
  void (*function)(void *);
  void *argument;
}threadpool_task_t;

struct threadpool_t
{
  pthread_mutex_t lock;
  pthread_cond_t notify;
  pthread_t *threads;
  threadpool_task_t *queue;
  int threadCount;
  int queueSize;
  int head;
  int tail;
  int count;
  int shutdown;
  int started;
};

#endif ///< __TYPEDEF_H__
