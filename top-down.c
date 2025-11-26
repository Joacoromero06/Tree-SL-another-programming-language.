#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char token[128]; // token actual

// ---------------------------------------------
//               LEXER MUY SIMPLE
// ---------------------------------------------
void next()
{
    if (scanf("%s", token) != 1)
    {
        strcpy(token, "EOF");
    }
}

int accept(const char *t)
{
    if (strcmp(token, t) == 0)
    {
        next();
        return 1;
    }
    return 0;
}

void expect(const char *t)
{
    if (!accept(t))
    {
        printf("Error: se esperaba '%s' y llegó '%s'\n", t, token);
        exit(1);
    }
}

// ---------------------------------------------
//            PROTOTIPOS DEL PARSER
// ---------------------------------------------
void E();
void E_or();
void E_and();
void E_not();
void E_rel();
void E_get();
void E_union();
void E_inter();
void E_diff();
void E_from();
void E_concat();
void E_add();
void E_arit_1();
void E_arit_2();
void E_prioridad();

// ---------------------------------------------
//                 PARSER
// ---------------------------------------------

void E()
{
    // E ::= id = E_or
    expect("id");
    expect("=");
    E_or();
}

void E_or()
{
    E_and();
    while (accept("or"))
        E_and();
}

void E_and()
{
    E_not();
    while (accept("and"))
        E_not();
}

void E_not()
{
    if (accept("not"))
        E_not();
    else
        E_rel();
}

void E_rel()
{
    E_get();
    if (accept("cmp"))
        E_rel();
}

void E_get()
{
    if (accept("get"))
    {
        E_prioridad();
        expect("from");
        E_union();
    }
    else
    {
        E_union();
    }
}

void E_union()
{
    E_inter();
    while (accept("union"))
        E_inter();
}

void E_inter()
{
    E_diff();
    while (accept("inter"))
        E_diff();
}

void E_diff()
{
    E_from();
    while (accept("diff"))
        E_from();
}

void E_from()
{
    if (accept("kick") || accept("take"))
    {
        E_concat();
        expect("from");
        E_concat();
    }
    else
    {
        E_concat();
    }
}

void E_concat()
{
    E_add();
    while (accept("concat"))
        E_add();
}

void E_add()
{
    if (accept("add"))
    {
        E_arit_1();
        expect("from");
        E_arit_1();
    }
    else
    {
        E_arit_1();
    }
}

void E_arit_1()
{
    E_arit_2();
    while (accept("+") || accept("-"))
        E_arit_2();
}

void E_arit_2()
{
    E_prioridad();
    while (accept("*") || accept("/"))
        E_prioridad();
}

void E_prioridad()
{
    if (accept("("))
    {
        E();
        expect(")");
    }
    else if (accept("|"))
    {
        E();
        expect("|");
    }
    else if (accept("id"))
    {
        // id
    }
    else if (strcmp(token, "literal") == 0)
    {
        next();
    }
    else
    {
        printf("Error: token inesperado en E_prioridad: %s\n", token);
        exit(1);
    }
}

// ---------------------------------------------
//                  MAIN
// ---------------------------------------------
int main()
{
    next();
    E();
    if (strcmp(token, "EOF") == 0)
        printf("Parsing correcto.\n");
    else
        printf("Sobran tokens: %s\n", token);

    return 0;
}
