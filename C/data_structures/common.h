#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <syslog.h>
#define READ_SIZE 32
#define DATA_SIZE 100
#define NEW_LINE 10
#define EOF_new 1
#define TOTAL_POKEMON 718
#define WORDSIZE 20
#define ALPHABETS 26

static uint8_t* fname="pokemon_raw.txt";
