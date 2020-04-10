#include "encrypt.h"
#include "checksum.h"

#include <stdio.h>

int main()
{
  char message[] = "Hello and welcome!";
  printf("Checksum: %i\n", checksum(message));
  encrypt(message);
  printf("Encrypted to '%s'\n", message);
  printf("Checksum: %i\n", checksum(message));
  encrypt(message);
  printf("Decrypted to '%s'\n", message);
  printf("Checksum: %i\n", checksum(message));
  return 0;
}
