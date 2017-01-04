#pragma once


typedef struct {
  int x;
  int y;
  int z;
  int face;
  char text[MAX_SIGN_LENGTH];
} Sign;

typedef struct {
  unsigned int capacity;
  unsigned int size;
  Sign *data;
} SignList;
