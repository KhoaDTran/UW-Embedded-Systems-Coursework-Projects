/**
 * Interactive calculator for expressions with rational numerbers.
 * CSE 374, 18sp, HP+MW
 */

#include <iostream>
#include <string>

#include "Parser.h"
#include "Rational.h"
#include "Scanner.h"

// Print rational r followed by a newline
void prrat(rational374::Rational r) {
  std::cout << r.n() << "/" << r.d() << std::endl;
}

// Read and print expressions until eof
int main() {
  rational374::Scanner scanner;
  rational374::Parser parser(&scanner);
  std::string inputLine;
  std::cout << "Enter expressions with integer rational numerbers (n/d) and"
            << std::endl;
  std::cout << "the operations +, -, *, and %.  One line per expression."
            << std::endl;
  std::cout << "Enter eof (cntrl-D) to stop." << std::endl;
  while (getline(std::cin, inputLine)) {
    scanner.setInput(inputLine);
    prrat(parser.expr());
  }

  return 0;
}
