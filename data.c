#include "data.h"
#include "defs.h"
#include <math.h>
/*==========================================================================*/
/*								CONSTRUCTORES								*/
/*==========================================================================*/
tData createData(int tipo)
{
	tData nvo; 
	nvo = (tData)malloc(sizeof(TNodoData));

	switch (tipo)
	{
	case STR:
		nvo->cad = create();
		break;

	case LIST:
	case SET:
		nvo->dato = NULL;
		nvo->sig = NULL;
		break;

	case INT:
		nvo->value = 0;
		break;

	case DOUBLE:
		nvo->real = 0.0;
		break;

	case BOOL:
		nvo->value = 0;
		break;

	default:
		printf("Error en createData tipo desconocido.\n");
		break;
	}
	nvo->tipoNodo = tipo;

	return nvo;
}

tData createStr(char *s)
{
	tData nvo = createData(STR);
	nvo->cad = load2(s);
	return nvo;
}
tData createInt(int value)
{
	tData nvo = createData(INT);
	nvo->value = value;
	return nvo;
}
tData createDouble(double real)
{
	tData nvo = createData(DOUBLE);
	nvo->real = real;
	return nvo;
}
tData createBool(char *s)
{
	if (!s)
	{
		printf("char* null en create bool ");
		return NULL;
	}
	int i, b;
	tData nvo = createData(BOOL);

	char *_true = "true";
	i = 0;
	b = 1;
	while (i < 4 && b)
	{
		if (s[i] != _true[i])
			b = 0;
		i++;
	}
	if (b)
	{
		nvo->value = 1;
		return nvo;
	}

	char *_false = "false";
	i = 0;
	b = 1;
	while (i < 4 && b)
	{
		if (s[i] != _false[i])
			b = 0;
		i++;
	}
	if (b)
	{
		nvo->value = 0;
		return nvo;
	}
	printf("error %s no es una valor valido para createBool", s);
	return NULL;
}

/*==========================================================================*/
/*								GETTER Y SETTERS							*/
/*==========================================================================*/
tData get_dato(tData a)
{
	if (get_tipo(a) == LIST || get_tipo(a) == SET)
	{
		return a->dato;
	}
	else
	{
		printf("error %d no tiene campo dato", get_tipo(a));
		return NULL;
	}
}
tData get_next(tData a)
{
	if (get_tipo(a) == LIST || get_tipo(a) == SET)
	{
		return a->sig;
	}
	else
	{
		printf("error %d no tiene campo sig", get_tipo(a));
		return NULL;
	}
}
void set_next(tData *node, tData next)
{
	if(!(*node))
	{
		printf("error en set_next puntero null");
		return;
	}
	if(get_tipo(*node) != SET && get_tipo(*node) != LIST)
	{
		printf("set_next solo funciona para nodotipo LIST SET");
		return;
	}
	(*node)->sig = next;
}
void set_dato(tData *node, tData dato)
{
	if(!(*node))
	{
		printf("error en set_dato puntero null");
		return;
	}
	if(get_tipo(*node) != SET && get_tipo(*node) != LIST)
	{
		printf("set_dato solo funciona para nodotipo LIST SET");
		return;
	}
	(*node)->dato = dato;
}

int get_tipo(tData a)
{
	if(!a)
	{
		printf("get_tipo recibe puntero null");
		return 0;
	}
	return a->tipoNodo;
}
int get_bool_value(tData a){
	if(!a)
	{
		//printf("\nEs aqui\n");
		printf("puntero null en get_bool_value\n");
		return 0;
	}
	int bool_value;
	switch (get_tipo(a))
	{
	case INT: case BOOL:
		bool_value = get_value(a);
		break;
	case DOUBLE:
		if(get_real(a) == 0.0)
		{
			bool_value = 0;
		}
		else 
		{
			bool_value = 1;
		}
		break;
	case STR:
		bool_value = 1;
		break;
	case LIST: case SET:
		if(get_dato(a) == NULL)
		{
			return 0;
		}
		else
		{
			return 1;
		}
		break;
	default:
		printf("tipoNodo desconocido get_bool_value\n");
		bool_value = 0;
		break;
	}
	return bool_value;
}

