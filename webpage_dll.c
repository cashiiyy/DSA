#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char url[100];
    struct Node* prev;
    struct Node* next;
} Node;

// Pointer to track the current page the user is viewing
Node* currentPage = NULL;

// Helper function to create a new node
Node* createNode(const char* url) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->url, url);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to free forward history when a new path is taken
void clearForwardHistory(Node* node) {
    while (node != NULL) {
        Node* temp = node;
        node = node->next;
        free(temp);
    }
}

// 1. Visit a new page
void visitPage(const char* url) {
    Node* newNode = createNode(url);
    printf("Visiting: %s\n", url);

    // If it's the first page visited
    if (currentPage == NULL) {
        currentPage = newNode;
        return;
    }

    // Clear any existing forward history from the current position
    if (currentPage->next != NULL) {
        clearForwardHistory(currentPage->next);
    }

    // Link the new page to the current page
    currentPage->next = newNode;
    newNode->prev = currentPage;

    // Move the pointer to the new page
    currentPage = newNode;
}

// 2. Backward navigation
void goBack() {
    if (currentPage == NULL || currentPage->prev == NULL) {
        printf("Action Failed: No backward history available.\n");
        return;
    }
    currentPage = currentPage->prev;
    printf("Moved Back to: %s\n", currentPage->url);
}

// 3. Forward navigation
void goForward() {
    if (currentPage == NULL || currentPage->next == NULL) {
        printf("Action Failed: No forward history available.\n");
        return;
    }
    currentPage = currentPage->next;
    printf("Moved Forward to: %s\n", currentPage->url);
}

// Function to print the current state
void displayStatus() {
    if (currentPage == NULL) {
        printf("Browser status: No pages open.\n");
        return;
    }
    printf("Current Page: -> [ %s ] <-\n", currentPage->url);
}

int main() {
    printf("--- Simulating Web Browser Navigation ---\n\n");

    // 1. Visit initial pages
    visitPage("google.com");
    visitPage("github.com");
    visitPage("stackoverflow.com");
    displayStatus();
    printf("\n");

    // 2. Navigate backward twice
    goBack();
    goBack();
    displayStatus();
    printf("\n");

    // 3. Navigate forward once
    goForward();
    displayStatus();
    printf("\n");

    // 4. Visit a brand new page from the middle of history
    // (This should wipe out "stackoverflow.com" from the forward history)
    visitPage("wikipedia.org");
    displayStatus();
    printf("\n");

    // 5. Try going forward (should fail because history was overwritten)
    goForward();

    // 6. Go back to check if previous history is still intact
    goBack();
    displayStatus();

    // Clean up memory before exit
    if (currentPage != NULL) {
        // Move to the absolute head of the list
        while (currentPage->prev != NULL) {
            currentPage = currentPage->prev;
        }
        clearForwardHistory(currentPage);
    }

    return 0;
}
