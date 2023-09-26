#pragma once

#include <string>
#include <vector>

// ReSharper disable once CppInconsistentNaming
struct Lexer
{
	explicit Lexer(std::string f_code);

	// ReSharper disable once CppInconsistentNaming
	void Tokenize();

	// ReSharper disable once CppInconsistentNaming
	std::vector<std::string> GetTokens();

private:
	std::string code_;
	std::string token_;
	const char* textptr_ = nullptr;
	std::vector<std::string> tokens_ = {};

	// ReSharper disable once CppInconsistentNaming
	void Check();

	// ReSharper disable once CppInconsistentNaming
	void Advance();
};
