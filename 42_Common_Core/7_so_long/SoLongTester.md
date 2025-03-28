	
# test.txt








It's necessary a map with '.ber' extension as an argument.
Please, provide a valid map
	ERROR: 	Usage: ./so_long [map.ber]

												. . . KO
												. . . STOP
												. . . SORRY! '>.<
						You can't play

________________________________________________________________________________________________________________________________________



	
# level_0.ber


El mapa estará construido de 3 componentes: paredes, objetos y espacio abierto. El mapa estará compuesto de solo 5 caracteres: 0 para un espacio vacío, 1 para un
muro, C para un coleccionable, E para salir del mapa y P para la posición inicial
del jugador

11111
100R1
1P001
11111


The map is in the valid format.
												. . . OK
The map is open.
												. . . OK
Please, provide a valid map
	ERROR: The map isn't a rectangle or it has an invalid char.
												. . . KO
												. . . STOP
												. . . SORRY! '>.<
						You can't play

________________________________________________________________________________________________________________________________________



	
# level_1.ber


El mapa debe tener una salida, una posición inicial y al menos un objeto coleccionable.

111111
1C0011
100001
1P0011
111111


The map is in the valid format.
												. . . OK
The map is open.
												. . . OK
The map is rectangle.
												. . . OK
The map is surrounded by walls.
												. . . OK
Please, provide a valid map
	ERROR: Incorrect number of exits. (E)
												. . . KO
												. . . SORRY! '>.<
						You can't play


111111
1CE011
1000E1
1P0011
111111


The map is in the valid format.
												. . . OK
The map is open.
												. . . OK
The map is rectangle.
												. . . OK
The map is surrounded by walls.
												. . . OK
Please, provide a valid map
	ERROR: Incorrect number of exits. (E)
												. . . KO
												. . . SORRY! '>.<
						You can't play


111111
1C0011
1000E1
100011
111111


The map is in the valid format.
												. . . OK
The map is open.
												. . . OK
The map is rectangle.
												. . . OK
The map is surrounded by walls.
												. . . OK
Please, provide a valid map
	ERROR: Incorrect number of player's position (P).
												. . . KO
												. . . SORRY! '>.<
						You can't play


111111
1C0P11
1000E1
1P0011
111111


The map is in the valid format.
												. . . OK
The map is open.
												. . . OK
The map is rectangle.
												. . . OK
The map is surrounded by walls.
												. . . OK
Please, provide a valid map
	ERROR: Incorrect number of player's position (P).
												. . . KO
												. . . SORRY! '>.<
						You can't play


111111
100011
1000E1
1P0011
111111


The map is in the valid format.
												. . . OK
The map is open.
												. . . OK
The map is rectangle.
												. . . OK
The map is surrounded by walls.
												. . . OK
Please, provide a valid map
	ERROR: Insufficient number of collectables. (C)
												. . . KO
												. . . SORRY! '>.<
						You can't play


111111
1C0011
10C0E1
1P0011
111111


The map is in the valid format.
												. . . OK
The map is open.
												. . . OK
The map is rectangle.
												. . . OK
The map is surrounded by walls.
												. . . OK
All the important elements are present.
												. . . OK
All elements are accesible.
												. . . OK

						¡¡¡You CAN play!!!


111111
1C0011
1000E1
1P0011
111111


The map is in the valid format.
												. . . OK
The map is open.
												. . . OK
The map is rectangle.
												. . . OK
The map is surrounded by walls.
												. . . OK
All the important elements are present.
												. . . OK
All elements are accesible.
												. . . OK

						¡¡¡You CAN play!!!



________________________________________________________________________________________________________________________________________



	
# level_2.ber


El mapa debe ser rectangular




The map is in the valid format.
												. . . OK
The map is open.
												. . . OK
Please, provide a valid map
	ERROR: The map file seams empty.
												. . . KO
												. . . STOP
												. . . SORRY! '>.<
						You can't play



111111
1C001001
1000E1
1P00101
111111


The map is in the valid format.
												. . . OK
The map is open.
												. . . OK
Please, provide a valid map
	ERROR: The map isn't a rectangle or it has an invalid char.
												. . . KO
												. . . STOP
												. . . SORRY! '>.<
						You can't play



111111
1C0011
1000E1

111111


The map is in the valid format.
												. . . OK
The map is open.
												. . . OK
Please, provide a valid map
	ERROR: The map isn't a rectangle or it has an invalid char.
												. . . KO
												. . . STOP
												. . . SORRY! '>.<
						You can't play



111111
1C0011
1000E1
1P0001
111111


The map is in the valid format.
												. . . OK
The map is open.
												. . . OK
The map is rectangle.
												. . . OK
The map is surrounded by walls.
												. . . OK
All the important elements are present.
												. . . OK
All elements are accesible.
												. . . OK

						¡¡¡You CAN play!!!



________________________________________________________________________________________________________________________________________



	
# level_3.ber


El mapa deberá estar cerrado/rodeado de muros, en caso contrario el programa
deberá devolver un error

111111
1C0011
1000E1
1P0011
110111


The map is in the valid format.
												. . . OK
The map is open.
												. . . OK
The map is rectangle.
												. . . OK
Please, provide a valid map
	ERROR: This map is NOT surrounded by walls (1).
												. . . KO
												. . . STOP
												. . . SORRY! '>.<
						You can't play




________________________________________________________________________________________________________________________________________



	
# level_4.ber


Tienes que comprobar si hay un camino válido en el mapa.

11111111
1C010111
10010E01
1P001111
11111111


The map is in the valid format.
												. . . OK
The map is open.
												. . . OK
The map is rectangle.
												. . . OK
The map is surrounded by walls.
												. . . OK
All the important elements are present.
												. . . OK
Please, provide a valid map
	ERROR: Not all elements are accesible.
												. . . KO
												. . . STOP
												. . . SORRY! '>.<
						You can't play



11111111
1C010111
10000E01
1P001111
11111111


The map is in the valid format.
												. . . OK
The map is open.
												. . . OK
The map is rectangle.
												. . . OK
The map is surrounded by walls.
												. . . OK
All the important elements are present.
												. . . OK
All elements are accesible.
												. . . OK

						¡¡¡You CAN play!!!


11111111
1C010111
100C0E01
1P001111
11111111


The map is in the valid format.
												. . . OK
The map is open.
												. . . OK
The map is rectangle.
												. . . OK
The map is surrounded by walls.
												. . . OK
All the important elements are present.
												. . . OK
All elements are accesible.
												. . . OK

						¡¡¡You CAN play!!!



________________________________________________________________________________________________________________________________________



	
# level_5.ber


El mapa debe tener una extensión .ber

level_5.bEr


It's necessary a map with '.ber' extension as an argument.
Please, provide a valid map
	ERROR: 	Usage: ./so_long [map.ber]

												. . . KO
												. . . STOP
												. . . SORRY! '>.<
						You can't play


level_5.md


It's necessary a map with '.ber' extension as an argument.
Please, provide a valid map
	ERROR: 	Usage: ./so_long [map.ber]

												. . . KO
												. . . STOP
												. . . SORRY! '>.<
						You can't play


level_5.ver


It's necessary a map with '.ber' extension as an argument.
Please, provide a valid map
	ERROR: 	Usage: ./so_long [map.ber]

												. . . KO
												. . . STOP
												. . . SORRY! '>.<
						You can't play




________________________________________________________________________________________________________________________________________



