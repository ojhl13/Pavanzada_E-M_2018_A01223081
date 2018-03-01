key string = char *
value "cualquier cosas"






void * es el apuntador supremo es literalmente solo una direccion


el ponerle el tipo de dato es para cuando el poerador contenido sepa intepretar el contenido de la direccion

por lo qeu no pudes ver el contendio de un void *

sirve para ver y par ainterpretar


debes limitar el hash
por que si no esta en rango 

como programador no podemos tener arreglos que no se van a usar y gastara RAM a lo Chrome

tendremos un parametro para tener un tamaño definido en el HASH
si es muy pequeño es listaligada
si es muy grande pues es un CHROME



da valores en un rango y su entrada e sinfinta puede tener coliciones

 ventaja real de un HASH realmente depende del tamaño que tengas 
 ademas que el arreglo donde buscagas es de N pequeña no N grande por donde tienes coliciones



 que informacion debemos guardar en las key y que debemos guardar en los espacios

  podemos empesar con key y espacios dinamicos para que no tengamos mucho espacio desperdiciado o que no te falte espacio


  array y vector uno tamaño fijo y el otro va creciendo


  par aun vector necesitamos el arreglo perse
  el apuntador al mismo
  el tamaño del mismo
  index es donde vamos a insertar 
  si index es igual a index debemos dulicar el tamaño y copiar lo que teniamos
  podemos empezar en 1 pero es muy costoso enCPU
  pero empezaremos con 2  y usaremos  malloc para ir creciendo
  entonces guadaremos key value por espacio
  	*tamaño
  	*index

  hash no le sacas solo le metes entonces esta medio dificil no jaja? :P

  se tendra
  Elements{
  	char * key
  	value
}


index 	| -> char *key
size 	| -> void * calue
------


usaremos strdump para el apuntador
y usaremos memcpy para compiar el value



init 

insert
	|-> hash(key)
	|-> if
	|-> else
		crecerlo
	|-> inserta
get 
	|-> hash
	|-> is null return null
	|->else buscar
		entregar valor
	|-> null entregado
	

