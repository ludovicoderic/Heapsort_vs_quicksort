## Valderico Carratala Rizzo 

set terminal png

##########################################################################
## Analisis del algoritmo Quicksort

set output "quickSort.png"

set xlabel "Array size"
set ylabel "Millions of program Steps"

set title  "qs-vs-hs: Empirical Analysis of Steps"

plot "qs-vs-hs.Msteps" using 1:2 with lines title "random arrays", "qs-vs-hs.Msteps" using 1:4 with lines title "sorted arrays","qs-vs-hs.Msteps" using 1:6 with lines title "reverse-sorted arrays"


##########################################################################
## Analisis del algoritmo Heapsort

set output "heapSort.png"

set xlabel "Size of array"
set ylabel "Millions of program steps"

set title  "Heapsort"

plot "qs-vs-hs.Msteps" using 1:3 with lines title "random arrays", "qs-vs-hs.Msteps" using 1:5 with lines title "sorted arrays","qs-vs-hs.Msteps" using 1:7 with lines title "reverse-sorted arrays"

##########################################################################
## Analisis comparativo de Quicksort y Heapsort cuando reciben vectores con contenido y orden aleatorio

set output "qs-vs-hs-RA.png"

set title "Quicksort versus Heapsort (random arrays)"

##Fit to a (n log n + k) function: 
y(x)=a*x*log(x) + b 
fitFunction="Fitting Quicksort time values to f(n) = n log(n)+k"
fit y(x) "qs-vs-hs.Msteps" using 1:2 via a,b

#y1(x)=a*x*log(x) + b 
fitFunction1="Fitting Heapsort time values to f(n) = n log(n)+k"
fit y(x) "qs-vs-hs.Msteps" using 1:3 via a,b

plot "qs-vs-hs.Msteps" using 1:2 with lines title "Quicksort", "qs-vs-hs.Msteps" using 1:3 with lines title "Hespsort", y(x) title fitFunction, y(x) title fitFunction1

##########################################################################
## Analisis comparativo de Quicksort y Heapsort cuando reciben vectores ordenados

set output "qs-vs-hs-SA.png"

set title "Quicksort versus Heapsort (sorted arrays)" 

#fitFunction="Fitting Quicksort time values to f(n) = n log(n)+k"
fit y(x) "qs-vs-hs.Msteps" using 1:4 via a,b

#fitFunction1="Fitting Heapsort time values to f(n) = n log(n)+k"
fit y(x) "qs-vs-hs.Msteps" using 1:5 via a,b

plot "qs-vs-hs.Msteps" using 1:4 with lines title "Quicksort", "qs-vs-hs.Msteps" using 1:5 with lines title "Hespsort", y(x) title fitFunction, y(x) title fitFunction1

##########################################################################
## Analisis comparativo de Quicksort y Heapsort cuando reciben vectores en orden inverso

set output "qs-vs-hs-RSA.png"

set title "Quicksort versus Heapsort (reverse-sorted arrays)" 

#fitFunction="Fitting Quicksort time values to f(n) = n log(n)+k"
fit y(x) "qs-vs-hs.Msteps" using 1:6 via a,b

#fitFunction1="Fitting Heapsort time values to f(n) = n log(n)+k"
fit y(x) "qs-vs-hs.Msteps" using 1:7 via a,b

plot "qs-vs-hs.Msteps" using 1:6 with lines title "Quicksort", "qs-vs-hs.Msteps" using 1:7 with lines title "Hespsort", y(x) title fitFunction, y(x) title fitFunction1
#------------------------------------------------------------------------