int get_value(tData a)
{
	if (!a)
	{
		printf("\nQuiere obtener un valor de un tdata vacio.\n");
		exit(1);
	}
	if(get_tipo(a) != INT && get_tipo(a) != BOOL)
	{
		printf("error en get_value solo para nodotipo INT o BOOL\n");
		return 0;
	}
	return a->value;
}
double get_real(tData a)
{
	if (get_tipo(a) != DOUBLE)
	{
		printf("error %d no tiene campo real", get_tipo(a));
		return 0;
	}
	else
	{
		return a->real;
	}
}
str get_cad(tData a)
{
	if (get_tipo(a) != STR)
	{
		printf("error %d no tiene campo cad", get_tipo(a));
		return 0;
	}
	else
	{
		return a->cad;
	}
}

/*==========================================================================*/
/*							OPERACIONES ARITMETICAS							*/
/*==========================================================================*/
tData sumaData(tData a, tData b)
{
	if (!a || !b)
	{
		printf("punteros nulos en sumaData");
		return NULL;
	}
	if (a->tipoNodo == DOUBLE && b->tipoNodo == DOUBLE)
		return createDouble(a->real + b->real);
	if (a->tipoNodo == DOUBLE && b->tipoNodo == INT)
		return createDouble(a->real + b->value);
	if (a->tipoNodo == INT && b->tipoNodo == DOUBLE)
		return createDouble(a->real + b->value);
	return createInt(a->value + b->value);
}
tData restaData(tData a, tData b)
{
	if (!a || !b)
	{
		printf("punteros nulos en restaData");
		return NULL;
	}
	if (a->tipoNodo == DOUBLE && b->tipoNodo == DOUBLE)
		return createDouble(a->real - b->real);
	if (a->tipoNodo == DOUBLE && b->tipoNodo == INT)
		return createDouble(a->real - b->value);
	if (a->tipoNodo == INT && b->tipoNodo == DOUBLE)
		return createDouble(a->real - b->value);
	return createInt(a->value - b->value);
}
tData prodData(tData a, tData b)
{
	if (!a || !b)
	{
		printf("punteros nulos en prodData");
		return NULL;
	}
	if (a->tipoNodo == DOUBLE && b->tipoNodo == DOUBLE)
		return createDouble(a->real * b->real);
	if (a->tipoNodo == DOUBLE && b->tipoNodo == INT)
		return createDouble(a->real * b->value);
	if (a->tipoNodo == INT && b->tipoNodo == DOUBLE)
		return createDouble(a->real * b->value);
	return createInt(a->value * b->value);
}
tData cocData(tData a, tData b)
{
	if (!a || !b)
	{
		printf("punteros nulos en divData");
		return NULL;
	}
	if (a->tipoNodo == DOUBLE && b->tipoNodo == DOUBLE)
		return createDouble(a->real / b->real);
	if (a->tipoNodo == DOUBLE && b->tipoNodo == INT)
		return createDouble(a->real / b->value);
	if (a->tipoNodo == INT && b->tipoNodo == DOUBLE)
		return createDouble(a->real / b->value);
	return createInt(a->value / b->value);
}

