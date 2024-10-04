//
// Created by schuberte on 10/4/2024.
//

#include "BankAccount.h"

int main() {
    BankAccount account = BankAccount("121-203", "Evan Schubert", 1000);
    account.deposit(100);
    account.withdraw(1000);
    account.checkBalance(); //expecting balance of $100
    return 0;
}
