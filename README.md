This project implements Secret Recovery using Lagrange Interpolation in C++. The program reads numerical values in different bases from JSON files, converts them to decimal, and reconstructs a secret value based on given (x, y) points.

📂 Files
SecretRecovery.cpp - C++ program to process JSON input and recover the secret.
testcase1.json - First test case with values in different bases.
testcase2.json - Second test case with more complex values.
⚙️ How It Works
Reads JSON Input

Extracts n (total points) and k (required points).
Parses (x, y) values stored in different bases.
Converts to Decimal

Converts values from given bases (binary, octal, decimal, etc.) to decimal.
Applies Lagrange Interpolation

Uses Lagrange Polynomial Interpolation to compute the secret at f(0).





