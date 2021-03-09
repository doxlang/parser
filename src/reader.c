/**
 * File  : reader.c
 * Author: Amsid S <amsit14@gmail.com>
 * Date  : 09.03.2021
 */


#include "dox/reader.h"

static int doxreader_chars_peek(doxreader_t *r) {
   doxreader_chars_t *self = (doxreader_chars_t *)r->ptr;
   return self->text[self->pos];
}


static int doxreader_chars_get(doxreader_t *r) {
   doxreader_chars_t *self = (doxreader_chars_t *)r->ptr;
   int c = self->text[self->pos];
   if (c != '\0') self->pos++;
   return c;
}


static int doxreader_chars_isend(doxreader_t *r) {
   doxreader_chars_t * self = (doxreader_chars_t *)r->ptr;
   return self->text[self->pos] == '\0';
}

doxreader_t doxreader_prepare(doxreader_t *r, void *subject) {
   switch (r->kind) {
      case DOXREADER_CHAR:
         r->ptr = subject;
         ((doxreader_chars_t *)r->ptr)->pos = 0;
         r->peek  = &doxreader_chars_peek;
         r->get   = &doxreader_chars_get;
         r->isend = &doxreader_chars_isend;
         break;
      case DOXREADER_FILE:
         break;
   }
   return *r;
}
