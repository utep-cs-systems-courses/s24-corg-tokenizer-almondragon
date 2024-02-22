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
  return copied_str; // returns copied_str
  
}

char **tokenize(char* str){
  // set the variable number_tokens to the number of tokens in the array
  int num_tokens = count_tokens(str);
  
  // allocate memory to the array of pointers to the tokens
  char **all_tokens = malloc((num_tokens + 1) * sizeof(char*));

  // checks if memory was allocated and prints error statment if not
  if(all_tokens == NULL){
    printf("Memory failed to allocate to all_tokens");
    return NULL;
  }
  for(int i = 0; i < num_tokens; i++){ // iterates through each token
    str = token_start(str); // the pointer is set to the next available pointer
    char *end = token_terminator(str); // sets a pointer end to the end of the token
    int len = end - str; // length of current token
    all_tokens[i] = malloc(sizeof(char) * (len+1)); // sets each index of the array to the
    // size of the current token
    // checks if memory was properly allocated to each index of the all_tokens array, free ow
    if(all_tokens[i] == NULL){
      printf("Memory failed to allocate to current token");
      // frees all others index
      for(int f = 0; f<i;f++){
	free(all_tokens[i]);
      }
      free(all_tokens);
      return NULL;
    }
    char *copied = copy_str(str,len); // set to a copy of the current token
    for (int z = 0; z < len; z++){ // traversing the characters of the current token
      all_tokens[i][z] = copied[z];
    }
    free(copied);
    all_tokens[i][len] = '\0'; // puts a zero-terminator
    str = token_start(end); // str is now set to point to the next token    
  }
  all_tokens[num_tokens] = NULL;
  return all_tokens;


}

void print_tokens(char **tokens){
  int index = 0;
  while(tokens[index] != NULL){
    printf("%s\n", tokens[index]);
    index++;
  }
}

void free_tokens(char **tokens){
  int index = 0;
  while(tokens[index] != NULL){
    free(tokens[index]);
    index++;
  }
  free(tokens);
}
