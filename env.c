#include "env.h"

/*=======================================================================*/
/*                              SYM LIST                                 */
/*=======================================================================*/
SymList *new_SL(char *key, tData value, SymList *next)
{
    SymList *sl = malloc(sizeof(struct sym_list));
    if (!sl)
    {
        envError("sin memoria new_SL");
        return NULL;
    }
    sl->key = strdup(key);
    sl->value = value;
    sl->next = next;

    return sl;
}
void delete_SL(SymList *sl)
{
    if (!sl)
    {
        //envError("free null en delete_SL");
        return;
    }

    SymList *temp = NULL;
    while (sl->next != NULL)
    {
        temp = sl;
        sl = sl->next;
        free(temp->key);
        freeData(temp->value);
        free(temp);
    }
    free(sl->key);
    freeData(sl->value);
    free(sl);
}

boolean pertence_SL(char *key, SymList *sl)
{
    if (!sl)
    { // lista vacia
        return FALSE;
    }
    while (sl != NULL)
    {
        if (strcmp(sl->key, key) == 0)
        {
            return TRUE;
        }
        sl = sl->next;
    }
    return FALSE;
}
tData localiza_SL(char *key, SymList *sl)
{
    while (sl != NULL)
    {
        if (strcmp(sl->key, key) == 0)
        {
            return sl->value;
        }
        sl = sl->next;
    }
    printf("Error: variable %s no definida\n", key);
    return NULL;
}
void inserta_SL(char *key, tData value, SymList **sl)
{
    if (!sl)
    {
        envError("puntero null en inserta_SL");
        return;
    }
    if (pertence_SL(key, (*sl)))
    {
        SymList *nav = *sl;
        while (nav != NULL)
        {
            if (strcmp(nav->key, key) == 0)
            {
                freeData(nav->value);
                nav->value = NULL;
                nav->value = value;
                return;
            }
            nav = nav->next;
        }
    }
    else
    {
        *sl = new_SL(key, value, *sl);
    }
}
void suprime_SL(char *key, SymList **sl)
{
    if (!sl)
    {
        envError("puntero null en suprime_SL");
        return;
    }
    if (!pertence_SL(key, *sl))
    {
        return;
    }

    SymList *cab = *sl;
    SymList *ant = NULL;
    while (cab != NULL && strcmp(cab->key, key) != 0)
    {
        ant = cab;
        cab = cab->next;
    }
    if (cab != NULL)
    {
        if (ant == NULL)
        {
            *sl = (*sl)->next;
        }
        else
        {
            ant->next = cab->next;
        }
        free(cab->key);
        freeData(cab->value);
        free(cab);
    }
}

/*=======================================================================*/

/*=======================================================================*/
/*                              HASH MAP                                 */
/*=======================================================================*/
static unsigned int h(char *x)
{
    int hash = 0;
    while (*x)
    {
        hash = (hash * 9) ^ (*x);
        x++;
    }
    return hash;
}

HashMap new_HM()
{
    HashMap hm = malloc(sizeof(SymList *) * NHASH);
    if (!hm)
    {
        envError("sin memoria new_HM()");
        return NULL;
    }
    for (int i = 0; i < NHASH; i++)
    {
        hm[i] = NULL;
    }
    return hm;
}
void delete_HM(HashMap hm)
{
    if (!hm)
    {
        envError("delete de null en delete_HM()");
        return;
    }
    for (int i = 0; i < NHASH; i++)
    {
        delete_SL(hm[i]);
        hm[i] = NULL;
    }
}

boolean pertenece_HM(char *key, HashMap hm)
{
    if (!hm)
    {
        envError("vector null en pretenece_HM()");
        return FALSE;
    }
    int cubeta = h(key) % NHASH;
    return pertence_SL(key, hm[cubeta]);
}
tData localiza_HM(char *key, HashMap hm)
{
    if (!hm)
    {
        envError("vector null en localiza_HM()");
        return NULL;
    }
    int cubeta = h(key) % NHASH;
    return localiza_SL(key, hm[cubeta]);
}
void inserta_HM(char *key, tData value, HashMap hm)
{
    if (!hm)
    {
        envError("vector null en insert_HM()");
        return;
    }
    int cubeta = h(key) % NHASH;
    inserta_SL(key, value, &(hm[cubeta]));
}
void suprime_HM(char *key, HashMap hm)
{
    if (!hm)
    {
        envError("vector nulo en suprime_HM()");
        return;
    }
    int cubeta = h(key) % NHASH;
    suprime_SL(key, &hm[cubeta]);
}
/*=======================================================================*/

/*=======================================================================*/
/*                                 ENV                                   */
/*=======================================================================*/
Env *newEnv(Env *parent)
{
    Env *e = malloc(sizeof(Env));
    if (!e)
    {
        envError("sin memoria en newEnv()");
        return NULL;
    }
    e->map = new_HM();
    e->parent = parent;
    return e;
}
Env *MAIN_ENV()
{
    return newEnv(NULL);
}
void deleteEnv(Env *e)
{
    if (!e)
    {
        envError("delete de null en deleteEnv()");
        return;
    }
    delete_HM(e->map);
    free(e);
}

void binding(char *key, tData value, Env *e)
{
    if (!e)
    {
        envError("Env null en binding()");
        return;
    }
    inserta_HM(key, value, e->map);
}
tData reference(char *key, Env *e)
{
    if (!e)
    {
        envError("Env null en reference()");
        return NULL;
    }
    return localiza_HM(key, e->map);
}
boolean is_binded(char *key, Env *e)
{
    if (!e)
    {
        envError("Env null en is_binded()");
        return FALSE;
    }
    return pertenece_HM(key, e->map);
}
/*=======================================================================*/

