#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


#include <sys/types.h>
#include <sys/wait.h>


int executeProgram(char * const program) {
  pid_t fork_result = fork();

  if (fork_result==0) {
    // This is the child
    int execvResult;
    char * const argv[] = {program, 0 };
    execvResult = execv(program, argv);
    
    // THIS LINE OF CODE NEVER REACHED IN CHILD
    // UNLESS THERE IS A SERIOUS PROBLEM
    
    perror("execv seems to have failed");
    printf("execvResult=%d\n", execvResult);
    exit(1);
  } else {
    
    // This is the parent
    // "else" unnecessary but helps readability

    int status;
    pid_t waitpid_result = waitpid(fork_result, &status, 0);
    printf("Successfully got the status back.  It was %d\n", status);
  }
}
 

int main() {

  const int BUFSIZE=2048;
  
  char str[BUFSIZE];
  
  int i;

  printf("Enter commands, end with CTRL/D\n");

  printf("> ");
  while(fgets(str, BUFSIZE, stdin) != NULL) {  // reads newline too

    executeProgram(str);
    
    printf("You typed: %s", str);
    printf("> ");
  }
  
  return 0;
  
  
}

