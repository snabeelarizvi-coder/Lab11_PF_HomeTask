#include <stdio.h>
#include <string.h>

typedef struct {
    char customerName[50];
    double loanAmount;
    double interestRate;     
    double monthlyInstallment;
} Loan;

void simulateRepayment(double remainingAmount, double monthlyInstallment, double interestRate, int month) {
    if (remainingAmount <= 0) {
        printf("Loan fully repaid in %d month(s).\n", month);
        return;
    }

    double interest = remainingAmount * (interestRate / 100.0);
    double newRemaining = remainingAmount - monthlyInstallment + interest;

    if (newRemaining < 0) newRemaining = 0; 

    printf("Month %d: Remaining Loan = %.2lf\n", month + 1, newRemaining);

    simulateRepayment(newRemaining, monthlyInstallment, interestRate, month + 1);
}

int main() {
    Loan loan;

    printf("Enter customer name: ");
    scanf(" %[^\n]", loan.customerName);

    printf("Enter loan amount: ");
    scanf("%lf", &loan.loanAmount);

    printf("Enter monthly interest rate (%%): ");
    scanf("%lf", &loan.interestRate);

    printf("Enter monthly installment amount: ");
    scanf("%lf", &loan.monthlyInstallment);

    printf("\n--- Loan Repayment Schedule for %s ---\n", loan.customerName);
    printf("Initial Loan Amount: %.2lf\n", loan.loanAmount);
    printf("Monthly Installment: %.2lf\n", loan.monthlyInstallment);
    printf("Monthly Interest Rate: %.2lf%%\n\n", loan.interestRate);

    simulateRepayment(loan.loanAmount, loan.monthlyInstallment, loan.interestRate, 0);

    return 0;
}


