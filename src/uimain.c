#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  char words[] = "hello my name is aitiana and this is a test";
  short length = 100;
  char **tokenized = tokenize(words);
  print_tokens(tokenized);

}
