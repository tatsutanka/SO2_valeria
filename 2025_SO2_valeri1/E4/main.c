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
  if (argc != 3) {
    printf("ERRO, formato %s,<Nome Arquivo> <Nome Link>", argv[0]);
    return 0;
  }
  // abrir o aquivo
  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    printf("The file is not opened");
    return 0;
  }
  struct tm *tm_info;

  char data_modificacao[50];
  struct stat info;
  struct stat linfo;
  stat(argv[1], &info);
  lstat(argv[2], &linfo);
  // Exibe tamanho em bytes
  printf("Tamanho: %lld bytes\n", (long long)info.st_size);

  // Número de links
  printf("Número de links: %lu\n", (unsigned long)info.st_nlink);

  // UID do dono
  printf("UID do dono: %u\n", info.st_uid);

  mode_t mode = info.st_mode;
  printf("Permissões: ");

  // Dono
  printf((mode & S_IRUSR) ? "r" : "-");
  printf((mode & S_IWUSR) ? "w" : "-");
  printf((mode & S_IXUSR) ? "x" : "-");

  // Grupo
  printf((mode & S_IRGRP) ? "r" : "-");
  printf((mode & S_IWGRP) ? "w" : "-");
  printf((mode & S_IXGRP) ? "x" : "-");

  // Outros
  printf((mode & S_IROTH) ? "r" : "-");
  printf((mode & S_IWOTH) ? "w" : "-");
  printf((mode & S_IXOTH) ? "x" : "-");

  printf("\n");
  // Última modificação formatada
  tm_info = localtime(&info.st_mtime);
  strftime(data_modificacao, sizeof(data_modificacao), "%d/%m/%Y %H:%M:%S",
           tm_info);
  printf("Última modificação: %s\n", data_modificacao);

  printf("-----------------Usanod Link----------------------\n");
  // Exibe tamanho em bytes
  printf("Tamanho: %lld bytes\n", (long long)linfo.st_size);

  // Número de links
  printf("Número de links: %lu\n", (unsigned long)linfo.st_nlink);

  // UID do dono
  printf("UID do dono: %u\n", linfo.st_uid);

  mode = linfo.st_mode;
  printf("Permissões: ");

  // Dono
  printf((mode & S_IRUSR) ? "r" : "-");
  printf((mode & S_IWUSR) ? "w" : "-");
  printf((mode & S_IXUSR) ? "x" : "-");

  // Grupo
  printf((mode & S_IRGRP) ? "r" : "-");
  printf((mode & S_IWGRP) ? "w" : "-");
  printf((mode & S_IXGRP) ? "x" : "-");

  // Outros
  printf((mode & S_IROTH) ? "r" : "-");
  printf((mode & S_IWOTH) ? "w" : "-");
  printf((mode & S_IXOTH) ? "x" : "-");

  printf("\n");
  // Última modificação formatada
  tm_info = localtime(&linfo.st_mtime);
  strftime(data_modificacao, sizeof(data_modificacao), "%d/%m/%Y %H:%M:%S",
           tm_info);
  printf("Última modificação: %s\n", data_modificacao);

  return EXIT_SUCCESS;
}