/*==========================================================================*/
/*							OPERACIONES RELACIONALES							*/
/*==========================================================================*/
tData compara_mayor(tData A, tData B){
	tData nuevo;
	if(!A || !B)
	{
		printf("puntero null en compara_mayor\n");
		return NULL;
	}
	if(get_tipo(A) != get_tipo(B))
	{
		printf("las comparaciones deben tener operandos de mismo tipo\n");
		return NULL;
	}
	
	switch (get_tipo(A))
	{
	case INT: nuevo = (get_value(A) > get_value(B)) ? createBool("true") : createBool("false"); break;
	case DOUBLE: nuevo = (get_real(A) > get_real(B)) ?  createBool("true"): createBool("false"); break;
	
	case SET: case LIST: case BOOL:
	{
		printf("Error: No se pueden comparar usando mayor las estos tipos de datos \n");
		break;
	}
	
	default: printf("Error: hola diablo\n"); break;
	}
	return nuevo;
}
tData compara_menor(tData A, tData B)
{	
	tData nuevo;
	if(!A || !B)
	{
		printf("puntero null en compara_menor\n");
		return NULL;
	}
	if(get_tipo(A) != get_tipo(B))
	{
		printf("las comparaciones deben tener operandos de mismo tipo\n");
		return NULL;
	}
	
	switch (get_tipo(A))
	{
	case INT: nuevo = (get_value(A) < get_value(B)) ? createBool("true") : createBool("false"); break;
	case DOUBLE: nuevo = (get_real(A) < get_real(B)) ?  createBool("true"): createBool("false"); break;
	
	case SET: case LIST: case BOOL:
	{
		printf("Error: No se pueden comparar usando menor las estos tipos de datos \n");
		break;
	}
	default: printf("Error: hola diablo\n"); break;
	}
	return nuevo;
}
tData compara_mayorigual(tData A, tData B)
{
	tData nuevo;
	if(!A || !B)
	{
		printf("puntero null en compara_mayorigual\n");
		return NULL;
	}
	if(get_tipo(A) != get_tipo(B))
	{
		printf("las comparaciones deben tener operandos de mismo tipo\n");
		return NULL;
	}
	
	switch (get_tipo(A))
	{
	case INT: nuevo = (get_value(A) >= get_value(B)) ? createBool("true") : createBool("false"); break;
	case DOUBLE: nuevo = (get_real(A) >= get_real(B)) ?  createBool("true"): createBool("false"); break;
	
	case SET: case LIST: case BOOL:
	{
		printf("Error: No se pueden comparar usando mayor-igual las estos tipos de datos \n");
		break;
	}
	default: printf("Error: hola diablo\n"); break;
	}
	return nuevo;
}
tData compara_menorigual(tData A, tData B){
	tData nuevo;
	if(!A || !B)
	{
		printf("puntero null en compara_menorigual\n");
		return NULL;
	}
	if(get_tipo(A) != get_tipo(B))
	{
		printf("las comparaciones deben tener operandos de mismo tipo\n");
		return NULL;
	}
	
	switch (get_tipo(A))
	{
	case INT: nuevo = (get_value(A) <= get_value(B)) ? createBool("true") : createBool("false"); break;
	case DOUBLE: nuevo = (get_real(A) <= get_real(B)) ?  createBool("true"): createBool("false"); break;
	
	case SET: case LIST: case BOOL:
	{
		printf("Error: No se pueden comparar usando menor-igual las estos tipos de datos \n");
		break;
	}
	
	default: printf("Error: hola diablo\n"); break;
	}
	return nuevo;
}
tData compara_igual(tData A, tData B)
{
	tData nuevo;
	if(!A || !B)
	{
		printf("puntero null en compara_igual\n");
		return NULL;
	}
	if(get_tipo(A) != get_tipo(B))
	{
		printf("las comparaciones deben tener operandos de mismo tipo\n");
		return NULL;
	}
	
	switch (get_tipo(A))
	{
	case INT: case BOOL: nuevo = (get_value(A) == get_value(B)) ? createBool("true") : createBool("false"); break;
	case DOUBLE: nuevo = (get_real(A) == get_real(B)) ?  createBool("true"): createBool("false"); break;
	case SET: case LIST: 
	{
		nuevo = (Igualdad(A,B) == 0) ? createBool("true") : createBool("false");
		break;
	}
	case STR:
		{
			nuevo = (!compStr(get_cad(A), get_cad(B))) ? createBool("true") : createBool("false");
		}
		break;
	default: printf("Error: hola diablo\n"); break;
	}
	return nuevo;
}
tData compara_distinto(tData A, tData B)
{
	tData nuevo;
	if(!A || !B)
	{
		printf("puntero null en compara_distinto\n");
		return NULL;
	}
	if(get_tipo(A) != get_tipo(B))
	{
		printf("las comparaciones deben tener operandos de mismo tipo\n");
		return NULL;
	}
	
	switch (get_tipo(A))
	{
	case INT: case BOOL: nuevo = (get_value(A) != get_value(B)) ? createBool("true") : createBool("false"); break;
	case DOUBLE: nuevo = (get_real(A) != get_real(B)) ?  createBool("true"): createBool("false"); break;
	case SET: case LIST: 
	{
		nuevo = (Igualdad(A,B) == 1) ? createBool("true") : createBool("false");
		break;
	}
	case STR:
		{
			nuevo = (compStr(get_cad(A), get_cad(B))) ? createBool("true") : createBool("false");
		}
		break;
	default: printf("Error: hola diablo\n"); break;
	}
	return nuevo;
}

