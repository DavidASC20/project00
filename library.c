#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "my_tunez.h"
#include "library.h"

struct song_node ** make_library() {
  struct song_node ** library = calloc(27, sizeof(struct song_node *));
  return library;
}

struct song_node ** add_list(struct song_node ** library, struct song_node * sn){
    library[library_index(sn->artist)] = insert_alphabetical(library[library_index(sn->artist)], sn->name, sn->artist);
    return library;
}

int library_index(char *a) {
    if (!isalpha(a[0])){
      return 0;
    } else{
      return ((int) tolower(a[0])) - 96; 
    }
}

struct song_node * search_song(struct song_node ** library, char * n, char * a){
    return (find_node(library[library_index(a)], n, a));
    
}

struct song_node * search_artist(struct song_node ** library, char * a){
    return (find_first(library[library_index(a)], a));
}

void print_letter(struct song_node ** library, char letter){
    char * p = &letter;
    struct song_node * letter_list = library[library_index(p)];
    printf("%c: ", letter);
    print_list(letter_list);
}

void print_artist(struct song_node ** library, char * a){
    struct song_node * letter = library[library_index(a)];
    printf("%s: [", a);
    while (letter) {
        if (!strcmp(letter->artist, a)) {
            printf("{%s, %s} |", letter->artist, letter-> name);
        }
        letter = letter->next;
    }
    printf(" ]\n");
}

void print_library(struct song_node ** library){
    if (library[0]) {
        printf("Other: ");
        print_list(library[0]);
    }
    int i = 1;
    while(i < 27){
        if (library[i]) {
            printf("%c: ", (char) (i + 96));
            print_list(library[i]);   
        }
        i++;
    }
}



struct song_node ** delete_song(struct song_node ** library, char * n, char * a){
    library[library_index(a)] = remove_node(library[library_index(a)], n, a);
    return library;
}

struct song_node ** clear_library(struct song_node ** library){
    int i = 0;
    while(i < 27){
        library[i] = free_list(library[i]);
        i++;
    }
    return library;
}


void shuffle(struct song_node ** library){
  int num = 3;
  int index;
  struct song_node * sn;

  while(num--){
    index = rand() %27;
    while ((sn = random_song(library[index])) == NULL) index = rand() %27;
    print_nodes(sn);
    printf("\n");
  }
}