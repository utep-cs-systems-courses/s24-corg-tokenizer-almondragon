#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  char user_input[101]; // an array of characters
  List* history = init_history(); // initializes linked list
  // while loop to iterate through program
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
    char *str = user_input;
    add_history(history,str);    
    if(user_input[0] == 'h' && user_input[1] == 'i' && user_input[2] == 's' && user_input[3] == 't' && user_input[4] == 'o' && user_input[5] == 'r' && user_input[6] == 'y' && user_input[7] == '\0'){
      print_history(history);
    }
    else if(user_input[0] == '!'){
      int id = 0;
      for(int i = 1; i < index; i++){
	id = id * 10 + (user_input[i]-48);
      }
      char *id_string = get_history(history, id);
      if(id_string != NULL){
	printf("%s\n",id_string);
      }
    } else{
    char **tokenized = tokenize(user_input);
    print_tokens(tokenized);
    free_tokens(tokenized);
    }
  }
}
