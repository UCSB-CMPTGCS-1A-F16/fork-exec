#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define HELLO_EXECUTABLE "/cs/faculty/pconrad/public_html/cs1a/15F/lect/12.01/hello"


int main() {

  printf("Before fork, FILE=%s LINE=%d FUNCTION=%s\n",
	 __FILE__, __LINE__, __FUNCTION__);
  pid_t result = fork();

  printf("After fork, result=%d FILE=%s LINE=%d FUNCTION=%s\n",
	 result, __FILE__, __LINE__, __FUNCTION__);


  if (result==0) {
    int execvResult;
    char * const argv[] = { HELLO_EXECUTABLE, 0 };
    execvResult = execv(HELLO_EXECUTABLE, argv);
    // THIS LINE OF CODE NEVER REACHED IN CHILD
    perror("execv seems to have failed");
    printf("execvResult=%d\n", execvResult);
    exit(1);
  }

  // parent

  sleep(30);

  printf("After sleep FILE=%s LINE=%d FUNCTION=%s\n",
	 __FILE__, __LINE__, __FUNCTION__);
  
  return 0;
}
