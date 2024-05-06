Algoritmo Subsistema_Bancos
	// Variables
	Definir numero_aleatorio1, numero_aleatorio2 Como Entero
	Definir MontoPago Como Real
	numero_aleatorio1 <- 0
	// generando numeros aleatorios de 8 digitos para el recibo
	Para i<-1 Hasta 8 Hacer
		digito <- Azar(9)
		Si i=1 Entonces
			Mientras digito=0 Hacer
				digito <- Azar(9)
			FinMientras
		FinSi
		numero_aleatorio1 <- numero_aleatorio1*10+digito
	FinPara
	// generando numeros aleatorios de 2 digitos para el recibo
	numero_aleatorio2 <- 0
	Para i<-1 Hasta 2 Hacer
		digito <- Azar(9)
		Si i=1 Entonces
			Mientras digito=0 Hacer
				digito <- Azar(9)
			FinMientras
		FinSi
		numero_aleatorio2 <- numero_aleatorio2*10+digito
	FinPara
	// Introduciendo la fecha 
	// Dia
	Escribir 'Introducir el dia: '
	Leer dia
	// Mes 
	Escribir 'Introducir el mes: '
	Leer mes
	// Año
	Escribir 'Introducir el año: '
	Leer ANO
	// MontoPago 
	Escribir 'Introducir el monto del pago'
	Leer MontoPago
	// recibo
	Escribir ' |-----------------------------------------------------------------------------------------| '
	Escribir ' |   BANRURAL                                                             No. B ', numero_aleatorio1, '   |'
	Escribir ' |', '                                                                                         |'
	Escribir ' |   Banco De Desarollo Rural S.A.  -- DEPOSITO DE CUENTAS CORRIENTES -', numero_aleatorio2, '                  |'
	Escribir ' |   ', dia, '/', mes, '/', ANO, '                                                                              |'
	Escribir ' |   Boleta ', numero_aleatorio1, '                                                                       |'
	Escribir ' |   Cuenta: Universidad Mariano Galvez                                                    |'
	Escribir ' |', ' ', '                                                                                        |'
	Escribir ' |', '   Efectivo:                            Q', MontoPago, '                                             |'
	Escribir ' |', '   Ch. Propios                          Q0', '                                               |'
	Escribir ' |', '   Ch. Bancos                           Q0', '                                               |'
	Escribir ' |', '   Doc. externos                        Q0', '                                               |'
	Escribir ' |', '   Total depositado                     Q', MontoPago, '                                             |'
	Escribir ' |-----------------------------------------------------------------------------------------|'
FinAlgoritmo
