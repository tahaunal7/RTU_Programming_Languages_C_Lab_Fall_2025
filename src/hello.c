
#include <stdio.h>

int main(int argc, char *argv[]) {
  // This is your first C program my friend
  printf("Hello, RTU World from C Lab in 2025!\n");
  printf("You passed %d argument(s).\n", argc - 1);
  printf("Hello from TAHA! \n");
  for (int i = 1; i < argc; ++i) {
    printf("  arg[%d] = %s\n", i, argv[i]);
  }
  return 0;
}
