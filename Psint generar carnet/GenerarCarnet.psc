Algoritmo GenerarCarnet
	Definir anio, correlativo, carnet Como Cadena;
	anio <- '24';
	correlativo <- ConvertirATexto(AZAR(9999)+1);
	carnet <- '9959-'+anio+'-'+correlativo;
	Escribir 'N�mero de carnet generado:', carnet;
FinAlgoritmo
