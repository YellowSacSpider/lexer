#include "lexer.h"

Lexer::Lexer(std::string f_code) : code_(std::move(f_code))
{
	textptr_ = code_.data();
}

// ReSharper disable once CppInconsistentNaming
void Lexer::Tokenize()
{
	if (code_.empty())
		return;

	token_.clear();
	tokens_.clear();

	while (true)
	{
		if (*textptr_ == '\0')
			break;

		Check();
	}
}

// ReSharper disable once CppInconsistentNaming
std::vector<std::string> Lexer::GetTokens()
{
	return tokens_;
}

// ReSharper disable once CppInconsistentNaming
void Lexer::Check()
{
	if (*textptr_ == ' ' || *textptr_ == '\t')
	{
		tokens_.emplace_back(token_);
		token_.clear();
		textptr_++;
	}

	if (std::isalnum(*textptr_))
		token_ += *textptr_;
	else
	{
		tokens_.emplace_back(token_);
		token_.clear();
		token_ = *textptr_;
		tokens_.emplace_back(token_);
		token_.clear();
	}
	Advance();
}

// ReSharper disable once CppInconsistentNaming
void Lexer::Advance()
{
	if (*textptr_ != '\0')
		textptr_++;
}
