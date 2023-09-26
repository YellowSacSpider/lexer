#include <iostream>

#include "lexer.h"

int main()
{
	Lexer lexer("Test red(string).");
	lexer.Tokenize();

	for (const auto& i : lexer.GetTokens())
		std::cout << i << '\n';
}
