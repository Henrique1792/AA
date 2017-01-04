#ifndef NODE_H_
#define NODE_H_
#include "utils.h"
#define IsHeader(x) (x==HEADER ? 1:0)

/*
 *Node Structure for
 *each region applied.
 *
 *\n param: Region Name
 *\n param: color painted
 *\n param: next node structure
 * 
*/
typedef struct NODE{
  char* name;
  int color;
  int header;
  struct NODE *nxt;
}NODE;

/*
 * Create a NODE structure.
 *
 * @return: NODE structure.
 *
*/
NODE *newNode();

/*
 * Create and plug a new Node structure
 *
 * \n param: Initial Node.
 * \n param: name for new Node
*/
void plugNode(NODE *tgt, char *name);

/*
 * Pop a Node Structure from a list.
 * 
 * \n param: initial structure
 *
 * @return: Node Structure.
 *
*/
NODE *popNode(NODE *tgt);

/*
 * Release Node structure
 * \n param: Target Node Structure
*/
void freeNode(NODE **tgt);

/*
 * Print a Node.
 *
 * \n param: Target node.
 *
*/
void printNode(NODE *tgt);

/*
 * Print Every node on a list.
 *
 * \n param: Start node.
*/
void printAllNodes(NODE *start);



void paintNode(NODE *tgt, int color);


#endif
