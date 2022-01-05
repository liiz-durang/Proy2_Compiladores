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
#line 31 "parser.yy"


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
      case symbol_kind::S_o: // o
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

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
        value.copy< std::string > (YY_MOVE (that.value));
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
      case symbol_kind::S_o: // o
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

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
        value.move< std::string > (YY_MOVE (s.value));
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
      case symbol_kind::S_o: // o
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

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
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
      case symbol_kind::S_o: // o
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

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
        value.move< std::string > (YY_MOVE (that.value));
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
      case symbol_kind::S_o: // o
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

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
        value.copy< std::string > (that.value);
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
      case symbol_kind::S_o: // o
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

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
        value.move< std::string > (that.value);
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
      case symbol_kind::S_o: // o
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

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_NUMERO: // NUMERO
        yylhs.value.emplace< std::string > ();
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
  case 5: // $@1: %empty
#line 85 "parser.yy"
        {
        driver.setType(yystack_[0].value.as < int > ());
        
    }
#line 784 "parser.tab.cc"
    break;

  case 6: // $@2: %empty
#line 88 "parser.yy"
         {
        //cout << $3 << endl;
        driver.setId(yystack_[0].value.as < std::string > ());
        cout << "Id Global:" << driver.getId() << endl;
        cout << "Tipo Global:" << driver.getGtype() << endl;

        driver.addSym(driver.getId(),driver.getGtype(),"variable");      
    }
#line 797 "parser.tab.cc"
    break;

  case 8: // $@3: %empty
#line 98 "parser.yy"
           {
            driver.setType(5);
            cout<<driver.getGtype()<<endl;
            }
#line 806 "parser.tab.cc"
    break;

  case 10: // $@4: %empty
#line 103 "parser.yy"
        {
            driver.setType(0);
            cout<<driver.getGtype()<<endl;
        }
#line 815 "parser.tab.cc"
    break;

  case 19: // lv_: COMA ID lv_
#line 134 "parser.yy"
                {
        driver.addSym(driver.getId(),driver.getGtype(),"variable");
    }
#line 823 "parser.tab.cc"
    break;

  case 21: // tipo: INT
#line 142 "parser.yy"
        { 
            yylhs.value.as < int > () = 1;
            //cout << "Tipo: " << $$ << endl; 
        }
#line 832 "parser.tab.cc"
    break;

  case 22: // tipo: FLOAT
#line 147 "parser.yy"
          { 
            yylhs.value.as < int > () = 2;
            //cout << "Tipo: " << $$ << endl;
        }
#line 841 "parser.tab.cc"
    break;

  case 23: // tipo: DOUBLE
#line 152 "parser.yy"
           {
                yylhs.value.as < int > () = 3; 
                //cout << "Tipo: " << $$ << endl;
            }
#line 850 "parser.tab.cc"
    break;

  case 24: // tipo: CHAR
#line 157 "parser.yy"
         { 
            yylhs.value.as < int > () = 4;
            //cout << "Tipo: " << $$ << endl;
        }
#line 859 "parser.tab.cc"
    break;

  case 60: // o: o OR a
#line 241 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 865 "parser.tab.cc"
    break;

  case 61: // o: a
#line 243 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[0].value.as < Expresion > (); }
#line 871 "parser.tab.cc"
    break;

  case 62: // a: a AND i
#line 246 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 877 "parser.tab.cc"
    break;

  case 63: // a: i
#line 248 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[0].value.as < Expresion > (); }
#line 883 "parser.tab.cc"
    break;

  case 64: // i: i IGUAL r
#line 251 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 889 "parser.tab.cc"
    break;

  case 65: // i: i DIF r
#line 253 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 895 "parser.tab.cc"
    break;

  case 66: // i: r
#line 255 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[0].value.as < Expresion > (); }
#line 901 "parser.tab.cc"
    break;

  case 67: // r: r MENOR mm
#line 258 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 907 "parser.tab.cc"
    break;

  case 68: // r: r MENORI mm
