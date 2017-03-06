# Debug

En esta carpeta hay cinco carpetas, cada una
con sus ejercicios. Las respuestas a los ejercicios tienen que estar
en esta carpeta, bajo el nombre `respuestas.md`.

## Varios bugs

En la carpeta `bugs/` hay varios bugs ya hechos y resueltos, pensado
para hacerlo en clase. Aquí tenemos un `Makefile` donde, además,
usamos una nueva variable: `$CFLAGS`. En esa variable pueden poner los
distintos flags de compilación que quieran pasarle a `$CC`. Esta
carpeta ya tiene un `Makefile` hecho, que compila todos los
casos. Algunas cosas que pueden hacer es:

- Correr el programa con un debugger, sin agregar flags de
debug. ¿Tienen toda la información que requerían?
- ¿Qué pasa si ponen el flag de debug? ¿Qué flag de optimización es el
mejor para debuggear?
- Agreguen algún flag para que informe todos los warnings en la
compilación, como `-Wall`. ¿Alguno les da alguna pista de por qué el
programa se rompe?


## Floating point exception

En la carpeta `fpe/` hay tres códigos de C, independientes, para
compilar.  Cada uno de estos códigos genera un ejecutable. Hay además
una carpeta que define la función `set_fpe_x87_sse_`. Una vez
compilados los tres ejecutables sin la opción `-DTRAPFPE`, responder
las siguientes preguntas:

- ¿Qué función requiere agregar `-DTRAPFPE`? ¿Cómo pueden hacer que el
programa *linkee* adecuadamente?
- Para cada uno de los ejecutables, ¿qué hace agregar la opción
`-DTRAPFPE` al compilar? ¿En qué se diferencian los mensajes de salida
de los programas con y sin esa opción cuando tratan de hacer una
operación matemática prohbida, como dividir por 0 o calcular la raíz
cuadrada de un número negativo?

Nota: Si agregan `-DTRAPFPE`, el programa va a tratar de incluir, en
la compilación, un archivo `.h` que está en la carpeta
`fpe_x87_sse`. Para pedirle al compilador que busque archivos `.h` en
una carpeta, usen el flag `-Icarpeta` (sí, sin espacio en el medio).

Otra nota: Para poder linkear `fpe_x87_sse.c` tienen que agregar la
librería matemática `libm`, con `-lm`.


## Segmentation Fault

En la carpeta `sigsegv/` hay códigos de C y de FORTRAN con su
`Makefile`.  Compilen y corran `small.e` y `big.e`.  Identifiquen los
errores que devuelven (¡si devuelven alguno!) los ejecutables.  Ahora
ejecuten `ulimit -s unlimited` en la terminal y vuelvan a
correrlo. Luego responder las siguientes preguntas:

- ¿Devuelven el mismo error que antes?
- Averigüen qué hicieron al ejecutar la sentencia `ulimit -s
unlimited`. Algunas pistas son: abran otra terminal distinta y fíjense
si vuelve al mismo error, fíjense la diferencia entre `ulimit -a`
antes y después de ejecutar `ulimit -s unlimited`, googleen, etcétera.
- La "solución" anterior, ¿es una solución en el sentido de debugging?
- ¿Cómo harían una solución más robusta que la anterior, que no
requiera tocar los `ulimits`?

## Valgrind

En la carpeta `valgrind/` hay ejemplos en C y FORTRAN que se pueden
ejecutar con valgrind. Describan el error y por qué sucede

## Funny

En la carpeta `funny/` hay un código de C. Describan las diferencias
de los ejecutables al compilar con y sin el flag `-DDEBUG`. ¿De dónde
vienen esas diferencias?

