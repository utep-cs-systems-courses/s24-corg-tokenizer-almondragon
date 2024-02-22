#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  char user_input[101];
  while(1){
  printf("> ");
  fgets(user_input,sizeof(user_input),stdin);
  int index = 0;
  while(user_input[index] != '\0'){
    if(user_input[index] == '\n'){
      user_input[index] = '\0';
      break;
    }
    index++;
  }
  if(user_input[0] == 'e' && user_input[1] == '\0'){
    printf("Program ended\n");
    break;
  }
  char **tokenized = tokenize(user_input);
  print_tokens(tokenized);
  }
}
