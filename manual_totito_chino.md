# 🎯 Manual de Usuario - Totito Chino

## ¿Qué es Totito Chino?

Totito Chino (también conocido como Timbiriche o Dots and Boxes) es un juego de estrategia donde los jugadores conectan puntos para formar cuadrados y ganar puntos. Es un juego que combina táctica, planificación y un poco de suerte con los poderes especiales.

## 🎮 Objetivo del Juego

Formar el mayor número de cuadrados conectando puntos adyacentes con líneas. Cada cuadrado completo te da:
- **1 punto**
- **Un turno extra**
- **Un poder especial** (si la casilla tiene uno)

## ⚙️ Configuración Inicial

### 1. Tamaño del Tablero
- **Mínimo**: 3x3 puntos  
- **Máximo**: 20x20 puntos
- El programa te preguntará las dimensiones al iniciar

### 2. Jugadores
- **Mínimo**: 2 jugadores
- **Máximo**: 6 jugadores
- Cada jugador debe ingresar:
  - Su nombre
  - Una inicial única (una sola letra)

### Ejemplo de configuración:
```
Ingrese nombre del jugador 1: Angel
Ingrese la inicial para el jugador 1: A
```

## 🎲 Cómo Jugar

### Formato de Movimiento
Para conectar dos puntos vecinos usa el formato:
```
fila1,col1 -> fila2,col2
```

### Ejemplos de movimientos válidos:
- `5,10 -> 5,11` (línea horizontal)
- `3,8 -> 4,8` (línea vertical)

### Reglas básicas:
- Los puntos deben estar **adyacentes** (horizontal o vertical)
- No debe existir una línea ya entre ellos
- Las coordenadas deben estar dentro del tablero

### Representación del Tablero
```
   1   2   3   4   5   
1  •   •   •   •   •
        DL      NT    
2  •   •   •   •   •
    LS      AC  DL    
3  •   •   •   •   •
```

**Leyenda:**
- `•` = Puntos del tablero
- `DL`, `NT`, `AC`, etc. = Poderes especiales en las casillas

## 🎯 Formando Cuadrados

### Ejemplo visual:
```
Antes:          Después (cuadrado completo):
•---•           •---•
    |           |[A]|  <- Casilla cerrada por jugador A
    •           •---•
```

Cuando cierres un cuadrado:
1. Tu inicial aparece en la casilla `[A]`
2. Ganas 1 punto
3. Obtienes el poder de esa casilla (si tiene uno)
4. **¡Juegas de nuevo!** (turno extra)

## ⚡ Poderes Disponibles

| Poder | Símbolo | Descripción |
|-------|---------|-------------|
| **Doble Línea** | `DL` | Coloca dos líneas seguidas en tu turno |
| **Trampa Secreta** | `TS` | Si alguien cierra con tu línea trampa, pierdes el turno pero ganas el punto |
| **Bloqueo** | `BL` | Tu línea no puede ser usada por otros para cerrar cuadrados |
| **Pase** | `PS` | Pasas tu turno y vas al final de la cola |
| **Llave Secreta** | `LS` | Ignora un bloqueo para cerrar un cuadrado |
| **Escurridizo** | `ES` | Te protege contra trampas |
| **Unión a Futuro** | `UF` | Si usas esta línea después para cerrar, obtienes doble punto |
| **A Qué Costo** | `AC` | El punto va al jugador correcto, pero la casilla lleva tu inicial |
| **Nuevas Tierras** | `NT` | Expande el tablero creando nuevos puntos |
| **Explosivos** | `EX` | Elimina un punto del tablero |

## 🎮 Opciones en Tu Turno

Cuando sea tu turno, verás estas opciones:
```
Opciones Disponibles: 
1. Hacer una línea 
2. Usar último power up obtenido 
3. Acabar con el juego 
```

### Opción 1: Hacer una línea
- Ingresa las coordenadas: `fila1,col1 -> fila2,col2`
- La línea se dibujará en el tablero
- Si formas un cuadrado, ¡juegas de nuevo!

### Opción 2: Usar poder
- Activa el último poder que obtuviste
- Algunos poderes se usan automáticamente, otros requieren selección

### Opción 3: Terminar juego
- Finaliza la partida actual

## 🏆 Condiciones de Victoria

El juego termina cuando no se pueden colocar más líneas. El ganador se decide por:

1. **Mayor cantidad de puntos**
2. En empate: Mayor cantidad de cuadrados cerrados
3. En empate: Quien controle más filas
4. En empate: Quien controle más columnas
5. En empate: Quien tenga la isla más grande
6. En empate: Mayor cantidad de poderes usados
7. Si persiste: **Empate técnico**

## 💡 Consejos Estratégicos

- **🔍 Observa las oportunidades**: Evita dar cuadrados fáciles al oponente
- **⚡ Usa los poderes sabiamente**: Algunos poderes son defensivos, otros ofensivos
- **🏰 Controla las esquinas**: Las esquinas del tablero son más difíciles de cerrar
- **🧠 Planifica tus movimientos**: Piensa en las consecuencias de cada línea
- **👀 Vigila los poderes**: Recuerda qué poderes tienen tus oponentes

## 🚀 Ejemplo de Partida

```
Turno de: Angel, inicial: A, punteo: 0

Tablero actual:
   1   2   3   
1  •   •   •   
        DL     
2  •   •   •   
    LS    AC   
3  •   •   •   

Movimiento: 1,1 -> 1,2
Resultado: Línea horizontal dibujada
```

## ❓ Problemas Comunes

**Error de formato**: Si ingresas mal las coordenadas, el programa te pedirá intentar de nuevo.

**Línea ya existe**: No puedes dibujar una línea donde ya existe otra.

**Coordenadas inválidas**: Las coordenadas deben estar dentro del tablero.

---

¡Diviértete jugando Totito Chino y que gane el mejor estratega! 🏆