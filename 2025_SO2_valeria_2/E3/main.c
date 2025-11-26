#include <fcntl.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  if (argc < 2) {
    fprintf(stderr, "Uso: %s <Caminho para navegar um subdiretorio>\n",
            argv[0]);
    return 1;
  }
  int status;
  char s[100];
  printf("path: %s\n", getcwd(s, 100));
  chdir(argv[1]);
  printf("new path: %s\n", getcwd(s, 100));
  return 0;
}
