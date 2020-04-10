#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

#include <random>

#include <pthread.h>
#include <semaphore.h>

int buf[100];
size_t head;
size_t tail;
pthread_mutex_t mutex;
sem_t sem;

void *threadFuncW(void *)
{
  pthread_mutex_lock(&mutex);

  buf[head++] = rand() % 10;
  head %= 100;

  sem_post(&sem);

  pthread_mutex_unlock(&mutex);

  return nullptr;
}

void *threadFuncR(void *)
{
  while (true)
    {
      cout << "waiting..." << endl;

      sem_wait(&sem);

      pthread_mutex_lock(&mutex);

      cout << buf[tail++] << endl;
      tail %= 100;

      pthread_mutex_unlock(&mutex);
    }
  return nullptr;
}

void error(const char *msg)
{
  cout << msg << endl;
  exit(1);
}

int main()
{
  head = tail = 0;

  if (pthread_mutex_init(&mutex, nullptr) != 0)
    error("Cann't init mutex.");

  if (sem_init(&sem, 0, 1) != 0)
    error("Cann't init semaphore.");

  pthread_t threads[100];
  for (size_t i = 0; i != 100; ++i)
    {
      if (pthread_create(&threads[i], nullptr, threadFuncW, nullptr) == -1)
	error("Cann't create a thread.");
    }

  pthread_t reader;
  if (pthread_create(&reader, nullptr, threadFuncR, nullptr) == -1)
    error("Cann't create a thread.");

  for (size_t i = 0; i != 100; ++i)
    {
      if (pthread_join(threads[i], nullptr) == -1)
	error("Cann't join to thread.");
    }

  if (pthread_join(reader, nullptr) == -1)
    error("Cann't join to thread.");

  return 0;
}