/*==========================================================================*/
/*							MODULOS BASICOS TDATA							*/
/*==========================================================================*/
void mostrarData(tData nodo)
{
	if (nodo == NULL)
	{
		// printf("_mostrando vacio_\n");
		return;
	}


	switch (nodo->tipoNodo)
	{
	case STR:
		print(nodo->cad);
		break;
	case INT:
		printf("%d", nodo->value);
		break;
	case DOUBLE:
		printf("%f", nodo->real);
		break;
	case BOOL:
		(nodo->value == 0) ? printf("false") : printf("true");
		break;
	case LIST:
		printf("[");

		tData aux;
		aux = nodo;
		while (aux != NULL)
		{
			mostrarData(aux->dato);
			if (aux->sig != NULL)
				printf(",");
			aux = aux->sig;
		}
		printf("]");

		break;
	case SET:
		printf("{");

		tData aux2;
		aux2 = nodo;
		while (aux2 != NULL)
		{
			mostrarData(aux2->dato);
			if (aux2->sig != NULL)
				printf(",");
			aux2 = aux2->sig;
		}
		printf("}");
		break;
	}
}
void agregarData(tData *cabe, tData elem)
{
	tData cab = *cabe;
	if (!cab)
	{
		printf("No se puede agregar un elemento a un espacio de memoria no asignado");
		return;
	}
	if (get_tipo(cab) != SET && get_tipo(cab) != LIST)
	{
		printf("No se puede agregar un elemento a un objeto que no es list o conjunto");
		return;
	}
	if (cab->dato == NULL)
	{
		cab->dato = elem; // copiarlo
	}
	else
	{
		switch (cab->tipoNodo)
		{
		case STR:
		case INT:
		case DOUBLE:
		case BOOL:
			break;
		case SET:
		case LIST:
		{
			tData nvo;

			if (cab->tipoNodo == SET)
			{
				if (pertenece(cab, elem) == 0)
					return;
			}
			// printf("Estoy en agregarData\n");

			while (cab->sig != NULL)
				cab = cab->sig;
			nvo = createData(cab->tipoNodo);
			nvo->dato = copiarData(elem);
			cab->sig = nvo;
			break;
		}
		default:
			printf("caso no def en agregarData");
			break;
		}
	}
	// printf("\n\ndespues de agregar elem: ");
	// mostrarData(elem);
	// printf("\nla lista cab quedo: ");
	// mostrarData(*cabe);
	// printf("\n");
}
tData copiarData(tData copiado)
{
	tData nvo = NULL;
	if (copiado == NULL)
		return NULL;
	switch (copiado->tipoNodo)
	{
	case INT:
		nvo = createInt(copiado->value);
		break;
	case DOUBLE:
		nvo = createDouble(copiado->real);
		break;
	case BOOL:
		if (get_value(copiado))
		{
			nvo = createBool("true");
		}
		else
		{
			nvo = createBool("false");
		}
		break;
	case STR:
		nvo = createData(STR);
		nvo->cad = copyStr(copiado->cad);
		break;
	case LIST:
		nvo = createData(LIST);
		nvo->dato = copiarData(copiado->dato);
		nvo->sig = copiarData(copiado->sig);
		break;
	case SET:
		nvo = createData(SET);
		nvo->dato = copiarData(copiado->dato);
		nvo->sig = copiarData(copiado->sig);
		break;
	}

	return nvo;
}
void freeData(tData descartado)
{

	if (descartado == NULL)
		return;

	switch (descartado->tipoNodo)
	{
	case STR:
		freeString(descartado->cad);
		break;
	case LIST:
	case SET:
		freeData(descartado->dato);
		freeData(descartado->sig);
		break;
	default: break;
	}

	free(descartado);
}
int Igualdad(tData A, tData B)
{

	if (A == NULL || B == NULL)
	{
		printf("Igualdad recibe punteros nulo\n");
		return 0;
	}
	if ((A->tipoNodo != B->tipoNodo))
	{
		return 1;
	}

	switch (A->tipoNodo)
	{
	case STR:
		return compStr(A->cad, B->cad);
		break;
	case BOOL:
	case INT:
		return !(get_value(A) == get_value(B));
	case DOUBLE:
		return !(get_real(A) == get_real(B));
	case SET:
	{
		tData auxA = A;
		while (auxA != NULL)
		{
			if (pertenece(B, auxA->dato) != 0) // 0 pertenece. 1 no pertenece
				return 1; //distintos
			auxA = auxA->sig;
		}
		tData auxB = B;
		while (auxB != NULL)
		{
			if (pertenece(A, auxB->dato) != 0)
				return 1;
			auxB = auxB->sig;
		}
		return 0; // iguales. todo A e B, todo B e A
	}

	case LIST:
	{
		tData auxA = A;
		tData auxB = B;

		while (auxA != NULL && auxB != NULL)
		{
			if (Igualdad(auxA->dato, auxB->dato) != 0)
				return 1; //1 no son iguales, 0 iguales
			auxA = auxA->sig;
			auxB = auxB->sig;
		}
		if (auxA != NULL || auxB != NULL)
			return 1; // si uno es mas largo que el otro

		return 0; // iguales
	}
	default:
		printf("tipoNodo desconocido\n");
		return 1;
	}
}

