#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_tunez.h"

void print_nodes(struct song_node *sn){
  if(sn == NULL){
    return;
  }printf("song is %s\t artist is %s", sn -> name, sn -> artist);
}

struct song_node * make_node(char *n, char *a){
  struct song_node *x = malloc(sizeof(struct song_node));

  strncpy(x -> name, n, sizeof(x -> name));
  strncpy(x -> artist, a, sizeof(x -> artist));

  x -> next = NULL;
  
}

void print_list(struct song_node *sn){
  if(sn == NULL){
    return;
  }
  print_nodes(sn*);
  if(sn -> next != NULL){
    print_list(s -> next);
  }
}

struct song_node * insert_front(struct song_node *sn, char *n, char *a){
  struct song_node *new = make_shoes(n, a);
  new -> next = sn;
}

struct song_node * free_list(struct song_node *sn){
  if(sn -> next != NULL{
      free_list(sn-> next);
      free(sn);
      return NULL;
    }
}

struct song_node * remove_node(struct song_node *front, char *n, char *a){
  if(front -> next == NULL || front == NULL){
    return front;
  }

  if(strcmp(front -> next ->name, n) == 0 && strcmp(front -> next -> artist, a) == 0){
    struct song_node *hold = front -> next ->next;
    free(front -> next);

    front ->next = hold;
  }

  else{
    front = remove_node(front -> next, n, a);
  }

  return front;

}
    
    
int main(){
  make_node


    return 0;
}
