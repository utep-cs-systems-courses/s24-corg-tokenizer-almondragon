#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main(){
  char user_input[101]; // an array of characters
  List* history = init_history(); // initializes linked list
  // while loop to iterate through program
  while(1){ 
    printf("> "); // prompting the user to input
    fgets(user_input,sizeof(user_input),stdin); // getting the user to input using fgets
    int index = 0; // will be used for length as well

    // setting the end of user_input to a zero terminator rather than a next line
    while(user_input[index] != '\0'){
      if(user_input[index] == '\n'){
	user_input[index] = '\0';
	break;
      }
      index++;
    }
    // to exit the program
    if(user_input[0] == 'e' && user_input[1] == '\0'){
      printf("Program ended\n");
      break;
    }
    // adding the user input to history
    char *str = user_input;
    add_history(history,str);

    // adding the history command
    if(user_input[0] == 'h' && user_input[1] == 'i' && user_input[2] == 's' && user_input[3] == 't' && user_input[4] == 'o' && user_input[5] == 'r' && user_input[6] == 'y' && user_input[7] == '\0'){
      print_history(history);
    }
    // adding the get history by ID command
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
      // tokenizing user input and freeing tokenized for the next input in program
    char **tokenized = tokenize(user_input);
    print_tokens(tokenized);
    free_tokens(tokenized);
    }
  }
}
