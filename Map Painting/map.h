#ifndef MAP_H_
#define MAP_H_
#include "node.h"


/*
 * Map structure: Linked List
 * used to handle map. 
 * 
 * \n value: vector of linked lists. Each list will have a header.
 * \n value: max number of regions of a given map.
 * \n value: number of color 
*/


typedef struct MAP{
  NODE **header;
  int map_size;
  int colors;
  int *nEdges;
}MAP;

/*
 * Creates a Map instance
 *
 * \n param: color quantity 
 * \n param: number of regions of desired map.
 *
*/
MAP *newMap(int colors, int map_size);

/*
 * startup a Map structure using an input File.
 * 
 * \n param: Target Map Structure.
 * \n param: Auxiliar File for Startup.
 *
*/
void mapStartUp(MAP **tgt, FILE *aux);

/*
 * Release Map structure's memory.
 *
 * \n param: Target Map Structure
 *
*/
void freeMap(MAP **tgt);

/*
 * Print map Structure
 *
 * \n param: Target Map Structure
 *
*/
void printMap(MAP *tgt);



void paintMapBruteForce(MAP **tgt);
void paintMapMVR(MAP **tgt);
void paintMapLookAhead(MAP **tgt);


#endif
