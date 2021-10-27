# include <stdio.h>
# include <strings.h>
# include <time.h>
# include <stdlib.h>
# include "library.h"
# include "my_tunez.h"

int main(){
    printf("Linked List \n\n");
    printf("\n===============\n");
    struct song_node *front = NULL;
    printf("\nTesting print list:\n");
    front = insert_alphabetical(front, "paranoid android", "radiohead");
    front = insert_alphabetical(front, "thunderstruck", "ac/dc");
    front = insert_alphabetical(front, "alive", "pearl jam");
    front = insert_alphabetical(front, "yellow ledbetter", "pearl jam");
    front = insert_alphabetical(front, "street spirit (fade out)", "radiohead");
    front = insert_alphabetical(front, "time", "pink floyd");
    front = insert_alphabetical(front, "even flow", "pearl jam");
    print_list(front);
    printf("\n===============\n");

    printf("\nTesting print_nodes:");
    print_nodes(front);
    printf("\n===============\n");

    printf("\nTesting find_node\n");
    front = find_node(front, "alive", "pearl jam");
    print_nodes(front);
    print_list(front);
    printf("\n===============\n");

    printf("\nTesting find_first\n");
    print_nodes(find_first(front, "pink floyd"));
    printf("\n===============\n");
    
    printf("\nTesting compare\n");
    struct song_node *a = make_node("aaa", "aaa");
    struct song_node *b = make_node("bbb", "bbb");
    struct song_node *c = make_node("ccc", "ccc");
    printf("comparing a to b\n");
    printf("%d\n", compare(a, b));
    printf("comparing b to c\n");
    printf("%d\n", compare(b, c));
    printf("comparing b to b\n");
    printf("%d\n", compare(b, b));
    printf("comparing b to a\n");
    printf("%d\n", compare(b, a));
    printf("comparing c to b\n");
    printf("%d\n", compare(c, b));
    printf("\n===============\n");
    
    printf("\nTesting random\n");
    print_list(front);
    printf("\n\nList for Reference\n\n");
    print_nodes(random_song(front));
    printf("\n===============\n");

    printf("\nTesting remove_node, removing thunderstruck and time\n");
    print_list(front);
    printf("\nremove thunderstruck\n");
    front = remove_node(front, "thunderstruck", "ac/dc");
    print_list(front);
    printf("\nremove time\n");
    front = remove_node(front, "time", "pink floyd");
    print_list(front);
    printf("\n===============\n");

    printf("\nTesting free\n");
    print_list(front);
    front = free_list(front);
    printf("\n\nFreed\n");
    print_list(front);
    printf("\n===============\n");










    printf("Library Tests \n\n");
    printf("\n===============\n");
    struct song_node **library = make_library();
    struct song_node * a1 = insert_front(0, "thunderstruck", "ac/dc");
    struct song_node * a2 = insert_front(0, "alive", "pearl jam");
    struct song_node * a3 = insert_front(0, "even flow", "pearl jam");
    struct song_node * a4 = insert_front(0, "yellow ledbetter", "pearl jam");
    struct song_node * a5 = insert_front(0, "time", "pink floyd");
    struct song_node * a6 = insert_front(0, "peaches", "presidents of the united states of america");
    struct song_node * a7 = insert_front(0, "street spirit (fade out)", "radiohead");
    struct song_node * a8 = insert_front(0,  "paranoid android", "radiohead");

    printf("\nTesting print_letter: \n");
    print_letter(library, 'p');
    printf("\n===============\n");

    printf("\nTesting print_library: \n");
    print_library(library);
    printf("\n===============\n");

    add_list(library, a1);
    add_list(library, a2);
    add_list(library, a3);
    add_list(library, a4);
    add_list(library, a5);
    add_list(library, a6);
    add_list(library, a7);
    add_list(library, a8);


    printf("\nTesting print_letter: \n");
    print_letter(library, 'p');
    printf("\n===============\n");


    printf("\nTesting print_library: \n");
    print_library(library);
    printf("\n===============\n");

    printf("\nTesting search_song\n");
    print_nodes(search_song(library, "alive", "pearl jam"));
    printf("\n===============\n");

    printf("\nTesting search_song\n");
    print_nodes(search_song(library, "bruh moment", "silento"));
    printf("\n===============\n");

    printf("\nTesting find artist\n");
    print_list(search_artist(library, "pearl jam"));
    printf("\n===============\n");

    printf("\nTesting find artist\n");
    print_list(search_artist(library, "pink floyd"));
    printf("\n===============\n");

    printf("\nTesting remove song\n");
    printf("\nBefore\n");
    print_library(library);
    delete_song(library, "alive", "pearl jam");
    printf("\nAfter\n");
    print_library(library);
    printf("\n===============\n");
   
    printf("\nTesting clear library\n");
    clear_library(library);
    print_library(library);
    printf("\n===============\n");

    add_list(library, a1);
    add_list(library, a2);
    add_list(library, a3);
    add_list(library, a4);

    printf("\nTesting shuffle, added songs again\n");
    printf("Before Shuffle");
    print_library(library);
    printf("\nAfter Shuffle\n");
    shuffle(library);
    printf("\n===============\n");


   
    
}