/*=======================================================================*/
/*                             ARGUMENT                                 */
/*=======================================================================*/
Argument *newValueArg(Ast *a)
{
    Argument *new = malloc(sizeof(Argument));
    if (!new)
    {
        envError("sin memoria en newActualArg()");
        exit(1);
    }
    new->tipo = xVALOR;
    new->a = a;
    new->data =NULL;
    return new;
}
Argument *newRefArg(char *name)
{
    Argument *new = malloc(sizeof(Argument));
    if (!new)
    {
        envError("sin memoria en newActualArg()");
        exit(1);
    }
    new->tipo = xREFERENCIA;
    new->name = name;
    return new;
}
void deleteArgument(Argument *arg)
{
    if (!arg)
    {
        envError("punteroo null en deleteArgument()");
        exit(1);
    }
    switch (arg->tipo)
    {
    case xREFERENCIA:
        free(arg->name);
        break;
    case xVALOR:
        if(arg->data!=NULL)
            freeData(arg->data);
        freetree(arg->a);  
        break;
    default:
        envError("argType desconocido en deleteArgumnet()");
        exit(1);
        break;
    }
    free(arg);
}
/*=======================================================================*/
/*                           ARGUMENT LIST                               */
/*=======================================================================*/
ArgList *newArgList(Argument *arg, ArgList* sig)
{
    ArgList *new = malloc(sizeof(ArgList));
    if (!new)
    {
        envError("sin memoria en newArgList()");
        exit(1);
    }
    new->arg = arg;
    new->sig = sig;
    return new;
}
void deleteArgList(ArgList *l)
{
    ArgList *temp;
    while (l != NULL)
    {
        temp = l;
        deleteArgument(l->arg);
        l = l->sig;
        free(temp);
    }
}
/*=======================================================================*/

/*=======================================================================*/
/*                             PARAMETER                                 */
/*=======================================================================*/
Parameter *newValueParam(boolean defaul, Ast *a, char *name)
{
    Parameter *new = malloc(sizeof(Parameter));
    if (!new)
    {
        envError("sin memoria en newActualArg()");
        exit(1);
    }
    new->tipo = xVALOR;
    new->defaul = defaul;
    new->a = a;
    new->name_val = name;
    new->data = NULL;
    return new;
}
Parameter *newRefParam(char *name)
{
    Parameter *new = malloc(sizeof(Parameter));
    if (!new)
    {
        envError("sin memoria en newActualArg()");
        exit(1);
    }
    new->tipo = xREFERENCIA;
    new->name_ref = name;
    return new;
}
void deleteParam(Parameter *param)
{
    if (!param)
    {
        envError("puntero null en delteParam()");
        exit(1);
    }
    switch (param->tipo)
    {
    case xVALOR:
    {
        free(param->name_val);
        freetree(param->a);
        if (param->data != NULL)
            freeData(param->data);
        break;
    }
    break;
    case xREFERENCIA:
        free(param->name_ref);
        break;
    default:
        envError("paramType desconocido en deleteParam()");
        exit(1);
        break;
    }
    free(param);
}
/*=======================================================================*/
/*                          PARAMETER LIST                               */
/*=======================================================================*/
ParamList *newParamList(Parameter *p, ParamList *sig)
{
    ParamList *new = malloc(sizeof(ParamList));
    if (!new)
    {
        envError("sin memoria en newParamList()");
        exit(1);
    }
    new->param = p;
    new->sig = sig;
    return new;
}
void deleteParamList(ParamList *l)
{
    ParamList *temp;
    while (l != NULL)
    {
        temp = l;
        deleteParam(l->param);
        l = l->sig;
        free(temp);
    }
}
/*=======================================================================*/

/*=======================================================================*/
/*                              FUNCTION                                 */
/*=======================================================================*/
SubProgram* newSubProgram(SpType tipo, char* name, ParamList* params, Ast* body )
{
    SubProgram* new = malloc(sizeof(SubProgram));
    if(!new)
    {
        envError("sin memoria en newSubProgram()"); exit(1);
    }
    new->tipo = tipo;
    new->name = name;
    new->params = params;
    new->body = body;
}
void deleteSubProgram(SubProgram* p)
{
    if(!p)
    {
        envError("puntero null en deleteSubProgram()"); exit(1);
    }
    free(p->name);
    deleteParamList(p->params);
    freetree(p->body);
    free(p);
}
/*=======================================================================*/
/*                            FUNCTION ENV                               */
/*=======================================================================*/
SpEnv* newSpEnv(SubProgram* f, SpEnv* sig)
{
    SpEnv* new = malloc(sizeof(SpEnv));
    if(!new)
    {
        envError("puntero null en newSpEnv()"); exit(1);
    }
    new->f = f;
    new->sig = sig;
    return new;
}
void binding_SP(SubProgram* f, SpEnv* e)
{
    e->sig = newSpEnv(f, e);
}
SubProgram* reference_SP(char* name, SpEnv* l)
{
    while (l != NULL)
    {
        if(l->f && strcmp(l->f->name, name) == 0)
        {
            return l->f;
        }
        l = l->sig;
    }
    return NULL;
}
boolean is_binded_SP(char* name, SpEnv* l)
{
    while (l != NULL)
    {
        if(l->f && strcmp(l->f->name, name) == 0)
        {
            return TRUE;
        }
        l = l->sig;
    }
    return FALSE;
}
/*=======================================================================*/

void envError(char *error)
{
    fprintf(stderr, "Enviromenrt Error: %s", error);
}

int yyerror(Env *e, SpEnv* fn_e, char *s)
{
    fprintf(stderr, "Error de sintaxis: %s", s);
}