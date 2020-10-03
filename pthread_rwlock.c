#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int num = 0;
pthread_rwlock_t rwlock;

void *rd_fun(void *arg)
{
	int i = (int)arg;
	while(1)
		{
			pthread_rwlock_rdlock(&rwlock);
			printf("=======%dth==========num is %d\n",i+1,num);
			pthread_rwlock_unlock(&rwlock);
			usleep(200000);
		}
	return NULL;
}

void *wr_fun(void *arg)
{
	int i = (int)arg;
	int t;
	while(1)
		{
			pthread_rwlock_wrlock(&rwlock);
			t = num;
			usleep(10000);
			printf("---%dth-----num: %d after write: num is %d\n",i+1,t,++num);
			pthread_rwlock_unlock(&rwlock);
			usleep(100000);
		}
	return NULL;
}

int main()
{
	int i,ret;
	ret = pthread_rwlock_init(&rwlock,NULL);
	if(ret != 0)
		{
			fprintf(stderr, "init rwlock error:%s\n",strerror(ret));
			pthread_exit(NULL);
		}
	pthread_t tid[8];
	for(i = 0; i < 3; i++)
		{
			ret = pthread_create(&tid[i],NULL,wr_fun,(void *)i);
			if(ret != 0)
				{
					fprintf(stderr, "create rd_thread error:%s\n",strerror(ret));
					pthread_exit(NULL);
				}

		}
	for(i = 0; i < 5; i++)
		{
			ret = pthread_create(&tid[i+3],NULL,rd_fun,(void *)i);
			if(ret != 0)
				{
					fprintf(stderr, "create wr_thread error:%s\n",strerror(ret));
					pthread_exit(NULL);
				}
		}
	for(i = 0; i < 8; i++)
		{
			ret = pthread_join(tid[i],NULL);
			if(ret != 0)
				{
					fprintf(stderr, "pthread_join error:%s\n",strerror(ret));
					pthread_exit(NULL);
				}
		}
	pthread_rwlock_destroy(&rwlock);
	return 0;
}
