/**
 * File  : reader.h
 * Author: Amsid S <amsit14@gmail.com>
 * Date  : 09.03.2021
 */

#define EXPORT extern


typedef enum doxreader_kind {

   DOXREADER_CHAR,
   DOXREADER_FILE,
} doxreader_kind_t;

typedef struct doxreader_chars {
   char *text;
   int pos;
} doxreader_chars_t;


typedef struct doxreader {
   doxreader_kind_t kind;
   void *ptr;
   int (* peek)(struct doxreader *);
} doxreader_t;


EXPORT doxreader_t doxreader_prepare(doxreader_t *r, void *ch);
