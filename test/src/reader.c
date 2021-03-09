/**
 * File  : reader.c
 * Author: Amsid S <amsit14@gmail.com>
 * Date  : 09.03.2021
 */


#include <stdio.h>
#include "dox/reader.h"

int main(void) {
   doxreader_chars_t text = { "test" };
   doxreader_t r = { DOXREADER_CHAR };
   doxreader_prepare(&r, &text);

   while (!r.isend(&r)) {
      printf("%c", r.get(&r));
   }
   puts("\0"); // blank new line.
}
