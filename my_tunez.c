#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_tunez.h"
#include <time.h>

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
  print_nodes(sn);
  if(sn -> next != NULL){
    print_list(sn -> next);
  }
}

struct song_node * insert_front(struct song_node *sn, char *n, char *a){
  struct song_node *new = make_node(n, a);
  new -> next = sn;
}

struct song_node * insert_alphabetical(struct song_node *sn, char *n, char *a){
  struct song_node *new = make_node(n, a);

  if(sn == NULL){
    return new;
  }
  struct song_node *now = sn;
  struct song_node *previous_song = NULL;

  while(sn != NULL){
    if(compare(now, new) > 0){
      break;
    }else{
      previous_song = now;
      now  = now -> next;
    }
  }
}


struct song_node * free_list(struct song_node *sn){
  if(sn -> next != NULL){
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

  struct song_node * find_node(struct song_node *front, char *n, char *a){
  if(front -> next == NULL || front == NULL){
    return front;
  }

  if(strcmp(front -> next ->name, n) == 0 && strcmp(front -> next -> artist, a) == 0){
    struct song_node *ans = front -> next;
    return ans;
  }

  else{
    front = find_node(front -> next, n, a);
  }

  return front;

}

   struct song_node * find_first(struct song_node *front, char *a){
  if(front -> next == NULL || front == NULL){
    return front;
  }

  if(strcmp(front -> next -> artist, a) == 0){
    struct song_node *ans = front -> next;
    return ans;
  }

  else{
    front = find_first(front -> next, a);
  }
  return front;

}
    
struct song_node * random_song(struct song_node *sn){
  srand(time(NULL));
  int size = list_len(sn);

  int rand_num = rand() % size;

  int i = 0;
  while(i < rand_num) {
    sn = sn -> next;
    i +=1;
  }
  return sn;
}


int list_len(struct song_node *sn){
  if(sn == NULL){
    return 0;
  }return 1 + list_len(sn -> next);
}

int compare(struct song_node *x, struct song_node *y){
  if(strcasecmp(x ->artist, y-> artist) > 0){
    return(strcasecmp(x -> name, y -> name));
  }
  else{
    return -1;
  }
}

int main(){

  return 0;
}