#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Wishlist structure
typedef struct {
    char *data;
    size_t length;
    size_t capacity;
} wishlist;

// Function to create a wishlist from a given string
wishlist create_wishlist(const char *l) {
    wishlist w;
    w.length = strlen(l);
    w.capacity = (w.length == 0) ? 1 : 2 * w.length;
    w.data = (char *)malloc(w.capacity * sizeof(char));
    if (w.data == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    strcpy(w.data, l);
    return w;
}

// Function to print the wishlist to the console
void print_wishlist(const wishlist *w) {
    printf("%s", w->data);
}

// Function to destroy the wishlist and free allocated memory
void destroy_wishlist(wishlist *w) {
    free(w->data);
    w->length = 0;
    w->capacity = 0;
}

// Function to append additional presents to the wishlist
int append_presents(wishlist *w, const char *l) {
    size_t new_length = w->length + strlen(l);

    // Check if capacity needs to be increased
    while (new_length >= w->capacity) {
        w->capacity *= 2;
        w->data = (char *)realloc(w->data, w->capacity * sizeof(char));
        if (w->data == NULL) {
            fprintf(stderr, "Memory reallocation error\n");
            exit(EXIT_FAILURE);
        }
    }

    // Append the new presents to the wishlist
    strcat(w->data, l);
    w->length = new_length;

    return 0;
}

size_t find_present(const wishlist *w, size_t present_pos) {
    size_t current_pos = 0;
    size_t present_start = 0;

    while (current_pos < w->length && present_pos > 0) {
        if (w->data[current_pos] == '\n') {
            present_start = current_pos + 1;
            present_pos--;
        }

        current_pos++;
    }

    return present_start;
}

wishlist cut_wishlist(wishlist *w, size_t count) {
    wishlist new_wishlist;

    // Initialize the new wishlist
    new_wishlist.length = 0;
    new_wishlist.capacity = w->capacity;
    new_wishlist.data = w->data;

    // Find the position to cut the original wishlist
    size_t cut_position = find_present(w, count);

    if (cut_position != (size_t)-1) {
        // Create a new wishlist from the cut position to the end
        new_wishlist.length = w->length - cut_position;
        new_wishlist.data = w->data + cut_position;

        // Truncate the original wishlist
        w->data[cut_position] = '\0';
        w->length = cut_position;
    }

    return new_wishlist;
}

int add_present(wishlist *w, const char *present, size_t position) {
    size_t present_start = find_present(w, position);

    if (present_start != (size_t)-1) {
        // Shift the existing content to make space for the new present
        size_t present_length = strlen(present);
        size_t shift_length = w->length - present_start + 1;  // Including the null terminator

        // Move the characters one by one
        for (size_t i = w->length; i >= present_start + present_length; i--) {
            w->data[i] = w->data[i - present_length];
        }

        // Copy the new present to the specified position
        for (size_t i = 0; i < present_length; i++) {
            w->data[present_start + i] = present[i];
        }

        w->length += present_length + 1;  // Including the new null terminator

        return 0;
    } else {
        // Invalid position, cannot add present
        return -1;
    }
}

int main() {
    // Example usage
    const char *initial_wishlist = "Toy\nChocolate\nBook\n";
    wishlist my_wishlist = create_wishlist(initial_wishlist);

    // Print the original wishlist
    printf("Original Wishlist:\n");
    print_wishlist(&my_wishlist);

    // Append additional presents
    const char *additional_presents = "Game\nMusic\n";
    append_presents(&my_wishlist, additional_presents);

    // Print the updated wishlist
    printf("\nUpdated Wishlist:\n");
    print_wishlist(&my_wishlist);

    // Destroy the wishlist and free memory
    destroy_wishlist(&my_wishlist);

    return 0;
}
