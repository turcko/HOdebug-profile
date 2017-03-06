## Varios bugs

Cuando se corre el programa sin un debugger, puede o no mostrar error.
El error se encuentra en la línea 7, accediendo a espacio de memoria fuera de lo reservado.

- Correr el programa con un debugger, sin agregar flags de
debug. ¿Tienen toda la información que requerían?

RESUESTA: 
>> gcc add_array_dynamic.c -o add_array_dynamic.e  (SIN FLAG)
No se obtiene la informacíón requerida, solo el aviso de existencia del tipo de error.
>> gcc -g -o0 add_array_dynamic.c -o add_array_dynamic.e (CON FLAG)
Ahora sí se obtiene información concreta: tipo y línea donde se encuentra el error.

El único ejecutable que me da un error es el ./add_array_segfault.e: 
>./add_array_static.e 
The addition is 6
>./add_array_dynamic.e 
The addition is 6
>./add_array_segfault.e 
Segmentation fault (core dumped)

Info con flag de debug del archivo add_array_segfault.e:
Program received signal SIGSEGV, Segmentation fault.
0x00000000004005f2 in main (argc=1, argv=0x7fffffffdc08) at add_array_segfault.c:19
19	    b[i] = i;

Hay que tener en cuenta que: en add_array_dynamic y add_array_static acceden a espacios indebidos de memoria.
Por el lado del add_array_segfault utiliza puro arreglo, por eso sucede el error.

- ¿Qué pasa si ponen el flag de debug? ¿Qué flag de optimización es el
mejor para debuggear?
Info con flag de debug del archivo add_array_segfault.e:
Program received signal SIGSEGV, Segmentation fault.
0x00000000004005f2 in main (argc=1, argv=0x7fffffffdc08) at add_array_segfault.c:19
19	    b[i] = i;

- Agreguen algún flag para que informe todos los warnings en la
compilación, como `-Wall`. ¿Alguno les da alguna pista de por qué el
programa se rompe?
-Wall da la misma info que -g. No da pista dónde está el error.

IMPORTANTE: C no controla límites de arreglos. Cuando se solicita espacio con malloc, el SO puede setear el stack a 0 (cero) y "no" dar error en el caso que no contenga basura.


## Segmentation Fault

En la carpeta `sigsegv/` hay códigos de C y de FORTRAN con su
`Makefile`.  Compilen y corran `small.e` y `big.e`.  Identifiquen los
errores que devuelven (¡si devuelven alguno!) los ejecutables.  Ahora
ejecuten `ulimit -s unlimited` en la terminal y vuelvan a
correrlo. Luego responder las siguientes preguntas:
------------------
ejecución comando make all:
>make all
gcc  -g -O0 -D__SMALL matmult.c -o small.e
gcc  -g -O0 matmult.c -o big.e
>./small.e 
>./big.e 
Segmentation fault (core dumped)
------------------

- ¿Devuelven el mismo error que antes?
Sí, devuelve el mismo error que antes.


- Averigüen qué hicieron al ejecutar la sentencia `ulimit -s
unlimited`. Algunas pistas son: abran otra terminal distinta y fíjense
si vuelve al mismo error, fíjense la diferencia entre `ulimit -a`
antes y después de ejecutar `ulimit -s unlimited`, googleen, etcétera.
La definición de la matriz:
float temp[SIZE][SIZE];
...
temp[j][i] = A[(i * SIZE) + j];
Supera el espacio disponible para el stack (memoria estática) para la función (error segmentation fault)

Al ejecutar el comando "ulimit -s unlimited", el SO sede espacio indefinido del stack a la función (caso no 
deseado a la hora de pasar un código a otra persona, ya que debería ejecutar el comando previamente).

>ulimit -a
core file size          (blocks, -c) 0
data seg size           (kbytes, -d) unlimited
scheduling priority             (-e) 0
file size               (blocks, -f) unlimited
pending signals                 (-i) 46085
max locked memory       (kbytes, -l) 64
max memory size         (kbytes, -m) unlimited
open files                      (-n) 1024
pipe size            (512 bytes, -p) 8
POSIX message queues     (bytes, -q) 819200
real-time priority              (-r) 0
stack size              (kbytes, -s) 8192
cpu time               (seconds, -t) unlimited
max user processes              (-u) 46085
virtual memory          (kbytes, -v) unlimited
file locks                      (-x) unlimited

Ejecutando el comando ulimit -a luego del unlimited, muestra todo el espacio disponible para el stack.

>ulimit -a
core file size          (blocks, -c) 0
data seg size           (kbytes, -d) unlimited
scheduling priority             (-e) 0
file size               (blocks, -f) unlimited
pending signals                 (-i) 46085
max locked memory       (kbytes, -l) 64
max memory size         (kbytes, -m) unlimited
open files                      (-n) 1024
pipe size            (512 bytes, -p) 8
POSIX message queues     (bytes, -q) 819200
real-time priority              (-r) 0
stack size              (kbytes, -s) unlimited
cpu time               (seconds, -t) unlimited
max user processes              (-u) 46085
virtual memory          (kbytes, -v) unlimited
file locks                      (-x) unlimited


- La "solución" anterior, ¿es una solución en el sentido de debugging?
No, no es una solución en el sentido del debugging. Pues habría que ceder todo el stack para la ejecución 
del programa.

- ¿Cómo harían una solución más robusta que la anterior, que no
requiera tocar los `ulimits`?
Para dar una solución optima, habría que modificar el tipo de dato de la matriz en general.
temp = (float *) malloc(SIZE * SIZE * sizeof(float));

//Conclusión
Para evitar poner ulimit, se requiere pasar el alojamiento de los datos del stack al heap (malloc).
Problema de big.e, valores que da la matriz: SIZE + SIZE + 4 (TAMA INT) = 2500 * 2500 * 4 = 25000000 Mb > 8 Kb (tama stack por defecto)



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