/* File: graphEvent.c
 * ------------------
 * This file provides the interaction
 * about shapes and arrows.
 */
#ifndef GRAPH_EVENT_H
#define GRAPH_EVENT_H

#include "arrow.h"
#include "shape.h"

#define DRAW_AREA_LEFT 0.88
#define DRAW_AREA_BOTTOM 0.9
#define DRAW_AREA_RIGHT (GetWindowWidth() - 0.2)
#define DRAW_AREA_HEIGHT (GetWindowHeight() - 0.43)

void GraphMouseEvent(int x, int y, int button, int event);

#endif /* GRAPH_EVENT_H */
