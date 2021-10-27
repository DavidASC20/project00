#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "my_tunez.h"
#include "library.h"

struct song_node ** create_library() {
  struct song_node ** library = calloc(27, sizeof(struct song_node *));
  return library;
}

struct song_node ** add_song(struct song_node ** library, struct song_node * sn){
    library[library_index(sn->artist)] = insert_alphabetical(library[library_index(sn->artist)], sn->artist, sn->name);
    return library;
}

int library_index(char *a) {
    if (!isalpha(a[0])){
      return 0;
    } else{
      return ((int) tolower(a[0])) - 96; 
    }
}

struct song_node * search_song(struct song_node ** library, char * a, char * n){
    return (find_node(library[library_index(a)], a, n));
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

void print_shuffle(struct song_node ** library){
    int i = 0;
    struct song_node * node = 0;
    while (i < 3) {
        int index = (rand() % 27);
        struct song_node * temp = random_song(library[index]);
        if(temp && !find_node(node,temp->artist, temp->name)){
            node = insert_front(node, temp->artist, temp->name);
            i++;
        }
    }
    while (node){
        struct song_node * temp = node;
        print_nodes(temp);
        node = node->next;
        free(temp);
    }
}

struct song_node ** delete_song(struct song_node ** library, char * a, char * n){
    library[library_index(a)] = remove_node(library[library_index(a)], a, n);
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
