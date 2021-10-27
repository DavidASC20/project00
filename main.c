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

    printf("\nTesting print_letter\n");
    printf("\n===============\n");
}