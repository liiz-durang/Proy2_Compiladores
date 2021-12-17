// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 29 "parser.yy"


#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
#include "Driver.h"
#include "Lexer.h"

#undef yylex
#define yylex lexer.yylex

#line 59 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 151 "parser.tab.cc"

  /// Build a parser object.
  Parser::Parser (Lexer  &lexer_yyarg, Driver  &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      lexer (lexer_yyarg),
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_a: // a
      case symbol_kind::S_i: // i
      case symbol_kind::S_r: // r
      case symbol_kind::S_mm: // mm
      case symbol_kind::S_md: // md
      case symbol_kind::S_n: // n
      case symbol_kind::S_f: // f
        value.copy< Expresion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo: // tipo
        value.copy< int > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_a: // a
      case symbol_kind::S_i: // i
      case symbol_kind::S_r: // r
      case symbol_kind::S_mm: // mm
      case symbol_kind::S_md: // md
      case symbol_kind::S_n: // n
      case symbol_kind::S_f: // f
        value.move< Expresion > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_tipo: // tipo
        value.move< int > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_a: // a
      case symbol_kind::S_i: // i
      case symbol_kind::S_r: // r
      case symbol_kind::S_mm: // mm
      case symbol_kind::S_md: // md
      case symbol_kind::S_n: // n
      case symbol_kind::S_f: // f
        value.YY_MOVE_OR_COPY< Expresion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo: // tipo
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_a: // a
      case symbol_kind::S_i: // i
      case symbol_kind::S_r: // r
      case symbol_kind::S_mm: // mm
      case symbol_kind::S_md: // md
      case symbol_kind::S_n: // n
      case symbol_kind::S_f: // f
        value.move< Expresion > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_tipo: // tipo
        value.move< int > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_a: // a
      case symbol_kind::S_i: // i
      case symbol_kind::S_r: // r
      case symbol_kind::S_mm: // mm
      case symbol_kind::S_md: // md
      case symbol_kind::S_n: // n
      case symbol_kind::S_f: // f
        value.copy< Expresion > (that.value);
        break;

      case symbol_kind::S_tipo: // tipo
        value.copy< int > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_a: // a
      case symbol_kind::S_i: // i
      case symbol_kind::S_r: // r
      case symbol_kind::S_mm: // mm
      case symbol_kind::S_md: // md
      case symbol_kind::S_n: // n
      case symbol_kind::S_f: // f
        value.move< Expresion > (that.value);
        break;

      case symbol_kind::S_tipo: // tipo
        value.move< int > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_expresion: // expresion
      case symbol_kind::S_a: // a
      case symbol_kind::S_i: // i
      case symbol_kind::S_r: // r
      case symbol_kind::S_mm: // mm
      case symbol_kind::S_md: // md
      case symbol_kind::S_n: // n
      case symbol_kind::S_f: // f
        yylhs.value.emplace< Expresion > ();
        break;

      case symbol_kind::S_tipo: // tipo
        yylhs.value.emplace< int > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 18: // tipo: INT
#line 121 "parser.yy"
        { yylhs.value.as < int > () = 1; }
#line 746 "parser.tab.cc"
    break;

  case 19: // tipo: FLOAT
#line 123 "parser.yy"
          { yylhs.value.as < int > ()= 2; }
#line 752 "parser.tab.cc"
    break;

  case 20: // tipo: DOUBLE
#line 125 "parser.yy"
           { yylhs.value.as < int > ()= 3; }
#line 758 "parser.tab.cc"
    break;

  case 21: // tipo: CHAR
#line 127 "parser.yy"
         { yylhs.value.as < int > ()= 4; }
#line 764 "parser.tab.cc"
    break;

  case 56: // expresion: expresion OR a
#line 239 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 770 "parser.tab.cc"
    break;

  case 57: // expresion: a
#line 241 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[0].value.as < Expresion > (); }
#line 776 "parser.tab.cc"
    break;

  case 58: // a: a AND i
#line 245 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 782 "parser.tab.cc"
    break;

  case 59: // a: i
#line 247 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[0].value.as < Expresion > (); }
#line 788 "parser.tab.cc"
    break;

  case 60: // i: i IGUAL r
#line 251 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 794 "parser.tab.cc"
    break;

  case 61: // i: i DIF r
#line 253 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 800 "parser.tab.cc"
    break;

  case 62: // i: r
#line 255 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[0].value.as < Expresion > (); }
#line 806 "parser.tab.cc"
    break;

  case 63: // r: r MENOR mm
#line 259 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 812 "parser.tab.cc"
    break;

  case 64: // r: r MENORI mm
#line 261 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 818 "parser.tab.cc"
    break;

  case 65: // r: r MAYOR mm
#line 263 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 824 "parser.tab.cc"
    break;

  case 66: // r: r MAYORI mm
#line 265 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 830 "parser.tab.cc"
    break;

  case 67: // r: mm
#line 267 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[0].value.as < Expresion > (); }
#line 836 "parser.tab.cc"
    break;

  case 68: // mm: mm MAS md
#line 271 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 842 "parser.tab.cc"
    break;

  case 69: // mm: mm MENOS md
#line 273 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 848 "parser.tab.cc"
    break;

  case 70: // mm: md
#line 275 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[0].value.as < Expresion > (); }
#line 854 "parser.tab.cc"
    break;

  case 71: // md: md DIV n
#line 279 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 860 "parser.tab.cc"
    break;

  case 72: // md: md MUL n
#line 281 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 866 "parser.tab.cc"
    break;

  case 73: // md: n
#line 283 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[0].value.as < Expresion > (); }
#line 872 "parser.tab.cc"
    break;

  case 75: // n: f
#line 289 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[0].value.as < Expresion > (); }
#line 878 "parser.tab.cc"
    break;


#line 882 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const short Parser::yypact_ninf_ = -135;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     117,  -135,  -135,  -135,  -135,    14,    24,    47,  -135,   117,
      26,    15,   123,  -135,  -135,    13,    -7,  -135,  -135,    39,
      18,  -135,  -135,    13,    84,  -135,    13,    92,    42,   123,
     123,  -135,    99,   123,  -135,   107,  -135,  -135,  -135,    13,
    -135,   147,   114,   140,  -135,   124,  -135,   125,  -135,  -135,
    -135,   146,   123,   148,   149,   123,  -135,   123,   123,   101,
     101,   101,   143,   131,   132,    75,   133,   134,  -135,     5,
     153,   116,  -135,  -135,  -135,  -135,  -135,   150,  -135,  -135,
    -135,  -135,  -135,   155,   156,   176,    20,    20,   116,  -135,
     172,     9,   178,   -18,  -135,  -135,  -135,    20,    20,    23,
     157,    91,   110,   118,   119,  -135,  -135,  -135,  -135,    20,
    -135,  -135,  -135,    11,    48,    59,   142,   144,    52,   145,
     180,    20,  -135,    62,  -135,    20,    20,    20,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    74,    75,    75,
    -135,    20,   164,   165,   166,  -135,   162,   151,   167,  -135,
    -135,   157,    91,   110,   110,   118,   118,   118,   118,   119,
     119,  -135,  -135,  -135,   152,  -135,    64,  -135,  -135,  -135,
    -135,    20,    75,  -135,  -135,  -135
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,    21,    18,    19,    20,     0,     0,     0,     2,     4,
       0,     0,     0,     6,    12,     0,     0,     1,     3,     0,
       0,    13,    11,     0,     0,    29,    17,     0,     0,     0,
       0,     5,     0,     0,    30,     0,    23,    28,    15,     0,
      22,     0,     0,    24,    26,     0,     8,     0,    14,    16,
      27,     0,     0,     0,     0,     0,    25,     0,     0,     0,
       0,     0,    48,     0,     0,     0,     0,     0,    53,     0,
       0,    31,    33,    34,    35,    40,    38,     0,    37,    36,
      42,    39,    41,     0,     0,     0,     0,     0,     0,    87,
       0,     0,     0,    77,    78,    81,    54,     0,     0,     0,
      57,    59,    62,    67,    70,    73,    75,     7,    32,     0,
       9,    10,    49,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      86,     0,     0,     0,     0,    80,    85,     0,    82,    84,
      76,    56,    58,    60,    61,    63,    65,    64,    66,    68,
      69,    72,    71,    47,    44,    45,     0,    51,    50,    52,
      79,     0,     0,    46,    83,    43
  };

  const short
  Parser::yypgoto_[] =
  {
    -135,  -135,   184,  -135,  -135,  -135,  -135,  -135,    38,     1,
     185,  -135,    61,  -135,   154,    94,    -5,    98,   109,   -65,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
     -66,    70,    72,    33,    16,    29,   -95,  -135,  -135,  -135,
      28,  -134
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     7,     8,     9,    31,    21,    13,    34,    28,    23,
      14,    15,    42,    43,    44,    24,    25,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
     146,   100,   101,   102,   103,   104,   105,   106,   147,   148,
     149,    90
  };

  const unsigned char
  Parser::yytable_[] =
  {
      89,    10,   122,    99,   164,   165,   108,   120,    93,    94,
      10,    95,    93,    94,   117,    95,    26,    11,    20,    37,
     113,   114,   121,    93,    94,   118,    95,    16,    96,    19,
      41,    41,   123,    29,    41,    12,    12,    27,   175,   125,
     161,   162,    26,   137,    97,    98,   124,    17,    97,    98,
     108,   125,   138,    41,    37,    37,    37,    32,    33,    97,
      98,    35,    62,    27,    38,    40,    63,    64,    65,    66,
      67,    68,    69,    89,    89,   166,   125,    49,    62,    30,
     125,   140,    63,    64,    65,    66,    67,    68,    69,   139,
     125,    45,   125,   143,    47,    39,    88,   163,     1,     2,
       3,     4,   125,   150,    62,   173,    36,    89,    63,    64,
      65,    66,    67,    68,    69,     1,     2,     3,     4,    62,
     127,   128,    46,    63,    64,    65,    66,    67,    68,    69,
      48,     1,     2,     3,     4,     5,     6,     1,     2,     3,
       4,   129,   130,   131,   132,   155,   156,   157,   158,    59,
      50,    60,    61,   133,   134,    51,   135,   136,    83,    84,
     153,   154,   159,   160,    52,    53,    54,    55,    85,    57,
      58,    86,    87,    91,    92,   107,   109,   110,   111,   112,
     116,   119,   141,   145,   126,   142,   144,   167,   168,   169,
     125,   171,   170,    18,   172,   151,    22,   115,   152,   174,
       0,     0,     0,     0,     0,     0,    56
  };

  const short
  Parser::yycheck_[] =
  {
      65,     0,    97,    69,   138,   139,    71,    25,     3,     4,
       9,     6,     3,     4,     5,     6,     3,     3,     3,    24,
      86,    87,    40,     3,     4,    91,     6,     3,    23,     3,
      29,    30,    98,    40,    33,    21,    21,    24,   172,    28,
     135,   136,     3,   109,    39,    40,    23,     0,    39,    40,
     115,    28,    41,    52,    59,    60,    61,    19,    40,    39,
      40,    23,     3,    24,    26,    23,     7,     8,     9,    10,
      11,    12,    13,   138,   139,   141,    28,    39,     3,    40,
      28,    22,     7,     8,     9,    10,    11,    12,    13,    41,
      28,    30,    28,    41,    33,     3,    21,    23,    14,    15,
      16,    17,    28,    41,     3,    41,    22,   172,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     3,
      29,    30,    23,     7,     8,     9,    10,    11,    12,    13,
      23,    14,    15,    16,    17,    18,    19,    14,    15,    16,
      17,    31,    32,    33,    34,   129,   130,   131,   132,    55,
       3,    57,    58,    35,    36,    41,    37,    38,    60,    61,
     127,   128,   133,   134,    24,    41,    41,    21,    25,    21,
      21,    40,    40,    40,    40,    22,    26,    22,    22,     3,
       8,     3,    40,     3,    27,    41,    41,    23,    23,    23,
      28,    24,    41,     9,    42,   125,    11,    88,   126,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    52
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    14,    15,    16,    17,    18,    19,    44,    45,    46,
      52,     3,    21,    49,    53,    54,     3,     0,    45,     3,
       3,    48,    53,    52,    58,    59,     3,    24,    51,    40,
      40,    47,    51,    40,    50,    51,    22,    59,    51,     3,
      23,    52,    55,    56,    57,    55,    23,    55,    23,    51,
       3,    41,    24,    41,    41,    21,    57,    21,    21,    58,
      58,    58,     3,     7,     8,     9,    10,    11,    12,    13,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    60,    60,    25,    40,    40,    21,    62,
      84,    40,    40,     3,     4,     6,    23,    39,    40,    73,
      74,    75,    76,    77,    78,    79,    80,    22,    62,    26,
      22,    22,     3,    73,    73,    61,     8,     5,    73,     3,
      25,    40,    79,    73,    23,    28,    27,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    73,    41,    41,
      22,    40,    41,    41,    41,     3,    73,    81,    82,    83,
      41,    74,    75,    76,    76,    77,    77,    77,    77,    78,
      78,    79,    79,    23,    84,    84,    73,    23,    23,    23,
      41,    24,    42,    41,    83,    84
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    43,    44,    45,    45,    46,    46,    46,    47,    47,
      48,    48,    49,    49,    50,    51,    51,    51,    52,    52,
      52,    52,    53,    54,    55,    56,    56,    57,    58,    58,
      59,    60,    61,    61,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    63,    63,    64,    65,    66,    67,    67,
      68,    69,    70,    71,    72,    72,    73,    73,    74,    74,
      75,    75,    75,    76,    76,    76,    76,    76,    77,    77,
      77,    78,    78,    78,    79,    79,    80,    80,    80,    80,
      80,    80,    81,    82,    82,    83,    84,    84
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     3,     2,     9,     2,     7,
       8,     1,     1,     2,     2,     2,     3,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     1,     2,     2,     1,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     7,     5,     5,     6,     4,     1,     3,
       5,     5,     5,     1,     2,     3,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     2,     1,     3,     1,     1,     4,
       3,     1,     1,     3,     1,     1,     3,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUMERO",
  "CADENA", "CARACTER", "IF", "WHILE", "DO", "PRINT", "SCAN", "BREAK",
  "RETURN", "CHAR", "INT", "FLOAT", "DOUBLE", "STRUCT", "VOID", "ESP",
  "LKEY", "RKEY", "PYC", "COMA", "PUNTO", "ASIG", "AND", "OR", "IGUAL",
  "DIF", "MENOR", "MAYOR", "MENORI", "MAYORI", "MAS", "MENOS", "MUL",
  "DIV", "NOT", "LPAR", "RPAR", "ELSE", "$accept", "programa",
  "declaraciones", "declaracion", "dcl1", "dcl2", "dcl3", "decl-var",
  "lista-var", "tipo", "decl-struct", "body-struct", "lista-args", "args",
  "arg", "decl-locales", "decl-local", "bloque-sentencias", "sentencias",
  "sentencia", "sentIf", "sentWhile", "sentDo", "sentAsig", "parte-izq",
  "sentPutw", "sentPuts", "sentScan", "sentBreak", "sentReturn",
  "expresion", "a", "i", "r", "mm", "md", "n", "f", "lista_params",
  "params", "param", "bloque-o-sentencia", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,    75,    75,    79,    81,    85,    87,    89,    93,    95,
      99,   101,   105,   107,   110,   113,   115,   117,   121,   123,
     125,   127,   131,   135,   139,   143,   145,   149,   153,   155,
     159,   163,   167,   169,   173,   175,   177,   179,   181,   183,
     185,   187,   189,   193,   195,   199,   203,   207,   211,   213,
     217,   221,   225,   229,   233,   235,   239,   241,   245,   247,
     251,   253,   255,   259,   261,   263,   265,   267,   271,   273,
     275,   279,   281,   283,   287,   289,   293,   295,   297,   299,
     301,   303,   307,   311,   313,   317,   321,   323
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
    };
    // Last valid token kind.
    const int code_max = 297;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1366 "parser.tab.cc"

#line 326 "parser.yy"




void yy::Parser::error( const location_type &l, const std::string &err_message )
{
    cerr << "Error: " << err_message << " at " << l << endl;
}
