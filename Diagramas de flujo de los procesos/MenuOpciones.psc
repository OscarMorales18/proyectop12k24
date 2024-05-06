Algoritmo MenuOpciones
    Definir opcion Como Entero;
    
    Escribir "Bienvenido al Sistema";
    Escribir "1. Generar Carnet";
    Escribir "2. Generar Boleta de Pago";
    Escribir "3. Subsistema de Bancos";
    Escribir "4. Matriculación";
    Escribir "Ingrese el número de la opción que desea:";
    Leer opcion;
    
    Segun opcion Hacer
        1:
            // Opción Generar Carnet
            Definir anio, correlativo, carnet Como Cadena;
            anio <- '24';
            correlativo <- ConvertirATexto(AZAR(9999)+1);
            carnet <- '9959-'+anio+'-'+correlativo;
            Escribir 'Número de carnet generado:', carnet;
        2:
            // Opción Generar Boleta de Pago
            Definir nombre, apellido como cadena;
            Definir codigo, tipoEstudiante como entero;
            Definir montoPago, montoInscripcion como real;
            Definir descuento, montoTotal, montoTotalInscripcion como real;
            
            Escribir "Ingrese el nombre del estudiante:";
            Leer nombre;
            Escribir "Ingrese el apellido del estudiante:";
            Leer apellido;
            Escribir "Ingrese el código del estudiante:";
            Leer codigo;
            Escribir "Seleccione el tipo de estudiante:";
            Escribir "1. Nuevo ingreso";
            Escribir "2. Reingreso";
            Leer tipoEstudiante;
            
            Si tipoEstudiante = 1 Entonces
                Escribir "Ingrese el monto de la mensualidad:";
                Leer montoPago;
                Escribir "Ingrese el monto de la inscripción:";
                Leer montoInscripcion;
                
                montoTotal <- montoPago;
                montoTotalInscripcion <- montoInscripcion;
                
                Escribir "********************************************************************************";
                Escribir "*                BOLETA DE PAGO - MENSUALIDAD                                  *";
                Escribir "* Nombre: ", nombre;
                Escribir "* Apellido: ", apellido;
                Escribir "* Código: ", codigo;
                Escribir "* Tipo de estudiante: Nuevo ingreso";
                Escribir "* Monto a pagar (mensualidad): Q", montoPago;
                Escribir "********************************************************************************";
                
                Escribir "********************************************************************************";
                Escribir "*                BOLETA DE PAGO - INSCRIPCIÓN                                  *";
                Escribir "* Nombre: ", nombre;
                Escribir "* Apellido: ", apellido;
                Escribir "* Código: ", codigo;
                Escribir "* Tipo de estudiante: Nuevo ingreso";
                Escribir "* Monto a pagar (inscripción): Q", montoInscripcion;
                Escribir "********************************************************************************";
            Sino
                Escribir "Ingrese el monto a pagar:";
                Leer montoPago;
                
                descuento <- montoPago * 0.1;
                montoTotal <- montoPago - descuento;
                
                Escribir "********************************************************************************";
                Escribir "*                BOLETA DE PAGO -                                              *";
                Escribir "* Nombre: ", nombre;
                Escribir "* Apellido: ", apellido;
                Escribir "* Código: ", codigo;
                Escribir "* Tipo de estudiante: Reingreso";
                Escribir "* Monto a pagar: Q", montoPago;
                Escribir "* Descuento (si se realiza un solo pago del semestre completo): Q", descuento;
                Escribir "* Monto total a pagar: Q", montoTotal;
                Escribir "********************************************************************************";
                
                Escribir "********************************************************************************";
                Escribir "*                BOLETA DE PAGO - INSCRIPCIÓN                                  *";
                Escribir "* Nombre: ", nombre;
                Escribir "* Apellido: ", apellido;
                Escribir "* Código: ", codigo;
                Escribir "* Tipo de estudiante: Nuevo ingreso";
                Escribir "* Monto a pagar (inscripción): Q", montoInscripcion;
                Escribir "********************************************************************************";
            FinSi
        3:
            // Opción Subsistema de Bancos
            // Variables
            Definir numero_aleatorio1, numero_aleatorio2 Como Entero;
            Definir MontoPago Como Real;
            numero_aleatorio1 <- 0;
            // generando numeros aleatorios de 8 digitos para el recibo
            Para i<-1 Hasta 8 Hacer
                digito <- Azar(9);
                Si i=1 Entonces
                    Mientras digito=0 Hacer
                        digito <- Azar(9);
                    FinMientras
                FinSi
                numero_aleatorio1 <- numero_aleatorio1*10+digito;
            FinPara
            // generando numeros aleatorios de 2 digitos para el recibo
            numero_aleatorio2 <- 0;
            Para i<-1 Hasta 2 Hacer
                digito <- Azar(9);
                Si i=1 Entonces
                    Mientras digito=0 Hacer
                        digito <- Azar(9);
                    FinMientras
                FinSi
                numero_aleatorio2 <- numero_aleatorio2*10+digito;
            FinPara
            // Introduciendo la fecha 
            // Dia
            Escribir 'Introducir el dia: ';
            Leer dia;
            // Mes 
            Escribir 'Introducir el mes: ';
            Leer mes;
            // Año
            Escribir 'Introducir el año: ';
            Leer ANO;
            // MontoPago 
            Escribir 'Introducir el monto del pago';
            Leer MontoPago;
            // recibo
            Escribir ' |-----------------------------------------------------------------------------------------| ';
            Escribir ' |   BANRURAL                                                             No. B ', numero_aleatorio1, '   |';
            Escribir ' |', '                                                                                         |';
            Escribir ' |   Banco De Desarollo Rural S.A.  -- DEPOSITO DE CUENTAS CORRIENTES -', numero_aleatorio2, '                  |';
            Escribir ' |   ', dia, '/', mes, '/', ANO, '                                                                              |';
            Escribir ' |   Boleta ', numero_aleatorio1, '                                                                       |';
            Escribir ' |   Cuenta: Universidad Mariano Galvez                                                    |';
            Escribir ' |', ' ', '                                                                                        |';
            Escribir ' |', '   Efectivo:                            Q', MontoPago, '                                             |';
            Escribir ' |', '   Ch. Propios                          Q0', '                                               |';
            Escribir ' |', '   Ch. Bancos                           Q0', '                                              |';
			Escribir ' |', '   Doc. externos                        Q0', '                                               |';
			Escribir ' |', '   Total depositado                     Q', MontoPago, '                                     |';
			Escribir ' |-----------------------------------------------------------------------------------------|';
        4:
          
            Escribir 'Ingrese nombre del alumno: ';
            Leer nomalum;
            Escribir 'Ingrese carnet del alumno';
            Leer carnealum;
            Escribir 'ingrese sede: ';
            Leer sede;
            Escribir 'ingrese numero de recibo: ';
            Leer recibo;
            Escribir 'El Alumno ', nomalum, ' con carnet ', carnealum, ' esta matriculado en ', sede, '.';
    FinSegun
FinAlgoritmo
