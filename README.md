# CashFlow_Minimizer
This algorithm minimizes the complex cashflow among persons into very simplified form

Approach: 
1. Compute the net amount for every person. The net amount for person ‘i’ can be computed by subtracting sum of all debts from sum of all credits.
2. Find the two persons that are maximum creditor and maximum debtor.  Let the maximum debtor be Pd and maximum creditor be Pc.
3. Find the minimum of maxDebit and maxCredit. Let minimum of two be x. Debit ‘x’ from Pd and credit this amount to Pc
4. Repeat until both Pd and Pc settles down to 0.

[References](https://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/)