#line 260 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 913 "parser.tab.cc"
    break;

  case 69: // r: r MAYOR mm
#line 262 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 919 "parser.tab.cc"
    break;

  case 70: // r: r MAYORI mm
#line 264 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 925 "parser.tab.cc"
    break;

  case 71: // r: mm
#line 266 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[0].value.as < Expresion > (); }
#line 931 "parser.tab.cc"
    break;

  case 72: // mm: mm MAS md
#line 269 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 937 "parser.tab.cc"
    break;

  case 73: // mm: mm MENOS md
#line 271 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 943 "parser.tab.cc"
    break;

  case 74: // mm: md
#line 273 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[0].value.as < Expresion > (); }
#line 949 "parser.tab.cc"
    break;

  case 75: // md: md DIV n
#line 276 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 955 "parser.tab.cc"
    break;

  case 76: // md: md MUL n
#line 278 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[2].value.as < Expresion > (); }
#line 961 "parser.tab.cc"
    break;

  case 77: // md: n
#line 280 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[0].value.as < Expresion > (); }
#line 967 "parser.tab.cc"
    break;

  case 79: // n: f
#line 285 "parser.yy"
    { yylhs.value.as < Expresion > () = yystack_[0].value.as < Expresion > (); }
#line 973 "parser.tab.cc"
    break;


