#include <tokenizer.h>
#include <stdio.h>
#include <stdlib.h>

int space_char(char c){
  return (c == '\t' | c == ' ');
}

int non_space_char(char c){
  return !space_char(c);
}

char *token_start(char *str){
  if(*str == '\0'){
    return NULL;
  }
  while(non_space_char(*str)){
      str++;
  }
  return str;
}

char *token_terminator(char *token){

}
