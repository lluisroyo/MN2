set terminal gif animate delay 2
set output "animacio.gif"

do for [i=0:980]{
unset key

set xrange[0:2]
set yrange[36:55]
set xlabel "x [cm]"
set ylabel "T [℃]" font "Symbola,10"

set object 1 rectangle from 0.75,50 to 1.25,55
set object 1 fillstyle pattern 1 fillcolor "red"
plot "pas".i.".dat"
}

