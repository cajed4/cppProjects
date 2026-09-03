#include <iostream>
/*
 * Program purpose: This program grades a driver's license exam by comparing student answers to correct answers
 * Written by: Amare Johnson
 */

using namespace std;

// Function prototypes
void displayResults(int correctCount, int incorrectCount, int incorrectQuestions[], int incorrectCount);
bool isValidAnswer(char answer);

int main() {
    // Correct answers for the exam
    char correctAnswers[10] = {'A', 'D', 'B', 'B', 'C', 'B', 'A', 'B', 'C', 'D'};
    char studentAnswers[10];
    int incorrectQuestions[10]; // Array to store question numbers of incorrect answers
    int correctCount = 0;
    int incorrectCount = 0;

    // Input student answers
    cout << "Enter the student's answers for the 10 questions (A, B, C, D):" << endl;
    for (int i = 0; i < 10; i++) {
        char answer;
        cout << "Question " << (i + 1) << ": ";
        cin >> answer;

        // Input validation
        while (!isValidAnswer(answer)) {
            cout << "Invalid answer. Please enter A, B, C, or D: ";
            cin >> answer;
        }

        studentAnswers[i] = answer;

        // Check if the answer is correct
        if (studentAnswers[i] == correctAnswers[i]) {
            correctCount++;
        } else {
            incorrectQuestions[incorrectCount] = i + 1; // Store question number (1-based index)
            incorrectCount++;
        }
    }

    // Determine pass/fail
    bool passed = correctCount >= 7;

    // Display results
    cout << (passed ? "The student passed the exam." : "The student failed the exam.") << endl;
    displayResults(correctCount, incorrectCount, incorrectQuestions, incorrectCount);

    return 0;
}

// Function to display results
void displayResults(int correctCount, int incorrectCount, int incorrectQuestions[], int incorrectCountDisplay) {
    cout << "Total correctly answered questions: " << correctCount << endl;
    cout << "Total incorrectly answered questions: " << incorrectCount << endl;

    if (incorrectCountDisplay > 0) {
        cout << "Question numbers of incorrectly answered questions: ";
        for (int i = 0; i < incorrectCountDisplay; i++) {
            cout << incorrectQuestions[i] << " ";
        }
        cout << endl;
    }
}

// Function to validate answers
bool isValidAnswer(char answer) {
    return answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D';
}


