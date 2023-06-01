/*
    Copyright (C) 2023  Markus Hanetzok

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "config.h"

#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1000

void print_head() {
    printf("<!DOCTYPE html>\n<html>\n<head>\n"
    "<meta charset=\"UTF-8\">\n"
    "<base href=\"%s\">\n"
    "<title>%s</title>\n"
    "<link rel=\"stylesheet\" href=\"%s\">\n"
    "</head>\n", url, title, css);
}
void create_post(const char *title, const char *content) {
    print_head();
    printf("<body>\n");
    printf("<h1>%s</h1>\n", title);
    printf("<p>%s</p>\n", content);
    printf("</body>\n");
    printf("</html>\n");
}

int main() {
    char input[MAX_TITLE_LENGTH + MAX_CONTENT_LENGTH + 2];

    if (!isatty(fileno(stdin))) {
        fgets(input, sizeof(input), stdin);
    } else {
        printf("Enter title and content (separated by |): ");
        fgets(input, sizeof(input), stdin);
    }

    char *separator = strchr(input, '|');
    if (separator == NULL) {
        printf("No separator found.\n");
        return 1;
    }

    *separator = '\0';

    char *title = input;
    char *content = separator + 1;

    content[strcspn(content, "\n")] = '\0';

    create_post(title, content);

    return 0;
}

