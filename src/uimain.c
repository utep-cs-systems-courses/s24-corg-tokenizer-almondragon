#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  char words[] = "hello my name is aitiana and this is a test";
  short length = 100;
  char *copied = copy_str(words,length);
  printf("Original: %s\n", words);
  printf("Copied: %s\n", copied);
  return 0;

}