#line 977 "parser.tab.cc"

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









  const signed char Parser::yypact_ninf_ = -118;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     110,  -118,  -118,  -118,  -118,  -118,  -118,    14,  -118,   110,
    -118,     6,     5,  -118,  -118,    33,     5,  -118,  -118,  -118,
      71,    47,  -118,  -118,  -118,   102,    64,    66,   116,    -6,
    -118,    71,  -118,    87,  -118,  -118,    88,    65,    83,  -118,
     116,  -118,    85,  -118,    93,    64,  -118,   100,   116,    81,
    -118,  -118,  -118,  -118,  -118,   122,    86,  -118,    98,   105,
     106,    72,   107,   108,   121,   126,   128,   101,  -118,  -118,
    -118,  -118,  -118,   125,  -118,  -118,  -118,  -118,  -118,    86,
     148,    24,    24,   101,  -118,   144,    18,   150,  -118,  -118,
    -118,  -118,    24,   133,  -118,     8,  -118,  -118,    24,    24,
     -20,   129,    16,   104,     7,    36,  -118,  -118,    10,    57,
     117,   118,    19,   119,   -12,  -118,   154,    24,  -118,    21,
      24,    72,    24,    24,    24,    24,    24,    24,    24,    24,
      24,    24,    24,    72,  -118,    24,   138,   139,   140,  -118,
    -118,   136,   124,   142,  -118,  -118,   129,   127,    16,   104,
     104,     7,     7,     7,     7,    36,    36,  -118,  -118,  -118,
      31,  -118,  -118,  -118,  -118,    24,    72,   145,  -118,  -118,
    -118
  };

  const signed char
  Parser::yydefact_[] =
  {
       4,    24,    21,    22,    23,     8,    10,     0,     2,     4,
       5,     0,     0,     1,     3,     0,     0,    33,     9,    15,
       0,     0,    11,     6,    16,     0,    20,     0,    28,    20,
      26,     0,    32,     0,    18,    25,     0,     0,    27,    30,
      28,     7,     0,    34,     0,    20,    31,     0,     0,     0,
      12,    17,    19,    33,    29,     0,    36,    33,    53,     0,
       0,     0,     0,     0,     0,     0,     0,    35,    38,    39,
      40,    45,    43,     0,    42,    41,    47,    44,    46,    36,
       0,     0,     0,     0,    92,     0,     0,     0,    58,    59,
      14,    37,     0,     0,    54,    81,    82,    85,     0,     0,
       0,    61,    63,    66,    71,    74,    77,    79,     0,     0,
       0,     0,     0,     0,     0,    13,     0,    87,    78,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,     0,     0,     0,     0,    52,
      84,    90,     0,    86,    89,    80,    60,    49,    62,    64,
      65,    67,    69,    68,    70,    72,    73,    76,    75,    50,
       0,    56,    55,    57,    83,     0,     0,     0,    88,    48,
      51
  };

  const short
  Parser::yypgoto_[] =
  {
    -118,  -118,   157,  -118,  -118,  -118,  -118,  -118,  -118,   153,
    -118,  -118,   141,   -10,     3,  -118,  -118,   130,  -118,   123,
     -19,  -118,    94,    91,   -54,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,   -81,    55,    54,   -71,    13,
     -53,   -92,  -118,  -118,  -118,    12,  -117
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     7,     8,     9,    15,    29,    11,    12,    41,    22,
      18,    43,    27,    34,    31,    19,    20,    37,    38,    39,
      25,    32,    66,    67,    84,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,   141,   101,   102,   103,   104,
     105,   106,   107,   142,   143,   144,    85
  };

  const unsigned char
  Parser::yytable_[] =
  {
     100,   108,    68,    10,   147,   112,   118,   120,    21,    16,
     139,   114,    10,    91,    13,   120,   159,    33,   119,    42,
     121,    95,    96,   111,    97,    68,    17,    95,    96,    68,
      97,    36,   116,    40,    56,    52,    23,   120,    79,   157,
     158,   129,   130,    36,   123,   124,   120,   117,   120,   169,
     133,    36,   149,   150,   160,    91,    98,    99,   120,   137,
      58,   145,    98,    99,    59,    60,    61,    62,    63,    64,
      65,   167,   131,   132,    26,    58,   155,   156,   134,    59,
      60,    61,    62,    63,    64,    65,    28,    33,    35,    58,
      45,    46,    83,    59,    60,    61,    62,    63,    64,    65,
       1,     2,     3,     4,    58,    47,    48,    50,    59,    60,
      61,    62,    63,    64,    65,    51,     1,     2,     3,     4,
      53,    55,    80,    30,     1,     2,     3,     4,     5,     6,
       1,     2,     3,     4,   125,   126,   127,   128,   151,   152,
     153,   154,    57,    88,    81,    82,    86,    87,    89,    90,
      92,    94,   110,   113,   115,   122,   135,   140,   136,   138,
     161,   162,   163,   120,   164,   165,    14,   170,   166,    24,
      49,    54,    44,    93,   109,   146,   148,   168
  };

  const unsigned char
  Parser::yycheck_[] =
  {
      81,    82,    56,     0,   121,    86,    98,    27,     3,     3,
      22,    92,     9,    67,     0,    27,   133,    23,    99,    29,
      40,     3,     4,     5,     6,    79,    20,     3,     4,    83,
       6,    28,    24,    39,    53,    45,     3,    27,    57,   131,
     132,    34,    35,    40,    28,    29,    27,    39,    27,   166,
      40,    48,   123,   124,   135,   109,    38,    39,    27,    40,
       3,    40,    38,    39,     7,     8,     9,    10,    11,    12,
      13,    40,    36,    37,     3,     3,   129,   130,    21,     7,
       8,     9,    10,    11,    12,    13,    39,    23,    22,     3,
       3,     3,    20,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     3,    40,    23,    22,     7,     8,
       9,    10,    11,    12,    13,    22,    14,    15,    16,    17,
      20,    40,    24,    21,    14,    15,    16,    17,    18,    19,
      14,    15,    16,    17,    30,    31,    32,    33,   125,   126,
     127,   128,    20,    22,    39,    39,    39,    39,    22,    21,
      25,     3,     8,     3,    21,    26,    39,     3,    40,    40,
      22,    22,    22,    27,    40,    23,     9,    22,    41,    16,
      40,    48,    31,    79,    83,   120,   122,   165
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    14,    15,    16,    17,    18,    19,    43,    44,    45,
      56,    48,    49,     0,    44,    46,     3,    20,    52,    57,
      58,     3,    51,     3,    51,    62,     3,    54,    39,    47,
      21,    56,    63,    23,    55,    22,    56,    59,    60,    61,
      39,    50,    55,    53,    54,     3,     3,    40,    23,    59,
      22,    22,    55,    20,    61,    40,    62,    20,     3,     7,
       8,     9,    10,    11,    12,    13,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    62,
      24,    39,    39,    20,    66,    88,    39,    39,    22,    22,
      21,    66,    25,    64,     3,     3,     4,     6,    38,    39,
      77,    78,    79,    80,    81,    82,    83,    84,    77,    65,
       8,     5,    77,     3,    77,    21,    24,    39,    83,    77,
      27,    40,    26,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    40,    21,    39,    40,    40,    40,    22,
       3,    77,    85,    86,    87,    40,    78,    88,    79,    80,
      80,    81,    81,    81,    81,    82,    82,    83,    83,    88,
      77,    22,    22,    22,    40,    23,    41,    40,    87,    88,
      22
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    42,    43,    44,    44,    46,    47,    45,    48,    45,
      49,    45,    50,    50,    51,    52,    52,    53,    54,    55,
      55,    56,    56,    56,    56,    57,    58,    59,    59,    60,
      60,    61,    62,    62,    63,    64,    64,    65,    65,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    67,    67,
      68,    69,    70,    71,    71,    72,    73,    74,    75,    76,
      77,    77,    78,    78,    79,    79,    79,    80,    80,    80,
      80,    80,    81,    81,    81,    82,    82,    82,    83,    83,
      84,    84,    84,    84,    84,    84,    85,    85,    86,    86,
      87,    88,    88
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     0,     0,     5,     0,     3,
       0,     3,     2,     7,     8,     1,     2,     2,     2,     3,
       0,     1,     1,     1,     1,     3,     3,     1,     0,     3,
       1,     2,     2,     0,     2,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     7,     5,
       5,     7,     4,     1,     3,     5,     5,     5,     2,     2,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     2,     1,
       3,     1,     1,     4,     3,     1,     1,     0,     3,     1,
       1,     3,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUMERO",
  "CADENA", "CARACTER", "IF", "WHILE", "DO", "PRINT", "SCAN", "BREAK",
  "RETURN", "CHAR", "INT", "FLOAT", "DOUBLE", "STRUCT", "VOID", "LKEY",
  "RKEY", "PYC", "COMA", "PUNTO", "ASIG", "AND", "OR", "IGUAL", "DIF",
  "MENOR", "MAYOR", "MENORI", "MAYORI", "MAS", "MENOS", "MUL", "DIV",
  "NOT", "LPAR", "RPAR", "ELSE", "$accept", "p", "dd", "d", "$@1", "$@2",
  "$@3", "$@4", "dcl1", "dcl2", "dcl3", "dv", "lv", "lv_", "tipo", "ds",
  "bs", "la", "as", "ar", "dls", "dl", "bqs", "ss", "s", "si", "sw", "sd",
  "sa", "pi", "spw", "sps", "ssc", "sb", "sr", "o", "a", "i", "r", "mm",
  "md", "n", "f", "lps", "pas", "pa", "bos", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,    76,    76,    79,    81,    85,    88,    85,    98,    98,
     103,   103,   110,   112,   116,   120,   122,   126,   130,   134,
     138,   142,   147,   152,   157,   164,   167,   170,   172,   176,
     178,   182,   185,   187,   191,   194,   196,   199,   201,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   207,   209,
     212,   215,   218,   221,   223,   226,   229,   232,   235,   238,
     241,   243,   246,   248,   251,   253,   255,   258,   260,   262,
     264,   266,   269,   271,   273,   276,   278,   280,   283,   285,
     288,   290,   292,   294,   296,   298,   301,   303,   306,   308,
     311,   314,   316
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
      35,    36,    37,    38,    39,    40,    41
    };
    // Last valid token kind.
    const int code_max = 296;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1455 "parser.tab.cc"

#line 319 "parser.yy"




void yy::Parser::error( const location_type &l, const std::string &err_message )
{
    cerr << "Error: " << err_message << " at " << l << endl;
}
