#include <unistd.h>
#include <stdio.h>


int main() {

  printf("Before fork, FILE=%s LINE=%d FUNCTION=%s\n",
	 __FILE__, __LINE__, __FUNCTION__);
  sleep(10);

  pid_t result = fork();


  
  printf("After fork, result=%d FILE=%s LINE=%d FUNCTION=%s\n",
	 result, __FILE__, __LINE__, __FUNCTION__);

  sleep(10);

  printf("After sleep FILE=%s LINE=%d FUNCTION=%s\n",
	 __FILE__, __LINE__, __FUNCTION__);
  
  return 0;
}
