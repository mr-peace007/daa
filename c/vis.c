#include <stdio.h>
#include <string.h>

// Function to provide health tips based on user input
void provideHealthTips(char* input) {
    // Check for specific keywords in the user input
    if (strstr(input, "nutrition") != NULL) {
        printf("Maintaining a balanced diet is essential for good health. Include a variety of fruits, vegetables, whole grains, lean proteins, and healthy fats in your meals.\n");
    } else if (strstr(input, "exercise") != NULL) {
        printf("Regular exercise is crucial for maintaining a healthy body. Aim for at least 150 minutes of moderate-intensity aerobic activity or 75 minutes of vigorous activity every week.\n");
    } else if (strstr(input, "hydration") != NULL) {
        printf("Staying hydrated is important for your overall well-being. Drink an adequate amount of water throughout the day to keep your body hydrated.\n");
    } else {
        printf("I'm sorry, I don't have information on that topic. How can I assist you further?\n");
    }
}

// Function to handle greetings
void handleGreeting(char* input) {
    // Check for common greetings in the user input
    if (strstr(input, "hi") != NULL || strstr(input, "hello") != NULL) {
        printf("Hello! How can I assist you today?\n");
    } else if (strstr(input, "how are you") != NULL) {
        printf("I'm a computer program, so I don't have feelings, but thank you for asking! How can I assist you?\n");
    } else {
        printf("Hi! How can I assist you today?\n");
        
    }
}

int main() {
    char input[100];

    printf("Welcome to the Health Chatbot!\n");
    printf("How can I assist you today?\n");

    // Start the conversation loop
    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Remove the trailing newline character
        input[strcspn(input, "\n")] = '\0';

        // Check if the user wants to exit
        if (strcmp(input, "exit") == 0) {
            printf("Thank you for using the Health Chatbot. Take care of your health!\n");
            break;
        }

        // Handle greetings
        handleGreeting(input);

        // Provide health tips based on user input
        provideHealthTips(input);
    }

    return 0;
}
