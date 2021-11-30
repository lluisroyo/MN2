set terminal gif animate delay 5
set output "animacio.gif"

do for [i=0:248]{
unset key 

set xrange[0:2]
set yrange[36:57]
set object 1 rectangle from 0.75,50 to 1.25,57
set object 1 fillstyle pattern 1 fillcolor "red"
plot "pas".i.".dat"
}
