 Módulo de Ranking Académico mediante Árbol AVL

 Descripción general

El presente proyecto implementa un módulo de ranking académico utilizando la estructura de datos conocida como árbol AVL. Esta estructura corresponde a un árbol binario de búsqueda autobalanceado, cuyo propósito principal es mantener una organización eficiente de los registros almacenados, garantizando tiempos de operación adecuados para la inserción, búsqueda y recorrido de datos.

El sistema permite registrar estudiantes con información académica relevante, tales como identificador, nombre completo, carrera, semestre, promedio académico y puntaje de habilidad. A partir de este último criterio, denominado skill_score, los estudiantes son organizados dentro del árbol AVL, permitiendo generar un ranking académico ordenado de manera descendente.

 Objetivo del proyecto

Desarrollar una aplicación en C++ que permita gestionar estudiantes dentro de un árbol AVL, aplicando los principios fundamentales de estructuras de datos jerárquicas y algoritmos de balanceo automático.

 Objetivos específicos

- Implementar una estructura de árbol AVL en lenguaje C++.
- Registrar estudiantes con información académica y de desempeño.
- Ordenar los registros con base en el campo skill_score.
- Permitir la búsqueda de estudiantes por puntaje de habilidad.
- Mostrar el ranking académico de forma descendente.
- Presentar estadísticas básicas del árbol, como altura, cantidad de nodos y cantidad de hojas.
- Aplicar buenas prácticas de organización modular mediante archivos de cabecera y archivos de implementación.

 Fundamento teórico

Un árbol AVL es una variante del árbol binario de búsqueda que conserva su balance mediante rotaciones simples y dobles. En este tipo de estructura, la diferencia de altura entre el subárbol izquierdo y el subárbol derecho de cualquier nodo no debe exceder una unidad.

Esta propiedad permite que las operaciones principales, como inserción y búsqueda, mantengan una complejidad temporal de orden logarítmico, es decir, O(log n), siempre que el árbol permanezca balanceado.

En el contexto de este proyecto, el árbol AVL se utiliza para organizar estudiantes según su skill_score, permitiendo construir un ranking académico eficiente y estructurado.

 Criterio de ordenamiento

El criterio principal de ordenamiento utilizado por el árbol AVL es el campo:

cpp
skill_score