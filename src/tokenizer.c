#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

int space_char(char c){
  // checks if the character is either a tab or space
  return  (c == '\t' || c == ' ');
}

int non_space_char(char c){
  // checks if the character is not a space or tab
  return !space_char(c);
}

char *token_start(char *str){
  // if the value of str is emtpy, null is returned
  if(*str== '\0') return NULL;
  // traverses through each character until a non space character is met,
  while(*str != '\0' && space_char(*str))
    str++;
  // a pointer to the starting character of the token
  return str;
}

char *token_terminator(char *token){
  // traverses token  until token is at the end or a space
  while (non_space_char(*token) && *token != '\0')
    token++; // moves to the next token pointer
  // returns token
  return token;
}

int count_tokens(char *str){
  int count = 0; // creates a count variable that will hold the number of tokens
  char *start = token_start(str); // set a dereference the start pointer to the returned character of token_start
  while(*start != '\0'){ // traverses the string until there are no more tokens
    count++; // count is increased for each token
    start = token_start(start); // moves to the next token
    start = token_terminator(start); // finds the next token
  }
  return count; // returns the value of count
}

char *copy_str(char *inStr, short len){
  // allocates the memory for the size of the string plus the '\0' terminator
  char *copied_str = (char *)malloc((len+1) * sizeof(char));
  // copies the characters of inStr to copied
  for(short i=0; i < len; i++){
    copied_str[i] = inStr[i];
  }
  // puts a terminator in the copy
  copied_str[len] = '\0';
  return copied_str;
  
}

char **tokenize(char* str){

}

void print_tokens(char **tokens){

}

void free_tokens(char **tokens){

}
