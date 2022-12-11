#include <stdio.h>
#include <pthread.h>

void* f_00(int* x)
{
	int i=*x;
	sleep(1);
	printf("f_00:%d\n", i);
	pthread_exit(0); 
}

void* f_01(int* x)
{
	int i=*x;
	sleep(1);
	printf("f_01:%d\n", i);
	pthread_exit(0); 
}

void* f_02(void* empty)
{
	pthread_t thread_id=pthread_self();
	printf("f_02\n");
	printf("thread_id=%u\n", (unsigned int)thread_id);
}

int main()
{
	{
		pthread_t thread_id_00;
		pthread_create(&thread_id_00, NULL, f_02, NULL);
	}
	{
		pthread_t thread_id_00;
		pthread_t thread_id_01;
		void* f_00();
		void* f_01();
		int arg_00=0;
		int arg_01=1;

		pthread_create(&thread_id_00, NULL, f_00, &arg_00);
		pthread_create(&thread_id_01, NULL, f_01, &arg_01);

		pthread_join(thread_id_00, NULL);
		pthread_join(thread_id_01, NULL);
	}

	return 0;
}
