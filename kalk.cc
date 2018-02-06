#include "kalk.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* Buffer for preloaded instructions, see gram/lexer */
extern char *preloaded_instructions;

int main (int argc, char **argv) {
  char buf[256];
  int i, bufready = 1, flag;
  unsigned int buflen;

  while ( (flag = getopt(argc, argv, "h")) > 0 )
    printf(
        "\n"
        "KAreL's KalCulator V%s (yeah.. good names are hard to find)\n"
        "Copyright (c) ICCE/Karel Kubat 1994 ff.. All rights reserved.\n"
        "Another MegaHard [tm] production!\n"
        "\n"
        "Usage: kalk [-h] [expression]\n"
        "   or: kalk [-h]\n"
        "Flag -h prints this banner.\n"
        "The optional expression can be given to 'preload' the input.\n"
        "\n"
        "Type 'help' to see what you can do now.\n"
        "\n"
        , VER);

  /* Create the preload buffer if argc/argv given. */
  if (argc > 1) {
    for (i = 1; i < argc; ++i) {
      if (i == 1)
        buflen = strlen(argv[i]);
      else
        buflen += strlen(argv[i]) + 1;

      if ( (buflen >= sizeof(buf) - 2) ) {
        puts("warning [kalk] expression preload exceeds 256 chars, ignored");
        bufready = 0;
        break;
      }

      if (i == 1)
        strcpy(buf, argv[i]);
      else {
        strcat(buf, " ");
        strcat(buf, argv[i]);
      }
    }

    if (bufready) {
      strcat(buf, "\n");
      preloaded_instructions = buf;
    }
  }


  register int
      ret = yyparse ();

  putchar ('\n');
  return (ret);
}
