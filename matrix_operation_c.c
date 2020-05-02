#include <stdio.h>
void enterData(int first[][10], int second[][10], int r1, int c1, int r2, int c2);
void multiplyMatrices(int first[][10], int second[][10], int multResult[][10], int r1, int c1, int r2, int c2);
void display(int mult[][10], int r1, int c2);
void scalarMultiply(int mult[][10], int scalar, int r, int c);

int main() {
	
	char operator;
	int first[10][10], second[10][10], mult[10][10], r1, c1, r2, c2;
	int r, c, scalar, a[100][100], b[100][100], sum[100][100], i, j;
	
	printf("Enter an operator (+, -, *, /,s): ");
    scanf("%c", &operator);
    // printf("Enter two operands: ");
    // scanf("%lf %lf",&n1, &n2);
	switch(operator)
    {
	case '*':
		printf("Enter rows and column for the first matrix: ");
		scanf("%d %d", &r1, &c1);
		printf("Enter rows and column for the second matrix: ");
		scanf("%d %d", &r2, &c2);

		// Taking input until columns of the first matrix is equal to the rows of the second matrix
		while (c1 != r2) {
			printf("Error! First Coulumn must be equal to second row. Enter rows and columns again.\n");
			printf("Enter rows and columns for the first matrix: ");
			scanf("%d%d", &r1, &c1);
			printf("Enter rows and columns for the second matrix: ");
			scanf("%d%d", &r2, &c2);
		}

		// Function to take matrices data
		enterData(first, second, r1, c1, r2, c2);

		// Function to multiply two matrices.
		multiplyMatrices(first, second, mult, r1, c1, r2, c2);

		
		
		printf("\nMultiplication of two matrices: \n");
		// printing the input
		printf("|\t");
		for (j = 0; j < c; ++j){printf("\t");}
		printf("|\n");
		for (i = 0; i < r; ++i){
			printf("|\t");
			for (j = 0; j < c; ++j) {
				printf("%d\t", a[i][j]);
				if (j == c - 1) {
					printf("|\n");
				}
			}
		}
			printf("|\t");
		for (j = 0; j < c; ++j){printf("\t");}
		printf("|\n");   
		
		printf("\t+\t\n");
		
		printf("|\t");
		for (j = 0; j < c; ++j){printf("\t");}
		printf("|\n");
		for (i = 0; i < r; ++i){
			printf("|\t");
			for (j = 0; j < c; ++j) {
				printf("%d\t", b[i][j]);
				if (j == c - 1) {
					printf("|\n");
				}
			}
		}
			printf("|\t");
		for (j = 0; j < c; ++j){printf("\t");}
		printf("|\n");  
			
		printf("\t=\t\n");
		printf("|\t");
		for (j = 0; j < c; ++j){printf("\t");}
		printf("|\n");
		for (i = 0; i < r; ++i){
			printf("|\t");
			for (j = 0; j < c; ++j) {
				printf("%d\t", sum[i][j]);
				if (j == c - 1) {
					printf("|\n");
				}
			}
		}
			printf("|\t");
		for (j = 0; j < c; ++j){printf("\t");}
		printf("|\n");
		
		
		
		
		// Function to display resultant matrix after multiplication.
		display(mult, r1, c2);
		break;
		
	case '+':
		printf("Enter the number of rows (between 1 and 100): ");
		scanf("%d", &r);
		printf("Enter the number of columns (between 1 and 100): ");
		scanf("%d", &c);

		printf("\nEnter elements of 1st matrix:\n");
		for (i = 0; i < r; ++i)
			for (j = 0; j < c; ++j) {
				printf("Enter element a%d%d: ", i + 1, j + 1);
				scanf("%d", &a[i][j]);
			}

		printf("Enter elements of 2nd matrix:\n");
		for (i = 0; i < r; ++i)
			for (j = 0; j < c; ++j) {
				printf("Enter element a%d%d: ", i + 1, j + 1);
				scanf("%d", &b[i][j]);
			}
		// adding two matrices
		for (i = 0; i < r; ++i)
			for (j = 0; j < c; ++j) {
				sum[i][j] = a[i][j] + b[i][j];
			}		
		printf("\nSum of two matrices: \n");
		// printing the input
		printf("|\t");
		for (j = 0; j < c; ++j){printf("\t");}
		printf("|\n");
		for (i = 0; i < r; ++i){
			printf("|\t");
			for (j = 0; j < c; ++j) {
				printf("%d\t", a[i][j]);
				if (j == c - 1) {
					printf("|\n");
				}
			}
		}
			printf("|\t");
		for (j = 0; j < c; ++j){printf("\t");}
		printf("|\n");   
		
		printf("\t+\t\n");
		
		printf("|\t");
		for (j = 0; j < c; ++j){printf("\t");}
		printf("|\n");
		for (i = 0; i < r; ++i){
			printf("|\t");
			for (j = 0; j < c; ++j) {
				printf("%d\t", b[i][j]);
				if (j == c - 1) {
					printf("|\n");
				}
			}
		}
			printf("|\t");
		for (j = 0; j < c; ++j){printf("\t");}
		printf("|\n");  
			
		printf("\t=\t\n");
		printf("|\t");
		for (j = 0; j < c; ++j){printf("\t");}
		printf("|\n");
		for (i = 0; i < r; ++i){
			printf("|\t");
			for (j = 0; j < c; ++j) {
				printf("%d\t", sum[i][j]);
				if (j == c - 1) {
					printf("|\n");
				}
			}
		}
			printf("|\t");
		for (j = 0; j < c; ++j){printf("\t");}
		printf("|\n");
		break;
		
	case 's':
	printf("Enter the number of rows (between 1 and 100): ");
		scanf("%d", &r);
		printf("Enter the number of columns (between 1 and 100): ");
		scanf("%d", &c);

		printf("\nEnter the scalar:\n");
		scanf("%d", &scalar);
		
		for (i = 0; i < r; ++i)
			for (j = 0; j < c; ++j) {
				printf("Enter element a%d%d: ", i + 1, j + 1);
				scanf("%d", &mult[i][j]);
			}
		scalarMultiply(mult,scalar,r,c);
		break;
		
	default:
		printf("Error! operator is not correct");
		
	}
	return 0;
}
//understand that
void enterData(int first[][10], int second[][10], int r1, int c1, int r2, int c2) {
    printf("\nEnter elements of matrix 1:\n");

    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
            printf("Enter a%d%d: ", i + 1, j + 1);
            scanf("%d", &first[i][j]);
        }
    }
    printf("\nEnter elements of matrix 2:\n");

    for (int i = 0; i < r2; ++i) {
        for (int j = 0; j < c2; ++j) {
            printf("Enter b%d%d: ", i + 1, j + 1);
            scanf("%d", &second[i][j]);
        }
    }
}

void multiplyMatrices(int first[][10], int second[][10], int mult[][10], int r1, int c1, int r2, int c2) {

    // Initializing elements of matrix mult to 0.
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            mult[i][j] = 0;
        }
    }

    // Multiplying first and second matrices and storing in mult.
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            for (int k = 0; k < c1; ++k) {
                mult[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

void display(int mult[][10], int r1, int c2) {

    printf("\nOutput Matrix:\n");
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            printf("%d  ", mult[i][j]);
            if (j == c2 - 1)
                printf("\n");
        }
    }
}

void scalarMultiply(int mult[][10], int scalar, int r, int c) {

    printf("\nOutput Matrix:\n");
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            printf("%d  ", scalar*mult[i][j]);
            if (j == c - 1)
                printf("\n");
        }
    }
}