/*==========================================================================*/
/*							OPERACIONES CONJUNTOS							*/
/*==========================================================================*/

tData Union(tData A, tData B)
{
	if (A == NULL )
	{
		return copiarData(B);
	}
	if ( get_dato(A) == NULL )
	{
		return copiarData(B); // B es el conj => AuB = A
	}
	if (B == NULL )
	{
		return copiarData(A);
	}
	if ( get_dato(B) == NULL )
	{
		return copiarData(A); // B es el conj => AuB = A
	}

	if (A->tipoNodo != SET || B->tipoNodo != SET)
		return NULL;

	tData C_Cab = NULL, C_act = NULL;
	tData aux;

	while (A != NULL)
	{

		aux = createData(SET);
		aux->dato = copiarData(A->dato);

		if (C_Cab == NULL)
			C_Cab = aux;
		else
			C_act->sig = aux;

		C_act = aux;

		A = A->sig;
	}
	
	while (B != NULL)
	{
		if ( pertenece(C_Cab, B->dato) )  // 1 si no pertence => agrega
		{
			
			aux = createData(SET);
			aux->dato = copiarData(B->dato);

			if (C_Cab == NULL)
				C_Cab = aux;
			else
				C_act->sig = aux;

			C_act = aux;
		}
		B = B->sig;
	}

	return C_Cab;
}
tData Interseccion(tData A, tData B)
{
	if (A == NULL || B == NULL)
		return NULL;

	if (A->tipoNodo != SET || B->tipoNodo != SET)
		return NULL;
	tData C_Cab = NULL, C_act = NULL;
	tData aux;
	while (A != NULL)
	{

		if (!pertenece(B, A->dato))
		{

			aux = createData(SET);
			aux->dato = copiarData(A->dato);

			if (C_Cab == NULL)
				C_Cab = aux;
			else
				C_act->sig = aux;

			C_act = aux;
		}
		A = A->sig;
	}
	return C_Cab;
}
tData Diferencia(tData A, tData B)
{
	if (A == NULL)
		return NULL;
	if (B == NULL)
		return copiarData(A);

	if (A->tipoNodo != SET || B->tipoNodo != SET)
		return NULL;

	tData C_Cab = NULL, C_act = NULL;
	tData aux;
	while (A != NULL)
	{

		if (pertenece(B, A->dato))
		{

			aux = createData(SET);
			aux->dato = copiarData(A->dato);

			if (C_Cab == NULL)
				C_Cab = aux;
			else
				C_act->sig = aux;

			C_act = aux;
		}
		A = A->sig;
	}
	return C_Cab;
}
tData DifSimetrica(tData A, tData B)
{
	if (A->tipoNodo != SET || B->tipoNodo != SET)
		return NULL;

	tData D = Diferencia(A, B);
	tData E = Diferencia(B, A);

	tData F = NULL;
	F = Union(D, E);

	return F;
}
int pertenece(tData A, tData elem)
{
	if ( A == NULL  )
	{
		printf("pertenece recibe conj: puntero nulo\n");
		return 1;
	}
	if ( elem == NULL)
	{
		//printf("pertenece recibe punteros nulos\n");
		return 1;
	}
	if (A->tipoNodo != LIST && A->tipoNodo != SET){
		printf("pertenece no recibe un conjunto o lista\n");
		return 1;
	}

	tData aux = A;

	while (aux != NULL)
	{
		//if (! aux->dato){printf("conj vacio\n");}
		if (Igualdad(aux->dato, elem) == 0) // si son iguañes
			return 0; // si pertenece
		aux = aux->sig;
	}

	return 1; // no pertenece
}
int pertenece_completing(tData elem, tData A)
{
	int band = 0; // elem no pertenece
	while (A != NULL && !band)
	{
		if ( Igualdad(elem, get_dato(A)) == 0 ) // pertenece(a,b)
			band = 1;  // elem si pertenece //no b=0
		A = get_next(A);
	}
	return band;
}
int contenido(tData A, tData B)
{

	tData auxA = A;
	while (auxA != NULL) // A c B <=> VaeA | aeB
	{
		if (pertenece(B, auxA->dato) != 0) // 0 pertence. 1 no pertenece
			return 0; 
		auxA = auxA->sig;
	}
	return 1;
}

