#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_TITLE_LENGTH 100
#define MAX_CONTENT_LENGTH 1000

void create_post(const char *title, const char *content) {
    char filename[MAX_TITLE_LENGTH + 5];
    sprintf(filename, "%s.html", title);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Could not create file.\n");
        return;
    }

    fprintf(file, "<html>\n");
    fprintf(file, "<head>\n");
    fprintf(file, "<title>%s</title>\n", title);
    fprintf(file, "<base href=\"https://blog.hanetzok.net\">\n");
    fprintf(file, "<link rel=\"stylesheet\" href=\"/blog.css\">\n");
    fprintf(file, "</head>\n");
    fprintf(file, "<body>\n");
    fprintf(file, "<h1>%s</h1>\n", title);
    fprintf(file, "<p>%s</p>\n", content);
    fprintf(file, "</body>\n");
    fprintf(file, "</html>\n");

    fclose(file);

    printf("Post created.\n");
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

