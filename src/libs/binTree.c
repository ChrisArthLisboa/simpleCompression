
#include <time.h>
#include <stdbool.h>

struct Node {

    char* pattern;
    unsigned int frequency;

    struct Node* left_node;
    struct Node* right_node;

} typedef node;

/*
 * traverse the array passing the callback to each node
 * if callback returns 1 it will stop and give an error
 *
 * callback receives the node
 */
void binTraversal(node parent_node, int callback(node receiver) ) {

    bool condition_left = parent_node.left_node != NULL;
    bool condition_right = parent_node.right_node != NULL;


    if (condition_right && condition_left) {
        callback(parent_node);
    } else {
        return;
    }

    if (condition_left) {

        binTraversal(*parent_node.left_node, callback);
        callback(*parent_node.left_node);

    } 

    if (condition_right) {

        binTraversal(*parent_node.right_node, callback);
        callback(*parent_node.right_node);

    }


}