/*==========================================================================*/
/*							OPERACIONES LISTA								*/
/*==========================================================================*/
tData concat_list(tData a, tData b)
{
	tData nuevo = createData(LIST);
	if (!a || !b)
	{
		printf("error concatenar_listas  de listas nulas");
		return NULL;
	}

	while (a != NULL)
	{
		agregarData(&nuevo, get_dato(a));
		a = get_next(a);
	}
	
	while (b != NULL)
	{
		agregarData(&nuevo, get_dato(b));
		b = get_next(b);
	}
	
	return nuevo;
}
void eliminar_pos(tData *l, int pos)
{
	int i;
	tData ant, nav;
	nav = *l;
	ant = NULL;

	if (!nav)
	{
		printf("Error eliminar_pos nav null");
		return ;
	}
	if ( get_tipo(nav) != LIST )
	{
		printf("Error eliminar_pos es una operacion de listas");
		return;
	}

	for (i = 1; i < pos && nav; i++)
	{
		ant = nav;
		nav = get_next(nav);
	}
	if (!nav)
		return; // posicion fuera de la lista
	if (!ant)
	{ // eliminar cabeza

		*l = get_next(nav);
		if (*l == NULL)
		{ // corresponde lista vacia
			*l = createData(LIST);
		}
		//freeData(get_dato(nav));
		//freeData(nav);
	}
	else
	{ // eliminacion en lista
		set_next(&ant, get_next(nav));
		//freeData(nav);
	}
}

/*==========================================================================*/
/*					   OPERACIONES LISTA Y CONJUNTOS						*/
/*==========================================================================*/
tData elemento_pos(tData data, int pos)
{
	if (!data)
	{
		printf("puntero nulo en elemento_pos\n");
		return NULL;
	}
	if (get_tipo(data) != SET && get_tipo(data) != LIST)
	{
		printf("Error elemento_pos es una operacion de listas o conjuntos\n");
		return NULL;
	}
	int i = 1;
	while (i < pos && data != NULL)
	{
		i++;
		data = get_next(data);
	}
	if (i == pos && data != NULL)
		return get_dato(data);
	printf("Posicion más grande que lista.\n");
	return createStr("-1"); // createInt(-1);
}
int tamanio(tData A)
{
	if ( !A ) 
	{
		printf("Error interno tamanio puntero null\n");
		return 0;
	}
	
	if ( A->tipoNodo != SET && A->tipoNodo != LIST )
		return 1;
		

	int c = 0;
	if ( get_next(A) == NULL )
	{
		if ( get_dato(A) == NULL )
		{
			return 0; // lista vacia
	
		}
	}
	
	while (A != NULL)
	{
		c++;
		A = A->sig;
	}
	
	return c;
}
tData negar_data(tData data)
{
	tData nuevo = NULL;
	if(!data)
	{
		return NULL;
	}
	switch (get_tipo(data))
    {
        case STR:
		{
			nuevo = copiarData(data);
			break;
		}
		case INT: 
        {
            nuevo = createInt(-get_value(data));
            break;
        } 
        case DOUBLE:
        {
            nuevo = createDouble(-get_real(data));
            break;
        }
        case BOOL:
        {
            if(get_value(data))
            {
                nuevo = createBool("false");
            }
            else
            {
                nuevo = createBool("true");
            }
            break;
        }
        case LIST: 
        {
            nuevo = createData(LIST);
			nuevo->dato = negar_data(data->dato);
			nuevo->sig = negar_data(data->sig);
            break;
        }         
		case SET:
		{
			nuevo = createData(SET);
			nuevo->dato = negar_data(data->dato);
			nuevo->sig = negar_data(data->sig);
            break;
		}
        default:
		{
			printf("nodotipo desconocido en negar_data\n");
            break;
		}
    }
	return nuevo;
}
tData modulo_data(tData data)
{
	tData modulo_data;
	if(!data)
	{
		printf("puntero null en modulo_data\n");
		return 0;
	}
	if(get_tipo(data) == BOOL)
	{
		printf("Error en modulo_data data es de tipo bool\n");
		return NULL;
	}
	switch (get_tipo(data))
	{ 
	case INT:
	{ 
		modulo_data = createInt(abs(get_value(data)));
		break;
	}
	case DOUBLE:
	{
		modulo_data = createDouble(fabs(get_real(data)));
		break;
	}
	case STR:
	{
		modulo_data = createInt(1);
		break;
	}
	case LIST: case SET:
	{
		modulo_data = createInt(tamanio(data));
		break;
	}
	default:
	{
		printf("tiponodo desconocido en modulo_data\n");
		break;
	}
	}

	
	return modulo_data;
}
