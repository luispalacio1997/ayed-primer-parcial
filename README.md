# JSON-AYED Validator

Proyecto de la asignatura Algoritmos y Estructuras de Datos para validar estructuras JSON-AYED en C++.

## Funcionalidades
- Leer archivos JSON-AYED.
- Validar la sintaxis.
- Generar un archivo de salida limpio.

## Estructura del proyecto
- `src/`: Código fuente.
- `src/Components/`: Clases específicas para componentes JSON-AYED.
- `README.md`: Descripción del proyecto.

--------------------------------------------------------------------------------------------------------------------

## Consigna del trabajo

- Realizar un programa que evalúe un archivo de formato JSON-AYED.
Una expresión de este tipo es una expresión delimitada por llaves que internamente tiene subexpresiones separadas por comas, donde una subexpresión es alguna de las siguientes:

Un par (llave: valor), ambos strings delimitados por comillas dobles.
Ejemplo: "nombre": "Carlos"

Un par ("llave": lista) de strings separados por comas y delimitados por corchetes.
Ejemplo: "telefonos": ["351-4555666", "351-5012789"]

Un par (llave: subexpresion) recursivamente definida delimitada por llaves ({}).

Un ejemplo completo sería:

{
  "nombre": "Carlos",
  "apellido": "Garciarena",
  "domicilio": {
    "calle": "San martin",
    "altura": "33",
    "ciudad": "Jujuy",
    "telefonos": ["351-4555666", "351-5012789"]
  },
  "conyuge": "Ana Castro",
  "hijos": ["Ana Garciarena", "Lucas Garciarena"]
}

Requerimientos del programa:

Leer un archivo de texto que contenga una sola expresión JSON-AYED.
Validar que sea correctamente escrita.
Imprimirla en otro archivo eliminando los espacios, saltos de línea y tabs.
Si no es correcta, indicar dónde se produjo el error en la expresión.
Lineamientos específicos:

Leer los caracteres del archivo de entrada uno a uno.
Usar estructuras de pilas y colas para la validación.
Cada componente de una expresión JSON-AYED debe ser representado por una clase:
Expresión entre llaves (expresión JSON-AYED).
Expresión llave: valor.
Expresión llave: expresión JSON-AYED.
Expresión llave: lista de strings.

Especificaciones técnicas:

Cada clase debe tener una pila para evaluar la correctitud de la expresión.
La lista de strings debe contar con una cola para almacenar los valores.
Los modos de evaluación determinarán la validez del próximo carácter leído.
Ejemplo: una pila vacía indica que se espera una llave de apertura ({).
Un string debe empezar y terminar con comillas dobles.
Cada modo debe tener su propia pila de evaluación.
Cambiar entre modos activará o desactivará las pilas correspondientes.
Estructura de clases en C++:

Cada clase debe tener un buffer para almacenar el contenido de la instancia.
Un método print permitirá imprimir el contenido almacenado en el buffer.

El código base puede adaptarse de los ejemplos de las clases prácticas.
Lo que no está especificado aquí es de libre elección.