#ifndef __SCANNER_HPP__
#define __SCANNER_HPP__

#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

namespace COMP
{

    class Lexer : public yyFlexLexer
    {
    public:
        Lexer(std::istream *in) : yyFlexLexer(in)
        {
        };

        using FlexLexer::yylex;
        virtual int yylex();

    private:
        const int ERROR = -1;
    };

}

#endif /* END __SCANNER_H__ */