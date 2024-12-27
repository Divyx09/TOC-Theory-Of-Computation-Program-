#include <stdio.h>
#include <string.h>

int main() {
    int numInputs, numStates, numFinalStates;
    char initState;
    char input[10], state[10], finalStates[10];
    char transitionTable[10][10][100];
    
    printf("Enter number of symbols (alphabet size): ");
    scanf("%d", &numInputs);
    
    printf("Enter number of states: ");
    scanf("%d", &numStates);
    
    printf("Enter the symbols (characters): \n");
    for (int i = 0; i < numInputs; i++) {
        printf("Symbol %d: ", i + 1);
        scanf(" %c", &input[i]);
    }
    
    printf("Enter the states (characters): \n");
    for (int i = 0; i < numStates; i++) {
        printf("State %d: ", i + 1);
        scanf(" %c", &state[i]);
    }
    
    printf("Enter transition table (for each input symbol): \n");
    for (int i = 0; i < numInputs; i++) {
        for (int j = 0; j < numStates; j++) {
            printf("Transition from state '%c' on symbol '%c': ", state[j], input[i]);
            scanf(" %s", transitionTable[i][j]);
        }
    }
    
    printf("Enter the initial state: ");
    scanf(" %c", &initState);
    
    printf("Enter number of final states: ");
    scanf("%d", &numFinalStates);
    printf("Enter the final states: \n");
    for (int i = 0; i < numFinalStates; i++) {
        printf("Final state %d: ", i + 1);
        scanf(" %c", &finalStates[i]);
    }
    
    char dfaStates[100][10];  
    int dfaStateCount = 0;
    
    char startStateSet[2] = {initState, '\0'};
    strcpy(dfaStates[dfaStateCount++], startStateSet);  
    
    for (int i = 0; i < dfaStateCount; i++) {
        for (int j = 0; j < numInputs; j++) {
            char newStateSet[10] = {0};  
            
            for (int k = 0; dfaStates[i][k] != '\0'; k++) {
                char currentState = dfaStates[i][k];
                
                for (int l = 0; l < numStates; l++) {
                    if (currentState == state[l]) {
                        strcat(newStateSet, transitionTable[j][l]);  
                    }
                }
            }
            
            if (strlen(newStateSet) > 0) {
                int exists = 0;
                for (int k = 0; k < dfaStateCount; k++) {
                    if (strcmp(dfaStates[k], newStateSet) == 0) {
                        exists = 1;
                        break;
                    }
                }
                
                if (!exists) {
                    strcpy(dfaStates[dfaStateCount++], newStateSet);
                }
            }
        }
    }
    
    printf("\nDFA States (each state is a set of NFA states):\n");
    for (int i = 0; i < dfaStateCount; i++) {
        printf("State %d: %s\n", i, dfaStates[i]);
    }
    
    return 0;
}
